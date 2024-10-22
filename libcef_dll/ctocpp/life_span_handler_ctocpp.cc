// Copyright (c) 2011 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool. If making changes by
// hand only do so within the body of existing method and function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//

#include "libcef_dll/cpptoc/browser_cpptoc.h"
#include "libcef_dll/ctocpp/client_ctocpp.h"
#include "libcef_dll/ctocpp/life_span_handler_ctocpp.h"


// VIRTUAL METHODS - Body may be edited by hand.

bool CefLifeSpanHandlerCToCpp::OnBeforePopup(
    CefRefPtr<CefBrowser> parentBrowser, const CefPopupFeatures& popupFeatures,
    CefWindowInfo& windowInfo, const CefString& url,
    CefRefPtr<CefClient>& client, CefBrowserSettings& settings)
{
  if (CEF_MEMBER_MISSING(struct_, on_before_popup))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: parentBrowser; type: refptr_diff
  DCHECK(parentBrowser.get());
  if (!parentBrowser.get())
    return false;
  // Unverified params: url

  // Translate param: client; type: refptr_same_byref
  cef_client_t* clientStruct = NULL;
  if(client.get())
    clientStruct = CefClientCToCpp::Unwrap(client);
  cef_client_t* clientOrig = clientStruct;

  // Execute
  int _retval = struct_->on_before_popup(struct_,
      CefBrowserCppToC::Wrap(parentBrowser),
      &popupFeatures,
      &windowInfo,
      url.GetStruct(),
      &clientStruct,
      &settings);

  // Restore param:client; type: refptr_same_byref
  if (clientStruct) {
    if (clientStruct != clientOrig) {
      client = CefClientCToCpp::Wrap(clientStruct);
    }
  } else {
    client = NULL;
  }

  // Return type: bool
  return _retval?true:false;
}

void CefLifeSpanHandlerCToCpp::OnAfterCreated(CefRefPtr<CefBrowser> browser)
{
  if (CEF_MEMBER_MISSING(struct_, on_after_created))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return;

  // Execute
  struct_->on_after_created(struct_,
      CefBrowserCppToC::Wrap(browser));
}

bool CefLifeSpanHandlerCToCpp::RunModal(CefRefPtr<CefBrowser> browser)
{
  if (CEF_MEMBER_MISSING(struct_, run_modal))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return false;

  // Execute
  int _retval = struct_->run_modal(struct_,
      CefBrowserCppToC::Wrap(browser));

  // Return type: bool
  return _retval?true:false;
}

bool CefLifeSpanHandlerCToCpp::DoClose(CefRefPtr<CefBrowser> browser)
{
  if (CEF_MEMBER_MISSING(struct_, do_close))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return false;

  // Execute
  int _retval = struct_->do_close(struct_,
      CefBrowserCppToC::Wrap(browser));

  // Return type: bool
  return _retval?true:false;
}

void CefLifeSpanHandlerCToCpp::OnBeforeClose(CefRefPtr<CefBrowser> browser)
{
  if (CEF_MEMBER_MISSING(struct_, on_before_close))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return;

  // Execute
  struct_->on_before_close(struct_,
      CefBrowserCppToC::Wrap(browser));
}


#ifndef NDEBUG
template<> long CefCToCpp<CefLifeSpanHandlerCToCpp, CefLifeSpanHandler,
    cef_life_span_handler_t>::DebugObjCt = 0;
#endif

