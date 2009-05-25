/*	$NetBSD: main.c,v 1.21 2009/05/25 00:29:08 dholland Exp $	*/

/*
 * Copyright (c) 1980, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/cdefs.h>
#ifndef lint
__COPYRIGHT("@(#) Copyright (c) 1980, 1993\
 The Regents of the University of California.  All rights reserved.");
#endif /* not lint */

#ifndef lint
#if 0
static char sccsid[] = "@(#)main.c	8.1 (Berkeley) 5/31/93";
#else
__RCSID("$NetBSD: main.c,v 1.21 2009/05/25 00:29:08 dholland Exp $");
#endif
#endif /* not lint */

#include <stdio.h>
#include <setjmp.h>
#include <termios.h>
#include <stdlib.h>
#include <unistd.h>
#include <err.h>
#include <time.h>
#include <sys/types.h>
#include "trek.h"
#include "getpar.h"


/*
**	 ####  #####    #    ####          #####  ####   #####  #   #
**	#        #     # #   #   #           #    #   #  #      #  #
**	 ###     #    #####  ####            #    ####   ###    ###
**	    #    #    #   #  #  #            #    #  #   #      #  #
**	####     #    #   #  #   #           #    #   #  #####  #   #
**
**	C version by Eric P. Allman 5/76 (U.C. Berkeley) with help
**		from Jeff Poskanzer and Pete Rubinstein.
**
**	I also want to thank everyone here at Berkeley who
**	where crazy enough to play the undebugged game.  I want to
**	particularly thank Nick Whyte, who made considerable
**	suggestions regarding the content of the game.  Why, I'll
**	never forget the time he suggested the name for the
**	"capture" command.
**
**	Please send comments, questions, and suggestions about this
**		game to:
**			Eric P. Allman
**			Project INGRES
**			Electronics Research Laboratory
**			Cory Hall
**			University of California
**			Berkeley, California  94720
**
**	If you make ANY changes in the game, I sure would like to
**	know about them.  It is sort of an ongoing project for me,
**	and I very much want to put in any bug fixes and improvements
**	that you might come up with.
**
**	FORTRASH version by Kay R. Fisher (DEC) "and countless others".
**	That was adapted from the "original BASIC program" (ha!) by
**		Mike Mayfield (Centerline Engineering).
**
**	Additional inspiration taken from FORTRAN version by
**		David Matuszek and Paul Reynolds which runs on the CDC
**		7600 at Lawrence Berkeley Lab, maintained there by
**		Andy Davidson.  This version is also available at LLL
**		and at LMSC.  In all fairness, this version was the
**		major inspiration for this version of the game (trans-
**		lation:  I ripped off a whole lot of code).
**
**	Minor other input from the "Battelle Version 7A" by Joe Miller
**		(Graphics Systems Group, Battelle-Columbus Labs) and
**		Ross Pavlac (Systems Programmer, Battelle Memorial
**		Institute).  That version was written in December '74
**		and extensively modified June '75.  It was adapted
**		from the FTN version by Ron Williams of CDC Sunnyvale,
**		which was adapted from the Basic version distributed
**		by DEC.  It also had "neat stuff swiped" from T. T.
**		Terry and Jim Korp (University of Texas), Hicks (Penn
**		U.), and Rick Maus (Georgia Tech).  Unfortunately, it
**		was not as readable as it could have been and so the
**		translation effort was severely hampered.  None the
**		less, I got the idea of inhabited starsystems from this
**		version.
**
**	Permission is given for use, copying, and modification of
**		all or part of this program and related documentation,
**		provided that all reference to the authors are maintained.
**
**
**********************************************************************
**
**  NOTES TO THE MAINTAINER:
**
**	There is a compilation option xTRACE which must be set for any
**	trace information to be generated.  It is probably defined in
**	the version that you get.  It can be removed, however, if you
**	have trouble finding room in core.
**
**	Many things in trek are not as clear as they might be, but are
**	done to reduce space.  I compile with the -f and -O flags.  I
**	am constrained to running with non-separated I/D space, since
**	we don't have doubleing point hardware here; even if we did, I
**	would like trek to be available to the large number of people
**	who either have an 11/40 or do not have FP hardware.  I also
**	found it desirable to make the code run reentrant, so this
**	added even more space constraints.
**
**	I use the portable C library to do my I/O.  This is done be-
**	cause I wanted the game easily transportable to other C
**	implementations, and because I was too lazy to do the doubleing
**	point input myself.  Little did I know.  The portable C library
**	released by Bell Labs has more bugs than you would believe, so
**	I ended up rewriting the whole blessed thing.  Trek excercises
**	many of the bugs in it, as well as bugs in some of the section
**	III UNIX routines.  We have fixed them here.  One main problem
**	was a bug in alloc() that caused it to always ask for a large
**	hunk of memory, which worked fine unless you were almost out,
**	which I inevitably was.  If you want the code for all of this
**	stuff, it is also available through me.
**
***********************************************************************
*/

jmp_buf env;

static void
usage(const char *av0)
{
	errx(1, "Usage: %s [-fs]", av0);
}

int main(int, char **);

int
main(int argc, char **argv)
{
	time_t		curtime;
	long			vect;
	int ch;

	/* Revoke setgid privileges */
	setgid(getgid());

	/* Default to fast mode */
	Etc.fast = 1;

	time(&curtime);
	vect = (long) curtime;
	srand(vect);

	while ((ch = getopt(argc, argv, "fst")) != -1) {
		switch (ch) {
		  case 'f':	/* set fast mode */
			Etc.fast++;
			break;

		  case 's':	/* set slow mode */
			Etc.fast = 0;
			break;

#ifdef xTRACE
		  case 't':	/* trace */
			Trace++;
			break;
#endif

		  default:
			usage(argv[0]);
		}
	}
	if (optind < argc)
		usage(argv[0]);

	printf("\n   * * *   S T A R   T R E K   * * *\n\n"
	       "Press return to continue.\n");

	if (setjmp(env)) {
		if ( !getynpar("Another game") )
			exit(0);
	}

	do {
		setup();
		play();
	} while (getynpar("Another game"));

	fflush(stdout);
	return 0;
}
