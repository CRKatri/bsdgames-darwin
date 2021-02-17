#	$NetBSD: Makefile,v 1.10 2019/10/13 07:28:09 mrg Exp $

PROG=	hunt
SRCS=	connect.c hunt.c otto.c playit.c server.c
MAN=	hunt.6

all: $(PROG)

$(PROG): $(SRCS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(PROG) $(SRCS) $(EXTRADEFS) -I../include -lncursesw
	$(STRIP) $(PROG)

install: $(PROG) $(MAN)
	$(GINSTALL) -Dm2755 $(PROG) $(DESTDIR)/usr/games/$(PROG)
	$(GINSTALL) -Dm644 $(MAN) $(DESTDIR)/usr/share/man/man6/$(MAN)

clean:
	rm -f $(CLEANFILES) $(PROG)

.PHONY: all clean install
