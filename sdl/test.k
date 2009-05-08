using sdl.*

SDL.init(SDL.SDL_INIT_VIDEO)

Surface test = SDL.createRGBSurface(SDL.SDL_SWSURFACE,256,256,256,0,0,0,0)

String name = SDL.videoDriverName("test",100)

Surface i = SDL.loadBMP("icon.bmp")

SDL.wmSetIcon(i,0)

Surface s = SDL.setVideoMode(444,444,32,SDL.SDL_SWSURFACE)

Surface bmp = SDL.loadBMP("sail.bmp")

bmp.blitSurface(s)

s.flip()

i.setColorKey(SDL.SDL_SRCCOLORKEY)

VideoInfo info = SDL.getVideoInfo()

Cursor c = SDL.getCursor()

String title = SDL.wmSetCaption("hello")

SDL.pumpEvents()

title.wmGetCaption(title)

SDL.wmGrabInput(SDL.SDL_QUERY)

//SDL.wmIconifyWindow()

Surface new = s.displayFormatAlpha()

name
info
c
