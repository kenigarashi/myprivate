using sdl.*
SDL.init(SDL.SDL_INIT_VIDEO)
Surface s = SDL.setVideoMode(612,612,32,SDL.SDL_SWSURFACE)
Surface bmp = SDL.loadBMP("sample.bmp")
int i = 0
for(i;i<128;i++){
	bmp.setAlpha(SDL.SDL_SRCALPHA,i)
	bmp.blitSurface(s)
	s.flip()
	SDL.delay(15)
}
SDL.quit()