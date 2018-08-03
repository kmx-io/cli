AC_PREREQ([2.59])
AC_INIT([cli], [0.1.0], [kmx.io], [cli], [http://kmx.io])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([build-aux/m4])
AC_CONFIG_SRCDIR([cli.c])
AC_CONFIG_HEADERS([config.h:config.h.in])

AM_INIT_AUTOMAKE
AM_PROG_AR

AC_PROG_CC

LT_INIT

LIBS="-lreadline -ltermcap"

AC_CHECK_LIB([readline], [readline],,
             AC_MSG_ERROR(missing readline library))
AC_CHECK_LIB([termcap], [tputs],,
             AC_MSG_ERROR(missing termcap library))

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
