#	$NetBSD: Makefile,v 1.37 2014/06/14 20:49:37 mrg Exp $
#	@(#)Makefile	8.1 (Berkeley) 5/31/93

PROG=	phantasia
SRCS=	fight.c gamesupport.c interplayer.c io.c main.c misc.c phantglobs.c
MAN=	phantasia.6

FILESDIR=$(LOCALSTATEDIR)/games/phantasia
FILESMODE=0660
ALLFILES=gold lastdead mess monsters void motd characs scoreboard
FILES=gold lastdead mess monsters void motd

CLEANFILES+=map mkdata $(ALLFILES) files.stamp

all: $(PROG) $(FILES)

$(FILES): files.stamp
files.stamp: mkdata monsters.asc
	rm -f files.stamp
	./mkdata -m monsters.asc
	touch files.stamp

mkdata: phantglobs.c setup.c
	clang -o mkdata phantglobs.c setup.c -I$(ROOT)

# Make Phantasia map.  Change the map commands reflect your installation.
# PLOTDEVICE is used for plotting the map.  Change as appropriate.

map: map.c
	clang -o map map.c -lplot
	./map | plot > /dev/tty

$(PROG): $(SRCS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(PROG) $(SRCS) -lncursesw -I$(ROOT)
	$(STRIP) $(PROG)

$(ALLFILES): files.stamp

install: $(PROG) $(MAN) $(ALLFILES)
	$(GINSTALL) -Dm2755 $(PROG) $(DESTDIR)/$(PREFIX)/games/$(PROG)
	$(GINSTALL) -Dm644 $(MAN) $(DESTDIR)/$(PREFIX)/share/man/man6/$(MAN)
	$(GINSTALL) -d $(DESTDIR)$(FILESDIR)
	$(GINSTALL) -Dm$(FILESMODE) $(ALLFILES) $(DESTDIR)$(FILESDIR)

clean:
	rm -f $(CLEANFILES) $(PROG)

.PHONY: all clean install
