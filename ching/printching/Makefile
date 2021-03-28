#	$NetBSD: Makefile,v 1.1 2005/06/30 13:30:33 perry Exp $

PROG=	printching
SRCS=	printching.c

all: $(PROG)

$(PROG): $(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) -I../include -I$(ROOT)
	$(STRIP) $(PROG)

install: $(PROG)
	$(GINSTALL) -Dm755 $(PROG) $(DESTDIR)/$(PREFIX)/libexec/ching/$(PROG)

clean:
	rm -f $(CLEANFILES) $(PROG)

.PHONY: all clean install
