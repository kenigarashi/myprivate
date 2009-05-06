using sdl.*

SDL.init(SDL.SDL_INIT_VIDEO)

String name = SDL.videoDriverName("s",100)

Surface s = SDL.setVideoMode(444,444,32,SDL.SDL_SWSURFACE)

VideoInfo info = SDL.getVideoInfo()

name

