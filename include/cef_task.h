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

#ifndef _CEF_TASK_H
#define _CEF_TASK_H

#include "cef_base.h"

class CefTask;

typedef cef_thread_id_t CefThreadId;

///
// CEF maintains multiple internal threads that are used for handling different
// types of tasks. The UI thread creates the browser window and is used for all
// interaction with the WebKit rendering engine and V8 JavaScript engine (The
// UI thread will be the same as the main application thread if CefInitialize()
// is called with a CefSettings.multi_threaded_message_loop value of false.) The
// IO thread is used for handling schema and network requests. The FILE thread
// is used for the application cache and other miscellaneous activities. This
// function will return true if called on the specified thread.
///
/*--cef()--*/
bool CefCurrentlyOn(CefThreadId threadId);

///
// Post a task for execution on the specified thread. This function may be
// called on any thread.
///
/*--cef()--*/
bool CefPostTask(CefThreadId threadId, CefRefPtr<CefTask> task);

///
// Post a task for delayed execution on the specified thread. This function may
// be called on any thread.
///
/*--cef()--*/
bool CefPostDelayedTask(CefThreadId threadId, CefRefPtr<CefTask> task,
                        long delay_ms);


///
// Implement this interface for task execution. The methods of this class may
// be called on any thread.
///
/*--cef(source=client)--*/
class CefTask : public virtual CefBase
{
public:
  ///
  // Method that will be executed. |threadId| is the thread executing the call.
  ///
  /*--cef()--*/
  virtual void Execute(CefThreadId threadId) =0;
};

#endif // _CEF_TASK_H
