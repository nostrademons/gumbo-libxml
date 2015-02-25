// Copyright 2013 Google Inc. All Rights Reserved.
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
//

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "gumbo_libxml.h"
#include "libxml/tree.h"
#include "libxml/xpath.h"

static void read_file(FILE* fp, char** output, int* length) {
  struct stat filestats;
  int fd = fileno(fp);
  fstat(fd, &filestats);
  *length = filestats.st_size;
  *output = malloc(*length + 1);
  int start = 0;
  int bytes_read;
  while ((bytes_read = fread(*output + start, 1, *length - start, fp))) {
    start += bytes_read;
  }
}

static void delete_nodes(xmlDocPtr doc, const char* xpath_expr) {
  xmlXPathContextPtr xpath_ctx = xmlXPathNewContext(doc);
  if (xpath_ctx == NULL) {
    fprintf(stderr, "Error: unable to create new XPath context.\n");
    return;
  }
  xmlXPathObjectPtr xpath_obj = xmlXPathEvalExpression(xpath_expr, xpath_ctx);
  if (xpath_obj == NULL) {
    fprintf(stderr, "Error: unable to create new XPath context.\n");
    xmlXPathFreeContext(xpath_ctx);
    return;
  }

  // It's often tricky to combine mutations and XPath in the same pass, because
  // XPath may select descendant nodes that are eliminated by the mutation.  For
  // this reason, you may want to iterate in reverse document order so that
  // children are mutated before they're thrown away.  In this particular
  // example, it doesn't matter since all the tags we scrub don't have children,
  // but see the note in:
  // http://www.xmlsoft.org/examples/xpath2.c
  for (int i = xpath_obj->nodesetval->nodeNr - 1; i >= 0; i--) {
    xmlNodePtr node = xpath_obj->nodesetval->nodeTab[i];
    xmlUnlinkNode(node);
    xmlFreeNode(node);
  }

  xmlXPathFreeObject(xpath_obj);
  xmlXPathFreeContext(xpath_ctx);
}

int main(int argc, const char** argv) {
  if (argc != 2) {
    printf("Usage: get_title <html filename>.\n");
    exit(EXIT_FAILURE);
  }
  const char* filename = argv[1];

  FILE* fp = fopen(filename, "r");
  if (!fp) {
    printf("File %s not found!\n", filename);
    exit(EXIT_FAILURE);
  }

  char* input;
  int input_length;
  read_file(fp, &input, &input_length);
  xmlDocPtr doc = gumbo_libxml_parse(input);
  delete_nodes(doc, "//script");
  delete_nodes(doc, "//style");
  delete_nodes(doc, "//link[@rel='stylesheet']");
  delete_nodes(doc, "//@style");
  delete_nodes(doc, "//@onload");
  delete_nodes(doc, "//@onclick");
  delete_nodes(doc, "//@onmousedown");
  delete_nodes(doc, "//@onmouseover");
  // Etc, this is not an exhaustive HTML scrubber.
  xmlSaveFormatFile("-", doc, 1);
  xmlFreeDoc(doc);
}
