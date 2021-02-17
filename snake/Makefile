#	$NetBSD: Makefile,v 1.3 1995/04/22 08:34:18 cgd Exp $
#	@(#)Makefile	8.1 (Berkeley) 5/31/93

SUBDIR=	snake snscore
TOPTARGETS= all clean install

$(TOPTARGETS): $(SUBDIR)

$(SUBDIR):
	$(MAKE) -C $@ $(MAKECMDGOALS)

.PHONY: $(TOPTARGETS) $(SUBDIR)
