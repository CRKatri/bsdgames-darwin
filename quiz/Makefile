#	$NetBSD: Makefile,v 1.13 1999/02/13 02:54:22 lukem Exp $
#	@(#)Makefile	8.1 (Berkeley) 5/31/93

PROG=	quiz
MAN=	quiz.6
SRCS=	quiz.c rxp.c
CATS=	africa america areas arith asia babies bard chinese collectives \
	ed elements europe flowers greek inca index latin locomotive \
	midearth morse mult murders poetry posneg pres province seq-easy \
	seq-hard sexes sov spell state trek ucc
FILES= $(addprefix datfiles/,$(CATS))
FILESDIR=$(PREFIX)/share/games/quiz.db

all: $(PROG)

$(PROG): $(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) -I$(ROOT)
	$(STRIP) $(PROG)

install: $(PROG) $(MAN)
	$(GINSTALL) -Dm755 $(PROG) $(DESTDIR)/$(PREFIX)/games/$(PROG)
	$(GINSTALL) -Dm644 $(MAN) $(DESTDIR)/$(PREFIX)/share/man/man6/$(MAN)
	$(GINSTALL) -d $(DESTDIR)$(FILESDIR)
	$(GINSTALL) -Dm644 $(FILES) $(DESTDIR)$(FILESDIR)

clean:
	rm -f $(CLEANFILES) $(PROG)

.PHONY: all clean install
