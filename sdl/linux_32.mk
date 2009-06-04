#Makefile for sdl.so

CC = gcc
CFLAGS = -O2 -Wall -fmessage-length=0 -fpic
LDLIBS = -lSDL -lkonoha

target = linux_32
pkgname = sdl

library = "$(pkgname)_$(target).so"

.PHONY: all
all: $(library)

objs = $(pkgname).o sdl_event.o sdl_keyboard.o sdl_color.o sdl_mouse.o sdl_cursor.o

"$(pkgname).o": $(pkgname).c
	$(CC) $(CFLAGS) -o $@ -c $^

sdl_event.o: sdl_event.c
	$(CC) $(CFLAGS) -o $@ -c $^

sdl_keyboard.o: sdl_keyboard.c
	$(CC) $(CFLAGS) -o $@ -c $^

sdl_color.o: sdl_color.c
	$(CC) $(CFLAGS) -o $@ -c $^

sdl_mouse.o: sdl_mouse.c
	$(CC) $(CFLAGS) -o $@ -c $^

sdl_cursor.o: sdl_cursor.c
	$(CC) $(CFLAGS) -o $@ -c $^

$(library): $(objs)
	$(CC) -shared -Wl -o $@ $^ $(LDLIBS)

.PHONY: clean
clean:
	$(RM) -rf $(objs) $(library) *~ .konoha

.PHONY: install
install: $(library)
	mkdir -p .konoha/sdl
	cp $(library) .konoha/sdl
	cp sdl.k .konoha/sdl
