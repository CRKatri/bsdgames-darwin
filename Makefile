#	from: @(#)Makefile	5.15.1.2 (Berkeley) 5/8/91
#	$Id: Makefile,v 1.9 1994/10/21 21:26:08 jtc Exp $

#Missing: ching dungeon hunt warp 

SUBDIR=	adventure arithmetic atc backgammon banner battlestar bcd boggle \
	caesar canfield cribbage dm factor fish fortune hack hangman \
	larn mille monop morse number phantasia pig pom ppt primes quiz \
	rain robots rogue sail snake tetris trek wargames worm worms wump

.include <bsd.subdir.mk>
