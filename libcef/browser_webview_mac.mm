// Copyright (c) 2008 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#import "browser_webview_mac.h"

#import <Cocoa/Cocoa.h>

#include "browser_impl.h"
#include "webwidget_host.h"

#include "base/scoped_ptr.h"
#include "base/utf_string_conversions.h"
#include "gfx/rect.h"
#include "third_party/WebKit/WebKit/chromium/public/WebFrame.h"
#include "third_party/WebKit/WebKit/chromium/public/WebView.h"

@implementation BrowserWebView

@synthesize browser = browser_;

- (id)initWithFrame:(NSRect)frame {
  self = [super initWithFrame:frame];
  if (self) {
    trackingArea_ =
    [[NSTrackingArea alloc] initWithRect:frame
                                 options:NSTrackingMouseMoved |
                                         NSTrackingActiveInActiveApp |
                                         NSTrackingInVisibleRect
                                   owner:self
                                userInfo:nil];
    [self addTrackingArea:trackingArea_];
  }
  return self;
}

- (void) dealloc {
  [self removeTrackingArea:trackingArea_];
  [trackingArea_ release];

  [super dealloc];
}

- (void)drawRect:(NSRect)rect {
  CGContextRef context =
      reinterpret_cast<CGContextRef>([[NSGraphicsContext currentContext]
                                      graphicsPort]);

  // start by filling the rect with magenta, so that we can see what's drawn
  CGContextSetRGBFillColor (context, 1, 0, 1, 1);
  CGContextFillRect(context, NSRectToCGRect(rect));

  if (browser_ && browser_->GetWebView()) {
    gfx::Rect client_rect(NSRectToCGRect(rect));
    // flip from cocoa coordinates
    client_rect.set_y([self frame].size.height -
                      client_rect.height() - client_rect.y());

    browser_->GetWebViewHost()->UpdatePaintRect(client_rect);
    browser_->GetWebViewHost()->Paint();
  }
}

- (IBAction)goBack:(id)sender {
  if (browser_)
    browser_->UIT_GoBackOrForward(-1);
}

- (IBAction)goForward:(id)sender {
  if (browser_)
    browser_->UIT_GoBackOrForward(1);
}

- (IBAction)reload:(id)sender {
  if (browser_)
    browser_->UIT_Reload(false);
}

- (IBAction)stopLoading:(id)sender {
  if (browser_ && browser_->GetWebView())
    browser_->GetWebView()->mainFrame()->stopLoading();
}

- (IBAction)takeURLStringValueFrom:(NSTextField *)sender {
  NSString *url = [sender stringValue];

  // if it doesn't already have a prefix, add http. If we can't parse it,
  // just don't bother rather than making things worse.
  NSURL* tempUrl = [NSURL URLWithString:url];
  if (tempUrl && ![tempUrl scheme])
    url = [@"http://" stringByAppendingString:url];
  browser_->LoadURL(browser_->GetMainFrame(), UTF8ToWide([url UTF8String]));
}

- (void)mouseDown:(NSEvent *)theEvent {
  if (browser_ && browser_->GetWebView())
    browser_->GetWebViewHost()->MouseEvent(theEvent);
}

- (void)rightMouseDown:(NSEvent *)theEvent {
  if (browser_ && browser_->GetWebView())
    browser_->GetWebViewHost()->MouseEvent(theEvent);
}

- (void)otherMouseDown:(NSEvent *)theEvent {
  if (browser_ && browser_->GetWebView())
    browser_->GetWebViewHost()->MouseEvent(theEvent);
}

- (void)mouseUp:(NSEvent *)theEvent {
  if (browser_ && browser_->GetWebView())
    browser_->GetWebViewHost()->MouseEvent(theEvent);
}

- (void)rightMouseUp:(NSEvent *)theEvent {
  if (browser_ && browser_->GetWebView())
    browser_->GetWebViewHost()->MouseEvent(theEvent);
}

- (void)otherMouseUp:(NSEvent *)theEvent {
  if (browser_ && browser_->GetWebView())
    browser_->GetWebViewHost()->MouseEvent(theEvent);
}

- (void)mouseMoved:(NSEvent *)theEvent {
  if (browser_ && browser_->GetWebView())
    browser_->GetWebViewHost()->MouseEvent(theEvent);
}

- (void)mouseDragged:(NSEvent *)theEvent {
  if (browser_ && browser_->GetWebView())
    browser_->GetWebViewHost()->MouseEvent(theEvent);
}

- (void)scrollWheel:(NSEvent *)theEvent {
  if (browser_ && browser_->GetWebView())
    browser_->GetWebViewHost()->WheelEvent(theEvent);
}

- (void)rightMouseDragged:(NSEvent *)theEvent {
  if (browser_ && browser_->GetWebView())
    browser_->GetWebViewHost()->MouseEvent(theEvent);
}

- (void)otherMouseDragged:(NSEvent *)theEvent {
  if (browser_ && browser_->GetWebView())
    browser_->GetWebViewHost()->MouseEvent(theEvent);
}

- (void)mouseEntered:(NSEvent *)theEvent {
  if (browser_ && browser_->GetWebView())
    browser_->GetWebViewHost()->MouseEvent(theEvent);
}

- (void)mouseExited:(NSEvent *)theEvent {
  if (browser_ && browser_->GetWebView())
    browser_->GetWebViewHost()->MouseEvent(theEvent);
}

- (void)keyDown:(NSEvent *)theEvent {
  if (browser_ && browser_->GetWebView())
    browser_->GetWebViewHost()->KeyEvent(theEvent);
}

- (void)keyUp:(NSEvent *)theEvent {
  if (browser_ && browser_->GetWebView())
    browser_->GetWebViewHost()->KeyEvent(theEvent);
}

- (BOOL)isOpaque {
  return YES;
}

- (BOOL)canBecomeKeyView {
  return browser_ && browser_->GetWebView();
}

- (BOOL)acceptsFirstResponder {
  return browser_ && browser_->GetWebView();
}

- (BOOL)becomeFirstResponder {
  if (browser_ && browser_->GetWebView()) {
    browser_->GetWebViewHost()->SetFocus(YES);
    return YES;
  }

  return NO;
}

- (BOOL)resignFirstResponder {
  if (browser_ && browser_->GetWebView()) {
    browser_->GetWebViewHost()->SetFocus(NO);
    return YES;
  }

  return NO;
}

- (void)setIsActive:(BOOL)active {
  if (browser_ && browser_->GetWebView())
    browser_->GetWebViewHost()->SetIsActive(active ? true : false);
}

- (void)setFrame:(NSRect)frameRect {
  [super setFrame:frameRect];
  if (browser_ && browser_->GetWebView())
    browser_->GetWebViewHost()->Resize(gfx::Rect(NSRectToCGRect(frameRect)));
  [self setNeedsDisplay:YES];
}

@end
