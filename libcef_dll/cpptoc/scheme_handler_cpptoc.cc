// Copyright (c) 2011 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// A portion of this file was generated by the CEF translator tool.  When
// making changes by hand only do so within the body of existing function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//

#include "libcef_dll/cpptoc/scheme_handler_cpptoc.h"
#include "libcef_dll/ctocpp/request_ctocpp.h"
#include "libcef_dll/ctocpp/response_ctocpp.h"
#include "libcef_dll/ctocpp/scheme_handler_callback_ctocpp.h"


// MEMBER FUNCTIONS - Body may be edited by hand.

int CEF_CALLBACK scheme_handler_process_request(
    struct _cef_scheme_handler_t* self, cef_request_t* request,
    cef_scheme_handler_callback_t* callback)
{
  DCHECK(self);
  DCHECK(request);
  if(!self || !request)
    return 0;

  return CefSchemeHandlerCppToC::Get(self)->ProcessRequest(
      CefRequestCToCpp::Wrap(request),
      CefSchemeHandlerCallbackCToCpp::Wrap(callback));
}

void CEF_CALLBACK scheme_handler_get_response_headers(
    struct _cef_scheme_handler_t* self, cef_response_t* response,
    int64* response_length, cef_string_t* redirectUrl)
{
  DCHECK(self);
  DCHECK(response);
  DCHECK(response_length);
  DCHECK(redirectUrl);
  if (!self || !response || !response_length || !redirectUrl)
    return;

  CefString redirectUrlStr(redirectUrl);
  CefSchemeHandlerCppToC::Get(self)->GetResponseHeaders(
      CefResponseCToCpp::Wrap(response), *response_length, redirectUrlStr);
}

int CEF_CALLBACK scheme_handler_read_response(
    struct _cef_scheme_handler_t* self, void* data_out, int bytes_to_read,
    int* bytes_read, cef_scheme_handler_callback_t* callback)
{
  DCHECK(self);
  DCHECK(data_out);
  DCHECK(bytes_read);
  if(!self || !data_out || !bytes_read)
    return 0;

  return CefSchemeHandlerCppToC::Get(self)->ReadResponse(
      data_out, bytes_to_read, *bytes_read,
      CefSchemeHandlerCallbackCToCpp::Wrap(callback)) ? 1 : 0;
}

void CEF_CALLBACK scheme_handler_cancel(struct _cef_scheme_handler_t* self)
{
  DCHECK(self);
  if(!self)
    return;

  CefSchemeHandlerCppToC::Get(self)->Cancel();
}


// CONSTRUCTOR - Do not edit by hand.

CefSchemeHandlerCppToC::CefSchemeHandlerCppToC(CefSchemeHandler* cls)
    : CefCppToC<CefSchemeHandlerCppToC, CefSchemeHandler, cef_scheme_handler_t>(
        cls)
{
  struct_.struct_.process_request = scheme_handler_process_request;
  struct_.struct_.get_response_headers = scheme_handler_get_response_headers;
  struct_.struct_.read_response = scheme_handler_read_response;
  struct_.struct_.cancel = scheme_handler_cancel;
}

#ifndef NDEBUG
template<> long CefCppToC<CefSchemeHandlerCppToC, CefSchemeHandler,
    cef_scheme_handler_t>::DebugObjCt = 0;
#endif

