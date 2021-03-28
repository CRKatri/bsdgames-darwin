#	$NetBSD: Makefile,v 1.11 2002/09/18 03:23:00 lukem Exp $
#	@(#)Makefile	8.1 (Berkeley) 5/31/93

PROG=	dm
SRCS=	dm.c utmpentry.c
MAN8=	dm.8
MAN5=	dm.conf.5

all: $(PROG)

$(PROG): $(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) -DSUPPORT_UTMPX -I$(ROOT)
	$(STRIP) $(PROG)

install: $(PROG) $(MAN)
	$(GINSTALL) -Dm755 $(PROG) $(DESTDIR)/$(PREFIX)/games/$(PROG)
	$(GINSTALL) -Dm644 $(MAN8) $(DESTDIR)/$(PREFIX)/share/man/man8/$(MAN8)
	$(GINSTALL) -Dm644 $(MAN5) $(DESTDIR)/$(PREFIX)/share/man/man5/$(MAN5)

clean:
	rm -f $(CLEANFILES) $(PROG)

.PHONY: all clean install
