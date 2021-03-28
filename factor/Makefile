#	$NetBSD: Makefile,v 1.13 2017/05/21 15:28:41 riastradh Exp $
#	@(#)Makefile	8.1 (Berkeley) 5/31/93

PROG=	factor
SRCS=	factor.c ../primes/pr_tbl.c
MAN=	factor.6

all: $(PROG)

$(PROG): $(SRCS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(PROG) $(SRCS) -I../primes -DHAVE_OPENSSL -lcrypto
	$(STRIP) $(PROG)

install: $(PROG) $(MAN)
	$(GINSTALL) -Dm755 $(PROG) $(DESTDIR)/$(PREFIX)/games/$(PROG)
	$(GINSTALL) -Dm644 $(MAN) $(DESTDIR)/$(PREFIX)/share/man/man6/$(MAN)

clean:
	rm -f $(CLEANFILES) $(PROG)

.PHONY: all clean install
