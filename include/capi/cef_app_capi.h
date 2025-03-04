// Copyright (c) 2011 Marshall A. Greenblatt. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//    * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//    * Neither the name of Google Inc. nor the name Chromium Embedded
// Framework nor the names of its contributors may be used to endorse
// or promote products derived from this software without specific prior
// written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool and should not edited
// by hand. See the translator.README.txt file in the tools directory for
// more information.
//

#ifndef _CEF_APP_CAPI_H
#define _CEF_APP_CAPI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "cef_base_capi.h"


///
// This function should be called on the main application thread to initialize
// CEF when the application is started. The |application| parameter may be NULL.
// A return value of true (1) indicates that it succeeded and false (0)
// indicates that it failed.
///
CEF_EXPORT int cef_initialize(const struct _cef_settings_t* settings,
    struct _cef_app_t* application);

///
// This function should be called on the main application thread to shut down
// CEF before the application exits.
///
CEF_EXPORT void cef_shutdown();

///
// Perform a single iteration of CEF message loop processing. This function is
// used to integrate the CEF message loop into an existing application message
// loop. Care must be taken to balance performance against excessive CPU usage.
// This function should only be called on the main application thread and only
// if cef_initialize() is called with a CefSettings.multi_threaded_message_loop
// value of false (0). This function will not block.
///
CEF_EXPORT void cef_do_message_loop_work();

///
// Run the CEF message loop. Use this function instead of an application-
// provided message loop to get the best balance between performance and CPU
// usage. This function should only be called on the main application thread and
// only if cef_initialize() is called with a
// CefSettings.multi_threaded_message_loop value of false (0). This function
// will block until a quit message is received by the system.
///
CEF_EXPORT void cef_run_message_loop();

///
// Quit the CEF message loop that was started by calling cef_run_message_loop().
// This function should only be called on the main application thread and only
// if cef_run_message_loop() was used.
///
CEF_EXPORT void cef_quit_message_loop();

///
// Implement this structure to provide handler implementations.
///
typedef struct _cef_app_t
{
  ///
  // Base structure.
  ///
  cef_base_t base;

  ///
  // Return the handler for proxy events. If not handler is returned the default
  // system handler will be used.
  ///
  struct _cef_proxy_handler_t* (CEF_CALLBACK *get_proxy_handler)(
      struct _cef_app_t* self);

} cef_app_t;


#ifdef __cplusplus
}
#endif

#endif // _CEF_APP_CAPI_H
