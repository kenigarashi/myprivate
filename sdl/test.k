using sdl.*

int color

SDL.init(SDL.SDL_INIT_VIDEO)

Surface test = SDL.createRGBSurface(SDL.SDL_SWSURFACE,256,256,256,0,0,0,0)

String name = SDL.videoDriverName("test",100)

Surface i = SDL.loadBMP("icon.bmp")

SDL.wmSetIcon(i,0)

Surface s = SDL.setVideoMode(444,444,32,SDL.SDL_SWSURFACE)

Surface bmp = SDL.loadBMP("sail.bmp")

int chk=0
for(chk;chk<256;chk++){

bmp.setAlpha(SDL.SDL_SRCALPHA,chk)

bmp.blitSurface(s)

s.flip()

SDL.delay(100)

}
bmp.blitSurface(s)

s.flip()

SDL.delay(2000)

i.setColorKey(SDL.SDL_SRCCOLORKEY)

VideoInfo info = SDL.getVideoInfo()

Cursor c = SDL.getCursor()

String title = SDL.wmSetCaption("hello")

title.wmGetCaption(title)

SDL.wmGrabInput(SDL.SDL_QUERY)

SDL.wmIconifyWindow()

name
info
c
color