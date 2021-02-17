#	$NetBSD: Makefile,v 1.9 2020/09/06 10:51:20 mrg Exp $
#	@(#)Makefile	8.1 (Berkeley) 5/31/93

PROG=	tetris
SRCS=	input.c screen.c shapes.c scores.c tetris.c
MAN=	tetris.6

all: $(PROG)

$(PROG): $(SRCS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(PROG) $(SRCS) -lncursesw
	$(STRIP) $(PROG)

install: $(PROG) $(MAN)
	$(GINSTALL) -Dm2755 $(PROG) $(DESTDIR)/usr/games/$(PROG)
	$(GINSTALL) -Dm644 $(MAN) $(DESTDIR)/usr/share/man/man6/$(MAN)
	$(GINSTALL) -d $(DESTDIR)/var/games

clean:
	rm -f $(CLEANFILES) $(PROG)

.PHONY: all clean install
