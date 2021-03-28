#	$NetBSD: Makefile,v 1.7 2010/02/03 15:34:38 roy Exp $

PROG=dab
MAN=dab.6
SRCS=algor.cc board.cc main.cc human.cc box.cc player.cc gamescreen.cc \
    ttyscrn.cc random.cc

all: $(PROG)

$(PROG): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(PROG) $(SRCS) -lncursesw
	$(STRIP) $(PROG)

install: $(PROG) $(MAN)
	$(GINSTALL) -Dm755 $(PROG) $(DESTDIR)/$(PREFIX)/games/$(PROG)
	$(GINSTALL) -Dm644 $(MAN) $(DESTDIR)/$(PREFIX)/share/man/man6/$(MAN)

clean:
	rm -f $(CLEANFILES) $(PROG)

.PHONY: all clean install
