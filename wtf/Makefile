#	$NetBSD: Makefile,v 1.1 1999/07/22 01:03:20 mrg Exp $

SCRIPTS=	wtf
MAN=		wtf.6

all:

install: $(MAN) $(SCRIPTS)
	$(GINSTALL) -Dm755 $(SCRIPTS) $(DESTDIR)/usr/games/$(basename $(SCRIPTS))
	$(GINSTALL) -Dm644 $(MAN) $(DESTDIR)/usr/share/man/man6/$(MAN)

.PHONY: all install clean
