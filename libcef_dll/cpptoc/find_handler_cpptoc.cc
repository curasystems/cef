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

#include "libcef_dll/cpptoc/find_handler_cpptoc.h"
#include "libcef_dll/ctocpp/browser_ctocpp.h"


// MEMBER FUNCTIONS - Body may be edited by hand.

void CEF_CALLBACK find_handler_on_find_result(struct _cef_find_handler_t* self,
    cef_browser_t* browser, int identifier, int count,
    const cef_rect_t* selectionRect, int activeMatchOrdinal, int finalUpdate)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return;
  // Verify param: selectionRect; type: simple_byref_const
  DCHECK(selectionRect);
  if (!selectionRect)
    return;

  // Translate param: selectionRect; type: simple_byref_const
  CefRect selectionRectVal = selectionRect?*selectionRect:CefRect();

  // Execute
  CefFindHandlerCppToC::Get(self)->OnFindResult(
      CefBrowserCToCpp::Wrap(browser),
      identifier,
      count,
      selectionRectVal,
      activeMatchOrdinal,
      finalUpdate?true:false);
}


// CONSTRUCTOR - Do not edit by hand.

CefFindHandlerCppToC::CefFindHandlerCppToC(CefFindHandler* cls)
    : CefCppToC<CefFindHandlerCppToC, CefFindHandler, cef_find_handler_t>(cls)
{
  struct_.struct_.on_find_result = find_handler_on_find_result;
}

#ifndef NDEBUG
template<> long CefCppToC<CefFindHandlerCppToC, CefFindHandler,
    cef_find_handler_t>::DebugObjCt = 0;
#endif

