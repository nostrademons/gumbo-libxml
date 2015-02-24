#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.65])
AC_INIT([gumbo_libxml], [0.9.0], [jonathan.d.tang@gmail.com])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([gumbo_libxml.c])
#AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile gumbo_libxml.pc])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC_C99

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stddef.h stdlib.h string.h strings.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_INLINE
AC_TYPE_SIZE_T

# Checks for library dependencies.
PKG_CHECK_MODULES(GUMBO, gumbo >= 0.10)
PKG_CHECK_MODULES(XML, libxml-2.0 >= 2.9)

# Init Automake & libtool
AM_INIT_AUTOMAKE([foreign subdir-objects])
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])
LT_INIT

AC_OUTPUT
