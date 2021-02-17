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

$(TOPTARGETS): $(SUBDIR)

$(SUBDIR):
	$(MAKE) -C $@ $(MAKECMDGOALS)

.PHONY: $(TOPTARGETS) $(SUBDIR)
