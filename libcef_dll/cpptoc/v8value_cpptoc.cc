// Copyright (c) 2010 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// A portion of this file was generated by the CEF translator tool.  When
// making changes by hand only do so within the body of existing function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//

#include "libcef_dll/cpptoc/v8value_cpptoc.h"
#include "libcef_dll/ctocpp/base_ctocpp.h"
#include "libcef_dll/ctocpp/v8handler_ctocpp.h"


// GLOBAL FUNCTIONS - Body may be edited by hand.

CEF_EXPORT cef_v8value_t* cef_v8value_create_undefined()
{
  CefRefPtr<CefV8Value> impl = CefV8Value::CreateUndefined();
  if(impl.get())
    return CefV8ValueCppToC::Wrap(impl);
  return NULL;
}

CEF_EXPORT cef_v8value_t* cef_v8value_create_null()
{
  CefRefPtr<CefV8Value> impl = CefV8Value::CreateNull();
  if(impl.get())
    return CefV8ValueCppToC::Wrap(impl);
  return NULL;
}

CEF_EXPORT cef_v8value_t* cef_v8value_create_bool(int value)
{
  CefRefPtr<CefV8Value> impl = CefV8Value::CreateBool(value?true:false);
  if(impl.get())
    return CefV8ValueCppToC::Wrap(impl);
  return NULL;
}

CEF_EXPORT cef_v8value_t* cef_v8value_create_int(int value)
{
  CefRefPtr<CefV8Value> impl = CefV8Value::CreateInt(value);
  if(impl.get())
    return CefV8ValueCppToC::Wrap(impl);
  return NULL;
}

CEF_EXPORT cef_v8value_t* cef_v8value_create_double(double value)
{
  CefRefPtr<CefV8Value> impl = CefV8Value::CreateDouble(value);
  if(impl.get())
    return CefV8ValueCppToC::Wrap(impl);
  return NULL;
}

CEF_EXPORT cef_v8value_t* cef_v8value_create_string(const wchar_t* value)
{
  std::wstring valueStr;
  if(value)
    valueStr = value;

  CefRefPtr<CefV8Value> impl = CefV8Value::CreateString(valueStr);
  if(impl.get())
    return CefV8ValueCppToC::Wrap(impl);
  return NULL;
}

CEF_EXPORT cef_v8value_t* cef_v8value_create_object(cef_base_t* user_data)
{
  CefRefPtr<CefBase> basePtr;
  if(user_data)
    basePtr = CefBaseCToCpp::Wrap(user_data);

  CefRefPtr<CefV8Value> impl = CefV8Value::CreateObject(basePtr);
  if(impl.get())
    return CefV8ValueCppToC::Wrap(impl);
  return NULL;
}

CEF_EXPORT cef_v8value_t* cef_v8value_create_array()
{
  CefRefPtr<CefV8Value> impl = CefV8Value::CreateArray();
  if(impl.get())
    return CefV8ValueCppToC::Wrap(impl);
  return NULL;
}

CEF_EXPORT cef_v8value_t* cef_v8value_create_function(const wchar_t* name,
    cef_v8handler_t* handler)
{
  std::wstring nameStr;
  if(name)
    nameStr = name;
  CefRefPtr<CefV8Handler> handlerPtr;
  if(handler)
    handlerPtr = CefV8HandlerCToCpp::Wrap(handler);

  CefRefPtr<CefV8Value> impl = CefV8Value::CreateFunction(nameStr, handlerPtr);
  if(impl.get())
    return CefV8ValueCppToC::Wrap(impl);
  return NULL;
}


// MEMBER FUNCTIONS - Body may be edited by hand.

int CEF_CALLBACK v8value_is_undefined(struct _cef_v8value_t* self)
{
  DCHECK(self);
  if(!self)
    return 0;

  return CefV8ValueCppToC::Get(self)->IsUndefined();
}

int CEF_CALLBACK v8value_is_null(struct _cef_v8value_t* self)
{
  DCHECK(self);
  if(!self)
    return 0;

  return CefV8ValueCppToC::Get(self)->IsNull();
}

int CEF_CALLBACK v8value_is_bool(struct _cef_v8value_t* self)
{
  DCHECK(self);
  if(!self)
    return 0;

  return CefV8ValueCppToC::Get(self)->IsBool();
}

int CEF_CALLBACK v8value_is_int(struct _cef_v8value_t* self)
{
  DCHECK(self);
  if(!self)
    return 0;

  return CefV8ValueCppToC::Get(self)->IsInt();
}

int CEF_CALLBACK v8value_is_double(struct _cef_v8value_t* self)
{
  DCHECK(self);
  if(!self)
    return 0;

  return CefV8ValueCppToC::Get(self)->IsDouble();
}

int CEF_CALLBACK v8value_is_string(struct _cef_v8value_t* self)
{
  DCHECK(self);
  if(!self)
    return 0;

  return CefV8ValueCppToC::Get(self)->IsString();
}

int CEF_CALLBACK v8value_is_object(struct _cef_v8value_t* self)
{
  DCHECK(self);
  if(!self)
    return 0;

  return CefV8ValueCppToC::Get(self)->IsObject();
}

int CEF_CALLBACK v8value_is_array(struct _cef_v8value_t* self)
{
  DCHECK(self);
  if(!self)
    return 0;

  return CefV8ValueCppToC::Get(self)->IsArray();
}

int CEF_CALLBACK v8value_is_function(struct _cef_v8value_t* self)
{
  DCHECK(self);
  if(!self)
    return 0;

  return CefV8ValueCppToC::Get(self)->IsFunction();
}

int CEF_CALLBACK v8value_get_bool_value(struct _cef_v8value_t* self)
{
  DCHECK(self);
  if(!self)
    return 0;

  return CefV8ValueCppToC::Get(self)->GetBoolValue();
}

int CEF_CALLBACK v8value_get_int_value(struct _cef_v8value_t* self)
{
  DCHECK(self);
  if(!self)
    return 0;

  return CefV8ValueCppToC::Get(self)->GetIntValue();
}

double CEF_CALLBACK v8value_get_double_value(struct _cef_v8value_t* self)
{
  DCHECK(self);
  if(!self)
    return 0;

  return CefV8ValueCppToC::Get(self)->GetDoubleValue();
}

cef_string_t CEF_CALLBACK v8value_get_string_value(struct _cef_v8value_t* self)
{
  DCHECK(self);
  if(!self)
    return 0;

  std::wstring valueStr = CefV8ValueCppToC::Get(self)->GetStringValue();
  if(!valueStr.empty())
    return cef_string_alloc(valueStr.c_str());
  return NULL;
}

int CEF_CALLBACK v8value_has_value_bykey(struct _cef_v8value_t* self,
    const wchar_t* key)
{
  DCHECK(self);
  if(!self)
    return 0;

  std::wstring keyStr;
  if(key)
    keyStr = key;

  return CefV8ValueCppToC::Get(self)->HasValue(keyStr);
}

int CEF_CALLBACK v8value_has_value_byindex(struct _cef_v8value_t* self,
    int index)
{
  DCHECK(self);
  if(!self)
    return 0;

  return CefV8ValueCppToC::Get(self)->HasValue(index);
}

int CEF_CALLBACK v8value_delete_value_bykey(struct _cef_v8value_t* self,
    const wchar_t* key)
{
  DCHECK(self);
  if(!self)
    return 0;

  std::wstring keyStr;
  if(key)
    keyStr = key;

  return CefV8ValueCppToC::Get(self)->DeleteValue(keyStr);
}

int CEF_CALLBACK v8value_delete_value_byindex(struct _cef_v8value_t* self,
    int index)
{
  DCHECK(self);
  if(!self)
    return 0;

  return CefV8ValueCppToC::Get(self)->DeleteValue(index);
}

struct _cef_v8value_t* CEF_CALLBACK v8value_get_value_bykey(
    struct _cef_v8value_t* self, const wchar_t* key)
{
  DCHECK(self);
  if(!self)
    return 0;

  std::wstring keyStr;
  if(key)
    keyStr = key;

  CefRefPtr<CefV8Value> valuePtr =
      CefV8ValueCppToC::Get(self)->GetValue(keyStr);
  return CefV8ValueCppToC::Wrap(valuePtr);
}

struct _cef_v8value_t* CEF_CALLBACK v8value_get_value_byindex(
    struct _cef_v8value_t* self, int index)
{
  DCHECK(self);
  if(!self)
    return 0;

  CefRefPtr<CefV8Value> valuePtr =
      CefV8ValueCppToC::Get(self)->GetValue(index);
  return CefV8ValueCppToC::Wrap(valuePtr);
}

int CEF_CALLBACK v8value_set_value_bykey(struct _cef_v8value_t* self,
    const wchar_t* key, struct _cef_v8value_t* value)
{
  DCHECK(self);
  if(!self)
    return 0;

  std::wstring keyStr;
  if(key)
    keyStr = key;

  CefRefPtr<CefV8Value> valuePtr = CefV8ValueCppToC::Unwrap(value);
  return CefV8ValueCppToC::Get(self)->SetValue(keyStr, valuePtr);
}

int CEF_CALLBACK v8value_set_value_byindex(struct _cef_v8value_t* self,
    int index, struct _cef_v8value_t* value)
{
  DCHECK(self);
  if(!self)
    return 0;

  CefRefPtr<CefV8Value> valuePtr = CefV8ValueCppToC::Unwrap(value);
  return CefV8ValueCppToC::Get(self)->SetValue(index, valuePtr);
}

int CEF_CALLBACK v8value_get_keys(struct _cef_v8value_t* self,
    cef_string_list_t keys)
{
  DCHECK(self);
  if(!self)
    return 0;

  std::vector<std::wstring> keysList;
  CefV8ValueCppToC::Get(self)->GetKeys(keysList);
  size_t size = keysList.size();
  for(size_t i = 0; i < size; ++i)
    cef_string_list_append(keys, keysList[i].c_str());
  return size;
}

cef_base_t* CEF_CALLBACK v8value_get_user_data(struct _cef_v8value_t* self)
{
  DCHECK(self);
  if(!self)
    return 0;

  CefRefPtr<CefBase> base = CefV8ValueCppToC::Get(self)->GetUserData();
  if(base.get())
    return CefBaseCToCpp::Unwrap(base);
  return NULL;
}

int CEF_CALLBACK v8value_get_array_length(struct _cef_v8value_t* self)
{
  DCHECK(self);
  if(!self)
    return 0;

  return CefV8ValueCppToC::Get(self)->GetArrayLength();
}

cef_string_t CEF_CALLBACK v8value_get_function_name(struct _cef_v8value_t* self)
{
  DCHECK(self);
  if(!self)
    return 0;

  std::wstring functionNameStr =
      CefV8ValueCppToC::Get(self)->GetFunctionName();
  if(!functionNameStr.empty())
    return cef_string_alloc(functionNameStr.c_str());
  return NULL;
}

cef_v8handler_t* CEF_CALLBACK v8value_get_function_handler(
    struct _cef_v8value_t* self)
{
  DCHECK(self);
  if(!self)
    return 0;

  CefRefPtr<CefV8Handler> handlerPtr =
      CefV8ValueCppToC::Get(self)->GetFunctionHandler();
  if(handlerPtr.get())
    return CefV8HandlerCToCpp::Unwrap(handlerPtr);
  return NULL;
}

int CEF_CALLBACK v8value_execute_function(struct _cef_v8value_t* self,
    struct _cef_v8value_t* object, size_t argumentCount,
    struct _cef_v8value_t* const* arguments, struct _cef_v8value_t** retval,
    cef_string_t* exception)
{
  DCHECK(self);
  DCHECK(object);
  if(!self || !object)
    return 0;

  CefRefPtr<CefV8Value> objectPtr = CefV8ValueCppToC::Unwrap(object);
  CefV8ValueList argsList;
  for(size_t i = 0; i < argumentCount; i++) {
    argsList.push_back(CefV8ValueCppToC::Unwrap(arguments[i]));
  }
  CefRefPtr<CefV8Value> retvalPtr;
  std::wstring exceptionStr;

  bool rv = CefV8ValueCppToC::Get(self)->ExecuteFunction(objectPtr,
      argsList, retvalPtr, exceptionStr);
  if(retvalPtr.get() && retval)
    *retval = CefV8ValueCppToC::Wrap(retvalPtr);
  if(!exceptionStr.empty() && exception)
    *exception = cef_string_alloc(exceptionStr.c_str());

  return rv;
}


// CONSTRUCTOR - Do not edit by hand.

CefV8ValueCppToC::CefV8ValueCppToC(CefV8Value* cls)
    : CefCppToC<CefV8ValueCppToC, CefV8Value, cef_v8value_t>(cls)
{
  struct_.struct_.is_undefined = v8value_is_undefined;
  struct_.struct_.is_null = v8value_is_null;
  struct_.struct_.is_bool = v8value_is_bool;
  struct_.struct_.is_int = v8value_is_int;
  struct_.struct_.is_double = v8value_is_double;
  struct_.struct_.is_string = v8value_is_string;
  struct_.struct_.is_object = v8value_is_object;
  struct_.struct_.is_array = v8value_is_array;
  struct_.struct_.is_function = v8value_is_function;
  struct_.struct_.get_bool_value = v8value_get_bool_value;
  struct_.struct_.get_int_value = v8value_get_int_value;
  struct_.struct_.get_double_value = v8value_get_double_value;
  struct_.struct_.get_string_value = v8value_get_string_value;
  struct_.struct_.has_value_bykey = v8value_has_value_bykey;
  struct_.struct_.has_value_byindex = v8value_has_value_byindex;
  struct_.struct_.delete_value_bykey = v8value_delete_value_bykey;
  struct_.struct_.delete_value_byindex = v8value_delete_value_byindex;
  struct_.struct_.get_value_bykey = v8value_get_value_bykey;
  struct_.struct_.get_value_byindex = v8value_get_value_byindex;
  struct_.struct_.set_value_bykey = v8value_set_value_bykey;
  struct_.struct_.set_value_byindex = v8value_set_value_byindex;
  struct_.struct_.get_keys = v8value_get_keys;
  struct_.struct_.get_user_data = v8value_get_user_data;
  struct_.struct_.get_array_length = v8value_get_array_length;
  struct_.struct_.get_function_name = v8value_get_function_name;
  struct_.struct_.get_function_handler = v8value_get_function_handler;
  struct_.struct_.execute_function = v8value_execute_function;
}

#ifdef _DEBUG
long CefCppToC<CefV8ValueCppToC, CefV8Value, cef_v8value_t>::DebugObjCt = 0;
#endif

