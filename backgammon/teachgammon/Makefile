#	$NetBSD: Makefile,v 1.11 2002/09/18 06:16:39 lukem Exp $
#	@(#)Makefile	8.1 (Berkeley) 5/31/93

PROG=		teachgammon
SRCS=		data.c teach.c ttext1.c ttext2.c tutor.c
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

install: $(PROG)
	$(GINSTALL) -Dm755 $(PROG) $(DESTDIR)/$(PREFIX)/games/$(PROG)

clean:
	rm -f $(CLEANFILES) $(PROG)

.PHONY: all clean install
