using sdl.*
SDL.init(SDL.SDL_INIT_VIDEO)
SDL.initSubSystem(SDL.SDL_INIT_EVERYTHING)
SDL.wasInit(SDL.SDL_INIT_VIDEO)
SDL.quitSubSystem(SDL.SDL_INIT_VIDEO)



Surface s = SDL.setVideoMode(333,333,32,SDL.SDL_SWSURFACE)
Surface i = SDL.loadBMP("sample.bmp")
SDL.wmSetCaption("hello")

s.wmToggleFullScreen()
s.blitSurface(i)
s.lockSurface()
s.unLockSurface()
s = SDL.getVideoSurface()
SDL.wmIconifyWindow()
s.updateRect(33,33,33,33)
SDL.warpMouse(22,22)
a = SDL.showCursor(SDL.SDL_QUERY)
s.flip()
int a = SDL.wmGrabInput(SDL.SDL_GRAB_QUERY)
VideoInfo info = SDL.getVideoInfo()
SDL.getError()
SDL.quit()
s.freeSurface()
SDL.getTicks()