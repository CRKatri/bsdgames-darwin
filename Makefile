#	$NetBSD: Makefile,v 1.31 2021/01/02 03:21:39 nat Exp $
#	@(#)Makefile	8.3 (Berkeley) 7/24/94

SUBDIR=	adventure arithmetic atc \
	backgammon banner battlestar bcd boggle \
	caesar canfield cgram ching colorbars countmail cribbage \
	dm factor fish gomoku \
	hack hals_end hangman hunt larn mille monop morse number \
	phantasia pig pom ppt primes quiz \
	rain random robots rogue sail snake testpat tetris trek \
	wargames warp worm worms wtf wump
TOPTARGETS= all clean install

PREFIX        ?= /usr
LOCALSTATEDIR ?= /var
SYSCONFDIR    ?= /etc
ROOT          := $(shell pwd)

export ROOT PREFIX LOCALSTATEDIR SYSCONFDIR

$(TOPTARGETS): $(SUBDIR)

$(SUBDIR): config.h
	+$(MAKE) -C $@ $(MAKECMDGOALS)

config.h:
	@echo "#define PREFIX \"$(PREFIX)\"" > config.h
	@echo "#define LOCALSTATEDIR \"$(LOCALSTATEDIR)\"" >> config.h
	@echo "#define SYSCONFDIR \"$(SYSCONFDIR)\"" >> config.h

clean:
	rm -f config.h

.PHONY: $(TOPTARGETS) $(SUBDIR)
