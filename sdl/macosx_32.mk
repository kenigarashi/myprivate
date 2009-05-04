# Last modified by Kimio Kuramitsu kkuramitsu@sourceforge.jp

CC = gcc
CFLAGS = -O2 -Wall -fmessage-length=0 -fPIC -I/opt/local/include/SDL -D_GNU_SOURCE=1 -D_THREAD_SAFE
LDLIBS = -L/opt/local/lib -lSDL -Wl,-framework,Cocoa -lkonoha

target = macosx_32
pkgname = sdl

library = "$(pkgname)_$(target).dylib"

.PHONY: all
all: $(library)

objs = $(pkgname).o

"$(pkgname).o": $(pkgname).c
	$(CC) $(CFLAGS) -o $@ -c $^

$(library): $(objs)
	$(CC) -dynamiclib -o $@ $^ $(LDLIBS)

.PHONY: clean
clean:
	$(RM) -rf $(objs) $(library)

