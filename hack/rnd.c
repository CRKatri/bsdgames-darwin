#ifndef lint
static char rcsid[] = "$NetBSD: rnd.c,v 1.3 1995/03/23 08:32:28 cgd Exp $";
#endif /* not lint */

#define RND(x)	((random()>>3) % x)

rn1(x,y)
register x,y;
{
	return(RND(x)+y);
}

rn2(x)
register x;
{
	return(RND(x));
}

rnd(x)
register x;
{
	return(RND(x)+1);
}

d(n,x)
register n,x;
{
	register tmp = n;

	while(n--) tmp += RND(x);
	return(tmp);
}
