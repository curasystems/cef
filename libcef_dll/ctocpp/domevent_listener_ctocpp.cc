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

#include "libcef_dll/cpptoc/domevent_cpptoc.h"
#include "libcef_dll/ctocpp/domevent_listener_ctocpp.h"


// VIRTUAL METHODS - Body may be edited by hand.

void CefDOMEventListenerCToCpp::HandleEvent(CefRefPtr<CefDOMEvent> event)
{
  if (CEF_MEMBER_MISSING(struct_, handle_event))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: event; type: refptr_diff
  DCHECK(event.get());
  if (!event.get())
    return;

  // Execute
  struct_->handle_event(struct_,
      CefDOMEventCppToC::Wrap(event));
}


#ifndef NDEBUG
template<> long CefCToCpp<CefDOMEventListenerCToCpp, CefDOMEventListener,
    cef_domevent_listener_t>::DebugObjCt = 0;
#endif

