// Copyright (c) 2010 The Chromium Embedded Framework Authors. All rights
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

#include "libcef_dll/cpptoc/handler_cpptoc.h"
#include "libcef_dll/ctocpp/browser_ctocpp.h"
#include "libcef_dll/ctocpp/frame_ctocpp.h"
#include "libcef_dll/transfer_util.h"


// STATIC METHODS - Body may be edited by hand.

bool CefBrowser::CreateBrowser(CefWindowInfo& windowInfo, bool popup,
    CefRefPtr<CefHandler> handler, const CefString& url)
{
  return cef_browser_create(&windowInfo, popup, CefHandlerCppToC::Wrap(handler),
      url.GetStruct())?true:false;
}

CefRefPtr<CefBrowser> CefBrowser::CreateBrowserSync(CefWindowInfo& windowInfo,
    bool popup, CefRefPtr<CefHandler> handler, const CefString& url)
{
  cef_browser_t* impl = cef_browser_create_sync(&windowInfo, popup,
      CefHandlerCppToC::Wrap(handler), url.GetStruct());
  if(impl)
    return CefBrowserCToCpp::Wrap(impl);
  return NULL;
}


// VIRTUAL METHODS - Body may be edited by hand.

bool CefBrowserCToCpp::CanGoBack()
{
  if(CEF_MEMBER_MISSING(struct_, can_go_back))
    return false;

  return struct_->can_go_back(struct_) ? true : false;
}

void CefBrowserCToCpp::GoBack()
{
  if(CEF_MEMBER_MISSING(struct_, go_back))
    return;

  struct_->go_back(struct_);
}

bool CefBrowserCToCpp::CanGoForward()
{
  if(CEF_MEMBER_MISSING(struct_, can_go_forward))
    return false;
  
  return struct_->can_go_forward(struct_)?true:false;
}

void CefBrowserCToCpp::GoForward()
{
  if(CEF_MEMBER_MISSING(struct_, go_forward))
    return;

  struct_->go_forward(struct_);
}

void CefBrowserCToCpp::Reload()
{
  if(CEF_MEMBER_MISSING(struct_, reload))
    return;

  struct_->reload(struct_);
}

void CefBrowserCToCpp::ReloadIgnoreCache()
{
  if(CEF_MEMBER_MISSING(struct_, reload))
    return;

  struct_->reload_ignore_cache(struct_);
}

void CefBrowserCToCpp::StopLoad()
{
  if(CEF_MEMBER_MISSING(struct_, stop_load))
    return;
  
  struct_->stop_load(struct_);
}

void CefBrowserCToCpp::SetFocus(bool enable)
{
  if(CEF_MEMBER_MISSING(struct_, set_focus))
    return;
  
  struct_->set_focus(struct_, enable);
}

CefWindowHandle CefBrowserCToCpp::GetWindowHandle()
{
  if(CEF_MEMBER_MISSING(struct_, get_window_handle))
      return 0;
  
  return struct_->get_window_handle(struct_);
}

bool CefBrowserCToCpp::IsPopup()
{
  if(CEF_MEMBER_MISSING(struct_, is_popup))
    return false;
  
  return struct_->is_popup(struct_)?true:false;
}

CefRefPtr<CefHandler> CefBrowserCToCpp::GetHandler()
{
  if(CEF_MEMBER_MISSING(struct_, get_handler))
    return NULL;

  cef_handler_t* handlerStruct = struct_->get_handler(struct_);
  if(handlerStruct)
    return CefHandlerCppToC::Unwrap(handlerStruct);

  return NULL;
}

CefRefPtr<CefFrame> CefBrowserCToCpp::GetMainFrame()
{
  if(CEF_MEMBER_MISSING(struct_, get_main_frame))
    return NULL;

  cef_frame_t* frameStruct = struct_->get_main_frame(struct_);
  if(frameStruct)
    return CefFrameCToCpp::Wrap(frameStruct);

  return NULL;
}

CefRefPtr<CefFrame> CefBrowserCToCpp::GetFocusedFrame()
{
   if(CEF_MEMBER_MISSING(struct_, get_main_frame))
    return NULL;

  cef_frame_t* frameStruct = struct_->get_focused_frame(struct_);
  if(frameStruct)
    return CefFrameCToCpp::Wrap(frameStruct);

  return NULL;
}

CefRefPtr<CefFrame> CefBrowserCToCpp::GetFrame(const CefString& name)
{
  if(CEF_MEMBER_MISSING(struct_, get_main_frame))
    return NULL;

  cef_frame_t* frameStruct = struct_->get_frame(struct_, name.GetStruct());
  if(frameStruct)
    return CefFrameCToCpp::Wrap(frameStruct);

  return NULL;
}

void CefBrowserCToCpp::GetFrameNames(std::vector<CefString>& names)
{
  if(CEF_MEMBER_MISSING(struct_, get_frame_names))
    return;

  cef_string_list_t list = cef_string_list_alloc();
  struct_->get_frame_names(struct_, list);

  transfer_string_list_contents(list, names);
  cef_string_list_free(list);
}

void CefBrowserCToCpp::Find(int identifier, const CefString& searchText,
    bool forward, bool matchCase, bool findNext)
{
  if(CEF_MEMBER_MISSING(struct_, find))
    return;

  struct_->find(struct_, identifier, searchText.GetStruct(), forward,
      matchCase, findNext);
}

void CefBrowserCToCpp::StopFinding(bool clearSelection)
{
  if(CEF_MEMBER_MISSING(struct_, stop_finding))
    return;

  struct_->stop_finding(struct_, clearSelection);
}


#ifdef _DEBUG
template<> long CefCToCpp<CefBrowserCToCpp, CefBrowser,
    cef_browser_t>::DebugObjCt = 0;
#endif

