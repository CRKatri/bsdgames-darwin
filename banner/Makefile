#	$NetBSD: Makefile,v 1.4 1995/03/25 07:44:46 glass Exp $
#	@(#)Makefile	8.1 (Berkeley) 6/6/93

PROG=	banner
MAN=	banner.6
SRCS= banner.c

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
