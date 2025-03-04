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

#include "libcef_dll/ctocpp/write_handler_ctocpp.h"


// VIRTUAL METHODS - Body may be edited by hand.

size_t CefWriteHandlerCToCpp::Write(const void* ptr, size_t size, size_t n)
{
  if (CEF_MEMBER_MISSING(struct_, write))
    return 0;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: ptr; type: simple_byaddr
  DCHECK(ptr);
  if (!ptr)
    return 0;

  // Execute
  size_t _retval = struct_->write(struct_,
      ptr,
      size,
      n);

  // Return type: simple
  return _retval;
}

int CefWriteHandlerCToCpp::Seek(long offset, int whence)
{
  if (CEF_MEMBER_MISSING(struct_, seek))
    return 0;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->seek(struct_,
      offset,
      whence);

  // Return type: simple
  return _retval;
}

long CefWriteHandlerCToCpp::Tell()
{
  if (CEF_MEMBER_MISSING(struct_, tell))
    return 0;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  long _retval = struct_->tell(struct_);

  // Return type: simple
  return _retval;
}

int CefWriteHandlerCToCpp::Flush()
{
  if (CEF_MEMBER_MISSING(struct_, flush))
    return 0;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->flush(struct_);

  // Return type: simple
  return _retval;
}


#ifndef NDEBUG
template<> long CefCToCpp<CefWriteHandlerCToCpp, CefWriteHandler,
    cef_write_handler_t>::DebugObjCt = 0;
#endif

