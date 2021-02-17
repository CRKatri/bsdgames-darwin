#	$NetBSD: Makefile,v 1.3 1999/02/13 23:53:57 lukem Exp $

SCRIPTS=	countmail
SCRIPTSDIR=	/usr/games
MAN=		countmail.6

all:

install: $(PROG) $(MAN) $(SCRIPTS)
	$(GINSTALL) -Dm755 $(SCRIPTS) $(DESTDIR)/usr/games/$(SCRIPTS)
	$(GINSTALL) -Dm644 $(MAN) $(DESTDIR)/usr/share/man/man6/$(MAN)

.PHONY: all install clean
