#	$NetBSD: Makefile,v 1.18 2011/08/25 15:50:45 joerg Exp $
#	@(#)Makefile	8.1 (Berkeley) 5/31/93

PROG=	sail
SRCS=	main.c pl_main.c pl_1.c pl_2.c pl_3.c pl_4.c pl_5.c pl_6.c pl_7.c \
	dr_main.c dr_1.c dr_2.c dr_3.c dr_4.c dr_5.c lo_main.c \
	assorted.c game.c globals.c misc.c parties.c sync.c array.c version.c
MAN=	sail.6

all: $(PROG)

$(PROG): $(SRCS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(PROG) $(SRCS) -lncursesw -I$(ROOT)
	$(STRIP) $(PROG)

install: $(PROG) $(MAN)
	$(GINSTALL) -Dm2755 $(PROG) $(DESTDIR)/$(PREFIX)/games/$(PROG)
	$(GINSTALL) -Dm644 $(MAN) $(DESTDIR)/$(PREFIX)/share/man/man6/$(MAN)
	$(GINSTALL) -d $(DESTDIR)/$(LOCALSTATEDIR)/games

clean:
	rm -f $(CLEANFILES) $(PROG)

.PHONY: all clean install
