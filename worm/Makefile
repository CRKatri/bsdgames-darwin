#	$NetBSD: Makefile,v 1.9 2010/02/06 23:45:26 he Exp $
#	@(#)Makefile	8.1 (Berkeley) 5/31/93

PROG=	worm
MAN=	worm.6
SRCS=	worm.c

all: $(PROG)

$(PROG): $(SRCS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(PROG) $(SRCS) -lncursesw
	$(STRIP) $(PROG)

install: $(PROG) $(MAN)
	$(GINSTALL) -Dm755 $(PROG) $(DESTDIR)/$(PREFIX)/games/$(PROG)
	$(GINSTALL) -Dm644 $(MAN) $(DESTDIR)/$(PREFIX)/share/man/man6/$(MAN)

clean:
	rm -f $(CLEANFILES) $(PROG)

.PHONY: all clean install
