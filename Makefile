#	$NetBSD: Makefile,v 1.25 2009/12/14 12:43:48 uebayasi Exp $
#	@(#)Makefile	8.3 (Berkeley) 7/24/94

# Missing: dungeon warp
# Moved: chess
# Don't belong: xneko xroach

.include <bsd.own.mk>

SUBDIR=	adventure arithmetic atc \
	backgammon banner battlestar bcd boggle \
	caesar canfield ching countmail cribbage \
	dm factor fish fortune gomoku \
	hack hangman hunt larn mille monop morse number \
	phantasia pig pom ppt primes quiz \
	rain random robots rogue sail snake tetris trek \
	wargames worm worms wtf wump

.if ${MKCXX} != "no"
SUBDIR=	dab 
.endif

.include <bsd.subdir.mk>
