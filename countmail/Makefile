#	$NetBSD: Makefile,v 1.3 1999/02/13 23:53:57 lukem Exp $

SCRIPTS=	countmail
MAN=		countmail.6

all:

install: $(PROG) $(MAN) $(SCRIPTS)
	$(GINSTALL) -Dm755 $(SCRIPTS) $(DESTDIR)/$(PREFIX)/games/$(SCRIPTS)
	$(GINSTALL) -Dm644 $(MAN) $(DESTDIR)/$(PREFIX)/share/man/man6/$(MAN)

.PHONY: all install clean
