// Copyright (c) 2009 The Chromium Embedded Framework Authors. All rights
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

#include "../precompiled_libcef.h"
#include "cpptoc/request_cpptoc.h"
#include "ctocpp/scheme_handler_ctocpp.h"
#include "../transfer_util.h"


// VIRTUAL METHODS - Body may be edited by hand.

bool CefSchemeHandlerCToCpp::ProcessRequest(CefRefPtr<CefRequest> request,
    std::wstring& mime_type, int* response_length)
{
  if(CEF_MEMBER_MISSING(struct_, process_request))
    return false;

  cef_string_t mimeTypeRet = NULL;
  if(!mime_type.empty())
    mimeTypeRet = cef_string_alloc(mime_type.c_str());

  int rv = struct_->process_request(struct_, CefRequestCppToC::Wrap(request),
      &mimeTypeRet, response_length);

  transfer_string_contents(mimeTypeRet, mime_type, true);

  return rv;
}

void CefSchemeHandlerCToCpp::Cancel()
{
  if(CEF_MEMBER_MISSING(struct_, cancel))
    return;

  struct_->cancel(struct_);
}

bool CefSchemeHandlerCToCpp::ReadResponse(void* data_out, int bytes_to_read,
    int* bytes_read)
{
  if(CEF_MEMBER_MISSING(struct_, read_response))
    return false;

  return struct_->read_response(struct_, data_out, bytes_to_read, bytes_read);
}


#ifdef _DEBUG
long CefCToCpp<CefSchemeHandlerCToCpp, CefSchemeHandler,
    cef_scheme_handler_t>::DebugObjCt = 0;
#endif

