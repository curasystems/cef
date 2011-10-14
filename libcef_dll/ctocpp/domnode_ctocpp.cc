// Copyright (c) 2011 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// A portion of this file was generated by the CEF translator tool.  When
// making changes by hand only do so within the body of existing static and
// virtual method implementations. See the translator.README.txt file in the
// tools directory for more information.
//

#include "libcef_dll/cpptoc/domevent_listener_cpptoc.h"
#include "libcef_dll/ctocpp/domdocument_ctocpp.h"
#include "libcef_dll/ctocpp/domnode_ctocpp.h"
#include "libcef_dll/transfer_util.h"


// VIRTUAL METHODS - Body may be edited by hand.

CefDOMNode::Type CefDOMNodeCToCpp::GetType()
{
  if(CEF_MEMBER_MISSING(struct_, get_type))
    return DOM_NODE_TYPE_UNSUPPORTED;

  return struct_->get_type(struct_);
}

bool CefDOMNodeCToCpp::IsText()
{
  if(CEF_MEMBER_MISSING(struct_, is_text))
    return false;

  return struct_->is_text(struct_) ? true : false;
}

bool CefDOMNodeCToCpp::IsElement()
{
  if(CEF_MEMBER_MISSING(struct_, is_element))
    return false;

  return struct_->is_element(struct_) ? true : false;
}

bool CefDOMNodeCToCpp::IsFormControlElement()
{
  if (CEF_MEMBER_MISSING(struct_, is_form_control_element))
    return false;

  return struct_->is_form_control_element(struct_) ? true : false;
}

CefString CefDOMNodeCToCpp::GetFormControlElementType()
{
  CefString str;
  if (CEF_MEMBER_MISSING(struct_, get_form_control_element_type))
    return str;

  cef_string_userfree_t strPtr =
      struct_->get_form_control_element_type(struct_);
  str.AttachToUserFree(strPtr);
  return str;
}

bool CefDOMNodeCToCpp::IsSame(CefRefPtr<CefDOMNode> that)
{
  if (CEF_MEMBER_MISSING(struct_, is_same))
    return false;

  return struct_->is_same(struct_, CefDOMNodeCToCpp::Unwrap(that)) ?
      true : false;
}

CefString CefDOMNodeCToCpp::GetName()
{
  CefString str;
  if(CEF_MEMBER_MISSING(struct_, get_name))
    return str;

  cef_string_userfree_t strPtr = struct_->get_name(struct_);
  str.AttachToUserFree(strPtr);
  return str;
}

CefString CefDOMNodeCToCpp::GetValue()
{
  CefString str;
  if(CEF_MEMBER_MISSING(struct_, get_value))
    return str;

  cef_string_userfree_t strPtr = struct_->get_value(struct_);
  str.AttachToUserFree(strPtr);
  return str;
}

bool CefDOMNodeCToCpp::SetValue(const CefString& value)
{
  if(CEF_MEMBER_MISSING(struct_, set_value))
    return false;

  return struct_->set_value(struct_, value.GetStruct()) ? true : false;
}

CefString CefDOMNodeCToCpp::GetAsMarkup()
{
  CefString str;
  if(CEF_MEMBER_MISSING(struct_, get_as_markup))
    return str;

  cef_string_userfree_t strPtr = struct_->get_as_markup(struct_);
  str.AttachToUserFree(strPtr);
  return str;
}

CefRefPtr<CefDOMDocument> CefDOMNodeCToCpp::GetDocument()
{
  if(CEF_MEMBER_MISSING(struct_, get_document))
    return NULL;

  cef_domdocument_t* documentStruct = struct_->get_document(struct_);
  if(documentStruct)
    return CefDOMDocumentCToCpp::Wrap(documentStruct);

  return NULL;
}

CefRefPtr<CefDOMNode> CefDOMNodeCToCpp::GetParent()
{
  if(CEF_MEMBER_MISSING(struct_, get_parent))
    return NULL;

  cef_domnode_t* nodeStruct = struct_->get_parent(struct_);
  if(nodeStruct)
    return CefDOMNodeCToCpp::Wrap(nodeStruct);
  return NULL;
}

CefRefPtr<CefDOMNode> CefDOMNodeCToCpp::GetPreviousSibling()
{
  if(CEF_MEMBER_MISSING(struct_, get_previous_sibling))
    return NULL;

  cef_domnode_t* nodeStruct = struct_->get_previous_sibling(struct_);
  if(nodeStruct)
    return CefDOMNodeCToCpp::Wrap(nodeStruct);
  return NULL;
}

CefRefPtr<CefDOMNode> CefDOMNodeCToCpp::GetNextSibling()
{
  if(CEF_MEMBER_MISSING(struct_, get_next_sibling))
    return NULL;

  cef_domnode_t* nodeStruct = struct_->get_next_sibling(struct_);
  if(nodeStruct)
    return CefDOMNodeCToCpp::Wrap(nodeStruct);
  return NULL;
}

bool CefDOMNodeCToCpp::HasChildren()
{
  if(CEF_MEMBER_MISSING(struct_, has_children))
    return false;

  return struct_->has_children(struct_) ? true : false;
}

CefRefPtr<CefDOMNode> CefDOMNodeCToCpp::GetFirstChild()
{
  if(CEF_MEMBER_MISSING(struct_, get_first_child))
    return NULL;

  cef_domnode_t* nodeStruct = struct_->get_first_child(struct_);
  if(nodeStruct)
    return CefDOMNodeCToCpp::Wrap(nodeStruct);
  return NULL;
}

CefRefPtr<CefDOMNode> CefDOMNodeCToCpp::GetLastChild()
{
  if(CEF_MEMBER_MISSING(struct_, get_last_child))
    return NULL;

  cef_domnode_t* nodeStruct = struct_->get_last_child(struct_);
  if(nodeStruct)
    return CefDOMNodeCToCpp::Wrap(nodeStruct);
  return NULL;
}

void CefDOMNodeCToCpp::AddEventListener(const CefString& eventType,
    CefRefPtr<CefDOMEventListener> listener, bool useCapture)
{
  if(CEF_MEMBER_MISSING(struct_, add_event_listener))
    return;

  struct_->add_event_listener(struct_, eventType.GetStruct(),
      CefDOMEventListenerCppToC::Wrap(listener), useCapture);
}

CefString CefDOMNodeCToCpp::GetElementTagName()
{
  CefString str;
  if(CEF_MEMBER_MISSING(struct_, get_element_tag_name))
    return str;

  cef_string_userfree_t strPtr = struct_->get_element_tag_name(struct_);
  str.AttachToUserFree(strPtr);
  return str;
}

bool CefDOMNodeCToCpp::HasElementAttributes()
{
  if(CEF_MEMBER_MISSING(struct_, has_element_attributes))
    return false;

  return struct_->has_element_attributes(struct_) ? true : false;
}

bool CefDOMNodeCToCpp::HasElementAttribute(const CefString& attrName)
{
  if(CEF_MEMBER_MISSING(struct_, has_element_attribute))
    return false;

  return struct_->has_element_attribute(struct_, attrName.GetStruct()) ?
      true : false;
}

CefString CefDOMNodeCToCpp::GetElementAttribute(const CefString& attrName)
{
  CefString str;
  if(CEF_MEMBER_MISSING(struct_, get_element_attribute))
    return str;

  cef_string_userfree_t strPtr =
      struct_->get_element_attribute(struct_, attrName.GetStruct());
  str.AttachToUserFree(strPtr);
  return str;
}

void CefDOMNodeCToCpp::GetElementAttributes(AttributeMap& attrMap)
{
  if(CEF_MEMBER_MISSING(struct_, get_element_attributes))
    return;

  cef_string_map_t map = cef_string_map_alloc();
  if(!map)
    return;

  struct_->get_element_attributes(struct_, map);
  transfer_string_map_contents(map, attrMap);
  cef_string_map_free(map);
}

bool CefDOMNodeCToCpp::SetElementAttribute(const CefString& attrName,
    const CefString& value)
{
  if(CEF_MEMBER_MISSING(struct_, set_element_attribute))
    return false;

  return struct_->set_element_attribute(struct_, attrName.GetStruct(),
      value.GetStruct()) ? true : false;
}

CefString CefDOMNodeCToCpp::GetElementInnerText()
{
  CefString str;
  if(CEF_MEMBER_MISSING(struct_, get_element_inner_text))
    return str;

  cef_string_userfree_t strPtr = struct_->get_element_inner_text(struct_);
  str.AttachToUserFree(strPtr);
  return str;
}


#ifndef NDEBUG
template<> long CefCToCpp<CefDOMNodeCToCpp, CefDOMNode,
    cef_domnode_t>::DebugObjCt = 0;
#endif

