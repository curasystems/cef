// Copyright (c) 2009 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#include "../precompiled_libcef.h"
#include "ctocpp/frame_ctocpp.h"
#include "ctocpp/request_ctocpp.h"
#include "ctocpp/stream_ctocpp.h"


void CefFrameCToCpp::Undo()
{
  if(CEF_MEMBER_MISSING(struct_, undo))
    return;
  
  struct_->undo(struct_);
}

void CefFrameCToCpp::Redo()
{
  if(CEF_MEMBER_MISSING(struct_, redo))
    return;
  
  struct_->redo(struct_);
}

void CefFrameCToCpp::Cut()
{
  if(CEF_MEMBER_MISSING(struct_, cut))
    return;
  
  struct_->cut(struct_);
}

void CefFrameCToCpp::Copy()
{
  if(CEF_MEMBER_MISSING(struct_, copy))
    return;
  
  struct_->copy(struct_);
}

void CefFrameCToCpp::Paste()
{
  if(CEF_MEMBER_MISSING(struct_, paste))
    return;
  
  struct_->paste(struct_);
}

void CefFrameCToCpp::Delete()
{
  if(CEF_MEMBER_MISSING(struct_, del))
    return;
  
  struct_->del(struct_);
}

void CefFrameCToCpp::SelectAll()
{
  if(CEF_MEMBER_MISSING(struct_, select_all))
    return;
  
  struct_->select_all(struct_);
}

void CefFrameCToCpp::Print()
{
  if(CEF_MEMBER_MISSING(struct_, print))
    return;
  
  struct_->print(struct_);
}

void CefFrameCToCpp::ViewSource()
{
  if(CEF_MEMBER_MISSING(struct_, view_source))
    return;
  
  struct_->view_source(struct_);
}

std::wstring CefFrameCToCpp::GetSource()
{
  std::wstring str;
  if(CEF_MEMBER_MISSING(struct_, get_source))
    return str;

  cef_string_t cef_str = struct_->get_source(struct_);
  if(cef_str) {
    str = cef_str;
    cef_string_free(cef_str);
  }
  return str;
}

std::wstring CefFrameCToCpp::GetText()
{
  std::wstring str;
  if(CEF_MEMBER_MISSING(struct_, get_text))
    return str;

  cef_string_t cef_str = struct_->get_text(struct_);
  if(cef_str) {
    str = cef_str;
    cef_string_free(cef_str);
  }
  return str;
}

void CefFrameCToCpp::LoadRequest(CefRefPtr<CefRequest> request)
{
  if(CEF_MEMBER_MISSING(struct_, load_request))
    return;

  struct_->load_request(struct_, CefRequestCToCpp::Unwrap(request));
}

void CefFrameCToCpp::LoadURL(const std::wstring& url)
{
  if(CEF_MEMBER_MISSING(struct_, load_url))
    return;

  struct_->load_url(struct_, url.c_str());
}

void CefFrameCToCpp::LoadString(const std::wstring& string,
                                const std::wstring& url)
{
  if(CEF_MEMBER_MISSING(struct_, load_string))
    return;
  
  struct_->load_string(struct_, string.c_str(), url.c_str());
}

void CefFrameCToCpp::LoadStream(CefRefPtr<CefStreamReader> stream,
                                const std::wstring& url)
{
  if(CEF_MEMBER_MISSING(struct_, load_stream))
    return;

  struct_->load_stream(struct_, CefStreamReaderCToCpp::Unwrap(stream),
      url.c_str());
}

void CefFrameCToCpp::ExecuteJavaScript(const std::wstring& js_code,
                                       const std::wstring& script_url,
                                       int start_line)
{
  if(CEF_MEMBER_MISSING(struct_, execute_javascript))
      return;

  struct_->execute_javascript(struct_, js_code.c_str(), script_url.c_str(),
      start_line);
}

bool CefFrameCToCpp::IsMain()
{
  if(CEF_MEMBER_MISSING(struct_, is_main))
      return false;

  return struct_->is_main(struct_);
}

bool CefFrameCToCpp::IsFocused()
{
  if(CEF_MEMBER_MISSING(struct_, is_focused))
      return false;

  return struct_->is_focused(struct_);
}

std::wstring CefFrameCToCpp::GetName()
{
  std::wstring str;
  if(CEF_MEMBER_MISSING(struct_, get_name))
    return str;

  cef_string_t cef_str = struct_->get_name(struct_);
  if(cef_str) {
    str = cef_str;
    cef_string_free(cef_str);
  }
  return str;
}

std::wstring CefFrameCToCpp::GetURL()
{
  std::wstring str;
  if(CEF_MEMBER_MISSING(struct_, get_url))
    return str;

  cef_string_t cef_str = struct_->get_url(struct_);
  if(cef_str) {
    str = cef_str;
    cef_string_free(cef_str);
  }
  return str;
}

#ifdef _DEBUG
long CefCToCpp<CefFrameCToCpp, CefFrame, cef_frame_t>::DebugObjCt = 0;
#endif
