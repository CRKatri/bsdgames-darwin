PROG=	boggle
SRCS=	bog.c help.c mach.c prtable.c timer.c word.c
MAN=	boggle.6

all: boggle

$(PROG): $(SRCS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(SRCS) -o $(PROG) -lncursesw -I$(ROOT)
	$(STRIP) boggle

clean:
	rm -f boggle

install: $(PROG) $(MAN)
	$(GINSTALL) -Dm755 $(PROG) $(DESTDIR)/$(PREFIX)/games/$(PROG)
	$(GINSTALL) -Dm644 $(MAN) $(DESTDIR)/$(PREFIX)/share/man/man6/$(MAN)

.PHONY: all clean install
