// Copyright (c) 2011 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// A portion of this file was generated by the CEF translator tool.  When
// making changes by hand only do so within the body of existing static and
// virtual method implementations. See the translator.README.txt file in the
// tools directory for more information.
//

#include "libcef_dll/cpptoc/browser_cpptoc.h"
#include "libcef_dll/ctocpp/keyboard_handler_ctocpp.h"


// VIRTUAL METHODS - Body may be edited by hand.

bool CefKeyboardHandlerCToCpp::OnKeyEvent(CefRefPtr<CefBrowser> browser,
    KeyEventType type, int code, int modifiers, bool isSystemKey,
    bool isAfterJavaScript)
{
  if (CEF_MEMBER_MISSING(struct_, on_key_event))
    return false;

  return struct_->on_key_event(struct_, CefBrowserCppToC::Wrap(browser),
      type, code, modifiers, isSystemKey, isAfterJavaScript) ? true : false;
}


#ifndef NDEBUG
template<> long CefCToCpp<CefKeyboardHandlerCToCpp, CefKeyboardHandler,
    cef_keyboard_handler_t>::DebugObjCt = 0;
#endif

