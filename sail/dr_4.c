/*	$NetBSD: dr_4.c,v 1.4 1997/01/07 12:42:15 tls Exp $	*/

/*
 * Copyright (c) 1983, 1993
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
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
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

#ifndef lint
#if 0
static char sccsid[] = "@(#)dr_4.c	8.2 (Berkeley) 4/28/95";
#else
static char rcsid[] = "$NetBSD: dr_4.c,v 1.4 1997/01/07 12:42:15 tls Exp $";
#endif
#endif /* not lint */

#include "extern.h"

ungrap(from, to)
register struct ship *from, *to;
{
	register k;
	char friend;

	if ((k = grappled2(from, to)) == 0)
		return;
	friend = capship(from)->nationality == capship(to)->nationality;
	while (--k >= 0) {
		if (friend || die() < 3) {
			cleangrapple(from, to, 0);
			makesignal(from, "ungrappling %s (%c%c)", to);
		}
	}
}

grap(from, to)
register struct ship *from, *to;
{
	if (capship(from)->nationality != capship(to)->nationality && die() > 2)
		return;
	Write(W_GRAP, from, 0, to->file->index, 0, 0, 0);
	Write(W_GRAP, to, 0, from->file->index, 0, 0, 0);
	makesignal(from, "grappled with %s (%c%c)", to);
}
