// Copyright 2015 Jonathan Tang (jonathan.d.tang@gmail.com). All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "gumbo_libxml.h"

#include "gumbo.h"
#include "libxml/tree.h"

xmlDocPtr gumbo_libxml_parse(
    const GumboOptions* options, const char* buffer, size_t buffer_length) {
  xmlDocPtr doc = xmlNewDoc(BAD_CAST "1.0");
  GumboOutput* output = gumbo_parse_with_options(options, buffer, buffer_length);
  // TODO: convert tree
  gumbo_destroy_output(options, output);
  return doc;
}

