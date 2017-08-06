AUTOMAKE_OPTIONS = gnu

SUBDIRS= src

EXTRA_DIST = 			\
	libstress.pc.in	\
	autogen.sh		\
	autoclean.sh		\
	HISTORY

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libstress.pc

$(pkgconfig_DATA): config.status
