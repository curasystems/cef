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

#include "libcef_dll/cpptoc/read_handler_cpptoc.h"
#include "libcef_dll/ctocpp/stream_reader_ctocpp.h"


// STATIC METHODS - Body may be edited by hand.

CefRefPtr<CefStreamReader> CefStreamReader::CreateForFile(
    const CefString& fileName)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: fileName; type: string_byref_const
  DCHECK(!fileName.empty());
  if (fileName.empty())
    return NULL;

  // Execute
  cef_stream_reader_t* _retval = cef_stream_reader_create_for_file(
      fileName.GetStruct());

  // Return type: refptr_same
  return CefStreamReaderCToCpp::Wrap(_retval);
}

CefRefPtr<CefStreamReader> CefStreamReader::CreateForData(void* data,
    size_t size)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: data; type: simple_byaddr
  DCHECK(data);
  if (!data)
    return NULL;

  // Execute
  cef_stream_reader_t* _retval = cef_stream_reader_create_for_data(
      data,
      size);

  // Return type: refptr_same
  return CefStreamReaderCToCpp::Wrap(_retval);
}

CefRefPtr<CefStreamReader> CefStreamReader::CreateForHandler(
    CefRefPtr<CefReadHandler> handler)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: handler; type: refptr_diff
  DCHECK(handler.get());
  if (!handler.get())
    return NULL;

  // Execute
  cef_stream_reader_t* _retval = cef_stream_reader_create_for_handler(
      CefReadHandlerCppToC::Wrap(handler));

  // Return type: refptr_same
  return CefStreamReaderCToCpp::Wrap(_retval);
}


// VIRTUAL METHODS - Body may be edited by hand.

size_t CefStreamReaderCToCpp::Read(void* ptr, size_t size, size_t n)
{
  if (CEF_MEMBER_MISSING(struct_, read))
    return 0;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: ptr; type: simple_byaddr
  DCHECK(ptr);
  if (!ptr)
    return 0;

  // Execute
  size_t _retval = struct_->read(struct_,
      ptr,
      size,
      n);

  // Return type: simple
  return _retval;
}

int CefStreamReaderCToCpp::Seek(long offset, int whence)
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

long CefStreamReaderCToCpp::Tell()
{
  if (CEF_MEMBER_MISSING(struct_, tell))
    return 0;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  long _retval = struct_->tell(struct_);

  // Return type: simple
  return _retval;
}

int CefStreamReaderCToCpp::Eof()
{
  if (CEF_MEMBER_MISSING(struct_, eof))
    return 0;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->eof(struct_);

  // Return type: simple
  return _retval;
}


#ifndef NDEBUG
template<> long CefCToCpp<CefStreamReaderCToCpp, CefStreamReader,
    cef_stream_reader_t>::DebugObjCt = 0;
#endif

