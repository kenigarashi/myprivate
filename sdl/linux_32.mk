#Makefile for math.so

CC = gcc
CFLAGS = -O2 -Wall -fmessage-length=0 -fpic
LDLIBS = -lSDL -lkonoha

library = sdl_linux_32.so
#library = math.dylib

.PHONY: all
all: $(library)

objs = sdl.o

sdl.o: sdl.c
	$(CC) $(CFLAGS) -o $@ -c $^

$(library): $(objs)
	$(CC) -shared -Wl -o $@ $^ $(LDLIBS)

.PHONY: clean
clean:
	$(RM) -rf $(objs) $(library)

.PHONY: konoha_install
konoha_install: $(library)
	mkdir -p .konoha/sdl
	cp $(library) .konoha/sdl
	cp sdl.k .konoha/sdl
