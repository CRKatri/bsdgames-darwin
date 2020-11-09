/* $Header: /cvsroot/src/games/warp/util.h,v 1.1 2020/11/09 23:37:05 kamil Exp $ */

/* $Log: util.h,v $
/* Revision 1.1  2020/11/09 23:37:05  kamil
/* Add Warp Kit, Version 7.0 by Larry Wall
/*
/* Warp is a real-time space war game that doesn't get boring very quickly.
/* Read warp.doc and the manual page for more information.
/*
/* games/warp originally distributed with 4.3BSD-Reno, is back to the BSD
/* world via NetBSD. Its remnants were still mentioned in games/Makefile.
/*
/* Larry Wall, the original author and the copyright holder, generously
/* donated the game and copyright to The NetBSD Foundation, Inc.
/*
/* Import the game sources as-is from 4.3BSD-Reno, with the cession
/* of the copyright and license to BSD-2-clause NetBSD-style.
/*
/* Signed-off-by: Larry Wall <larry@wall.org>
/* Signed-off-by: Kamil Rytarowski <kamil@netbsd.org>
/*
 * Revision 7.0  86/10/08  15:14:37  lwall
 * Split into separate files.  Added amoebas and pirates.
 * 
 */

#if RANDBITS < 15 || defined(lint)
#define rand_mod(m) getpid()
#define RANDRAND 0.0
#define HALFRAND 0
#define myrand() getpid()
#else
#if RANDBITS == 15	/* 15 bits of rand()? */
#define RANDRAND 268435456.0 /* that's 2**28 */
#define HALFRAND 0x4000 /* that's 2**14 */
int rand();
#define myrand() (rand()&32767)
#define rand_mod(m) ((int)((double)myrand() / 32768.0 * ((double)(m))))
/* pick number in 0..m-1 */

#else

#if RANDBITS < 31	/* 16 bits of rand()? */
#define RANDRAND 1073741824.0 /* that's 2**30 */
#define HALFRAND 0x8000 /* that's 2**15 */
unsigned rand();
#define myrand() (rand()&65535)
#define rand_mod(m) ((int)((double)myrand() / 65536.0 * ((double)(m))))
/* pick number in 0..m-1 */

#else		/* assume 31 bits */
#define RANDRAND 1152921504606846976.0 /* that's 2**60 */
#define HALFRAND 0x40000000 /* that's 2**30 */
long rand();
#define myrand() rand()
#define rand_mod(m) ((myrand() / 37) % (m)) /* pick number in 0..m-1 */
/*
 * The reason for the /37 above is that our random number generator yields
 * successive evens and odds, for some reason.  This makes strange star maps.
 */
#endif
#endif
#endif


    /* we get fractions of seconds from calling ftime on timebuf */

EXT struct timeb timebuf;
#define roundsleep(x) (ftime(&timebuf),sleep(timebuf.millitm > 500?x+1:x))

void movc3();
void no_can_do();
int exdis();

EXT bool waiting INIT(FALSE);		/* are we waiting for subprocess (in doshell)? */

#ifdef NOTDEF
EXT int len_last_line_got INIT(0);
			/* strlen of some_buf after */
			/*  some_buf = get_a_line(bufptr,buffersize,fp) */
#endif

#ifdef NOTDEF
/* is the string for makedir a directory name or a filename? */

#define MD_DIR 0
#define MD_FILE 1
#endif

void util_init();
char	*safemalloc();
char	*safecpy();
char	*cpytill();
char	*instr();
#ifdef SETUIDGID
    int		eaccess();
#endif
char	*getwd();
void	cat();
void	prexit();
char	*savestr();
char	*getval();
