#	$NetBSD: Makefile,v 1.6 2002/09/18 06:16:40 lukem Exp $
#	@(#)Makefile	8.1 (Berkeley) 5/31/93

PROG=		morse
SRCS=		morse.c

all: $(PROG)

$(PROG): $(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS)
	$(STRIP) $(PROG)

install: $(PROG) $(MAN)
	$(GINSTALL) -Dm755 $(PROG) $(DESTDIR)/usr/games/$(PROG)

clean:
	rm -f $(CLEANFILES) $(PROG)

.PHONY: all clean install
