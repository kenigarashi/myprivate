using sdl.*

SDL.init(SDL.SDL_INIT_VIDEO)

Surface s = SDL.setVideoMode(444,444,32,SDL.SDL_SWSURFACE)

VideoInfo info = SDL.getVideoInfo()