AM_CFLAGS := -Wundef \
        -Wstrict-prototypes \
        -Wno-trigraphs \
        -g -O0 \
        -fno-inline \
        -fno-short-enums \
        -fpic

AM_CPPFLAGS := \
              -I. \
	      -USE_GLIB

AM_LDFLAGS := -shared -version-info 1:0:0

min_c_sources := \
        mounts.c \
        mtdutils.c

h_sources := \
        mounts.h \
        mtdutils.h

library_includedir := $(pkgincludedir)
library_include_HEADERS := $(h_sources)

lib_LTLIBRARIES := libmtdutils.la
libmtdutils_la_SOURCES := $(min_c_sources) $(h_sources)

if USE_GLIB
libmtdutils_la_CFLAGS := $(AM_CFLAGS) -DUSE_GLIB @GLIB_CFLAGS@
libmtdutils_la_CPPFLAGS := $(AM_CPPFLAGS) -DUSE_GLIB @GLIB_CFLAGS@
libmtdutils_la_LIBADD := -lm -lpthread @GLIB_LIBS@
libmtdutils_la_LDFLAGS := -all-static
else
libmtdutils_la_CFLAGS := $(AM_CFLAGS)
libmtdutils_la_CPPFLAGS := $(AM_CPPFLAGS)
libmtdutils_la_LIBADD := -lm -lpthread
libmtdutils_la_LDFLAGS := -all-static
endif
