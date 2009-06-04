using sdl.*

Surface s = SDL.setVideoMode(333,333,8,SDL.SWSURFACE);
Color c = new Color(100,100,100);

c.setColors(s,0,128);
