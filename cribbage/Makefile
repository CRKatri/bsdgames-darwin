#	$NetBSD: Makefile,v 1.13 2010/02/06 23:45:25 he Exp $
#	@(#)Makefile	8.1 (Berkeley) 5/31/93

PROG=	cribbage
SRCS=	extern.c crib.c cards.c instr.c io.c score.c support.c
MAN=	cribbage.6
FILES=	cribbage.n
FILESNAME=cribbage.instr

all: $(PROG)

$(PROG): $(SRCS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(PROG) $(SRCS) -lncursesw -I$(ROOT)
	$(STRIP) $(PROG)

install: $(PROG) $(MAN)
	$(GINSTALL) -Dm755 $(PROG) $(DESTDIR)/$(PREFIX)/games/$(PROG)
	$(GINSTALL) -Dm644 $(MAN) $(DESTDIR)/$(PREFIX)/share/man/man6/$(MAN)
	$(GINSTALL) -Dm644 $(FILES) $(DESTDIR)/$(PREFIX)/share/games/$(FILESNAME)

clean:
	rm -f $(CLEANFILES) $(PROG)

.PHONY: all clean install
