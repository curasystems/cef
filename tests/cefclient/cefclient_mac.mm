// Copyright (c) 2010 The Chromium Embedded Framework Authors.
// Portions copyright (c) 2010 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "cefclient.h"
#include "include/cef_app.h"
#import "include/cef_application_mac.h"
#include "include/cef_browser.h"
#include "include/cef_frame.h"
#include "include/cef_runnable.h"
#include "binding_test.h"
#include "client_handler.h"
#include "extension_test.h"
#include "resource_util.h"
#include "scheme_test.h"
#include "string_util.h"
#import <Cocoa/Cocoa.h>
#include <sstream>

// The global ClientHandler reference.
extern CefRefPtr<ClientHandler> g_handler;

char szWorkingDir[512];   // The current working directory

// Sizes for URL bar layout
#define BUTTON_HEIGHT 22
#define BUTTON_WIDTH 72
#define BUTTON_MARGIN 8
#define URLBAR_HEIGHT  32

// Content area size for newly created windows.
const int kWindowWidth = 800;
const int kWindowHeight = 600;

// Memory AutoRelease pool.
static NSAutoreleasePool* g_autopool = nil;

// Provide the CefAppProtocol implementation required by CEF.
@interface ClientApplication : NSApplication<CefAppProtocol> {
@private
  BOOL handlingSendEvent_;
}
@end

@implementation ClientApplication
- (BOOL)isHandlingSendEvent {
  return handlingSendEvent_;
}

- (void)setHandlingSendEvent:(BOOL)handlingSendEvent {
  handlingSendEvent_ = handlingSendEvent;
}

- (void)sendEvent:(NSEvent*)event {
  CefScopedSendingEvent sendingEventScoper;
  [super sendEvent:event];
}
@end


// Receives notifications from controls and the browser window. Will delete
// itself when done.
@interface ClientWindowDelegate : NSObject <NSWindowDelegate>
- (IBAction)goBack:(id)sender;
- (IBAction)goForward:(id)sender;
- (IBAction)reload:(id)sender;
- (IBAction)stopLoading:(id)sender;
- (IBAction)takeURLStringValueFrom:(NSTextField *)sender;
- (void)alert:(NSString*)title withMessage:(NSString*)message;
- (void)notifyConsoleMessage:(id)object;
- (void)notifyDownloadComplete:(id)object;
- (void)notifyDownloadError:(id)object;
@end

@implementation ClientWindowDelegate

- (IBAction)goBack:(id)sender {
  if (g_handler.get() && g_handler->GetBrowserHwnd())
    g_handler->GetBrowser()->GoBack();
}

- (IBAction)goForward:(id)sender {
  if (g_handler.get() && g_handler->GetBrowserHwnd())
    g_handler->GetBrowser()->GoForward();
}

- (IBAction)reload:(id)sender {
  if (g_handler.get() && g_handler->GetBrowserHwnd())
    g_handler->GetBrowser()->Reload();
}

- (IBAction)stopLoading:(id)sender {
  if (g_handler.get() && g_handler->GetBrowserHwnd())
    g_handler->GetBrowser()->StopLoad();
}

- (IBAction)takeURLStringValueFrom:(NSTextField *)sender {
  if (!g_handler.get() || !g_handler->GetBrowserHwnd())
    return;
  
  NSString *url = [sender stringValue];
  
  // if it doesn't already have a prefix, add http. If we can't parse it,
  // just don't bother rather than making things worse.
  NSURL* tempUrl = [NSURL URLWithString:url];
  if (tempUrl && ![tempUrl scheme])
    url = [@"http://" stringByAppendingString:url];
  
  std::string urlStr = [url UTF8String];
  g_handler->GetBrowser()->GetMainFrame()->LoadURL(urlStr);
}

- (void)alert:(NSString*)title withMessage:(NSString*)message {
  NSAlert *alert = [NSAlert alertWithMessageText:title
                                   defaultButton:@"OK"
                                 alternateButton:nil
                                     otherButton:nil
                       informativeTextWithFormat:message];
  [alert runModal];
}

- (void)notifyConsoleMessage:(id)object {
  std::stringstream ss;
  ss << "Console messages will be written to " << g_handler->GetLogFile();
  NSString* str = [NSString stringWithUTF8String:(ss.str().c_str())];
  [self alert:@"Console Messages" withMessage:str];
}

- (void)notifyDownloadComplete:(id)object {
  std::stringstream ss;
  ss << "File \"" << g_handler->GetLastDownloadFile() <<
      "\" downloaded successfully.";
  NSString* str = [NSString stringWithUTF8String:(ss.str().c_str())];
  [self alert:@"File Download" withMessage:str];
}

- (void)notifyDownloadError:(id)object {
  std::stringstream ss;
  ss << "File \"" << g_handler->GetLastDownloadFile() <<
      "\" failed to download.";
  NSString* str = [NSString stringWithUTF8String:(ss.str().c_str())];
  [self alert:@"File Download" withMessage:str];
}

- (void)windowDidBecomeKey:(NSNotification*)notification {
  if(g_handler.get() && g_handler->GetBrowserHwnd()) {
    // Give focus to the browser window.
    g_handler->GetBrowser()->SetFocus(true);
  }
}

// Called when the window is about to close. Perform the self-destruction
// sequence by getting rid of the window. By returning YES, we allow the window
// to be removed from the screen.
- (BOOL)windowShouldClose:(id)window {  
  // Try to make the window go away.
  [window autorelease];
  
  // Clean ourselves up after clearing the stack of anything that might have the
  // window on it.
  [self performSelectorOnMainThread:@selector(cleanup:)
                         withObject:window
                      waitUntilDone:NO];
  
  return YES;
}

// Deletes itself.
- (void)cleanup:(id)window {  
  [self release];
}

@end


NSButton* MakeButton(NSRect* rect, NSString* title, NSView* parent) {
  NSButton* button = [[[NSButton alloc] initWithFrame:*rect] autorelease];
  [button setTitle:title];
  [button setBezelStyle:NSSmallSquareBezelStyle];
  [button setAutoresizingMask:(NSViewMaxXMargin | NSViewMinYMargin)];
  [parent addSubview:button];
  rect->origin.x += BUTTON_WIDTH;
  return button;
}

// Receives notifications from the application. Will delete itself when done.
@interface ClientAppDelegate : NSObject
- (void)createApp:(id)object;
- (IBAction)testGetSource:(id)sender;
- (IBAction)testGetText:(id)sender;
- (IBAction)testJSBinding:(id)sender;
- (IBAction)testJSExtension:(id)sender;
- (IBAction)testJSExtensionPerf:(id)sender;
- (IBAction)testJSExecute:(id)sender;
- (IBAction)testJSInvoke:(id)sender;
- (IBAction)testRequest:(id)sender;
- (IBAction)testLocalStorage:(id)sender;
- (IBAction)testXMLHttpRequest:(id)sender;
- (IBAction)testWebURLRequest:(id)sender;
- (IBAction)testDOMAccess:(id)sender;
- (IBAction)testSchemeHandler:(id)sender;
- (IBAction)testPopupWindow:(id)sender;
- (IBAction)testAccelerated2DCanvas:(id)sender;
- (IBAction)testAcceleratedLayers:(id)sender;
- (IBAction)testWebGL:(id)sender;
- (IBAction)testHTML5Video:(id)sender;
- (IBAction)testDragDrop:(id)sender;
- (IBAction)testZoomIn:(id)sender;
- (IBAction)testZoomOut:(id)sender;
- (IBAction)testZoomReset:(id)sender;
- (IBAction)testDevToolsShow:(id)sender;
- (IBAction)testDevToolsClose:(id)sender;
@end

@implementation ClientAppDelegate

// Create the application on the UI thread.
- (void)createApp:(id)object {
  [NSApplication sharedApplication];
  [NSBundle loadNibNamed:@"MainMenu" owner:NSApp];
  
  // Set the delegate for application events.
  [NSApp setDelegate:self];
  
  // Add the Tests menu.
  NSMenu* menubar = [NSApp mainMenu];
  NSMenuItem *testItem = [[[NSMenuItem alloc] initWithTitle:@"Tests"
                                                     action:nil
                                              keyEquivalent:@""] autorelease];
  NSMenu *testMenu = [[[NSMenu alloc] initWithTitle:@"Tests"] autorelease];
  [testMenu addItemWithTitle:@"Get Source"
                      action:@selector(testGetSource:)
               keyEquivalent:@""];
  [testMenu addItemWithTitle:@"Get Text"
                      action:@selector(testGetText:)
               keyEquivalent:@""];
  [testMenu addItemWithTitle:@"JavaScript Binding Handler"
                      action:@selector(testJSBinding:)
               keyEquivalent:@""];
  [testMenu addItemWithTitle:@"JavaScript Extension Handler"
                      action:@selector(testJSExtension:)
               keyEquivalent:@""];
  [testMenu addItemWithTitle:@"JavaScript Extension Performance"
                      action:@selector(testJSExtensionPerf:)
               keyEquivalent:@""];
  [testMenu addItemWithTitle:@"JavaScript Execute"
                      action:@selector(testJSExecute:)
               keyEquivalent:@""];
  [testMenu addItemWithTitle:@"JavaScript Invoke"
                      action:@selector(testJSInvoke:)
               keyEquivalent:@""];
  [testMenu addItemWithTitle:@"Popup Window"
                      action:@selector(testPopupWindow:)
               keyEquivalent:@""];
  [testMenu addItemWithTitle:@"Request"
                      action:@selector(testRequest:)
               keyEquivalent:@""];
  [testMenu addItemWithTitle:@"Scheme Handler"
                      action:@selector(testSchemeHandler:)
               keyEquivalent:@""];
  [testMenu addItemWithTitle:@"Local Storage"
                      action:@selector(testLocalStorage:)
               keyEquivalent:@""];
  [testMenu addItemWithTitle:@"XMLHttpRequest"
                      action:@selector(testXMLHttpRequest:)
               keyEquivalent:@""];
  [testMenu addItemWithTitle:@"WebURLRequest"
                      action:@selector(testWebURLRequest:)
               keyEquivalent:@""];
  [testMenu addItemWithTitle:@"DOM Access"
                      action:@selector(testDOMAccess:)
               keyEquivalent:@""];
  [testMenu addItemWithTitle:@"Accelerated 2D Canvas"
                      action:@selector(testAccelerated2DCanvas:)
               keyEquivalent:@""];
  [testMenu addItemWithTitle:@"Accelerated Layers"
                      action:@selector(testAcceleratedLayers:)
               keyEquivalent:@""];
  [testMenu addItemWithTitle:@"WebGL"
                      action:@selector(testWebGL:)
               keyEquivalent:@""];
  [testMenu addItemWithTitle:@"HTML5 Video"
                      action:@selector(testHTML5Video:)
               keyEquivalent:@""];
  [testMenu addItemWithTitle:@"Drag & Drop"
                      action:@selector(testDragDrop:)
               keyEquivalent:@""];
  [testMenu addItemWithTitle:@"Zoom In"
                      action:@selector(testZoomIn:)
               keyEquivalent:@""];
  [testMenu addItemWithTitle:@"Zoom Out"
                      action:@selector(testZoomOut:)
               keyEquivalent:@""];
  [testMenu addItemWithTitle:@"Zoom Reset"
                      action:@selector(testZoomReset:)
               keyEquivalent:@""];
  [testMenu addItemWithTitle:@"Show DevTools"
                      action:@selector(testDevToolsShow:)
               keyEquivalent:@""];
  [testMenu addItemWithTitle:@"Close DevTools"
                      action:@selector(testDevToolsClose:)
               keyEquivalent:@""];
  [testItem setSubmenu:testMenu];
  [menubar addItem:testItem];
  
  // Create the delegate for control and browser window events.
  ClientWindowDelegate* delegate = [[ClientWindowDelegate alloc] init];
  
  // Create the main application window.
  NSRect screen_rect = [[NSScreen mainScreen] visibleFrame];
  NSRect window_rect = { {0, screen_rect.size.height - kWindowHeight},
    {kWindowWidth, kWindowHeight} };
  NSWindow* mainWnd = [[NSWindow alloc]
                       initWithContentRect:window_rect
                       styleMask:(NSTitledWindowMask |
                                  NSClosableWindowMask |
                                  NSMiniaturizableWindowMask |
                                  NSResizableWindowMask )
                       backing:NSBackingStoreBuffered
                       defer:NO];
  [mainWnd setTitle:@"cefclient"];
  [mainWnd setDelegate:delegate];

  // Rely on the window delegate to clean us up rather than immediately
  // releasing when the window gets closed. We use the delegate to do
  // everything from the autorelease pool so the window isn't on the stack
  // during cleanup (ie, a window close from javascript).
  [mainWnd setReleasedWhenClosed:NO];

  NSView* contentView = [mainWnd contentView];

  // Create the buttons.
  NSRect button_rect = [contentView bounds];
  button_rect.origin.y = window_rect.size.height - URLBAR_HEIGHT +
      (URLBAR_HEIGHT - BUTTON_HEIGHT) / 2;
  button_rect.size.height = BUTTON_HEIGHT;
  button_rect.origin.x += BUTTON_MARGIN;
  button_rect.size.width = BUTTON_WIDTH;

  NSButton* button = MakeButton(&button_rect, @"Back", contentView);
  [button setTarget:delegate];
  [button setAction:@selector(goBack:)];

  button = MakeButton(&button_rect, @"Forward", contentView);
  [button setTarget:delegate];
  [button setAction:@selector(goForward:)];

  button = MakeButton(&button_rect, @"Reload", contentView);
  [button setTarget:delegate];
  [button setAction:@selector(reload:)];

  button = MakeButton(&button_rect, @"Stop", contentView);
  [button setTarget:delegate];
  [button setAction:@selector(stopLoading:)];

  // Create the URL text field.
  button_rect.origin.x += BUTTON_MARGIN;
  button_rect.size.width = [contentView bounds].size.width -
      button_rect.origin.x - BUTTON_MARGIN;
  NSTextField* editWnd = [[NSTextField alloc] initWithFrame:button_rect];
  [contentView addSubview:editWnd];
  [editWnd setAutoresizingMask:(NSViewWidthSizable | NSViewMinYMargin)];
  [editWnd setTarget:delegate];
  [editWnd setAction:@selector(takeURLStringValueFrom:)];
  [[editWnd cell] setWraps:NO];
  [[editWnd cell] setScrollable:YES];

  // Create the handler.
  g_handler = new ClientHandler();
  g_handler->SetMainHwnd(contentView);
  g_handler->SetEditHwnd(editWnd);

  // Create the browser view.
  CefWindowInfo window_info;
  CefBrowserSettings settings;

  // Populate the settings based on command line arguments.
  AppGetBrowserSettings(settings);

  window_info.SetAsChild(contentView, 0, 0, kWindowWidth, kWindowHeight);
  CefBrowser::CreateBrowser(window_info, g_handler.get(),
                            "http://www.google.com", settings);

  // Show the window.
  [mainWnd makeKeyAndOrderFront: nil];

  // Size the window.
  NSRect r = [mainWnd contentRectForFrameRect:[mainWnd frame]];
  r.size.width = kWindowWidth;
  r.size.height = kWindowHeight + URLBAR_HEIGHT;
  [mainWnd setFrame:[mainWnd frameRectForContentRect:r] display:YES];
}

- (IBAction)testGetSource:(id)sender {
  if(g_handler.get() && g_handler->GetBrowserHwnd())
    RunGetSourceTest(g_handler->GetBrowser());
}

- (IBAction)testGetText:(id)sender {
  if(g_handler.get() && g_handler->GetBrowserHwnd())
    RunGetTextTest(g_handler->GetBrowser());
}

- (IBAction)testJSBinding:(id)sender {
  if(g_handler.get() && g_handler->GetBrowserHwnd())
    RunBindingTest(g_handler->GetBrowser());
}

- (IBAction)testJSExtension:(id)sender {
  if(g_handler.get() && g_handler->GetBrowserHwnd())
    RunExtensionTest(g_handler->GetBrowser());
}

- (IBAction)testJSExtensionPerf:(id)sender {
  if(g_handler.get() && g_handler->GetBrowserHwnd())
    RunExtensionPerfTest(g_handler->GetBrowser());
}

- (IBAction)testJSExecute:(id)sender {
  if(g_handler.get() && g_handler->GetBrowserHwnd())
    RunJavaScriptExecuteTest(g_handler->GetBrowser());
}

- (IBAction)testJSInvoke:(id)sender {
  if(g_handler.get() && g_handler->GetBrowserHwnd())
    RunJavaScriptInvokeTest(g_handler->GetBrowser());
}

- (IBAction)testRequest:(id)sender {
  if(g_handler.get() && g_handler->GetBrowserHwnd())
    RunRequestTest(g_handler->GetBrowser());
}

- (IBAction)testLocalStorage:(id)sender {
  if(g_handler.get() && g_handler->GetBrowserHwnd())
    RunLocalStorageTest(g_handler->GetBrowser());
}

- (IBAction)testXMLHttpRequest:(id)sender {
  if(g_handler.get() && g_handler->GetBrowserHwnd())
    RunXMLHTTPRequestTest(g_handler->GetBrowser());
}

- (IBAction)testWebURLRequest:(id)sender {
  if(g_handler.get() && g_handler->GetBrowserHwnd())
    RunWebURLRequestTest(g_handler->GetBrowser());
}

- (IBAction)testDOMAccess:(id)sender {
  if(g_handler.get() && g_handler->GetBrowserHwnd())
    RunDOMAccessTest(g_handler->GetBrowser());
}

- (IBAction)testSchemeHandler:(id)sender {
  if(g_handler.get() && g_handler->GetBrowserHwnd())
    RunSchemeTest(g_handler->GetBrowser());
}

- (IBAction)testPopupWindow:(id)sender {
  if(g_handler.get() && g_handler->GetBrowserHwnd())
    RunPopupTest(g_handler->GetBrowser());
}

- (IBAction)testAccelerated2DCanvas:(id)sender {
  if(g_handler.get() && g_handler->GetBrowserHwnd())
    RunAccelerated2DCanvasTest(g_handler->GetBrowser());
}

- (IBAction)testAcceleratedLayers:(id)sender {
  if(g_handler.get() && g_handler->GetBrowserHwnd())
    RunAcceleratedLayersTest(g_handler->GetBrowser());
}

- (IBAction)testWebGL:(id)sender {
  if(g_handler.get() && g_handler->GetBrowserHwnd())
    RunWebGLTest(g_handler->GetBrowser());
}

- (IBAction)testHTML5Video:(id)sender {
  if(g_handler.get() && g_handler->GetBrowserHwnd())
    RunHTML5VideoTest(g_handler->GetBrowser());
}

- (IBAction)testDragDrop:(id)sender {
  if(g_handler.get() && g_handler->GetBrowserHwnd())
    RunDragDropTest(g_handler->GetBrowser());
}

- (IBAction)testZoomIn:(id)sender {
  if(g_handler.get() && g_handler->GetBrowserHwnd()) {
    CefRefPtr<CefBrowser> browser = g_handler->GetBrowser();
    browser->SetZoomLevel(browser->GetZoomLevel() + 0.5);
  }
}

- (IBAction)testZoomOut:(id)sender {
  if(g_handler.get() && g_handler->GetBrowserHwnd()) {
    CefRefPtr<CefBrowser> browser = g_handler->GetBrowser();
    browser->SetZoomLevel(browser->GetZoomLevel() - 0.5);
  }
}

- (IBAction)testZoomReset:(id)sender {
  if(g_handler.get() && g_handler->GetBrowserHwnd()) {
    CefRefPtr<CefBrowser> browser = g_handler->GetBrowser();
    browser->SetZoomLevel(0.0);
  }
}

- (IBAction)testDevToolsShow:(id)sender {
  if(g_handler.get() && g_handler->GetBrowserHwnd()) {
    CefRefPtr<CefBrowser> browser = g_handler->GetBrowser();
    browser->ShowDevTools();
  }
}

- (IBAction)testDevToolsClose:(id)sender {
  if(g_handler.get() && g_handler->GetBrowserHwnd()) {
    CefRefPtr<CefBrowser> browser = g_handler->GetBrowser();
    browser->CloseDevTools();
  }
}

// Sent by the default notification center immediately before the application
// terminates.
- (void)applicationWillTerminate:(NSNotification *)aNotification {
  // Shut down CEF.
  g_handler = NULL;
  CefShutdown();

  [self release];

  // Release the AutoRelease pool.
  [g_autopool release];
}

@end


int main(int argc, char* argv[])
{
  // Retrieve the current working directory.
  getcwd(szWorkingDir, sizeof(szWorkingDir));

  // Initialize the AutoRelease pool.
  g_autopool = [[NSAutoreleasePool alloc] init];

  // Initialize the ClientApplication instance.
  [ClientApplication sharedApplication];
  
  // Parse command line arguments.
  AppInitCommandLine(argc, argv);

  CefSettings settings;
  CefRefPtr<CefApp> app;

  // Populate the settings based on command line arguments.
  AppGetSettings(settings, app);

  // Initialize CEF.
  CefInitialize(settings, app);

  // Initialize tests.
  InitExtensionTest();
  InitSchemeTest();

  // Create the application delegate and window.
  NSObject* delegate = [[ClientAppDelegate alloc] init];
  [delegate performSelectorOnMainThread:@selector(createApp:) withObject:nil
                          waitUntilDone:NO];

  // Run the application message loop.
  CefRunMessageLoop();

  // Don't put anything below this line because it won't be executed.
  return 0;
}


// Global functions

std::string AppGetWorkingDirectory()
{
  return szWorkingDir;
}
