#	from: @(#)Makefile	5.15.1.2 (Berkeley) 5/8/91
#	$Id: Makefile,v 1.4 1993/08/01 05:46:30 mycroft Exp $

#Missing: adventure boggle ching dungeon hunt phantasia warp 

SUBDIR=	arithmetic atc backgammon banner battlestar bcd caesar canfield \
	cribbage dm factor fish fortune hack hangman larn \
	mille monop morse number pom ppt primes quiz rain robots rogue \
	sail snake trek wargames worm worms wump

.include <bsd.subdir.mk>
