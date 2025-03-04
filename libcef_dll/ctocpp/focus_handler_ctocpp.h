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

#ifndef _FOCUSHANDLER_CTOCPP_H
#define _FOCUSHANDLER_CTOCPP_H

#ifndef BUILDING_CEF_SHARED
#pragma message("Warning: "__FILE__" may be accessed DLL-side only")
#else // BUILDING_CEF_SHARED

#include "include/cef_focus_handler.h"
#include "include/capi/cef_focus_handler_capi.h"
#include "include/cef_browser.h"
#include "include/capi/cef_browser_capi.h"
#include "include/cef_frame.h"
#include "include/capi/cef_frame_capi.h"
#include "libcef_dll/ctocpp/ctocpp.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed DLL-side only.
class CefFocusHandlerCToCpp
    : public CefCToCpp<CefFocusHandlerCToCpp, CefFocusHandler,
        cef_focus_handler_t>
{
public:
  CefFocusHandlerCToCpp(cef_focus_handler_t* str)
      : CefCToCpp<CefFocusHandlerCToCpp, CefFocusHandler, cef_focus_handler_t>(
          str) {}
  virtual ~CefFocusHandlerCToCpp() {}

  // CefFocusHandler methods
  virtual void OnTakeFocus(CefRefPtr<CefBrowser> browser, bool next) OVERRIDE;
  virtual bool OnSetFocus(CefRefPtr<CefBrowser> browser,
      FocusSource source) OVERRIDE;
  virtual void OnFocusedNodeChanged(CefRefPtr<CefBrowser> browser,
      CefRefPtr<CefFrame> frame, CefRefPtr<CefDOMNode> node) OVERRIDE;
};

#endif // BUILDING_CEF_SHARED
#endif // _FOCUSHANDLER_CTOCPP_H

