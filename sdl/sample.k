using sdl.*
SDL.init(SDL.SDL_INIT_VIDEO)
Surface s = SDL.setVideoMode(612,612,32,SDL.SDL_SWSURFACE)
Rect r1 = new Rect(0,0,400,400)
Rect r2 = new Rect(80,150,0,0)
Surface bmp = SDL.loadBMP("sample.bmp")
bmp.blitSurface(r1,s,r2)
int i =1;
for(i;i<612;i++){
	s.updateRect(i,i,i,i)
	SDL.delay(5)
}
SDL.quit()

