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

#ifndef GUMBO_LIBXML_H_
#define GUMBO_LIBXML_H_

#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _xmlDoc *xmlDocPtr;
typedef struct _xmlNode *xmlNodePtr;
typedef struct GumboInternalOptions GumboOptions;
typedef struct GumboInternalNode GumboNode;

xmlDocPtr gumbo_libxml_parse(const char* buffer);

xmlDocPtr gumbo_libxml_parse_with_options(
    GumboOptions*, const char* buffer, size_t buffer_length);

#ifdef __cplusplus
}
#endif

#endif  // GUMBO_LIBXML_H_
