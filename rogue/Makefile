#	$NetBSD: Makefile,v 1.21 2019/10/13 07:28:09 mrg Exp $
#	@(#)Makefile	8.1 (Berkeley) 5/31/93

PROG=	rogue
CPPFLAGS+=-DUNIX
SRCS=	hit.c init.c inventory.c level.c machdep.c main.c \
	message.c monster.c move.c object.c pack.c play.c random.c ring.c \
	room.c save.c score.c spec_hit.c throw.c trap.c use.c zap.c
MAN=	rogue.6

all: $(PROG)

$(PROG): $(SRCS)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $(PROG) $(SRCS) -lncursesw -I$(ROOT)
	$(STRIP) $(PROG)

install: $(PROG) $(MAN)
	$(GINSTALL) -Dm2755 $(PROG) $(DESTDIR)/$(PREFIX)/games/$(PROG)
	$(GINSTALL) -Dm644 $(MAN) $(DESTDIR)/$(PREFIX)/share/man/man6/$(MAN)
	$(GINSTALL) -d $(DESTDIR)/$(LOCALSTATEDIR)/games

clean:
	rm -f $(CLEANFILES) $(PROG)

.PHONY: all clean install
