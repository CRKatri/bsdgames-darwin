#	$NetBSD: Makefile,v 1.8 2009/07/26 03:02:38 dholland Exp $
#	@(#)Makefile	8.1 (Berkeley) 5/31/93

PROG=	bcd
MAN=	bcd.6
MLINKS=	bcd.6 morse.6 bcd.6 ppt.6
SRCS= bcd.c

all: $(PROG)

$(PROG): $(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS)
	$(STRIP) $(PROG)

install: $(PROG) $(MAN)
	$(GINSTALL) -Dm755 $(PROG) $(DESTDIR)/$(PREFIX)/games/$(PROG)
	$(GINSTALL) -Dm644 $(MAN) $(DESTDIR)/$(PREFIX)/share/man/man6/$(MAN)
	$(LN) -sf $(MAN).zst $(DESTDIR)/$(PREFIX)/share/man/man6/morse.6
	$(LN) -sf $(MAN).zst $(DESTDIR)/$(PREFIX)/share/man/man6/ppt.6

clean:
	rm -f $(CLEANFILES) $(PROG)

.PHONY: all clean install
