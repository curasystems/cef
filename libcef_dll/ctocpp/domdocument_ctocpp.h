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

#ifndef _DOMDOCUMENT_CTOCPP_H
#define _DOMDOCUMENT_CTOCPP_H

#ifndef USING_CEF_SHARED
#pragma message("Warning: "__FILE__" may be accessed wrapper-side only")
#else // USING_CEF_SHARED

#include "include/cef_dom.h"
#include "include/capi/cef_dom_capi.h"
#include "libcef_dll/ctocpp/ctocpp.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed wrapper-side only.
class CefDOMDocumentCToCpp
    : public CefCToCpp<CefDOMDocumentCToCpp, CefDOMDocument, cef_domdocument_t>
{
public:
  CefDOMDocumentCToCpp(cef_domdocument_t* str)
      : CefCToCpp<CefDOMDocumentCToCpp, CefDOMDocument, cef_domdocument_t>(
          str) {}
  virtual ~CefDOMDocumentCToCpp() {}

  // CefDOMDocument methods
  virtual Type GetType() OVERRIDE;
  virtual CefRefPtr<CefDOMNode> GetDocument() OVERRIDE;
  virtual CefRefPtr<CefDOMNode> GetBody() OVERRIDE;
  virtual CefRefPtr<CefDOMNode> GetHead() OVERRIDE;
  virtual CefString GetTitle() OVERRIDE;
  virtual CefRefPtr<CefDOMNode> GetElementById(const CefString& id) OVERRIDE;
  virtual CefRefPtr<CefDOMNode> GetFocusedNode() OVERRIDE;
  virtual bool HasSelection() OVERRIDE;
  virtual CefRefPtr<CefDOMNode> GetSelectionStartNode() OVERRIDE;
  virtual int GetSelectionStartOffset() OVERRIDE;
  virtual CefRefPtr<CefDOMNode> GetSelectionEndNode() OVERRIDE;
  virtual int GetSelectionEndOffset() OVERRIDE;
  virtual CefString GetSelectionAsMarkup() OVERRIDE;
  virtual CefString GetSelectionAsText() OVERRIDE;
  virtual CefString GetBaseURL() OVERRIDE;
  virtual CefString GetCompleteURL(const CefString& partialURL) OVERRIDE;
};

#endif // USING_CEF_SHARED
#endif // _DOMDOCUMENT_CTOCPP_H

