#	$NetBSD: Makefile,v 1.1 2005/06/30 13:30:33 perry Exp $

PROG=	castching
SRCS=	castching.c
BINDIR=	$(PREFIX)/libexec/ching

all: $(PROG)

$(PROG): $(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) -I../include
	$(STRIP) $(PROG)

install: $(PROG)
	$(GINSTALL) -Dm755 $(PROG) $(DESTDIR)/$(BINDIR)/$(PROG)

clean:
	rm -f $(CLEANFILES) $(PROG)

.PHONY: all clean install
