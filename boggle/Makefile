all: dictionary dictindex boggle

mkdict:
	$(MAKE) -C mkdict

mkindex:
	$(MAKE) -C mkindex

boggle:
	$(MAKE) -C boggle 

clean:
	rm -f dictionary dictindex
	$(MAKE) -C mkdict clean
	$(MAKE) -C mkindex clean
	$(MAKE) -C boggle clean

dictionary: mkdict
	./mkdict/mkdict < mkdict/web2 > dictionary

dictindex: mkindex dictionary
	./mkindex/mkindex < dictionary > dictindex

install: dictindex dictionary boggle
	$(GINSTALL) -Dm644 dictionary $(DESTDIR)/$(PREFIX)/share/games/boggle/dictionary
	$(GINSTALL) -Dm644 dictindex $(DESTDIR)/$(PREFIX)/share/games/boggle/dictindex
	$(MAKE) -C boggle install

.PHONY: all clean install mkdict mkindex boggle
