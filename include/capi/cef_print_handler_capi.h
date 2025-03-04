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
// This file was generated by the CEF translator tool and should not edited
// by hand. See the translator.README.txt file in the tools directory for
// more information.
//

#ifndef _CEF_PRINT_HANDLER_CAPI_H
#define _CEF_PRINT_HANDLER_CAPI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "cef_base_capi.h"


///
// Implement this structure to handle events related to printing. The functions
// of this structure will be called on the UI thread.
///
typedef struct _cef_print_handler_t
{
  ///
  // Base structure.
  ///
  cef_base_t base;

  ///
  // Called to allow customization of standard print options before the print
  // dialog is displayed. |printOptions| allows specification of paper size,
  // orientation and margins. Note that the specified margins may be adjusted if
  // they are outside the range supported by the printer. All units are in
  // inches. Return false (0) to display the default print options or true (1)
  // to display the modified |printOptions|.
  ///
  int (CEF_CALLBACK *get_print_options)(struct _cef_print_handler_t* self,
      struct _cef_browser_t* browser,
      struct _cef_print_options_t* printOptions);

  ///
  // Called to format print headers and footers. |printInfo| contains platform-
  // specific information about the printer context. |url| is the URL if the
  // currently printing page, |title| is the title of the currently printing
  // page, |currentPage| is the current page number and |maxPages| is the total
  // number of pages. Six default header locations are provided by the
  // implementation: top left, top center, top right, bottom left, bottom center
  // and bottom right. To use one of these default locations just assign a
  // string to the appropriate variable. To draw the header and footer yourself
  // return true (1). Otherwise, populate the approprate variables and return
  // false (0).
  ///
  int (CEF_CALLBACK *get_print_header_footer)(struct _cef_print_handler_t* self,
      struct _cef_browser_t* browser, struct _cef_frame_t* frame,
      const struct _cef_print_info_t* printInfo, const cef_string_t* url,
      const cef_string_t* title, int currentPage, int maxPages,
      cef_string_t* topLeft, cef_string_t* topCenter, cef_string_t* topRight,
      cef_string_t* bottomLeft, cef_string_t* bottomCenter,
      cef_string_t* bottomRight);

} cef_print_handler_t;


#ifdef __cplusplus
}
#endif

#endif // _CEF_PRINT_HANDLER_CAPI_H
