lib_LTLIBRARIES = libgumbo_xml.la
libgumbo_xml_la_CFLAGS = -Wall
libgumbo_xml_la_CPPFLAGS = -I"$(srcdir)" $(GUMBO_CFLAGS) $(XML_CFLAGS)
libgumbo_xml_la_LDFLAGS = -version-info 1:0:0 -no-undefine
libgumbo_xml_la_LIBADD = $(GUMBO_LIBS) $(XML_LIBS)
libgumbo_xml_la_SOURCES = gumbo_libxml.c gumbo_libxml.h
include_HEADERS = gumbo_libxml.h

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = gumbo_libxml.pc

noinst_PROGRAMS = example
example_SOURCES = example.c
example_CPPFLAGS = -I"$(srcdir)" $(XML_CFLAGS)
example_LDADD = libgumbo_xml.la $(XML_LIBS)
