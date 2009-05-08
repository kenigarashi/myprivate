class SDL;
class Surface;
class VideoInfo;
class Event;
class Rect;
class PixelFormat;
class Color;
class Cursor;
class Overlay;
class Eventaction;
class Joystick;
class AudioSpec;
class AudioCVT;
class CD;



void SDL.sample()



//	General
void SDL.init(int flags);
void SDL.initSubSystem(int flags);
void SDL.quit();							
void SDL.quitSubSystem(int flags);
void SDL.wasInit(int flags);
void SDL.getError();


//	Video
Surface SDL.getVideoSurface();
VideoInfo SDL.getVideoInfo();
String SDL.videoDriverName(String namebuf, int maxlen);
// TODO
void SDL.listModes(PixelFormat fmt, int flags);

void SDL.videoModeOK(int width, int height, int bpp, int flags);
Surface SDL.setVideoMode(int width, int height, int bpp, int flags);
void Surface.updateRect(int x, int y, int width, int height);

//void SDL.updateRects(Surface screen, int numrects, Rect rects);
void Surface.flip();

//void SDL.setColors(Surface screen, Color color, int firstcolor, int ncolors);
//void SDL.setPalette(Surface screen, int flags, Color color, int firstcolor, int ncolors);

//void SDL.setGamma(float redgamma, float greengamma, float bluegamma);	
//void SDL.getGammaramp(int* redtable, int* greentable, int* bluetable);
//void SDL.setGammaramp(int* redtable, int* greentable, int* bluetable);

int Surface.mapRGB(int r, int g, int b);
//int SDL.mapRGBA(PixelFormat fmt, int r, int g, int b, int a);
//void SDL.getRGB(int pixel, PixelFormat fmt, int r, int g, int b);
//void SDL.getRGBA(int pixel, PixelFormat fmt, int r, int g, int b, int a);

Surface SDL.createRGBSurface(int flags, int width, int height, int depth, int rmask, int gmask, int bmask, int amask);
//todo
Surface SDL.createRGBSurfaceFrom(void[] pixels, int width, int height, int depth, int pitch, int rmask, int gmask, int bmask, int amask);

void Surface.freeSurface();
void Surface.lockSurface();
void Surface.unLockSurface();
Surface SDL.loadBMP(String file);
void Surface.saveBMP(String file);
void Surface.setColorKey(int flag);
//chk
void Surface.setAlpha(int flag, int alpha);

//void SDL.setCliprect(Surface surface, Rect rect);
//void SDL.getCliprect(Surface surface, Rect rect);
//Surface SDL.converSurface(Surface screen, PixelFormat fmt, int flags);

void Surface.blitSurface(Surface screen);

//void Surface.fillRect(Rect dstrect, int color);

//check
void Surface.displayFormat();
Surface Surface.displayFormatAlpha();

void SDL.warpMouse(int x,int y);

//todo
Cursor SDL.createCursor(int data, int mask, int width, int height, int hot_x, int hot_y);

//void SDL.freeCursor(Cursor cursor);
//void* SDL.setCursor(Cursor cursor);

Cursor SDL.getCursor();

int SDL.showCursor(int toggle);
void SDL.glLoadLibrary(String path);

// void* SDL.glGetProcAddress(String proc);
// void SDL.glGetAttribute(GLattr attr, int* value);
//void SDL.glSetAttribute(int attr, int value);
//void SDL.glSwapbuffers();
//Overlay SDL.createYUVoverlay(int width, int height, int fmt, Surface display);
//void SDL.lockYUVoverlay(Overlay o);
//void SDL.unlockYUVoverlay(Overlay ol);
//void SDL.displayYUVoverlay(Overlay ol, Rect dstrect);
//void SDL.freeYUVoverlay(Overlay ol);

//   	Window Management
String SDL.wmSetCaption(String title);
void String.wmGetCaption(String title); 
void SDL.wmSetIcon(Surface icon, int mask);
int SDL.wmIconifyWindow();
int SDL.wmGrabInput(int grabmode);
//todo
void Surface.wmToggleFullScreen();


//   	Event
//void SDL.pumpEvents();
//void SDL.peepEvents(Event evt, int num, int action, int mask);
//void SDL.pollEvent(Event evt);
//void SDL.waitEvent(Event evt);
//void SDL.pushEvent(Event evt);
// void SDL.setEventfilter(EventFilter filter);
// EventFilter SDL.getEventfilter();
//int SDL.eventState(int type, int state);
//int* SDL.getKeyState(int* numkeys);
//int SDL.getModstate();
//void SDL.setModstate(int modstate);
//void SDL.getKeyname(int key);
//void SDL.enableUNICODE(int enable);
//void SDL.enableKeyrepeat(int delay, int interval);
//int SDL.getMousestate(int[] x, int[] y);
//int SDL.getRelativemousestate(int[] x, int[] y);
//int SDL.getAppstate();
//int SDL.joystickEventstate(int state);

//   	Joystick
//int SDL.numJoysticks();
//String SDL.joystickName(int index);
//Joystick SDL.joystickOpen(int index);
//int SDL.joystickOpened(int index); 
//int SDL.joystickIndex(Joystick js);
//int SDL.joystickNumaxes(Joystick js);
//int SDL.joystickNumballs(Joystick js);
//int SDL.joystickNumhats(Joystick js);
//int SDL.joystickNumbuttons(Joystick js);
//void SDL.joystickUpdate();
//int SDL.joystickGetaxis(Joystick js, int axis);
//int SDL.joystickGethat(Joystick js, int hat);
//int SDL.joystickGetbutton(Joystick js, int button);
//void SDL.joystickGetball(Joystick js, int ball, int[] dx, int[] dy);
//void SDL.joystickClose(Joystick js);

//	Audio
//void SDL.openAudio(AudioSpec desired, AudioSpec obtained);
//void SDL.pauseAudio(int pause_on);
//int SDL.getAudiostatus();
//AudioSpec SDL.loadWAV(String file, AudioSpec spec, int[][] audio_buf, int[] audio_len);
//void SDL.freeWAV(int[] audio_buf);
//void SDL.buildAudioCVT(AudioCVT cvt, int src_fmt, int src_channels, int src_rate, int dst_fmt, int dst_channels, int dst_rate);
//void SDL.convertAudio(AudioCVT cvt);
//void SDL.mixAudio(int[] dst, int[] src, int len, int volume);
//void SDL.lockAudio();
//void SDL.unLockAudio();
//void SDL.closeAudio();

//	CD-ROM
//int SDL.cdNumDrives();
//String SDL.cdName(int drive);
//CD SDL.cdOpen(int drive);
//int SDL.cdStatus(CD cdrom);
//void SDL.cdPlay(CD cdrom, int start, int length);
//void SDL.cdPlayTracks(CD cdrom, int start_track, int start_frame, int ntracks, int nframes);


//	Multi-threaded Programming





//	Time
float SDL.getTicks();
void SDL.delay(int ms);


















//    	SDL_image

//Surface SDL.imgLoad();
//Surface SDL.imgLoadRW();