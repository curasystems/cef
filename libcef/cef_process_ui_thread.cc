// Copyright (c) 2010 The Chromium Embedded Framework Authors.
// Portions copyright (c) 2010 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "cef_process_ui_thread.h"
#include "browser_webkit_glue.h"
#include "browser_webkit_init.h"
#include "cef_context.h"
#include "include/cef_version.h"

#include "base/bind.h"
#include "base/command_line.h"
#include "base/i18n/icu_util.h"
#include "base/metrics/stats_table.h"
#include "base/rand_util.h"
#include "base/string_number_conversions.h"
#include "base/stringprintf.h"
#include "build/build_config.h"
#include "net/base/net_module.h"
#include "third_party/WebKit/Source/WebKit/chromium/public/WebNetworkStateNotifier.h"
#include "third_party/WebKit/Source/WebKit/chromium/public/WebScriptController.h"
#include "ui/base/ui_base_paths.h"
#include "ui/gfx/gl/gl_implementation.h"
#include "webkit/extensions/v8/gc_extension.h"
#include "webkit/glue/user_agent.h"
#include "webkit/glue/webkit_glue.h"
#include "webkit/plugins/npapi/plugin_list.h"

#if defined(OS_WIN)
#include <commctrl.h>
#include <Objbase.h>
#endif

static const char* kStatsFilePrefix = "libcef_";
static int kStatsFileThreads = 20;
static int kStatsFileCounters = 200;

CefProcessUIThread::CefProcessUIThread()
      : CefThread(CefThread::UI), statstable_(NULL), webkit_init_(NULL) {}

CefProcessUIThread::CefProcessUIThread(MessageLoop* message_loop)
      : CefThread(CefThread::UI, message_loop), statstable_(NULL),
        webkit_init_(NULL) {}

CefProcessUIThread::~CefProcessUIThread() {
  // We cannot rely on our base class to stop the thread since we want our
  // CleanUp function to run.
  Stop();
}

void CefProcessUIThread::Init() {
  // Initialize the global CommandLine object.
  CommandLine::Init(0, NULL);

  const CefSettings& settings = _Context->settings();

  // Initialize logging.
  logging::LoggingDestination logging_dest;
  if (settings.log_severity == LOGSEVERITY_DISABLE) {
    logging_dest = logging::LOG_NONE;
  } else {
#if defined(OS_WIN)
    logging_dest = logging::LOG_ONLY_TO_FILE;
#else
    logging_dest = logging::LOG_TO_BOTH_FILE_AND_SYSTEM_DEBUG_LOG;
#endif
    logging::SetMinLogLevel(settings.log_severity);
  }

  FilePath log_file = FilePath(CefString(&settings.log_file));
  logging::InitLogging(log_file.value().c_str(), logging_dest,
      logging::DONT_LOCK_LOG_FILE, logging::APPEND_TO_OLD_LOG_FILE,
      logging::DISABLE_DCHECK_FOR_NON_OFFICIAL_RELEASE_BUILDS);

  // Load ICU data tables.
  bool ret = icu_util::Initialize();
  if(!ret) {
#if defined(OS_WIN)
    MessageBox(NULL, L"Failed to load the required icudt library",
      L"CEF Initialization Error", MB_ICONERROR | MB_OK);
#endif
    return;
  }

  // Provides path resolution required for locating locale pack files.
  ui::RegisterPathProvider();

  webkit_glue::InitializeResourceBundle(_Context->locale());

  PlatformInit();

  // Initialize WebKit.
  webkit_init_ = new BrowserWebKitInit();

  // Initialize WebKit encodings
  webkit_glue::InitializeTextEncoding();

  // Config the network module so it has access to a limited set of resources.
  net::NetModule::SetResourceProvider(webkit_glue::GetDataResource);

  // Load and initialize the stats table.  Attempt to construct a somewhat
  // unique name to isolate separate instances from each other.
  statstable_ = new base::StatsTable(
      kStatsFilePrefix + base::Uint64ToString(base::RandUint64()),
      kStatsFileThreads,
      kStatsFileCounters);
  base::StatsTable::set_current(statstable_);

  // CEF always exposes the GC.
  std::string javascript_flags = "--expose-gc";
  if (settings.javascript_flags.length > 0)
    javascript_flags += " " + CefString(&settings.javascript_flags).ToString();
  webkit_glue::SetJavaScriptFlags(javascript_flags);

  // Expose GCController to JavaScript.
  WebKit::WebScriptController::registerExtension(
      extensions_v8::GCExtension::Get());

#if defined(OS_WIN)
  if (settings.graphics_implementation == ANGLE_IN_PROCESS ||
      settings.graphics_implementation == ANGLE_IN_PROCESS_COMMAND_BUFFER) {
    gfx::InitializeGLBindings(gfx::kGLImplementationEGLGLES2);
  } else {
    gfx::InitializeGLBindings(gfx::kGLImplementationDesktopGL);
  }
#else
  gfx::InitializeGLBindings(gfx::kGLImplementationDesktopGL);
#endif

  // Set storage quota limits.
  if (settings.local_storage_quota != 0)
    DOMStorageContext::set_local_storage_quota(settings.local_storage_quota);
  if (settings.session_storage_quota != 0)
    DOMStorageContext::set_session_storage_quota(settings.session_storage_quota);

  // Create the storage context object.
  _Context->set_storage_context(new DOMStorageContext(_Context->cache_path()));

  if (settings.user_agent.length > 0) {
    webkit_glue::SetUserAgent(CefString(&settings.user_agent), false);
  } else {
    std::string product_version;

    if (settings.product_version.length > 0) {
      product_version = CefString(&settings.product_version).ToString();
    } else {
      product_version = base::StringPrintf("Chrome/%d.%d.%d.%d",
          CHROME_VERSION_MAJOR, CHROME_VERSION_MINOR, CHROME_VERSION_BUILD,
          CHROME_VERSION_PATCH);
    }

    webkit_glue::SetUserAgent(
        webkit_glue::BuildUserAgentFromProduct(product_version), false);
  }
  
  if (settings.extra_plugin_paths) {
    cef_string_t str;
    memset(&str, 0, sizeof(str));

    FilePath path;
    int size = cef_string_list_size(settings.extra_plugin_paths);
    for(int i = 0; i < size; ++i) {
      if (!cef_string_list_value(settings.extra_plugin_paths, i, &str))
        continue;
      path = FilePath(CefString(&str));
      webkit::npapi::PluginList::Singleton()->AddExtraPluginPath(path);
    }
  }

  // Create a network change notifier before starting the IO & File threads.
  network_change_notifier_.reset(net::NetworkChangeNotifier::Create());

  // Add a listener for OnOnlineStateChanged to notify WebKit of changes.
  net::NetworkChangeNotifier::AddOnlineStateObserver(this);

  // Initialize WebKit with the current state.
  WebKit::WebNetworkStateNotifier::setOnLine(
      !net::NetworkChangeNotifier::IsOffline());
}

void CefProcessUIThread::CleanUp() {
  // Flush any remaining messages.  This ensures that any accumulated
  // Task objects get destroyed before we exit, which avoids noise in
  // purify leak-test results.
  MessageLoop::current()->RunAllPending();

  // Destroy the storage context object.
  _Context->set_storage_context(NULL);

  // Tear down the shared StatsTable.
  base::StatsTable::set_current(NULL);
  delete statstable_;
  statstable_ = NULL;

  // Shut down WebKit.
  delete webkit_init_;
  webkit_init_ = NULL;

  // Release the network change notifier after all other threads end.
  net::NetworkChangeNotifier::RemoveOnlineStateObserver(this);
  network_change_notifier_.reset();

  PlatformCleanUp();

  webkit_glue::CleanupResourceBundle();
}

AudioManager* CefProcessUIThread::audio_manager() {
  DCHECK(CefThread::CurrentlyOn(CefThread::UI));
  if (!audio_manager_)
    audio_manager_ = AudioManager::Create();

  return audio_manager_;
}

void CefProcessUIThread::OnOnlineStateChanged(bool online) {
  DCHECK(CefThread::CurrentlyOn(CefThread::UI));
  WebKit::WebNetworkStateNotifier::setOnLine(online);
}

