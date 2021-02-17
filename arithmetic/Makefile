#	$NetBSD: Makefile,v 1.4 1995/03/21 11:59:28 cgd Exp $
#	@(#)Makefile	8.1 (Berkeley) 5/31/93

PROG=	arithmetic
MAN=	arithmetic.6
SRCS= arithmetic.c

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
