#	$NetBSD: Makefile,v 1.7 2002/09/18 06:16:41 lukem Exp $
#	@(#)Makefile	8.1 (Berkeley) 5/31/93

PROG=		snscore
SRCS=		snscore.c

all: $(PROG)

$(PROG): $(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) -I../snake
	$(STRIP) $(PROG)

install: $(PROG) $(MAN)
	$(GINSTALL) -Dm2755 $(PROG) $(DESTDIR)/usr/games/$(PROG)

clean:
	rm -f $(CLEANFILES) $(PROG)

.PHONY: all clean install
