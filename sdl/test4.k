using sdl.*

Surface s = SDL.setVideoMode(333,333,32,SDL.SWSURFACE);
int i = s.mapRGB(100,100,100)
Rect r = new Rect(0,0,0,0);
s.fillRect(r,i);
s.flip()