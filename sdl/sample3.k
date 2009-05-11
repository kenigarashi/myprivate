using sdl.*

Color c = new Color(1,2,3)

SDL.testColor(c);

Rect r1 = new Rect(0,0,400,400)

Rect r2 = new Rect(100,100,0,0)

SDL.testRect(r1)

SDL.testRect(r2)

Surface s = SDL.setVideoMode(500,500,32,SDL.SDL_SWSURFACE)

Surface bmp = SDL.loadBMP("sample.bmp")

bmp.blitSurface(r1,s,r2)

s.flip()


