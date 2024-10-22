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

#include "libcef_dll/cpptoc/browser_cpptoc.h"
#include "libcef_dll/cpptoc/frame_cpptoc.h"
#include "libcef_dll/ctocpp/client_ctocpp.h"
#include "libcef_dll/transfer_util.h"


// GLOBAL FUNCTIONS - Body may be edited by hand.

CEF_EXPORT int cef_browser_create(cef_window_info_t* windowInfo,
    struct _cef_client_t* client, const cef_string_t* url,
    const struct _cef_browser_settings_t* settings)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: windowInfo; type: struct_byref
  DCHECK(windowInfo);
  if (!windowInfo)
    return 0;
  // Verify param: client; type: refptr_diff
  DCHECK(client);
  if (!client)
    return 0;
  // Verify param: settings; type: struct_byref_const
  DCHECK(settings);
  if (!settings)
    return 0;
  // Unverified params: url

  // Translate param: windowInfo; type: struct_byref
  CefWindowInfo windowInfoObj;
  if (windowInfo)
    windowInfoObj.AttachTo(*windowInfo);
  // Translate param: settings; type: struct_byref_const
  CefBrowserSettings settingsObj;
  if (settings)
    settingsObj.Set(*settings, false);

  // Execute
  bool _retval = CefBrowser::CreateBrowser(
      windowInfoObj,
      CefClientCToCpp::Wrap(client),
      CefString(url),
      settingsObj);

  // Restore param: windowInfo; type: struct_byref
  if (windowInfo)
    windowInfoObj.DetachTo(*windowInfo);

  // Return type: bool
  return _retval;
}

CEF_EXPORT cef_browser_t* cef_browser_create_sync(cef_window_info_t* windowInfo,
    struct _cef_client_t* client, const cef_string_t* url,
    const struct _cef_browser_settings_t* settings)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: windowInfo; type: struct_byref
  DCHECK(windowInfo);
  if (!windowInfo)
    return NULL;
  // Verify param: client; type: refptr_diff
  DCHECK(client);
  if (!client)
    return NULL;
  // Verify param: settings; type: struct_byref_const
  DCHECK(settings);
  if (!settings)
    return NULL;
  // Unverified params: url

  // Translate param: windowInfo; type: struct_byref
  CefWindowInfo windowInfoObj;
  if (windowInfo)
    windowInfoObj.AttachTo(*windowInfo);
  // Translate param: settings; type: struct_byref_const
  CefBrowserSettings settingsObj;
  if (settings)
    settingsObj.Set(*settings, false);

  // Execute
  CefRefPtr<CefBrowser> _retval = CefBrowser::CreateBrowserSync(
      windowInfoObj,
      CefClientCToCpp::Wrap(client),
      CefString(url),
      settingsObj);

  // Restore param: windowInfo; type: struct_byref
  if (windowInfo)
    windowInfoObj.DetachTo(*windowInfo);

  // Return type: refptr_same
  return CefBrowserCppToC::Wrap(_retval);
}


// MEMBER FUNCTIONS - Body may be edited by hand.

void CEF_CALLBACK browser_parent_window_will_close(struct _cef_browser_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserCppToC::Get(self)->ParentWindowWillClose();
}

void CEF_CALLBACK browser_close_browser(struct _cef_browser_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserCppToC::Get(self)->CloseBrowser();
}

int CEF_CALLBACK browser_can_go_back(struct _cef_browser_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefBrowserCppToC::Get(self)->CanGoBack();

  // Return type: bool
  return _retval;
}

void CEF_CALLBACK browser_go_back(struct _cef_browser_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserCppToC::Get(self)->GoBack();
}

int CEF_CALLBACK browser_can_go_forward(struct _cef_browser_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefBrowserCppToC::Get(self)->CanGoForward();

  // Return type: bool
  return _retval;
}

void CEF_CALLBACK browser_go_forward(struct _cef_browser_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserCppToC::Get(self)->GoForward();
}

void CEF_CALLBACK browser_reload(struct _cef_browser_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserCppToC::Get(self)->Reload();
}

void CEF_CALLBACK browser_reload_ignore_cache(struct _cef_browser_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserCppToC::Get(self)->ReloadIgnoreCache();
}

void CEF_CALLBACK browser_stop_load(struct _cef_browser_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserCppToC::Get(self)->StopLoad();
}

void CEF_CALLBACK browser_set_focus(struct _cef_browser_t* self, int enable)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserCppToC::Get(self)->SetFocus(
      enable?true:false);
}

cef_window_handle_t CEF_CALLBACK browser_get_window_handle(
    struct _cef_browser_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  cef_window_handle_t _retval = CefBrowserCppToC::Get(self)->GetWindowHandle();

  // Return type: simple
  return _retval;
}

cef_window_handle_t CEF_CALLBACK browser_get_opener_window_handle(
    struct _cef_browser_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  cef_window_handle_t _retval = CefBrowserCppToC::Get(
      self)->GetOpenerWindowHandle();

  // Return type: simple
  return _retval;
}

int CEF_CALLBACK browser_is_popup(struct _cef_browser_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefBrowserCppToC::Get(self)->IsPopup();

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK browser_has_document(struct _cef_browser_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefBrowserCppToC::Get(self)->HasDocument();

  // Return type: bool
  return _retval;
}

struct _cef_client_t* CEF_CALLBACK browser_get_client(
    struct _cef_browser_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefClient> _retval = CefBrowserCppToC::Get(self)->GetClient();

  // Return type: refptr_diff
  return CefClientCToCpp::Unwrap(_retval);
}

struct _cef_frame_t* CEF_CALLBACK browser_get_main_frame(
    struct _cef_browser_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefFrame> _retval = CefBrowserCppToC::Get(self)->GetMainFrame();

  // Return type: refptr_same
  return CefFrameCppToC::Wrap(_retval);
}

struct _cef_frame_t* CEF_CALLBACK browser_get_focused_frame(
    struct _cef_browser_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefFrame> _retval = CefBrowserCppToC::Get(self)->GetFocusedFrame();

  // Return type: refptr_same
  return CefFrameCppToC::Wrap(_retval);
}

struct _cef_frame_t* CEF_CALLBACK browser_get_frame(struct _cef_browser_t* self,
    const cef_string_t* name)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;
  // Verify param: name; type: string_byref_const
  DCHECK(name);
  if (!name)
    return NULL;

  // Execute
  CefRefPtr<CefFrame> _retval = CefBrowserCppToC::Get(self)->GetFrame(
      CefString(name));

  // Return type: refptr_same
  return CefFrameCppToC::Wrap(_retval);
}

void CEF_CALLBACK browser_get_frame_names(struct _cef_browser_t* self,
    cef_string_list_t names)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: names; type: string_vec_byref
  DCHECK(names);
  if (!names)
    return;

  // Translate param: names; type: string_vec_byref
  std::vector<CefString> namesList;
  transfer_string_list_contents(names, namesList);

  // Execute
  CefBrowserCppToC::Get(self)->GetFrameNames(
      namesList);

  // Restore param: names; type: string_vec_byref
  cef_string_list_clear(names);
  transfer_string_list_contents(namesList, names);
}

void CEF_CALLBACK browser_find(struct _cef_browser_t* self, int identifier,
    const cef_string_t* searchText, int forward, int matchCase, int findNext)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: searchText; type: string_byref_const
  DCHECK(searchText);
  if (!searchText)
    return;

  // Execute
  CefBrowserCppToC::Get(self)->Find(
      identifier,
      CefString(searchText),
      forward?true:false,
      matchCase?true:false,
      findNext?true:false);
}

void CEF_CALLBACK browser_stop_finding(struct _cef_browser_t* self,
    int clearSelection)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserCppToC::Get(self)->StopFinding(
      clearSelection?true:false);
}

double CEF_CALLBACK browser_get_zoom_level(struct _cef_browser_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  double _retval = CefBrowserCppToC::Get(self)->GetZoomLevel();

  // Return type: simple
  return _retval;
}

void CEF_CALLBACK browser_set_zoom_level(struct _cef_browser_t* self,
    double zoomLevel)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserCppToC::Get(self)->SetZoomLevel(
      zoomLevel);
}

void CEF_CALLBACK browser_clear_history(struct _cef_browser_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserCppToC::Get(self)->ClearHistory();
}

void CEF_CALLBACK browser_show_dev_tools(struct _cef_browser_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserCppToC::Get(self)->ShowDevTools();
}

void CEF_CALLBACK browser_close_dev_tools(struct _cef_browser_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserCppToC::Get(self)->CloseDevTools();
}

int CEF_CALLBACK browser_is_window_rendering_disabled(
    struct _cef_browser_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefBrowserCppToC::Get(self)->IsWindowRenderingDisabled();

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK browser_get_size(struct _cef_browser_t* self,
    enum cef_paint_element_type_t type, int* width, int* height)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: width; type: simple_byref
  DCHECK(width);
  if (!width)
    return 0;
  // Verify param: height; type: simple_byref
  DCHECK(height);
  if (!height)
    return 0;

  // Translate param: width; type: simple_byref
  int widthVal = width?*width:0;
  // Translate param: height; type: simple_byref
  int heightVal = height?*height:0;

  // Execute
  bool _retval = CefBrowserCppToC::Get(self)->GetSize(
      type,
      widthVal,
      heightVal);

  // Restore param: width; type: simple_byref
  if (width)
    *width = widthVal;
  // Restore param: height; type: simple_byref
  if (height)
    *height = heightVal;

  // Return type: bool
  return _retval;
}

void CEF_CALLBACK browser_set_size(struct _cef_browser_t* self,
    enum cef_paint_element_type_t type, int width, int height)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserCppToC::Get(self)->SetSize(
      type,
      width,
      height);
}

int CEF_CALLBACK browser_is_popup_visible(struct _cef_browser_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefBrowserCppToC::Get(self)->IsPopupVisible();

  // Return type: bool
  return _retval;
}

void CEF_CALLBACK browser_hide_popup(struct _cef_browser_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserCppToC::Get(self)->HidePopup();
}

void CEF_CALLBACK browser_invalidate(struct _cef_browser_t* self,
    const cef_rect_t* dirtyRect)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: dirtyRect; type: simple_byref_const
  DCHECK(dirtyRect);
  if (!dirtyRect)
    return;

  // Translate param: dirtyRect; type: simple_byref_const
  CefRect dirtyRectVal = dirtyRect?*dirtyRect:CefRect();

  // Execute
  CefBrowserCppToC::Get(self)->Invalidate(
      dirtyRectVal);
}

int CEF_CALLBACK browser_get_image(struct _cef_browser_t* self,
    enum cef_paint_element_type_t type, int width, int height, void* buffer)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: buffer; type: simple_byaddr
  DCHECK(buffer);
  if (!buffer)
    return 0;

  // Execute
  bool _retval = CefBrowserCppToC::Get(self)->GetImage(
      type,
      width,
      height,
      buffer);

  // Return type: bool
  return _retval;
}

void CEF_CALLBACK browser_send_key_event(struct _cef_browser_t* self,
    enum cef_key_type_t type, int key, int modifiers, int sysChar,
    int imeChar)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserCppToC::Get(self)->SendKeyEvent(
      type,
      key,
      modifiers,
      sysChar?true:false,
      imeChar?true:false);
}

void CEF_CALLBACK browser_send_mouse_click_event(struct _cef_browser_t* self,
    int x, int y, enum cef_mouse_button_type_t type, int mouseUp,
    int clickCount)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserCppToC::Get(self)->SendMouseClickEvent(
      x,
      y,
      type,
      mouseUp?true:false,
      clickCount);
}

void CEF_CALLBACK browser_send_mouse_move_event(struct _cef_browser_t* self,
    int x, int y, int mouseLeave)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserCppToC::Get(self)->SendMouseMoveEvent(
      x,
      y,
      mouseLeave?true:false);
}

void CEF_CALLBACK browser_send_mouse_wheel_event(struct _cef_browser_t* self,
    int x, int y, int delta)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserCppToC::Get(self)->SendMouseWheelEvent(
      x,
      y,
      delta);
}

void CEF_CALLBACK browser_send_focus_event(struct _cef_browser_t* self,
    int setFocus)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserCppToC::Get(self)->SendFocusEvent(
      setFocus?true:false);
}

void CEF_CALLBACK browser_send_capture_lost_event(struct _cef_browser_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserCppToC::Get(self)->SendCaptureLostEvent();
}


// CONSTRUCTOR - Do not edit by hand.

CefBrowserCppToC::CefBrowserCppToC(CefBrowser* cls)
    : CefCppToC<CefBrowserCppToC, CefBrowser, cef_browser_t>(cls)
{
  struct_.struct_.parent_window_will_close = browser_parent_window_will_close;
  struct_.struct_.close_browser = browser_close_browser;
  struct_.struct_.can_go_back = browser_can_go_back;
  struct_.struct_.go_back = browser_go_back;
  struct_.struct_.can_go_forward = browser_can_go_forward;
  struct_.struct_.go_forward = browser_go_forward;
  struct_.struct_.reload = browser_reload;
  struct_.struct_.reload_ignore_cache = browser_reload_ignore_cache;
  struct_.struct_.stop_load = browser_stop_load;
  struct_.struct_.set_focus = browser_set_focus;
  struct_.struct_.get_window_handle = browser_get_window_handle;
  struct_.struct_.get_opener_window_handle = browser_get_opener_window_handle;
  struct_.struct_.is_popup = browser_is_popup;
  struct_.struct_.has_document = browser_has_document;
  struct_.struct_.get_client = browser_get_client;
  struct_.struct_.get_main_frame = browser_get_main_frame;
  struct_.struct_.get_focused_frame = browser_get_focused_frame;
  struct_.struct_.get_frame = browser_get_frame;
  struct_.struct_.get_frame_names = browser_get_frame_names;
  struct_.struct_.find = browser_find;
  struct_.struct_.stop_finding = browser_stop_finding;
  struct_.struct_.get_zoom_level = browser_get_zoom_level;
  struct_.struct_.set_zoom_level = browser_set_zoom_level;
  struct_.struct_.clear_history = browser_clear_history;
  struct_.struct_.show_dev_tools = browser_show_dev_tools;
  struct_.struct_.close_dev_tools = browser_close_dev_tools;
  struct_.struct_.is_window_rendering_disabled =
      browser_is_window_rendering_disabled;
  struct_.struct_.get_size = browser_get_size;
  struct_.struct_.set_size = browser_set_size;
  struct_.struct_.is_popup_visible = browser_is_popup_visible;
  struct_.struct_.hide_popup = browser_hide_popup;
  struct_.struct_.invalidate = browser_invalidate;
  struct_.struct_.get_image = browser_get_image;
  struct_.struct_.send_key_event = browser_send_key_event;
  struct_.struct_.send_mouse_click_event = browser_send_mouse_click_event;
  struct_.struct_.send_mouse_move_event = browser_send_mouse_move_event;
  struct_.struct_.send_mouse_wheel_event = browser_send_mouse_wheel_event;
  struct_.struct_.send_focus_event = browser_send_focus_event;
  struct_.struct_.send_capture_lost_event = browser_send_capture_lost_event;
}

#ifndef NDEBUG
template<> long CefCppToC<CefBrowserCppToC, CefBrowser,
    cef_browser_t>::DebugObjCt = 0;
#endif

