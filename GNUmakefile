BASE=/usr

INC_DBG_INFO=-g

CFLAGS+=	$(INC_DBG_INFO) \
		-D_GNU_SOURCE \
		-include openbsd.h -include queue.h -include /usr/include/signal.h \
		$(shell pkg-config --cflags x11 freetype2)

LDFLAGS+=	$(INC_DBG_INFO) $(shell pkg-config --libs xft xrender x11 xau fontconfig xinerama xrandr xext) -lz

.SUFFIXES: .c .o
PROG=	cwm
SRCS=	calmwm.c screen.c xmalloc.c client.c menu.c		\
	search.c util.c xutil.c conf.c xevents.c group.c	\
	kbfunc.c mousefunc.c font.c parse.c			\
	strlcpy.c strlcat.c strtonum.c fgetln.c log.c
OBJS = $(filter %.o, $(SRCS:.c=.o))
MANPAGES=cwm.1.gz cwmrc.5.gz

all: parse.c $(PROG)

parse.c:
	yacc -d parse.y
	mv y.tab.c parse.c

$(PROG): $(OBJS) $(MANPAGES)
	@$(CC) $(LDFLAGS) -o $@ $(OBJS)
	@echo CC $@

.c.o:
	@$(CC) -c $(CFLAGS) -o $@ $<
	@echo CC $@

$(MANPAGES): cwm.1 cwmrc.5
	@gzip -c cwm.1 > cwm.1.gz
	@gzip -c cwmrc.5 > cwmrc.5.gz
	@echo MAN 1 cwm
	@echo MAN 5 cwmrc

clean:
	rm -f $(PROG) $(OBJS) $(MANPAGES)

install:
	mkdir -p $(BASE)/bin $(BASE)/share/man/man{1,5}
	install $(PROG) $(BASE)/bin
	install cwm.1.gz $(BASE)/share/man/man1/cwm.1.gz
	install cwmrc.5.gz $(BASE)/share/man/man5/cwmrc.5.gz

uninstall:
	rm -f $(BASE)/bin/$(PROG)
	rm -f $(BASE)/man/man1/cwm.1.gz
	rm -f $(BASE)/man/man5/cwmrc.5.gz
