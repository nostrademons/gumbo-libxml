# gumbo-libxml
LibXML2 bindings for the Gumbo HTML5 parser

This provides a libxml2 API on top of the Gumbo parser.  It lets you use a
modern parser - Gumbo now passes all html5lib tests, including the template tag,
and should be fully conformant with the HTML5 spec - with the full ecosystem of
libxml tools, including XPath, tree modification, DTD validation, etc.

## Installation and dependencies

These bindings depend upon both [Gumbo][] and [libxml2][], and assume you
already have them installed.  At present they require Gumbo v0.10.0, which
hasn't yet been officially released but is available as a branch within the
GitHub repository.

To build and install the library, issue the standard UNIX incantation from
the root of the distribution:

```bash
$ ./autogen.sh
$ ./configure
$ make
$ sudo make install
```

pkg-config works too:

```bash
$ pkg-config --cflags gumbo_libxml         # print compiler flags
$ pkg-config --libs gumbo_libxml           # print linker flags
$ pkg-config --cflags --libs gumbo_libxml  # print both
```

For example:

```bash
$ gcc my_program.c `pkg-config --cflags --libs gumbo_libxml`
```

There is an example program, example.c, inside the distribution that illustrates
how you might use gumbo-libxml to parse an HTML document, remove script and
style tags, and pretty-print it back out to stdout.

## Usage

The main entry point you'll probably want is gumbo_libxml_parse:

```C
#include "gumbo_libxml.h"
#include "libxml_tree.h"

const char* input = "...";
xmlDocPtr doc = gumbo_libxml_parse(input);
xmlFreeDoc(doc);
```

You can use any libxml2 functions on the resulting doc, including third-party
software that's built to work with libxml2.  The caller is responsible for
deleting libxml trees built this way, both for this function and others in the
library.  The library handles deletion of the Gumbo objects in the intermediate
parse tree.

If you need to tweak Gumbo options, there's also a version that functions like
gumbo_parse_with_options:

```C
#include "gumbo.h"
#include "gumbo_libxml.h"
#include "libxml_tree.h"

const char* input = "...";
GumboOptions options;
options.tab_stop = 2;
xmlDocPtr doc = gumbo_libxml_parse_with_options(&options, input, strlen(input));
xmlFreeDoc(doc);
```

[Gumbo]: https://github.com/google/gumbo-parser
[libxml2]: http://xmlsoft.org/
