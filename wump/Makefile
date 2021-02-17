#	$NetBSD: Makefile,v 1.10 2008/01/28 07:04:00 dholland Exp $
#	@(#)Makefile	8.1 (Berkeley) 5/31/93

PROG=	wump
MAN=	wump.6
SRCS=	wump.c
FILES=wump.info
FILESDIR=/usr/share/games

all: $(PROG)

$(PROG): $(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS)
	$(STRIP) $(PROG)

install: $(PROG) $(MAN)
	$(GINSTALL) -Dm2755 $(PROG) $(DESTDIR)/usr/games/$(PROG)
	$(GINSTALL) -Dm644 $(MAN) $(DESTDIR)/usr/share/man/man6/$(MAN)
	$(GINSTALL) -Dm644 $(FILES) $(DESTDIR)$(FILESDIR)

clean:
	rm -f $(CLEANFILES) $(PROG)

.PHONY: all clean install
