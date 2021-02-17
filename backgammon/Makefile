#	$NetBSD: Makefile,v 1.6 2001/01/09 03:13:39 lukem Exp $
#	@(#)Makefile	8.1 (Berkeley) 5/31/93

SUBDIR=	backgammon teachgammon
TOPTARGETS= all install

$(TOPTARGETS): $(SUBDIR)

clean:
	$(MAKE) -C backgammon clean
	$(MAKE) -C teachgammon clean
	$(MAKE) -C common_source clean

common_source:
	$(MAKE) -C $@ $(MAKECMDGOALS)

$(SUBDIR): common_source
	$(MAKE) -C $@ $(MAKECMDGOALS)

.PHONY: $(TOPTARGETS) $(SUBDIR) clean
