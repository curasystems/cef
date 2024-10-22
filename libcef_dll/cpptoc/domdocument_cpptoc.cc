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

#include "libcef_dll/cpptoc/domdocument_cpptoc.h"
#include "libcef_dll/cpptoc/domnode_cpptoc.h"


// MEMBER FUNCTIONS - Body may be edited by hand.

enum cef_dom_document_type_t CEF_CALLBACK domdocument_get_type(
    struct _cef_domdocument_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return DOM_DOCUMENT_TYPE_UNKNOWN;

  // Execute
  cef_dom_document_type_t _retval = CefDOMDocumentCppToC::Get(self)->GetType();

  // Return type: simple
  return _retval;
}

struct _cef_domnode_t* CEF_CALLBACK domdocument_get_document(
    struct _cef_domdocument_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefDOMNode> _retval = CefDOMDocumentCppToC::Get(self)->GetDocument(
      );

  // Return type: refptr_same
  return CefDOMNodeCppToC::Wrap(_retval);
}

struct _cef_domnode_t* CEF_CALLBACK domdocument_get_body(
    struct _cef_domdocument_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefDOMNode> _retval = CefDOMDocumentCppToC::Get(self)->GetBody();

  // Return type: refptr_same
  return CefDOMNodeCppToC::Wrap(_retval);
}

struct _cef_domnode_t* CEF_CALLBACK domdocument_get_head(
    struct _cef_domdocument_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefDOMNode> _retval = CefDOMDocumentCppToC::Get(self)->GetHead();

  // Return type: refptr_same
  return CefDOMNodeCppToC::Wrap(_retval);
}

cef_string_userfree_t CEF_CALLBACK domdocument_get_title(
    struct _cef_domdocument_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefDOMDocumentCppToC::Get(self)->GetTitle();

  // Return type: string
  return _retval.DetachToUserFree();
}

struct _cef_domnode_t* CEF_CALLBACK domdocument_get_element_by_id(
    struct _cef_domdocument_t* self, const cef_string_t* id)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;
  // Verify param: id; type: string_byref_const
  DCHECK(id);
  if (!id)
    return NULL;

  // Execute
  CefRefPtr<CefDOMNode> _retval = CefDOMDocumentCppToC::Get(
      self)->GetElementById(
      CefString(id));

  // Return type: refptr_same
  return CefDOMNodeCppToC::Wrap(_retval);
}

struct _cef_domnode_t* CEF_CALLBACK domdocument_get_focused_node(
    struct _cef_domdocument_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefDOMNode> _retval = CefDOMDocumentCppToC::Get(
      self)->GetFocusedNode();

  // Return type: refptr_same
  return CefDOMNodeCppToC::Wrap(_retval);
}

int CEF_CALLBACK domdocument_has_selection(struct _cef_domdocument_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefDOMDocumentCppToC::Get(self)->HasSelection();

  // Return type: bool
  return _retval;
}

struct _cef_domnode_t* CEF_CALLBACK domdocument_get_selection_start_node(
    struct _cef_domdocument_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefDOMNode> _retval = CefDOMDocumentCppToC::Get(
      self)->GetSelectionStartNode();

  // Return type: refptr_same
  return CefDOMNodeCppToC::Wrap(_retval);
}

int CEF_CALLBACK domdocument_get_selection_start_offset(
    struct _cef_domdocument_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  int _retval = CefDOMDocumentCppToC::Get(self)->GetSelectionStartOffset();

  // Return type: simple
  return _retval;
}

struct _cef_domnode_t* CEF_CALLBACK domdocument_get_selection_end_node(
    struct _cef_domdocument_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefDOMNode> _retval = CefDOMDocumentCppToC::Get(
      self)->GetSelectionEndNode();

  // Return type: refptr_same
  return CefDOMNodeCppToC::Wrap(_retval);
}

int CEF_CALLBACK domdocument_get_selection_end_offset(
    struct _cef_domdocument_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  int _retval = CefDOMDocumentCppToC::Get(self)->GetSelectionEndOffset();

  // Return type: simple
  return _retval;
}

cef_string_userfree_t CEF_CALLBACK domdocument_get_selection_as_markup(
    struct _cef_domdocument_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefDOMDocumentCppToC::Get(self)->GetSelectionAsMarkup();

  // Return type: string
  return _retval.DetachToUserFree();
}

cef_string_userfree_t CEF_CALLBACK domdocument_get_selection_as_text(
    struct _cef_domdocument_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefDOMDocumentCppToC::Get(self)->GetSelectionAsText();

  // Return type: string
  return _retval.DetachToUserFree();
}

cef_string_userfree_t CEF_CALLBACK domdocument_get_base_url(
    struct _cef_domdocument_t* self)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefDOMDocumentCppToC::Get(self)->GetBaseURL();

  // Return type: string
  return _retval.DetachToUserFree();
}

cef_string_userfree_t CEF_CALLBACK domdocument_get_complete_url(
    struct _cef_domdocument_t* self, const cef_string_t* partialURL)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;
  // Verify param: partialURL; type: string_byref_const
  DCHECK(partialURL);
  if (!partialURL)
    return NULL;

  // Execute
  CefString _retval = CefDOMDocumentCppToC::Get(self)->GetCompleteURL(
      CefString(partialURL));

  // Return type: string
  return _retval.DetachToUserFree();
}


// CONSTRUCTOR - Do not edit by hand.

CefDOMDocumentCppToC::CefDOMDocumentCppToC(CefDOMDocument* cls)
    : CefCppToC<CefDOMDocumentCppToC, CefDOMDocument, cef_domdocument_t>(cls)
{
  struct_.struct_.get_type = domdocument_get_type;
  struct_.struct_.get_document = domdocument_get_document;
  struct_.struct_.get_body = domdocument_get_body;
  struct_.struct_.get_head = domdocument_get_head;
  struct_.struct_.get_title = domdocument_get_title;
  struct_.struct_.get_element_by_id = domdocument_get_element_by_id;
  struct_.struct_.get_focused_node = domdocument_get_focused_node;
  struct_.struct_.has_selection = domdocument_has_selection;
  struct_.struct_.get_selection_start_node =
      domdocument_get_selection_start_node;
  struct_.struct_.get_selection_start_offset =
      domdocument_get_selection_start_offset;
  struct_.struct_.get_selection_end_node = domdocument_get_selection_end_node;
  struct_.struct_.get_selection_end_offset =
      domdocument_get_selection_end_offset;
  struct_.struct_.get_selection_as_markup = domdocument_get_selection_as_markup;
  struct_.struct_.get_selection_as_text = domdocument_get_selection_as_text;
  struct_.struct_.get_base_url = domdocument_get_base_url;
  struct_.struct_.get_complete_url = domdocument_get_complete_url;
}

#ifndef NDEBUG
template<> long CefCppToC<CefDOMDocumentCppToC, CefDOMDocument,
    cef_domdocument_t>::DebugObjCt = 0;
#endif

