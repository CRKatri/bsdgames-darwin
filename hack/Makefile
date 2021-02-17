#	$NetBSD: Makefile,v 1.47 2020/02/08 00:59:55 fox Exp $
#	@(#)Makefile	8.2 (Berkeley) 4/27/95

PROG=	hack
SRCS+=	alloc.c hack.Decl.c hack.apply.c hack.bones.c hack.c hack.cmd.c \
	hack.do.c hack.do_name.c hack.do_wear.c hack.dog.c hack.eat.c \
	hack.end.c hack.engrave.c hack.fight.c hack.invent.c hack.ioctl.c \
	hack.lev.c hack.main.c hack.makemon.c hack.mhitu.c hack.mklev.c \
	hack.mkmaze.c hack.mkobj.c hack.mkshop.c hack.mon.c hack.monst.c \
	hack.o_init.c hack.objnam.c hack.options.c hack.pager.c hack.potion.c \
	hack.pri.c hack.read.c hack.rip.c hack.rumors.c hack.save.c \
	hack.search.c hack.shk.c hack.shknam.c hack.steal.c hack.terminfo.c \
	hack.timeout.c hack.topl.c hack.track.c hack.trap.c hack.tty.c \
	hack.u_init.c hack.unix.c hack.vault.c hack.version.c hack.wield.c \
	hack.wizard.c hack.worm.c hack.worn.c hack.zap.c rnd.c
MAN=	hack.6
CLEANFILES+=makedefs
FILES=help hh data
FILESDIR=/var/games/hackdir
CLEANFILES+=hack.onames.h

all: $(PROG)

hack.onames.h: makedefs def.objects.h
	./makedefs def.objects.h > hack.onames.h

makedefs: makedefs.c
	clang -o makedefs makedefs.c

hack.h:	hack.onames.h

$(PROG): $(SRCS) hack.h
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(PROG) $(SRCS) -lncursesw
	$(STRIP) $(PROG)

install: $(PROG) $(MAN)
	$(GINSTALL) -Dm2755 $(PROG) $(DESTDIR)/usr/games/$(PROG)
	$(GINSTALL) -Dm644 $(MAN) $(DESTDIR)/usr/share/man/man6/$(MAN)
	mkdir -p $(DESTDIR)$(FILESDIR)
	$(GINSTALL) -Dm660 $(FILES) $(DESTDIR)$(FILESDIR)

clean:
	rm -f $(CLEANFILES) $(PROG)

.PHONY: all clean install
