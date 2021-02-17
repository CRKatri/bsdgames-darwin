/*	$NetBSD: map.c,v 1.2 1995/03/24 03:58:58 cgd Exp $	*/

#define	minusminus	plusplus
#define	minusplus	plusminus

#include <stdio.h>
#include <stdlib.h>
#include <plot.h>

void plusminus(char *s, int x, int y);
void plusplus(char *s, int x, int y);

int
main()
{
    /* Set up */

    pl_openpl();
    pl_space(-1400, -1000, 1200, 1200);

    /* Big box */

    pl_move(-1400, -1000);
    pl_cont(-1400, 1000);
    pl_cont(600, 1000);
    pl_cont(600, -1000);
    pl_cont(-1400, -1000);

    /* Grid -- horizontal lines every 200 */

    pl_linemod("dotted");
    pl_line(600, -800, -1400, -800);
    pl_line(-1400, -600, 600, -600);
    pl_line(600, -400, -1400, -400);
    pl_line(-1400, -200, 600, -200);
    pl_linemod("solid");
    pl_line(600, 0, -1400, 0);
    pl_linemod("dotted");
    pl_line(-1400, 200, 600, 200);
    pl_line(600, 400, -1400, 400);
    pl_line(-1400, 600, 600, 600);
    pl_line(600, 800, -1400, 800);

    /* Grid -- vertical lines every 200 */

    pl_line(-1200, 1000, -1200, -1000);
    pl_line(-1000, 1000, -1000, -1000);
    pl_line(-800, 1000, -800, -1000);
    pl_line(-600, 1000, -600, -1000);
    pl_linemod("solid");
    pl_line(-400, 1000, -400, -1000);
    pl_linemod("dotted");
    pl_line(-200, 1000, -200, -1000);
    pl_line(0, 1000, 0, -1000);
    pl_line(200, 1000, 200, -1000);
    pl_line(400, 1000, 400, -1000);

    /* Circles radius +250 on "center" */

    pl_linemod("solid");
    pl_circle(-400, 0, 250);
    pl_circle(-400, 0, 500);
    pl_circle(-400, 0, 750);
    pl_circle(-400, 0, 1000);

    /* A few labels */

    pl_move(-670, 1075);
    pl_label("- THE PHANTASIA UNIVERSE -");
    pl_line(-630, 1045, -115, 1045);
    pl_move(-360, 80);
    pl_label("Lorien");
    pl_move(-385, -100);
    pl_label("Ithilien");
    pl_move(-560, 80);
    pl_label("Rohan");
    pl_move(-580, -100);
    pl_label("Anorien");
    plusplus("Rovanion", -250, 320);
    plusplus("The Iron Hills", -100, 560);
    plusplus("Rhun", 250, 570);
    minusplus("Dunland", -700, 160);
    minusplus("Eriador", -920, 300);
    minusplus("The Northern Waste", -1240, 320);
    minusminus("Gondor", -720, -180);
    minusminus("South Gondor", -940, -270);
    minusminus("Far Harad", -1100, -500);
    plusminus("Mordor", -180, -300);
    plusminus("Khand", 0, -500);
    plusminus("Near Harad", 40, -780);
    pl_move(340, 900);
    pl_label("The Moors");
    pl_move(300, 840);
    pl_label("Adventurous");
    pl_move(340, -840);
    pl_label("The Moors");
    pl_move(300, -900);
    pl_label("Adventurous");
    pl_move(-1340, 900);
    pl_label("The Moors");
    pl_move(-1340, 840);
    pl_label("Adventurous");
    pl_move(-1340, -840);
    pl_label("The Moors");
    pl_move(-1340, -900);
    pl_label("Adventurous");
    pl_move(700, 1000);
    pl_label("OUTER CIRCLES:");
    pl_line(690, 970, 1000, 970);
    pl_move(700, 900);
    pl_label("> 9:  The Outer Waste");
    pl_move(700, 800);
    pl_label("> 20: The Dead Marshes");
    pl_move(700, 700);
    pl_label("> 35: Kennaquhair");
    pl_move(700, 600);
    pl_label("> 55: Morannon");
    pl_move(700, 300);
    pl_label("(0,0): The Lord's Chamber");

    pl_move(700, -400);
    pl_label("Grid squares are 100 x 100");
    pl_move(700, -800);
    pl_label("Created by Ted Estes");
    pl_move(700, -860);
    pl_label("Plotted by Chris Robertson");
    pl_move(700, -920);
    pl_label(" c  1985");
    pl_circle(723, -923, 20);

    /* Close down */

    pl_move(-1380, 1180);
    pl_closepl();
    exit(0);
}

void
plusplus(char *s, int x, int y)	/* draw strings in plus plus quadrant */
{
char	s1[2];

    while (*s)
	{
	pl_move(x, y);
	s1[0] = *s++;
	s1[1] = '\0';
	pl_label(s1);
	x += 25;
	y -= 30;
	}
}

void
plusminus(char *s, int x, int y)	/* draw strings in plus minus quadrant */
{
char	s1[2];

    while (*s)
	{
	pl_move(x, y);
	s1[0] = *s++;
	s1[1] = '\0';
	pl_label(s1);
	x += 25;
	y += 30;
	}
}
