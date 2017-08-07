AC_PREREQ(2.59)

AC_INIT([LIBSTRESS], [0.0.1],
        [Olivier Delhomme],
        [libstress])

AC_PROG_CC
AC_CONFIG_MACRO_DIR([m4])
AC_PROG_INTLTOOL([0.23])

AM_INIT_AUTOMAKE
AM_MAINTAINER_MODE
AM_SILENT_RULES([yes])


dnl Libraries requirements
GLIB_VERSION=2.2.0
AC_SUBST(GLIB_VERSION)


dnl Put the preprocessor macros in a header instead of command line 
AC_CONFIG_HEADER([config.h])
AC_CONFIG_SRCDIR([src/libstress.c])

dnl Checks for headers
AC_CHECK_HEADERS([errno.h fnctl.h glib.h stdio.h stdlib.h sys/types.h unistd.h])

dnl Checks for programs
AM_PROG_LIBTOOL

dnl ********************************************************
dnl languages
dnl ********************************************************
ALL_LINGUAS="fr"


dnl ********************************************************
dnl triggers gettext
dnl ********************************************************
GETTEXT_PACKAGE=libstress
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE, "$GETTEXT_PACKAGE", [Gettext package used])
AM_GLIB_GNU_GETTEXT


dnl *******************************
dnl checking for glib
dnl *******************************
PKG_CHECK_MODULES(GLIB, [glib-2.0 >= $GLIB_VERSION])

AC_PROG_INSTALL

CFLAGS="$CFLAGS -Wall -Wstrict-prototypes -Wmissing-declarations \
-Wbad-function-cast -Wcast-qual -Wcast-align -Wnested-externs -Wunused \
-D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE"

case $host in
    *freebsd*)
	AC_DEFINE_UNQUOTED(SYS_FREEBSD,1,[This is a FreeBSD system])
	AC_DEFINE_UNQUOTED(SYS_POSIX,1,[This is a Posix system])
	;;	
    *linux*)
	AC_DEFINE_UNQUOTED(SYS_LINUX,1,[This is a Linux system])
	AC_DEFINE_UNQUOTED(SYS_POSIX,1,[This is a Posix system])
	;;
    *mingw*)
	AC_DEFINE_UNQUOTED(SYS_MINGW,1,[This is a MinGW system])
     	AC_DEFINE_UNQUOTED(WINDOWS,1,[This is a Windows system])
     	AC_DEFINE_UNQUOTED(_WIN32,1,[This is a Windows system])
        CFLAGS="$CFLAGS -mms-bitfields -mwindows -mno-cygwin"
        ;;
esac

AC_SUBST(LDFLAGS)
AC_SUBST(CFLAGS)
AC_SUBST(GLIB_CFLAGS)
AC_SUBST(GLIB_LIBS)

AC_CONFIG_FILES([
Makefile 
src/Makefile 
po/Makefile.in
libstress.pc
])

AC_OUTPUT

AC_MSG_NOTICE([

 *** Flags that will be used to compile cdpfgl ***

    CFLAGS         : ${CFLAGS}
    LDFLAGS        : ${LDFLAGS}

    GLIB CFLAGS    : ${GLIB_CFLAGS}
    GLIB LIBS      : ${GLIB_LIBS}


 *** Dumping configuration ***"
 
    - Host                   : $host"
    - Compiler               : ${CC}"
    - Prefix                 : $prefix"
    - Exec prefix            : $exec_prefix"
    - Data dir               : $datadir"

You can now run 'make' to compile libstress"

])
