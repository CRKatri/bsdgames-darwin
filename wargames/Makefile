#	$NetBSD: Makefile,v 1.10 2000/01/25 21:41:18 drochner Exp $
#	@(#)Makefile	8.1 (Berkeley) 5/31/93

SCRIPTS=wargames.sh
MAN=	wargames.6

all:

install: $(MAN) $(SCRIPTS)
	$(GINSTALL) -Dm755 $(SCRIPTS) $(DESTDIR)/usr/games/$(basename $(SCRIPTS))
	$(GINSTALL) -Dm644 $(MAN) $(DESTDIR)/usr/share/man/man6/$(MAN)

.PHONY: all install clean
