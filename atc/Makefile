#	$NetBSD: Makefile,v 1.30 2011/08/16 10:14:40 christos Exp $
#	@(#)Makefile	8.1 (Berkeley) 5/31/93

PROG=	atc
SRCS=	extern.c graphics.c input.c list.c log.c \
	main.c tunable.c update.c
MAN=	atc.6
FILES=${GAMES:S@^@${.CURDIR}/games/@g}
FILESDIR=/usr/share/games/atc
FILESMODE=644

all: $(PROG)

$(PROG): $(SRCS) grammar.y lex.l
	yacc -d grammar.y -o grammar.c
	lex lex.l
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(PROG) $(SRCS) grammar.c lex.yy.c -lncursesw $(LIBFLA)
	$(STRIP) $(PROG)

install: $(PROG) $(MAN)
	$(GINSTALL) -Dm2755 $(PROG) $(DESTDIR)/usr/games/$(PROG)
	$(GINSTALL) -Dm644 $(MAN) $(DESTDIR)/usr/share/man/man6/$(MAN)
	mkdir -p $(DESTDIR)/usr/share/games
	cp -r games $(DESTDIR)/usr/share/games/atc
	chmod -R 644 $(DESTDIR)/usr/share/games/atc/*
	mkdir -p $(DESTDIR)/var/games/


clean:
	rm -f $(CLEANFILES) $(PROG) grammar.c grammar.h lex.yy.c

.PHONY: all clean install
