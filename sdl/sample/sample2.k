using sdl.*
SDL.init(SDL.INIT_VIDEO)
Surface s = SDL.setVideoMode(612,612,32,SDL.SWSURFACE)
Rect r1 = new Rect(0, 0, 400, 400)
Rect r2 = new Rect(80, 175, 0, 0)
Surface bmp = SDL.loadBMP("./bmp/sample.bmp")
int i = 0
for(i;i<128;i++){
	bmp.setAlpha(SDL.SRCALPHA,i)
	bmp.blitSurface(r1,s,r2)
	s.flip()
	SDL.delay(15)
}
SDL.quit()

