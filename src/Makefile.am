## Process this file with automake to produce Makefile.in

localedir   = $(prefix)/$(DATADIRNAME)/locale

DEFS = -DLOCALEDIR=\"$(localedir)\" @DEFS@
INCLUDES = -I. -I$(srcdir) -I$(top_builddir) @GTK_CFLAGS@ @YAZINC@ @XML_CFLAGS@

bin_PROGRAMS = eta
# noinst_PROGRAMS = dblist

eta_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	z3950.c z3950.h \
	dblist.c dblist.h

# dblist_SOURCES = dblist.c dblist.h

eta_LDADD = @YAZLIB@ @GTK_LIBS@ @YAZLIB@ @INTLLIBS@ @XML_LIBS@
# dblist_LDADD = @GTK_LIBS@ @XML_LIBS@
