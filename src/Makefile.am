## Process this file with automake to produce Makefile.in

localedir   = $(prefix)/$(DATADIRNAME)/locale

INCLUDES = -I. -I$(srcdir) -I$(top_builddir) @GTK_CFLAGS@ @YAZINC@
DEFS = -DLOCALEDIR=\"$(localedir)\" @DEFS@

bin_PROGRAMS = eta

eta_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	z3950.c z3950.h

eta_LDADD = @GTK_LIBS@ @YAZLIB@ @INTLLIBS@
