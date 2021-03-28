#	$NetBSD: Makefile,v 1.5 2020/11/11 20:04:02 christos Exp $

PROG=	warp
SRCS=	bang.c init.c intrp.c move.c object.c play.c score.c sig.c term.c \
	them.c us.c util.c version.c warp.c weapon.c

CPPFLAGS+=-DHAVETERMLIB

CLEANFILES+=sm smap.0 smap.1 smap.2 smap.3 smap.4 smap.5 smap.6 smap.7
CLEANFILES+=warp.6
MAN=	warp.6

FILES=smap.0 smap.1 smap.2 smap.3 smap.4 smap.5 smap.6 smap.7
FILESDIR=$(PREFIX)/share/games/warp

all: $(PROG) $(MAN) $(FILES)

$(PROG): $(SRCS)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $(PROG) $(SRCS) -lncursesw -I$(ROOT)
	$(STRIP) $(PROG)

install: $(PROG) $(MAN) $(FILES)
	$(GINSTALL) -Dm2755 $(PROG) $(DESTDIR)/$(PREFIX)/games/$(PROG)
	$(GINSTALL) -Dm644 $(MAN) $(DESTDIR)/$(PREFIX)/share/man/man6/$(MAN)
	$(GINSTALL) -d $(DESTDIR)$(FILESDIR)
	$(GINSTALL) -Dm644 $(FILES) $(DESTDIR)$(FILESDIR)

clean:
	rm -f $(CLEANFILES) $(PROG)

warp.6:
	cat warp.man > $@

smap.0: smp.0 sm
	./sm < smp.0 > $@

smap.1: smp.1 sm
	./sm < smp.1 > $@

smap.2: smp.2 sm
	./sm < smp.2 > $@

smap.3: smp.3 sm
	./sm < smp.3 > $@

smap.4: smp.4 sm
	./sm < smp.4 > $@

smap.5: smp.5 sm
	./sm < smp.5 > $@

smap.6: smp.6 sm
	./sm < smp.6 > $@

smap.7: smp.7 sm
	./sm < smp.7 > $@

sm: sm.c
	clang -o $@ sm.c -I$(ROOT)

.PHONY: all clean install
