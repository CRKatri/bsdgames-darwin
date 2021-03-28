#	$NetBSD: Makefile,v 1.8 2019/09/29 23:44:59 mrg Exp $

PROG=	huntd
SRCS=	answer.c draw.c driver.c execute.c expl.c \
	extern.c makemaze.c shots.c support.c terminal.c
MAN=	huntd.6

all: $(PROG)

$(PROG): $(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(EXTRADEFS) -I../include -I$(ROOT)
	$(STRIP) $(PROG)

install: $(PROG) $(MAN)
	$(GINSTALL) -Dm2755 $(PROG) $(DESTDIR)/$(PREFIX)/games/$(PROG)
	$(GINSTALL) -Dm644 $(MAN) $(DESTDIR)/$(PREFIX)/share/man/man6/$(MAN)

clean:
	rm -f $(CLEANFILES) $(PROG)

.PHONY: all clean install
