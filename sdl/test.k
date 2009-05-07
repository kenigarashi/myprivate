using sdl.*

SDL.init(SDL.SDL_INIT_VIDEO)

String name = SDL.videoDriverName("s",100)

Surface s = SDL.setVideoMode(444,444,32,SDL.SDL_SWSURFACE)

VideoInfo info = SDL.getVideoInfo()

Cursor c = SDL.getCursor()

Cursor new = SDL.createCursor(0,1,32,32,32,32)
name
info
c
