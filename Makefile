#	from: @(#)Makefile	5.15.1.2 (Berkeley) 5/8/91
#	$Id: Makefile,v 1.5 1994/05/05 07:04:04 cgd Exp $

#Missing: adventure boggle ching dungeon hunt phantasia warp 

SUBDIR=	arithmetic atc backgammon banner battlestar bcd caesar canfield \
	cribbage dm factor fish fortune hack hangman larn \
	mille monop morse number pig pom ppt primes quiz rain robots rogue \
	sail snake trek wargames worm worms wump

.include <bsd.subdir.mk>
