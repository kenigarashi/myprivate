using sdl.*
SDL.init(SDL.SDL_INIT_VIDEO)
Surface s = SDL.setVideoMode(612,612,32,SDL.SDL_SWSURFACE)
Surface bmp = SDL.loadBMP("sample.bmp")
bmp.blitSurface(s)
int i =1;
for(i;i<256;i++){
	s.updateRect(i,i,i,i)
	SDL.delay(10)
}
SDL.quit()

