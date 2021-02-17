#	$NetBSD: Makefile,v 1.8 2008/01/28 07:03:59 dholland Exp $
#	@(#)Makefile	8.1 (Berkeley) 5/31/93

PROG=	caesar
MAN=	caesar.6
SCRIPTS=rot13.sh
SRCS=	caesar.c

all: $(PROG)

$(PROG): $(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS)
	$(STRIP) $(PROG)

install: $(PROG) $(MAN) $(SCRIPTS)
	$(GINSTALL) -Dm755 $(PROG) $(DESTDIR)/usr/games/$(PROG)
	$(GINSTALL) -Dm755 $(SCRIPTS) $(DESTDIR)/usr/games/$(basename $(SCRIPTS))
	$(GINSTALL) -Dm644 $(MAN) $(DESTDIR)/usr/share/man/man6/$(MAN)
	$(LN) -sf $(MAN).zst $(DESTDIR)/usr/share/man/man6/rot13.6

clean:
	rm -f $(CLEANFILES) $(PROG)

.PHONY: all clean install
