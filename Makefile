#	$NetBSD: Makefile,v 1.15 1997/10/04 09:27:11 mrg Exp $
#	@(#)Makefile	8.3 (Berkeley) 7/24/94

# Missing: ching dungeon hunt warp
# Moved: chess
# Don't belong: xneko xroach

SUBDIR=	adventure arithmetic atc backgammon banner battlestar bcd boggle \
	caesar canfield countmail cribbage dm factor fish fortune gomoku hack \
	hangman hunt larn mille monop morse number phantasia pig pom ppt \
	primes quiz rain random robots rogue sail snake tetris trek wargames \
	worm worms wump

.include <bsd.subdir.mk>
