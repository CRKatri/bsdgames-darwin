#	$NetBSD: Makefile,v 1.8 2010/02/06 23:45:25 he Exp $
#	@(#)Makefile	8.1 (Berkeley) 5/31/93

PROG=	canfield
MAN=	canfield.6
SRCS=	canfield.c

all: $(PROG)

$(PROG): $(SRCS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(PROG) $(SRCS) -lncursesw
	$(STRIP) $(PROG)

install: $(PROG) $(MAN)
	$(GINSTALL) -Dm2755 $(PROG) $(DESTDIR)/usr/games/$(PROG)
	$(GINSTALL) -Dm644 $(MAN) $(DESTDIR)/usr/share/man/man6/$(MAN)

clean:
	rm -f $(CLEANFILES) $(PROG)

.PHONY: all clean install
