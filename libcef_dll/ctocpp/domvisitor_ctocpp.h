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

#ifndef _DOMVISITOR_CTOCPP_H
#define _DOMVISITOR_CTOCPP_H

#ifndef BUILDING_CEF_SHARED
#pragma message("Warning: "__FILE__" may be accessed DLL-side only")
#else // BUILDING_CEF_SHARED

#include "include/cef_dom.h"
#include "include/capi/cef_dom_capi.h"
#include "libcef_dll/ctocpp/ctocpp.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed DLL-side only.
class CefDOMVisitorCToCpp
    : public CefCToCpp<CefDOMVisitorCToCpp, CefDOMVisitor, cef_domvisitor_t>
{
public:
  CefDOMVisitorCToCpp(cef_domvisitor_t* str)
      : CefCToCpp<CefDOMVisitorCToCpp, CefDOMVisitor, cef_domvisitor_t>(str) {}
  virtual ~CefDOMVisitorCToCpp() {}

  // CefDOMVisitor methods
  virtual void Visit(CefRefPtr<CefDOMDocument> document) OVERRIDE;
};

#endif // BUILDING_CEF_SHARED
#endif // _DOMVISITOR_CTOCPP_H

