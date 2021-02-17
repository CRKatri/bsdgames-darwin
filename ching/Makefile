#	$NetBSD: Makefile,v 1.1 2005/06/30 13:30:33 perry Exp $

SUBDIR=	ching castching printching
TOPTARGETS= all clean install

$(TOPTARGETS): $(SUBDIR)

$(SUBDIR):
	$(MAKE) -C $@ $(MAKECMDGOALS)

.PHONY: $(TOPTARGETS) $(SUBDIR)
