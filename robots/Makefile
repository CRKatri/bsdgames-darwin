#	$NetBSD: Makefile,v 1.16 2010/02/06 23:45:25 he Exp $
#	@(#)Makefile	8.1 (Berkeley) 5/31/93

PROG=	robots
CPPFLAGS+=-DMAX_PER_UID=5
SRCS=	auto.c extern.c init_field.c main.c make_level.c move.c move_robs.c \
	play_level.c query.c rnd_pos.c score.c flush_in.c
MAN=	robots.6

all: $(PROG)

$(PROG): $(SRCS)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $(PROG) $(SRCS) -lncursesw
	$(STRIP) $(PROG)

install: $(PROG) $(MAN)
	$(GINSTALL) -Dm2755 $(PROG) $(DESTDIR)/usr/games/$(PROG)
	$(GINSTALL) -Dm644 $(MAN) $(DESTDIR)/usr/share/man/man6/$(MAN)
	$(GINSTALL) -d $(DESTDIR)/var/games

clean:
	rm -f $(CLEANFILES) $(PROG)

.PHONY: all clean install
