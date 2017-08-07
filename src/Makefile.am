AUTOMAKE_OPTIONS = no-dependencies foreign

SUBDIRS = 

DEFS = 	 $(CFLAGS) $(GLIB2_CFLAGS)

libdir=$(exec_prefix)/lib
includedir=$(prefix)/include

headerfiles = 			\
	include/libstress.h	

lib_LTLIBRARIES = libstress.la
include_HEADERS = $(headerfiles)
libstress_la_LDFLAGS = -version 0:0:1 -no-undefined -module -export-dynamic 
libstress_la_LIBADD = $(GLIB2_LIBS) $(LDFLAGS)

libstress_la_SOURCES = 	\
	libstress.c     \
	$(headerfiles)
