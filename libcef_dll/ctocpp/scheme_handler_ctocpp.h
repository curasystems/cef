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

#ifndef _SCHEMEHANDLER_CTOCPP_H
#define _SCHEMEHANDLER_CTOCPP_H

#ifndef BUILDING_CEF_SHARED
#pragma message("Warning: "__FILE__" may be accessed DLL-side only")
#else // BUILDING_CEF_SHARED

#include "include/cef_scheme.h"
#include "include/capi/cef_scheme_capi.h"
#include "include/cef_browser.h"
#include "include/capi/cef_browser_capi.h"
#include "include/cef_request.h"
#include "include/capi/cef_request_capi.h"
#include "include/cef_response.h"
#include "include/capi/cef_response_capi.h"
#include "libcef_dll/ctocpp/ctocpp.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed DLL-side only.
class CefSchemeHandlerCToCpp
    : public CefCToCpp<CefSchemeHandlerCToCpp, CefSchemeHandler,
        cef_scheme_handler_t>
{
public:
  CefSchemeHandlerCToCpp(cef_scheme_handler_t* str)
      : CefCToCpp<CefSchemeHandlerCToCpp, CefSchemeHandler,
          cef_scheme_handler_t>(str) {}
  virtual ~CefSchemeHandlerCToCpp() {}

  // CefSchemeHandler methods
  virtual bool ProcessRequest(CefRefPtr<CefRequest> request,
      CefRefPtr<CefSchemeHandlerCallback> callback) OVERRIDE;
  virtual void GetResponseHeaders(CefRefPtr<CefResponse> response,
      int64& response_length, CefString& redirectUrl) OVERRIDE;
  virtual bool ReadResponse(void* data_out, int bytes_to_read, int& bytes_read,
      CefRefPtr<CefSchemeHandlerCallback> callback) OVERRIDE;
  virtual void Cancel() OVERRIDE;
};

#endif // BUILDING_CEF_SHARED
#endif // _SCHEMEHANDLER_CTOCPP_H

