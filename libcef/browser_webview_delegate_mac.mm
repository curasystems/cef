// Copyright (c) 2008 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "browser_webview_delegate.h"
#import "browser_webview_mac.h"
#include "browser_impl.h"
#include "drag_data_impl.h"
#import "include/cef_application_mac.h"

#import <Cocoa/Cocoa.h>

#include "base/file_util.h"
#include "base/mac/mac_util.h"
#include "base/sys_string_conversions.h"
#include "base/threading/thread_restrictions.h"
#include "skia/ext/skia_utils_mac.h"
#include "third_party/WebKit/Source/WebKit/chromium/public/WebContextMenuData.h"
#include "third_party/WebKit/Source/WebKit/chromium/public/WebCursorInfo.h"
#include "third_party/WebKit/Source/WebKit/chromium/public/platform/WebDragData.h"
#include "third_party/WebKit/Source/WebKit/chromium/public/platform/WebImage.h"
#include "third_party/WebKit/Source/WebKit/chromium/public/platform/WebPoint.h"
#include "third_party/WebKit/Source/WebKit/chromium/public/WebPopupMenu.h"
#include "third_party/WebKit/Source/WebKit/chromium/public/WebView.h"
#include "webkit/glue/webcursor.h"
#include "webkit/glue/webdropdata.h"
#include "webkit/plugins/npapi/plugin_list.h"
#include "webkit/plugins/npapi/webplugin_delegate_impl.h"
#include "webkit/glue/webmenurunner_mac.h"

using webkit::npapi::WebPluginDelegateImpl;
using WebKit::WebContextMenuData;
using WebKit::WebCursorInfo;
using WebKit::WebDragData;
using WebKit::WebDragOperationsMask;
using WebKit::WebExternalPopupMenu;
using WebKit::WebExternalPopupMenuClient;
using WebKit::WebImage;
using WebKit::WebNavigationPolicy;
using WebKit::WebPoint;
using WebKit::WebPopupMenuInfo;
using WebKit::WebRect;
using WebKit::WebWidget;


namespace {

void AddMenuItem(CefRefPtr<CefBrowser> browser,
                 CefRefPtr<CefMenuHandler> handler,
                 NSMenu* menu,
                 cef_menu_id_t menuId,
                 const std::string& label,
                 bool enabled) {
  std::string disp_str;
  if (handler.get()) {
    // Let the handler change the label if desired.
    CefString actual_label(label);
    handler->GetMenuLabel(browser, menuId, actual_label);
    disp_str = actual_label;
  } else {
    disp_str = label;
  }

  NSString* str = base::SysUTF8ToNSString(disp_str);
  NSMenuItem* item =
      [[[NSMenuItem alloc] initWithTitle:str
                                 action:enabled?@selector(menuItemSelected:):nil
                           keyEquivalent:@""] autorelease]; 
  [item setTag:menuId];
  [menu addItem:item];
}

void AddMenuSeparator(NSMenu* menu) {
  NSMenuItem* item = [NSMenuItem separatorItem]; 
  [menu addItem:item];
}

} // namespace


// WebViewClient --------------------------------------------------------------

WebExternalPopupMenu* BrowserWebViewDelegate::createExternalPopupMenu(
    const WebPopupMenuInfo& info,
    WebExternalPopupMenuClient* client) {
  DCHECK(!external_popup_menu_.get());
  external_popup_menu_.reset(new ExternalPopupMenu(this, info, client));
  return external_popup_menu_.get();
}

void BrowserWebViewDelegate::ClosePopupMenu() {
  if (external_popup_menu_ == NULL) {
    NOTREACHED();
    return;
  }
  external_popup_menu_.reset();
}

void BrowserWebViewDelegate::showContextMenu(
    WebKit::WebFrame* frame, const WebKit::WebContextMenuData& data) {
  WebWidgetHost* host = GetWidgetHost();
  if (!host)
    return;

  BrowserWebView *view = static_cast<BrowserWebView*>(host->view_handle());
  if (!view)
    return;

  NSWindow* window = [view window];
  NSPoint position = [window mouseLocationOutsideOfEventStream];

  int edit_flags = 0;
  int type_flags = 0;
  NSMenu* menu = nil;

  // Make sure events can be pumped while the menu is up.
  MessageLoop::ScopedNestableTaskAllower allow(MessageLoop::current());

  // Give the client a chance to handle the menu.
  if (OnBeforeMenu(data, position.x, position.y, edit_flags, type_flags))
    return;

  CefRefPtr<CefClient> client = browser_->GetClient();
  CefRefPtr<CefMenuHandler> handler;
  if (client.get())
    handler = client->GetMenuHandler();

  // Build the correct default context menu
  if (type_flags &  MENUTYPE_EDITABLE) {
    menu = [[[NSMenu alloc] initWithTitle:@""] autorelease];

    AddMenuItem(browser_, handler, menu, MENU_ID_UNDO, "Undo",
                !!(edit_flags & MENU_CAN_UNDO));
    AddMenuItem(browser_, handler, menu, MENU_ID_REDO, "Redo",
                !!(edit_flags & MENU_CAN_REDO));
    AddMenuSeparator(menu);
    AddMenuItem(browser_, handler, menu, MENU_ID_CUT, "Cut",
                !!(edit_flags & MENU_CAN_CUT));
    AddMenuItem(browser_, handler, menu, MENU_ID_COPY, "Copy",
                !!(edit_flags & MENU_CAN_COPY));
    AddMenuItem(browser_, handler, menu, MENU_ID_PASTE, "Paste",
                !!(edit_flags & MENU_CAN_PASTE));
    AddMenuItem(browser_, handler, menu, MENU_ID_DELETE, "Delete",
                !!(edit_flags & MENU_CAN_DELETE));
    AddMenuSeparator(menu);
    AddMenuItem(browser_, handler, menu, MENU_ID_SELECTALL, "Select All",
                !!(edit_flags & MENU_CAN_SELECT_ALL));
  } else if(type_flags & MENUTYPE_SELECTION) {
    menu = [[[NSMenu alloc] initWithTitle:@""] autorelease];

    AddMenuItem(browser_, handler, menu, MENU_ID_COPY, "Copy",
                !!(edit_flags & MENU_CAN_COPY));
  } else if(type_flags & (MENUTYPE_PAGE | MENUTYPE_FRAME)) {
    menu = [[[NSMenu alloc] initWithTitle:@""] autorelease];

    AddMenuItem(browser_, handler, menu, MENU_ID_NAV_BACK, "Back",
                !!(edit_flags & MENU_CAN_GO_BACK));
    AddMenuItem(browser_, handler, menu, MENU_ID_NAV_FORWARD, "Forward",
                !!(edit_flags & MENU_CAN_GO_FORWARD));
    // TODO(port): Enable the below menu items when supported.
    //AddMenuSeparator(menu);
    //AddMenuItem(browser_, handler, menu, MENU_ID_PRINT, "Print", true);
    //AddMenuItem(browser_, handler, menu, MENU_ID_VIEWSOURCE, "View Source",
    //            true);
  }

  if (!menu)
    return;

  // Synthesize an event for the click, as there is no certainty that
  // [NSApp currentEvent] will return a valid event.
  NSEvent* currentEvent = [NSApp currentEvent];
  NSTimeInterval eventTime = [currentEvent timestamp];
  NSEvent* clickEvent = [NSEvent mouseEventWithType:NSRightMouseDown
                                          location:position
                                     modifierFlags:NSRightMouseDownMask
                                         timestamp:eventTime
                                      windowNumber:[window windowNumber]
                                           context:nil
                                       eventNumber:0
                                        clickCount:1
                                          pressure:1.0];
    

  // Menu selection events go to the BrowserWebView.
  [menu setDelegate:view];

  // Show the menu.
  [NSMenu popUpContextMenu:menu
                 withEvent:clickEvent
                   forView:view];
}

// WebWidgetClient ------------------------------------------------------------

void BrowserWebViewDelegate::show(WebNavigationPolicy policy) {
}

void BrowserWebViewDelegate::didChangeCursor(const WebCursorInfo& cursor_info) {
  NSCursor* ns_cursor = WebCursor(cursor_info).GetCursor();
  [ns_cursor set];
}

WebRect BrowserWebViewDelegate::windowRect() {
  if (WebWidgetHost* host = GetWidgetHost()) {
    NSView *view = host->view_handle();
    NSRect rect = [view frame];
    return gfx::Rect(NSRectToCGRect(rect));
  }
  return WebRect();
}

void BrowserWebViewDelegate::setWindowRect(const WebRect& rect) {
  if (this == browser_->UIT_GetWebViewDelegate()) {
    // TODO(port): Set the window rectangle.
  }
}

WebRect BrowserWebViewDelegate::rootWindowRect() {
  if (WebWidgetHost* host = GetWidgetHost()) {
    NSView *view = host->view_handle();
    NSRect rect = [[[view window] contentView] frame];
    return gfx::Rect(NSRectToCGRect(rect));
  }
  return WebRect();
}

@interface NSWindow(OSInternals)
- (NSRect)_growBoxRect;
@end

WebRect BrowserWebViewDelegate::windowResizerRect() {
  NSRect resize_rect = NSMakeRect(0, 0, 0, 0);
  WebWidgetHost* host = GetWidgetHost();
  if (host) {
    NSView *view = host->view_handle();
    NSWindow* window = [view window];
    if (window == nil)
      return gfx::Rect();

    resize_rect = [window _growBoxRect];
    // The scrollbar assumes that the resizer goes all the way down to the
    // bottom corner, so we ignore any y offset to the rect itself and use the
    // entire bottom corner.
    resize_rect.origin.y = 0;
    // Convert to view coordinates from window coordinates.
    resize_rect = [view convertRect:resize_rect fromView:nil];
    // Flip the rect in view coordinates
    resize_rect.origin.y =
        [view frame].size.height - resize_rect.origin.y -
        resize_rect.size.height;
  }
  return gfx::Rect(NSRectToCGRect(resize_rect));
}

void BrowserWebViewDelegate::startDragging(const WebDragData& data,
                                           WebDragOperationsMask mask,
                                           const WebImage& image,
                                           const WebPoint& image_offset) {
  if (browser_->settings().drag_drop_disabled) {
    browser_->UIT_GetWebView()->dragSourceSystemDragEnded();
    return;
  }

  WebWidgetHost* host = GetWidgetHost();
  if (!host)
    return;
  
  BrowserWebView *view = static_cast<BrowserWebView*>(host->view_handle());
  if (!view)
    return;
  
  WebDropData drop_data(data);

  CefRefPtr<CefClient> client = browser_->GetClient();
  if (client.get()) {
    CefRefPtr<CefDragHandler> handler = client->GetDragHandler();
    if (handler.get()) {
      CefRefPtr<CefDragData> data(new CefDragDataImpl(drop_data));
      if (handler->OnDragStart(browser_, data,
              static_cast<CefDragHandler::DragOperationsMask>(mask))) {
        browser_->UIT_GetWebView()->dragSourceSystemDragEnded();
        return;
      }
    }
  }

  // By allowing nested tasks, the code below also allows Close(),
  // which would deallocate |this|.  The same problem can occur while
  // processing -sendEvent:, so Close() is deferred in that case.
  // Drags from web content do not come via -sendEvent:, this sets the
  // same flag -sendEvent: would.
  CefScopedSendingEvent sendingEventScoper;
  
  // The drag invokes a nested event loop, arrange to continue
  // processing events.
  MessageLoop::ScopedNestableTaskAllower allow(MessageLoop::current());
  
  NSImage* ns_image = nil;
  if (!image.isNull()) {
    const SkBitmap& bitmap = image.getSkBitmap();
    CGColorSpaceRef color_space = base::mac::GetSystemColorSpace();
    ns_image = gfx::SkBitmapToNSImageWithColorSpace(bitmap, color_space);
  }
  NSPoint offset = NSPointFromCGPoint(gfx::Point(image_offset).ToCGPoint());
  [view startDragWithDropData:drop_data
            dragOperationMask:static_cast<NSDragOperation>(mask)
                        image:ns_image
                       offset:offset];
}

void BrowserWebViewDelegate::runModal() {
  NOTIMPLEMENTED();
}

// WebPluginPageDelegate ------------------------------------------------------

webkit::npapi::WebPluginDelegate* BrowserWebViewDelegate::CreatePluginDelegate(
    const FilePath& path,
    const std::string& mime_type) {
  WebWidgetHost *host = GetWidgetHost();
  if (!host)
    return NULL;

  gfx::PluginWindowHandle containing_view = NULL;
  WebPluginDelegateImpl* delegate = WebPluginDelegateImpl::Create(
      path, mime_type, containing_view);
  if (delegate)
    delegate->SetNoBufferContext();
  return delegate;
}

void BrowserWebViewDelegate::CreatedPluginWindow(
    gfx::PluginWindowHandle handle) {
}

void BrowserWebViewDelegate::WillDestroyPluginWindow(
    gfx::PluginWindowHandle handle) {
}

void BrowserWebViewDelegate::DidMovePlugin(
    const webkit::npapi::WebPluginGeometry& move) {
  // TODO(port): add me once plugins work.
}

// Protected methods ----------------------------------------------------------

void BrowserWebViewDelegate::ShowJavaScriptAlert(
    WebKit::WebFrame* webframe, const CefString& message) {
  std::string messageStr(message);
  NSString *text = [NSString stringWithUTF8String:messageStr.c_str()];
  NSAlert *alert = [NSAlert alertWithMessageText:@"JavaScript Alert"
                                   defaultButton:@"OK"
                                 alternateButton:nil
                                     otherButton:nil
                       informativeTextWithFormat:text];
  [alert runModal];
}

bool BrowserWebViewDelegate::ShowJavaScriptConfirm(
    WebKit::WebFrame* webframe, const CefString& message) {
  NOTIMPLEMENTED();
  return false;
}

bool BrowserWebViewDelegate::ShowJavaScriptPrompt(
    WebKit::WebFrame* webframe, const CefString& message,
    const CefString& default_value, CefString* result) {
  NOTIMPLEMENTED();
  return false;
}

// Called to show the file chooser dialog.
bool BrowserWebViewDelegate::ShowFileChooser(std::vector<FilePath>& file_names,
                                             const bool multi_select,
                                             const WebKit::WebString& title,
                                             const FilePath& default_file) {
  NSOpenPanel* dialog = [NSOpenPanel openPanel];
  if (!title.isNull())
    [dialog setTitle:base::SysUTF16ToNSString(title)];

  NSString* default_dir = nil;
  NSString* default_filename = nil;
  if (!default_file.empty()) {
    // The file dialog is going to do a ton of stats anyway. Not much
    // point in eliminating this one.
    base::ThreadRestrictions::ScopedAllowIO allow_io;
    if (file_util::DirectoryExists(default_file)) {
      default_dir = base::SysUTF8ToNSString(default_file.value());
    } else {
      default_dir = base::SysUTF8ToNSString(default_file.DirName().value());
      default_filename =
          base::SysUTF8ToNSString(default_file.BaseName().value());
    }
  }

  [dialog setAllowsOtherFileTypes:YES];
  [dialog setAllowsMultipleSelection:multi_select];
  [dialog setCanChooseFiles:YES];
  [dialog setCanChooseDirectories:NO];

  NSInteger result = [dialog runModalForDirectory:default_dir
                                             file:default_filename];
  if (result == NSFileHandlingPanelCancelButton)
    return false;

  NSArray *urls = [dialog URLs];
  int i, count = [urls count];
  for (i=0; i<count; i++) {
    NSURL* url = [urls objectAtIndex:i];
    if ([url isFileURL])
      file_names.push_back(FilePath(base::SysNSStringToUTF8([url path])));
  }

  return true;
}
