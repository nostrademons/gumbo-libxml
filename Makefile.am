lib_LTLIBRARIES = libgumbo_xml.la
libgumbo_xml_la_CFLAGS = -Wall
libgumbo_xml_la_LDFLAGS = -version-info 1:0:0 -no-undefined
libgumbo_xml_la_SOURCES = gumbo_libxml.c gumbo_libxml.h
include_HEADERS = gumbo_libxml.h

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = gumbo_libxml.pc

AM_CPPFLAGS = -I"$(srcdir)" $(GUMBO_CFLAGS) $(XML_CFLAGS)
AM_LDFLAGS = $(GUMBO_LIBS) $(XML_LIBS)
