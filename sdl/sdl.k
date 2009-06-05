class SDL;
class Surface;
class VideoInfo;
class KeySym;
class KeyBoard;
class MouseMotion;
class MouseButton;
class Event;
class Cursor;

class Rect
{
	int x;
	int y;
	int w;
	int h;
	Rect(int x, int y, int w, int h){
		 _x = x;
		 _y = y;
		 _w = w;
		 _h = h;
	}
};

class Color
{
	int r;
	int g;
	int b;
	Color(int r, int g, int b){
		  _r = r;
		  _g = g;
		  _b = b;
	}
};


//    class PixelFormat;
//    class Overlay;
//    class Joystick;
//    class AudioSpec;
//    class AudioCVT;
//    class CD;




//---------------General------------------------------------
void SDL.init(int flags);
void SDL.initSubSystem(int flags);
void SDL.quit();	
void SDL.quitSubSystem(int flags);
void SDL.wasInit(int flags);
void SDL.getError();



//----------------Video-------------------------------------
int Surface.mapRGB(int red, int green, int blue);
int Surface.mapRGBA(int red, int green, int blue, int alpha);
void SDL.videoModeOK(int width, int height, int bpp, int flags);
void SDL.setGamma(float redgamma, float greengamma, float bluegamma);
void Surface.updateRect(int x, int y, int width, int height);
void Surface.updateRects(int numrects, Rect rects);
void Surface.getClipRect(Rect rect);
void Surface.setClipRect(Rect rect);
void Surface.flip();
void Surface.freeSurface();
void Surface.lockSurface();
void Surface.unLockSurface();
void Surface.saveBMP(String file);
void Surface.setColorKey(int flag, int key);
void Surface.setAlpha(int flag, int alpha);
void Surface.blitSurface(Rect srcrect, Surface screen, Rect dstrect);
void Surface.fillRect(Rect dstrect, int color);
void SDL.warpMouse(int x,int y);
void Color.setColors(Surface screen, int firstcolor, int ncolors);
void Color.setPalette(Surface screen, int flags, int firstcolor, int ncolors);
String SDL.videoDriverName(String namebuf, int maxlen);
Surface SDL.getVideoSurface();
Surface SDL.setVideoMode(int width, int height, int bpp, int flags);
Surface SDL.createRGBSurface(int flags, int width, int height, int depth, int rmask, int gmask, int bmask, int amask);
Surface SDL.loadBMP(String file);
Surface Surface.displayFormat();
Surface Surface.displayFormatAlpha();
VideoInfo SDL.getVideoInfo();

//   void SDL.getGammaRamp(int redtable, int greentable, int bluetable);
//   void SDL.setGammaRamp(int redtable, int greentable, int bluetable);
//   void SDL.getRGB(int pixel, PixelFormat fmt, int red, int green, int blue);
//   void SDL.getRGBA(int pixel, PixelFormat fmt, int red, int green, int blue, int alpha);
//   Surface SDL.createRGBSurfaceFrom(void[] pixels, int width, int height, int depth, int pitch, int rmask, int gmask, int bmask, int amask);
//   Surface SDL.convertSurface(Surface screen, PixelFormat fmt, int flags);



//------------------Cursor-----------------------------------
int Cursor.showCursor(int toggle);
void Cursor.freeCursor();
void Cursor.setCursor();
Cursor Cursor.getCursor();
Cursor Cursor.createCursor(int data, int mask, int width, int height, int hot_x, int hot_y);


//------------------SDL_GL-----------------------------------
//   void SDL.glLoadLibrary(String path);
//   void[] SDL.glGetProcAddress(String proc);
//   void SDL.glGetAttribute(int attr);
//   void SDL.glSetAttribute(int attr, int value);
//   void SDL.glSwapBuffers();


//------------------OverLay----------------------------------
//   void SDL.lockYUVoverlay(Overlay ol);
//   void SDL.unlockYUVoverlay(Overlay ol);
//   void SDL.displayYUVoverlay(Overlay ol, Rect dstrect);
//   void SDL.freeYUVoverlay(Overlay ol);
//   Overlay SDL.createYUVoverlay(int width, int height, int fmt, Surface display);




//-------------Window Management-----------------------------
int SDL.wmIconifyWindow();
int SDL.wmGrabInput(int grabmode);
void String.wmGetCaption(String title); 
void SDL.wmSetIcon(Surface icon, int mask);
void SDL.wmToggleFullScreen(Surface screen);
String SDL.wmSetCaption(String title);




//------------------Time-------------------------------------
void SDL.delay(int ms);
float SDL.getTicks();





//-----------------Event-------------------------------------
int Event.getType();
int Event.waitEvent(Event evt);
int Event.eventState(int type, int state);
int Event.getModState();
int Event.getAppState();
int Event.joystickEventState(int state);
int Event.enableUNICODE(int enable);
void Event.pumpEvents();
void Event.pollEvent(Event evt);
void Event.pushEvent(Event evt);
void Event.setModState(int modstate);
void Event.enableKeyRepeat(int delay, int interval);
Event Event.new();
String Event.getKeyName(int key);
KeyBoard Event.getKeyBoard();
MouseMotion Event.getMouseMotion();
MouseButton Event.getMouseButton();

//   void Event.peepEvents(Event evt, int num, int action, int mask);
//   void Event.setEventFilter(EventFilter filter);
//   EventFilter Event.getEventFilter();
//   int[] Event.getKeyState(int[] numkeys);
//   int Event.getMouseState(int[] x, int[] y);
//   int Event.getRelativemouseState(int[] x, int[] y);




//-----------------Key---------------------------------------
int KeySym.getScanCode();
int KeySym.getSym();
int KeySym.getMod();
int KeySym.getUniCode();
int KeyBoard.getType();
int KeyBoard.getState();
KeySym KeyBoard.getKeySym();




//----------------Mouse------------------------------------
int MouseMotion.getType();
int MouseMotion.getState();
int MouseMotion.getX();
int MouseMotion.getY();
int MouseMotion.getXrel();
int MouseMotion.getYrel();
int MouseButton.getType();
int MouseButton.getButton();
int MouseButton.getState();
int MouseButton.getX();
int MouseButton.getY();



//---------------Joystick-----------------------------------
//	int SDL.numJoysticks();
//	int SDL.joystickOpened(int index); 
//	int SDL.joystickIndex(Joystick js);
//	int SDL.joystickNumaxes(Joystick js);
//	int SDL.joystickNumballs(Joystick js);
//	int SDL.joystickNumhats(Joystick js);
//	int SDL.joystickNumbuttons(Joystick js);
//	int SDL.joystickGetaxis(Joystick js, int axis);
//	int SDL.joystickGethat(Joystick js, int hat);
//	int SDL.joystickGetbutton(Joystick js, int button);
//	void SDL.joystickGetball(Joystick js, int ball, int[] dx, int[] dy);
//	void SDL.joystickClose(Joystick js);
//	void SDL.joystickUpdate();
//	String SDL.joystickName(int index);
//	Joystick SDL.joystickOpen(int index);



//------------------Audio----------------------------------
//	int SDL.getAudiostatus();
//	void SDL.openAudio(AudioSpec desired, AudioSpec obtained);
//	void SDL.pauseAudio(int pause_on);
//	void SDL.freeWAV(int[] audio_buf);
//	void SDL.buildAudioCVT(AudioCVT cvt, int src_fmt, int src_channels, int src_rate, int dst_fmt, int dst_channels, int dst_rate);
//	void SDL.convertAudio(AudioCVT cvt);
//	void SDL.mixAudio(int[] dst, int[] src, int len, int volume);
//	void SDL.lockAudio();
//	void SDL.unLockAudio();
//	void SDL.closeAudio();
//	AudioSpec SDL.loadWAV(String file, AudioSpec spec, int[][] audio_buf, int[] audio_len);



//-----------------CD-ROM------------------------------------
//	CD SDL.cdOpen(int drive);
//	int SDL.cdNumDrives();
//	int SDL.cdStatus(CD cdrom);
//	void SDL.cdPlay(CD cdrom, int start, int length);
//	void SDL.cdPlayTracks(CD cdrom, int start_track, int start_frame, int ntracks, int nframes);
//	String SDL.cdName(int drive);




//-----------Multi-threaded Programming---------------------






//-----------------SDL_image--------------------------------
//	Surface SDL.imgLoad();
//	Surface SDL.imgLoadRW();