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

#ifndef _CEF_FRAME_H
#define _CEF_FRAME_H

#include "cef_base.h"

class CefBrowser;
class CefDOMVisitor;
class CefRequest;
class CefStreamReader;
class CefV8Context;

///
// Class used to represent a frame in the browser window. The methods of this
// class may be called on any thread unless otherwise indicated in the comments.
///
/*--cef(source=library)--*/
class CefFrame : public virtual CefBase
{
public:
  ///
  // Execute undo in this frame.
  ///
  /*--cef()--*/
  virtual void Undo() =0;
  ///
  // Execute redo in this frame.
  ///
  /*--cef()--*/
  virtual void Redo() =0;
  ///
  // Execute cut in this frame.
  ///
  /*--cef()--*/
  virtual void Cut() =0;
  ///
  // Execute copy in this frame.
  ///
  /*--cef()--*/
  virtual void Copy() =0;
  ///
  // Execute paste in this frame.
  ///
  /*--cef()--*/
  virtual void Paste() =0;
  ///
  // Execute delete in this frame.
  ///
  /*--cef(capi_name=del)--*/
  virtual void Delete() =0;
  ///
  // Execute select all in this frame.
  ///
  /*--cef()--*/
  virtual void SelectAll() =0;

  ///
  // Execute printing in the this frame.  The user will be prompted with the
  // print dialog appropriate to the operating system.
  ///
  /*--cef()--*/
  virtual void Print() =0;

  ///
  // Save this frame's HTML source to a temporary file and open it in the
  // default text viewing application.
  ///
  /*--cef()--*/
  virtual void ViewSource() =0;

  ///
  // Returns this frame's HTML source as a string. This method should only be
  // called on the UI thread.
  ///
  /*--cef()--*/
  virtual CefString GetSource() =0;

  ///
  // Returns this frame's display text as a string. This method should only be
  // called on the UI thread.
  ///
  /*--cef()--*/
  virtual CefString GetText() =0;

  ///
  // Load the request represented by the |request| object.
  ///
  /*--cef()--*/
  virtual void LoadRequest(CefRefPtr<CefRequest> request) =0;

  ///
  // Load the specified |url|.
  ///
  /*--cef()--*/
  virtual void LoadURL(const CefString& url) =0;

  ///
  // Load the contents of |string| with the optional dummy target |url|.
  ///
  /*--cef()--*/
  virtual void LoadString(const CefString& string,
                          const CefString& url) =0;

  ///
  // Load the contents of |stream| with the optional dummy target |url|.
  ///
  /*--cef()--*/
  virtual void LoadStream(CefRefPtr<CefStreamReader> stream,
                          const CefString& url) =0;

  ///
  // Execute a string of JavaScript code in this frame. The |script_url|
  // parameter is the URL where the script in question can be found, if any.
  // The renderer may request this URL to show the developer the source of the
  // error.  The |start_line| parameter is the base line number to use for error
  // reporting.
  ///
  /*--cef(optional_param=scriptUrl)--*/
  virtual void ExecuteJavaScript(const CefString& jsCode, 
                                 const CefString& scriptUrl,
                                 int startLine) =0;

  ///
  // Returns true if this is the main (top-level) frame.
  ///
  /*--cef()--*/
  virtual bool IsMain() =0;

  ///
  // Returns true if this is the focused frame. This method should only be
  // called on the UI thread.
  ///
  /*--cef()--*/
  virtual bool IsFocused() =0;

  ///
  // Returns the name for this frame. If the frame has an assigned name (for
  // example, set via the iframe "name" attribute) then that value will be
  // returned. Otherwise a unique name will be constructed based on the frame
  // parent hierarchy. The main (top-level) frame will always have an empty name
  // value.
  ///
  /*--cef()--*/
  virtual CefString GetName() =0;

  ///
  // Returns the globally unique identifier for this frame. This method should
  // only be called on the UI thread.
  ///
  /*--cef()--*/
  virtual long long GetIdentifier() =0;

  ///
  // Returns the parent of this frame or NULL if this is the main (top-level)
  // frame. This method should only be called on the UI thread.
  ///
  /*--cef()--*/
  virtual CefRefPtr<CefFrame> GetParent() =0;

  ///
  // Returns the URL currently loaded in this frame. This method should only be
  // called on the UI thread.
  ///
  /*--cef()--*/
  virtual CefString GetURL() =0;

  ///
  // Returns the browser that this frame belongs to.
  ///
  /*--cef()--*/
  virtual CefRefPtr<CefBrowser> GetBrowser() =0;

  ///
  // Visit the DOM document.
  ///
  /*--cef()--*/
  virtual void VisitDOM(CefRefPtr<CefDOMVisitor> visitor) =0;

  ///
  // Get the V8 context associated with the frame. This method should only be
  // called on the UI thread.
  ///
  /*--cef()--*/
  virtual CefRefPtr<CefV8Context> GetV8Context() =0;
};

#endif // _CEF_FRAME_H
