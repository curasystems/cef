// Copyright (c) 2011 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#ifndef _TEST_HANDLER_H
#define _TEST_HANDLER_H

#include "include/cef_browser.h"
#include "include/cef_client.h"
#include "include/cef_frame.h"
#include "include/cef_task.h"
#include "base/synchronization/waitable_event.h"
#include "testing/gtest/include/gtest/gtest.h"

class TrackCallback
{
public:
  TrackCallback(): gotit_(false) {}
  void yes() { gotit_ = true; }
  bool isSet() { return gotit_; }
  void reset() { gotit_ = false; }
  operator bool() const { return gotit_; }
protected:
  bool gotit_;
};

// Base implementation of CefClient for unit tests. Add new interfaces as needed
// by test cases.
class TestHandler : public CefClient,
                    public CefDisplayHandler,
                    public CefLifeSpanHandler,
                    public CefLoadHandler,
                    public CefRequestHandler,
                    public CefV8ContextHandler
{
public:
  TestHandler();
  virtual ~TestHandler();

  // Implement this method to run the test
  virtual void RunTest() =0;

  // CefClient methods. Add new methods as needed by test cases.
  virtual CefRefPtr<CefDisplayHandler> GetDisplayHandler() OVERRIDE
      { return this; }
  virtual CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() OVERRIDE
      { return this; }
  virtual CefRefPtr<CefLoadHandler> GetLoadHandler() OVERRIDE
      { return this; }
  virtual CefRefPtr<CefRequestHandler> GetRequestHandler() OVERRIDE
      { return this; }
  virtual CefRefPtr<CefV8ContextHandler> GetV8ContextHandler() OVERRIDE
      { return this; }
  
  // CefLifeSpanHandler methods
  virtual void OnAfterCreated(CefRefPtr<CefBrowser> browser) OVERRIDE;
  virtual void OnBeforeClose(CefRefPtr<CefBrowser> browser) OVERRIDE;

  // CefRequestHandler methods
  virtual bool OnBeforeResourceLoad(CefRefPtr<CefBrowser> browser,
                                    CefRefPtr<CefRequest> request,
                                    CefString& redirectUrl,
                                    CefRefPtr<CefStreamReader>& resourceStream,
                                    CefRefPtr<CefResponse> response,
                                    int loadFlags) OVERRIDE;

  CefRefPtr<CefBrowser> GetBrowser() { return browser_; }
  CefWindowHandle GetBrowserHwnd() { return browser_hwnd_; }

  // Called by the test function to execute the test.  This method blocks until
  // the test is complete. Do not reference the object after this method
  // returns.
  void ExecuteTest();

protected:
  // Destroy the browser window. Once the window is destroyed test completion
  // will be signaled.
  void DestroyTest();

  void CreateBrowser(const CefString& url);

  void AddResource(const CefString& key, const std::string& value,
                   const CefString& mimeType);
  void ClearResources();

private:
  // The child browser window
  CefRefPtr<CefBrowser> browser_;

  // The browser window handle
  CefWindowHandle browser_hwnd_;

  // Handle used to notify when the test is complete
  base::WaitableEvent completion_event_;

  // Map of resources that can be automatically loaded
  typedef std::map<CefString, std::pair<std::string, CefString> > ResourceMap;
  ResourceMap resource_map_;

  // Include the default reference counting implementation.
  IMPLEMENT_REFCOUNTING(TestHandler);
  // Include the default locking implementation.
  IMPLEMENT_LOCKING(TestHandler);
};


// Post a task to the specified thread and wait for the task to execute as
// indication that all previously pending tasks on that thread have completed.
void WaitForThread(CefThreadId thread_id);

#define WaitForIOThread() WaitForThread(TID_IO)
#define WaitForUIThread() WaitForThread(TID_UI)

#endif // _TEST_HANDLER_H
