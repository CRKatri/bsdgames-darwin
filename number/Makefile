#	$NetBSD: Makefile,v 1.4 1995/03/23 08:35:27 cgd Exp $
#	@(#)Makefile	8.1 (Berkeley) 5/31/93

PROG=	number
MAN=	number.6
SRCS=	number.c

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
