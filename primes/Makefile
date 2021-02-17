#	$NetBSD: Makefile,v 1.8 2014/10/02 21:36:37 ast Exp $
#	@(#)Makefile	8.1 (Berkeley) 5/31/93

PROG=		primes
SRCS=		pattern.c pr_tbl.c primes.c spsp.c
MAN=		primes.6

all: $(PROG)

$(PROG): $(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS)
	$(STRIP) $(PROG)

install: $(PROG) $(MAN)
	$(GINSTALL) -Dm755 $(PROG) $(DESTDIR)/usr/games/$(PROG)
	$(GINSTALL) -Dm644 $(MAN) $(DESTDIR)/usr/share/man/man6/$(MAN)

clean:
	rm -f $(CLEANFILES) $(PROG)

.PHONY: all clean install
