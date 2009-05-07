#Makefile for sdl.so

CC = gcc
CFLAGS = -O2 -Wall -fmessage-length=0 -fpic
LDLIBS = -lSDL -lkonoha

target = linux_32
pkgname = sdl

library = "$(pkgname)_$(target).so"

.PHONY: all
all: $(library)

objs = $(pkgname).o

"$(pkgname).o": $(pkgname).c
	$(CC) $(CFLAGS) -o $@ -c $^

$(library): $(objs)
	$(CC) -shared -Wl -o $@ $^ $(LDLIBS)

.PHONY: clean
clean:
	$(RM) -rf $(objs) $(library)

.PHONY: install
install: $(library)
	mkdir -p .konoha/sdl
	cp $(library) .konoha/sdl
	cp sdl.k .konoha/sdl