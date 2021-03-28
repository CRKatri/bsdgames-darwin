#	$NetBSD: Makefile,v 1.9 1997/10/10 08:59:34 lukem Exp $
#	@(#)Makefile	8.1 (Berkeley) 5/31/93

PROG=	backgammon
SRCS=	extra.c main.c move.c text.c version.c
MAN=	backgammon.6
COMMONOBJS=	../common_source/allow.o \
	../common_source/board.o \
	../common_source/check.o \
	../common_source/fancy.o \
	../common_source/init.o \
	../common_source/odds.o \
	../common_source/one.o \
	../common_source/save.o \
	../common_source/subs.o \
	../common_source/table.o

all: $(PROG)

$(PROG): $(SRCS) $(COMMONOBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(PROG) $(SRCS) $(COMMONOBJS) -I../common_source -lncursesw
	$(STRIP) $(PROG)

install: $(PROG) $(MAN)
	$(GINSTALL) -Dm755 $(PROG) $(DESTDIR)/$(PREFIX)/games/$(PROG)
	$(GINSTALL) -Dm644 $(MAN) $(DESTDIR)/$(PREFIX)/share/man/man6/$(MAN)

clean:
	rm -f $(CLEANFILES) $(PROG)

.PHONY: all clean install
