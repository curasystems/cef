// Copyright (c) 2011 Marshall A. Greenblatt. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//    * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//    * Neither the name of Google Inc. nor the name Chromium Embedded
// Framework nor the names of its contributors may be used to endorse
// or promote products derived from this software without specific prior
// written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// ---------------------------------------------------------------------------
//
// The contents of this file must follow a specific format in order to
// support the CEF translator tool. See the translator.README.txt file in the
// tools directory for more information.
//

#ifndef _CEF_COMMAND_LINE_H
#define _CEF_COMMAND_LINE_H

#include "cef_base.h"
#include <map>
#include <vector>

///
// Class used to create and/or parse command line arguments. Arguments with
// '--', '-' and, on Windows, '/' prefixes are considered switches. Switches
// will always precede any arguments without switch prefixes. Switches can
// optionally have a value specified using the '=' delimiter (e.g. 
// "-switch=value"). An argument of "--" will terminate switch parsing with all
// subsequent tokens, regardless of prefix, being interpreted as non-switch
// arguments. Switch names are considered case-insensitive. This class can be
// used before CefInitialize() is called.
///
/*--cef(source=library,no_debugct_check)--*/
class CefCommandLine : public virtual CefBase
{
public:
  typedef std::vector<CefString> ArgumentList;
  typedef std::map<CefString,CefString> SwitchMap;

  ///
  // Create a new CefCommandLine instance.
  ///
  /*--cef(revision_check)--*/
  static CefRefPtr<CefCommandLine> CreateCommandLine();

  ///
  // Initialize the command line with the specified |argc| and |argv| values.
  // The first argument must be the name of the program. This method is only
  // supported on non-Windows platforms.
  ///
  /*--cef()--*/
  virtual void InitFromArgv(int argc, const char* const* argv) =0;

  ///
  // Initialize the command line with the string returned by calling
  // GetCommandLineW(). This method is only supported on Windows.
  ///
  /*--cef()--*/
  virtual void InitFromString(const CefString& command_line) =0;

  ///
  // Constructs and returns the represented command line string. Use this method
  // cautiously because quoting behavior is unclear.
  ///
  /*--cef()--*/
  virtual CefString GetCommandLineString() =0;

  ///
  // Get the program part of the command line string (the first item).
  ///
  /*--cef()--*/
  virtual CefString GetProgram() =0;

  ///
  // Set the program part of the command line string (the first item).
  ///
  /*--cef()--*/
  virtual void SetProgram(const CefString& program) =0;

  ///
  // Returns true if the command line has switches.
  ///
  /*--cef()--*/
  virtual bool HasSwitches() =0;

  ///
  // Returns true if the command line contains the given switch.
  ///
  /*--cef()--*/
  virtual bool HasSwitch(const CefString& name) =0;

  ///
  // Returns the value associated with the given switch. If the switch has no
  // value or isn't present this method returns the empty string.
  ///
  /*--cef()--*/
  virtual CefString GetSwitchValue(const CefString& name) =0;

  ///
  // Returns the map of switch names and values. If a switch has no value an 
  // empty string is returned.
  ///
  /*--cef()--*/
  virtual void GetSwitches(SwitchMap& switches) =0;

  ///
  // Add a switch to the end of the command line. If the switch has no value
  // pass an empty value string.
  ///
  /*--cef()--*/
  virtual void AppendSwitch(const CefString& name) =0;

  ///
  // Add a switch with the specified value to the end of the command line.
  ///
  /*--cef()--*/
  virtual void AppendSwitchWithValue(const CefString& name,
                                     const CefString& value) =0;

  ///
  // True if there are remaining command line arguments.
  ///
  /*--cef()--*/
  virtual bool HasArguments() =0;

  ///
  // Get the remaining command line arguments.
  ///
  /*--cef()--*/
  virtual void GetArguments(ArgumentList& arguments) =0;

  ///
  // Add an argument to the end of the command line.
  ///
  /*--cef()--*/
  virtual void AppendArgument(const CefString& argument) =0;
};

#endif // _CEF_COMMAND_LINE_H
