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

#include "libcef_dll/cpptoc/client_cpptoc.h"
#include "libcef_dll/ctocpp/browser_ctocpp.h"
#include "libcef_dll/ctocpp/frame_ctocpp.h"
#include "libcef_dll/transfer_util.h"


// STATIC METHODS - Body may be edited by hand.

bool CefBrowser::CreateBrowser(CefWindowInfo& windowInfo,
    CefRefPtr<CefClient> client, const CefString& url,
    const CefBrowserSettings& settings)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: client; type: refptr_diff
  DCHECK(client.get());
  if (!client.get())
    return false;
  // Unverified params: url

  // Execute
  int _retval = cef_browser_create(
      &windowInfo,
      CefClientCppToC::Wrap(client),
      url.GetStruct(),
      &settings);

  // Return type: bool
  return _retval?true:false;
}

CefRefPtr<CefBrowser> CefBrowser::CreateBrowserSync(CefWindowInfo& windowInfo,
    CefRefPtr<CefClient> client, const CefString& url,
    const CefBrowserSettings& settings)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: client; type: refptr_diff
  DCHECK(client.get());
  if (!client.get())
    return NULL;
  // Unverified params: url

  // Execute
  cef_browser_t* _retval = cef_browser_create_sync(
      &windowInfo,
      CefClientCppToC::Wrap(client),
      url.GetStruct(),
      &settings);

  // Return type: refptr_same
  return CefBrowserCToCpp::Wrap(_retval);
}


// VIRTUAL METHODS - Body may be edited by hand.

void CefBrowserCToCpp::ParentWindowWillClose()
{
  if (CEF_MEMBER_MISSING(struct_, parent_window_will_close))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  struct_->parent_window_will_close(struct_);
}

void CefBrowserCToCpp::CloseBrowser()
{
  if (CEF_MEMBER_MISSING(struct_, close_browser))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  struct_->close_browser(struct_);
}

bool CefBrowserCToCpp::CanGoBack()
{
  if (CEF_MEMBER_MISSING(struct_, can_go_back))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->can_go_back(struct_);

  // Return type: bool
  return _retval?true:false;
}

void CefBrowserCToCpp::GoBack()
{
  if (CEF_MEMBER_MISSING(struct_, go_back))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  struct_->go_back(struct_);
}

bool CefBrowserCToCpp::CanGoForward()
{
  if (CEF_MEMBER_MISSING(struct_, can_go_forward))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->can_go_forward(struct_);

  // Return type: bool
  return _retval?true:false;
}

void CefBrowserCToCpp::GoForward()
{
  if (CEF_MEMBER_MISSING(struct_, go_forward))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  struct_->go_forward(struct_);
}

void CefBrowserCToCpp::Reload()
{
  if (CEF_MEMBER_MISSING(struct_, reload))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  struct_->reload(struct_);
}

void CefBrowserCToCpp::ReloadIgnoreCache()
{
  if (CEF_MEMBER_MISSING(struct_, reload_ignore_cache))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  struct_->reload_ignore_cache(struct_);
}

void CefBrowserCToCpp::StopLoad()
{
  if (CEF_MEMBER_MISSING(struct_, stop_load))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  struct_->stop_load(struct_);
}

void CefBrowserCToCpp::SetFocus(bool enable)
{
  if (CEF_MEMBER_MISSING(struct_, set_focus))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  struct_->set_focus(struct_,
      enable);
}

CefWindowHandle CefBrowserCToCpp::GetWindowHandle()
{
  if (CEF_MEMBER_MISSING(struct_, get_window_handle))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_window_handle_t _retval = struct_->get_window_handle(struct_);

  // Return type: simple
  return _retval;
}

CefWindowHandle CefBrowserCToCpp::GetOpenerWindowHandle()
{
  if (CEF_MEMBER_MISSING(struct_, get_opener_window_handle))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_window_handle_t _retval = struct_->get_opener_window_handle(struct_);

  // Return type: simple
  return _retval;
}

bool CefBrowserCToCpp::IsPopup()
{
  if (CEF_MEMBER_MISSING(struct_, is_popup))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->is_popup(struct_);

  // Return type: bool
  return _retval?true:false;
}

bool CefBrowserCToCpp::HasDocument()
{
  if (CEF_MEMBER_MISSING(struct_, has_document))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->has_document(struct_);

  // Return type: bool
  return _retval?true:false;
}

CefRefPtr<CefClient> CefBrowserCToCpp::GetClient()
{
  if (CEF_MEMBER_MISSING(struct_, get_client))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_client_t* _retval = struct_->get_client(struct_);

  // Return type: refptr_diff
  return CefClientCppToC::Unwrap(_retval);
}

CefRefPtr<CefFrame> CefBrowserCToCpp::GetMainFrame()
{
  if (CEF_MEMBER_MISSING(struct_, get_main_frame))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_frame_t* _retval = struct_->get_main_frame(struct_);

  // Return type: refptr_same
  return CefFrameCToCpp::Wrap(_retval);
}

CefRefPtr<CefFrame> CefBrowserCToCpp::GetFocusedFrame()
{
  if (CEF_MEMBER_MISSING(struct_, get_focused_frame))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_frame_t* _retval = struct_->get_focused_frame(struct_);

  // Return type: refptr_same
  return CefFrameCToCpp::Wrap(_retval);
}

CefRefPtr<CefFrame> CefBrowserCToCpp::GetFrame(const CefString& name)
{
  if (CEF_MEMBER_MISSING(struct_, get_frame))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: name; type: string_byref_const
  DCHECK(!name.empty());
  if (name.empty())
    return NULL;

  // Execute
  cef_frame_t* _retval = struct_->get_frame(struct_,
      name.GetStruct());

  // Return type: refptr_same
  return CefFrameCToCpp::Wrap(_retval);
}

void CefBrowserCToCpp::GetFrameNames(std::vector<CefString>& names)
{
  if (CEF_MEMBER_MISSING(struct_, get_frame_names))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Translate param: names; type: string_vec_byref
  cef_string_list_t namesList = cef_string_list_alloc();
  DCHECK(namesList);
  if (namesList)
    transfer_string_list_contents(names, namesList);

  // Execute
  struct_->get_frame_names(struct_,
      namesList);

  // Restore param:names; type: string_vec_byref
  if (namesList) {
    names.clear();
    transfer_string_list_contents(namesList, names);
    cef_string_list_free(namesList);
  }
}

void CefBrowserCToCpp::Find(int identifier, const CefString& searchText,
    bool forward, bool matchCase, bool findNext)
{
  if (CEF_MEMBER_MISSING(struct_, find))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: searchText; type: string_byref_const
  DCHECK(!searchText.empty());
  if (searchText.empty())
    return;

  // Execute
  struct_->find(struct_,
      identifier,
      searchText.GetStruct(),
      forward,
      matchCase,
      findNext);
}

void CefBrowserCToCpp::StopFinding(bool clearSelection)
{
  if (CEF_MEMBER_MISSING(struct_, stop_finding))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  struct_->stop_finding(struct_,
      clearSelection);
}

double CefBrowserCToCpp::GetZoomLevel()
{
  if (CEF_MEMBER_MISSING(struct_, get_zoom_level))
    return 0;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  double _retval = struct_->get_zoom_level(struct_);

  // Return type: simple
  return _retval;
}

void CefBrowserCToCpp::SetZoomLevel(double zoomLevel)
{
  if (CEF_MEMBER_MISSING(struct_, set_zoom_level))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  struct_->set_zoom_level(struct_,
      zoomLevel);
}

void CefBrowserCToCpp::ClearHistory()
{
  if (CEF_MEMBER_MISSING(struct_, clear_history))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  struct_->clear_history(struct_);
}

void CefBrowserCToCpp::ShowDevTools()
{
  if (CEF_MEMBER_MISSING(struct_, show_dev_tools))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  struct_->show_dev_tools(struct_);
}

void CefBrowserCToCpp::CloseDevTools()
{
  if (CEF_MEMBER_MISSING(struct_, close_dev_tools))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  struct_->close_dev_tools(struct_);
}

bool CefBrowserCToCpp::IsWindowRenderingDisabled()
{
  if (CEF_MEMBER_MISSING(struct_, is_window_rendering_disabled))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->is_window_rendering_disabled(struct_);

  // Return type: bool
  return _retval?true:false;
}

bool CefBrowserCToCpp::GetSize(PaintElementType type, int& width, int& height)
{
  if (CEF_MEMBER_MISSING(struct_, get_size))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->get_size(struct_,
      type,
      &width,
      &height);

  // Return type: bool
  return _retval?true:false;
}

void CefBrowserCToCpp::SetSize(PaintElementType type, int width, int height)
{
  if (CEF_MEMBER_MISSING(struct_, set_size))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  struct_->set_size(struct_,
      type,
      width,
      height);
}

bool CefBrowserCToCpp::IsPopupVisible()
{
  if (CEF_MEMBER_MISSING(struct_, is_popup_visible))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->is_popup_visible(struct_);

  // Return type: bool
  return _retval?true:false;
}

void CefBrowserCToCpp::HidePopup()
{
  if (CEF_MEMBER_MISSING(struct_, hide_popup))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  struct_->hide_popup(struct_);
}

void CefBrowserCToCpp::Invalidate(const CefRect& dirtyRect)
{
  if (CEF_MEMBER_MISSING(struct_, invalidate))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  struct_->invalidate(struct_,
      &dirtyRect);
}

bool CefBrowserCToCpp::GetImage(PaintElementType type, int width, int height,
    void* buffer)
{
  if (CEF_MEMBER_MISSING(struct_, get_image))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: buffer; type: simple_byaddr
  DCHECK(buffer);
  if (!buffer)
    return false;

  // Execute
  int _retval = struct_->get_image(struct_,
      type,
      width,
      height,
      buffer);

  // Return type: bool
  return _retval?true:false;
}

void CefBrowserCToCpp::SendKeyEvent(KeyType type, int key, int modifiers,
    bool sysChar, bool imeChar)
{
  if (CEF_MEMBER_MISSING(struct_, send_key_event))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  struct_->send_key_event(struct_,
      type,
      key,
      modifiers,
      sysChar,
      imeChar);
}

void CefBrowserCToCpp::SendMouseClickEvent(int x, int y, MouseButtonType type,
    bool mouseUp, int clickCount)
{
  if (CEF_MEMBER_MISSING(struct_, send_mouse_click_event))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  struct_->send_mouse_click_event(struct_,
      x,
      y,
      type,
      mouseUp,
      clickCount);
}

void CefBrowserCToCpp::SendMouseMoveEvent(int x, int y, bool mouseLeave)
{
  if (CEF_MEMBER_MISSING(struct_, send_mouse_move_event))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  struct_->send_mouse_move_event(struct_,
      x,
      y,
      mouseLeave);
}

void CefBrowserCToCpp::SendMouseWheelEvent(int x, int y, int delta)
{
  if (CEF_MEMBER_MISSING(struct_, send_mouse_wheel_event))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  struct_->send_mouse_wheel_event(struct_,
      x,
      y,
      delta);
}

void CefBrowserCToCpp::SendFocusEvent(bool setFocus)
{
  if (CEF_MEMBER_MISSING(struct_, send_focus_event))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  struct_->send_focus_event(struct_,
      setFocus);
}

void CefBrowserCToCpp::SendCaptureLostEvent()
{
  if (CEF_MEMBER_MISSING(struct_, send_capture_lost_event))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  struct_->send_capture_lost_event(struct_);
}


#ifndef NDEBUG
template<> long CefCToCpp<CefBrowserCToCpp, CefBrowser,
    cef_browser_t>::DebugObjCt = 0;
#endif

