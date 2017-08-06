AC_PREREQ(2.59)

AC_INIT([LIBSTRESS], [0.0.1],
        [Olivier Delhomme],
        [libstress])
AC_CONFIG_HEADER([config.h])
AM_INIT_AUTOMAKE([$PACKAGE_TARNAME], [$PACKAGE_VERSION])

dnl directory requirement
TOP_DIR=`pwd`
SRC_DIR="${TOP_DIR}/src"
AC_SUBST(TOP_DIR)
AC_SUBST(SRC_DIR)

dnl Libraries requirements
GLIB2_VERSION=2.2.0
AC_SUBST(GLIB2_VERSION)


AM_MAINTAINER_MODE

dnl Put the preprocessor macros in a header instead of command line 
AC_CONFIG_SRCDIR([src/libstress.c])

dnl Checks for headers
AC_HEADER_STDC
AC_HEADER_DIRENT
AC_CHECK_HEADERS([stdlib.h string.h sys/time.h unistd.h])

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_TYPE_SIGNAL
AC_STRUCT_TM

dnl Checks for library functions.
AC_FUNC_STAT
AC_FUNC_STRFTIME
AC_FUNC_VPRINTF
AC_CHECK_FUNCS(gettimeofday select socket strdup strerror strstr)

dnl dynamic libraries/plugins
dnl Checks for programs

AM_PROG_LIBTOOL

if test "x$prefix" = "xNONE"; then
	prefix="/usr/local"
fi

if test "x$localstatedir" = "x\${prefix}/var"; then
	localstatedir="$prefix/var"
fi

if test "x$sysconfdir" = "x\${prefix}/etc"; then
    sysconfdir="$prefix/etc"
fi

AC_SUBST(localstatedir)

dnl ********************************************************
dnl languages
dnl ********************************************************
ALL_LINGUAS="fr_FR en_GB"

dnl ********************************************************
dnl triggers gettext
dnl ********************************************************
AM_GLIB_GNU_GETTEXT
GETTEXT_PACKAGE=libstress
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE,"$GETTEXT_PACKAGE",[fix])

dnl *******************************
dnl checking for glib
dnl *******************************
PKG_CHECK_MODULES(GLIB2,[glib-2.0 >= $GLIB2_VERSION])

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
AC_SUBST(GLIB2_CFLAGS)
AC_SUBST(GLIB2_LIBS)

AC_CONFIG_FILES([Makefile src/Makefile libstress.pc])
AC_OUTPUT


echo
echo "*** Dumping configuration ***"
echo 
echo "    - Host                   : $host"
echo "    - Compiler               : ${CC}"
echo "    - Prefix                 : $prefix"
echo "    - Exec prefix            : $exec_prefix"
echo "    - Data dir               : $datadir"
echo
echo "    You can now run 'make' to compile libstress"
echo
