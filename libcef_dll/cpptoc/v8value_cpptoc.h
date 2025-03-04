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

#ifndef _V8VALUE_CPPTOC_H
#define _V8VALUE_CPPTOC_H

#ifndef BUILDING_CEF_SHARED
#pragma message("Warning: "__FILE__" may be accessed DLL-side only")
#else // BUILDING_CEF_SHARED

#include "include/cef_v8.h"
#include "include/capi/cef_v8_capi.h"
#include "include/cef_browser.h"
#include "include/capi/cef_browser_capi.h"
#include "include/cef_frame.h"
#include "include/capi/cef_frame_capi.h"
#include "libcef_dll/cpptoc/cpptoc.h"

// Wrap a C++ class with a C structure.
// This class may be instantiated and accessed DLL-side only.
class CefV8ValueCppToC
    : public CefCppToC<CefV8ValueCppToC, CefV8Value, cef_v8value_t>
{
public:
  CefV8ValueCppToC(CefV8Value* cls);
  virtual ~CefV8ValueCppToC() {}
};

#endif // BUILDING_CEF_SHARED
#endif // _V8VALUE_CPPTOC_H

