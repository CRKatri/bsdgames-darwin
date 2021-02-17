#	$NetBSD: Makefile,v 1.3 1995/03/21 15:08:26 cgd Exp $
#	@(#)Makefile	8.1 (Berkeley) 5/31/93

SUBDIR= canfield cfscores
TOPTARGETS= all clean install

$(TOPTARGETS): $(SUBDIR)

$(SUBDIR): 
	$(MAKE) -C $@ $(MAKECMDGOALS)

.PHONY: $(TOPTARGETS) $(SUBDIR)
