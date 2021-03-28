#	$NetBSD: Makefile,v 1.10 1999/02/13 02:54:21 lukem Exp $
#	@(#)Makefile	8.1 (Berkeley) 5/31/93

PROG=	fish
MAN=	fish.6
SRCS=	fish.c
FILES=fish.instr

all: $(PROG)

$(PROG): $(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) -I$(ROOT)
	$(STRIP) $(PROG)

install: $(PROG) $(MAN)
	$(GINSTALL) -Dm755 $(PROG) $(DESTDIR)/$(PREFIX)/games/bsd-$(PROG)
	$(GINSTALL) -Dm644 $(MAN) $(DESTDIR)/$(PREFIX)/share/man/man6/bsd-$(MAN)
	$(GINSTALL) -Dm644 $(FILES) $(DESTDIR)/$(PREFIX)/share/games/bsd-$(FILES)

clean:
	rm -f $(CLEANFILES) $(PROG)

.PHONY: all clean install
