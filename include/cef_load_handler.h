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
// The contents of this file must follow a specific format in order to
// support the CEF translator tool. See the translator.README.txt file in the
// tools directory for more information.
//

#ifndef _CEF_LOAD_HANDLER_H
#define _CEF_LOAD_HANDLER_H

#include "cef_base.h"

class CefBrowser;
class CefFrame;

///
// Implement this interface to handle events related to browser load status. The
// methods of this class will be called on the UI thread.
///
/*--cef(source=client)--*/
class CefLoadHandler : public virtual CefBase
{
public:
  typedef cef_handler_errorcode_t ErrorCode;

  ///
  // Called when the browser begins loading a frame. The |frame| value will
  // never be empty -- call the IsMain() method to check if this frame is the
  // main frame. Multiple frames may be loading at the same time. Sub-frames may
  // start or continue loading after the main frame load has ended. This method
  // may not be called for a particular frame if the load request for that frame
  // fails.
  ///
  /*--cef()--*/
  virtual void OnLoadStart(CefRefPtr<CefBrowser> browser,
                           CefRefPtr<CefFrame> frame) {}

  ///
  // Called when the browser is done loading a frame. The |frame| value will
  // never be empty -- call the IsMain() method to check if this frame is the
  // main frame. Multiple frames may be loading at the same time. Sub-frames may
  // start or continue loading after the main frame load has ended. This method
  // will always be called for all frames irrespective of whether the request
  // completes successfully.
  ///
  /*--cef()--*/
  virtual void OnLoadEnd(CefRefPtr<CefBrowser> browser,
                         CefRefPtr<CefFrame> frame,
                         int httpStatusCode) {}

  ///
  // Called when the browser fails to load a resource. |errorCode| is the error
  // code number and |failedUrl| is the URL that failed to load. To provide
  // custom error text assign the text to |errorText| and return true.
  // Otherwise, return false for the default error text. See
  // net\base\net_error_list.h for complete descriptions of the error codes.
  ///
  /*--cef()--*/
  virtual bool OnLoadError(CefRefPtr<CefBrowser> browser,
                           CefRefPtr<CefFrame> frame,
                           ErrorCode errorCode,
                           const CefString& failedUrl,
                           CefString& errorText) { return false; }
};

#endif // _CEF_LOAD_HANDLER_H
