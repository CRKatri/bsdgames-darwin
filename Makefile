#	$NetBSD: Makefile,v 1.31 2021/01/02 03:21:39 nat Exp $
#	@(#)Makefile	8.3 (Berkeley) 7/24/94

SUBDIR=	adventure arithmetic atc \
	backgammon banner battlestar bcd boggle \
	caesar canfield cgram ching colorbars countmail cribbage \
	dm factor fish gomoku \
	hack hals_end hangman hunt larn mille monop morse number \
	phantasia pig pom ppt primes quiz \
	rain random robots rogue sail snake testpat tetris trek \
	wargames warp worm worms wtf wump
TOPTARGETS= all clean install

PREFIX        ?= /usr
LOCALSTATEDIR ?= /var
SYSCONFDIR    ?= /etc
ROOT          := $(shell pwd)

export ROOT PREFIX LOCALSTATEDIR SYSCONFDIR

$(TOPTARGETS): $(SUBDIR)

$(SUBDIR): config.h
	+$(MAKE) -C $@ $(MAKECMDGOALS)

config.h:
	@echo "#define PREFIX \"$(PREFIX)\"" > config.h
	@echo "#define LOCALSTATEDIR \"$(LOCALSTATEDIR)\"" >> config.h
	@echo "#define SYSCONFDIR \"$(SYSCONFDIR)\"" >> config.h

update:
	TEMP=$$(mktemp -d); \
	cd ~/Documents/NetBSD; \
	git format-patch -o $$TEMP $(shell cat upstream-commit) games; \
	git rev-list HEAD -1 games/ > $(ROOT)/upstream-commit; \
	cd $(ROOT); \
	for patch in $$TEMP/*.patch; do \
		if [ "$$(filterdiff -x '*/Makefile' --strip=1 $$patch --clean)" = "" ]; then \
			echo "Skipping $$(basename $$patch) because it's empty"; \
		else \
			filterdiff -x '*/Makefile' --strip=1 $$patch | git am; \
		fi; \
	done

clean:
	rm -f config.h

.PHONY: $(TOPTARGETS) $(SUBDIR) update
