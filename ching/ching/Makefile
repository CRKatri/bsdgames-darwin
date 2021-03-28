#	$NetBSD: Makefile,v 1.2 2008/10/30 21:37:55 mrg Exp $

SCRIPTS=ching.sh
MAN=	ching.6

FILES=	hexagrams macros
FILESDIR=$(PREFIX)/share/games/ching

all:

install: $(PROG) $(MAN) $(SCRIPTS)
	$(GINSTALL) -Dm755 $(SCRIPTS) $(DESTDIR)/$(PREFIX)/games/$(basename $(SCRIPTS))
	$(GINSTALL) -Dm644 $(MAN) $(DESTDIR)/$(PREFIX)/share/man/man6/$(MAN)
	$(GINSTALL) -d $(DESTDIR)$(FILESDIR)
	$(GINSTALL) -Dm644 $(FILES) $(DESTDIR)$(FILESDIR)

.PHONY: all install clean
