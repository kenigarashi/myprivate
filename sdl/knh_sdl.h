//#include <konoha.h>

//#ifdef
//#include <SDL/SDL.h>
#include <konoha.h>

typedef struct knh_sdl_rect_t {
  knh_int_t x;
  knh_int_t y;
  knh_int_t w;
  knh_int_t h;
} knh_sdl_rect_t;

typedef struct knh_sdl_color_t {
  knh_int_t r;
  knh_int_t g;
  knh_int_t b;
} knh_sdl_color_t;

typedef struct knh_sdl_active_t {
  knh_int_t type;
  knh_int_t gain;
  knh_int_t state;
} knh_sdl_active_t;

typedef struct knh_sdl_keysym_t {
  knh_int_t scancode;
  knh_int_t sym;
  knh_int_t mod;
  knh_int_t unicode;
} knh_sdl_keysym_t;

typedef struct knh_sdl_keyboard_t {
  knh_int_t type;
  knh_int_t state;
  knh_sdl_keysym_t* keysym;
} knh_sdl_keyboard_t;

typedef struct knh_sdl_mousemotion_t {
  knh_int_t type;
  knh_int_t state;
  knh_int_t x;
  knh_int_t y;
  knh_int_t xrel;
  knh_int_t yrel;
} knh_sdl_mousemotion_t;

typedef struct knh_sdl_mousebutton_t {
  knh_int_t type;
  knh_int_t button;
  knh_int_t state;
  knh_int_t x;
  knh_int_t y;
} knh_sdl_mousebutton_t;

typedef struct knh_sdl_resize_t {
  knh_int_t type;
  knh_int_t w;
  knh_int_t h;
} knh_sdl_resize_t;

typedef struct knh_sdl_expose_t {
  knh_int_t type;
} knh_sdl_expose_t;

typedef struct knh_sdl_quit_t {
  knh_int_t type;
} knh_sdl_quit_t;

typedef struct knh_sdl_event_t {
  knh_int_t type;
  knh_sdl_active_t active;
  knh_sdl_keyboard_t key;
  knh_sdl_mousemotion_t motion;
  knh_sdl_mousebutton_t button;
  knh_sdl_resize_t resize;
  knh_sdl_expose_t expose;
  knh_sdl_quit_t quit;
} knh_sdl_event_t;

/* ConstData */
 
static
knh_IntConstData_t IntConstData[] = {
  // init
  {"SDL.INIT_TIMER", SDL_INIT_TIMER},
  {"SDL.INIT_AUDIO", SDL_INIT_AUDIO},
  {"SDL.INIT_VIDEO", SDL_INIT_VIDEO},
  {"SDL.INIT_CDROM", SDL_INIT_CDROM},
  {"SDL.INIT_JOYSTICK", SDL_INIT_JOYSTICK},
  {"SDL.INIT_EVERYTHING", SDL_INIT_EVERYTHING},
  {"SDL.INIT_NOPARACHUTE", SDL_INIT_NOPARACHUTE},
  {"SDL.INIT_EVENTTHREAD", SDL_INIT_EVENTTHREAD}, 
  // 
  {"SDL.SWSURFACE", SDL_SWSURFACE},
  {"SDL.HWSURFACE", SDL_HWSURFACE},
  {"SDL.ASYNCBLIT", SDL_ASYNCBLIT},
  {"SDL.ANYFORMAT", SDL_ANYFORMAT},
  {"SDL.HWPALETTE", SDL_HWPALETTE},     
  {"SDL.DOUBLEBUF", SDL_DOUBLEBUF},     
  {"SDL.FULLSCREEN", SDL_FULLSCREEN},   
  {"SDL.OPENGL", SDL_OPENGL},           
  {"SDL.OPENGLBLIT", SDL_OPENGLBLIT},   
  {"SDL.RESIZABLE",SDL_RESIZABLE},      
  {"SDL.HWACCEL",SDL_HWACCEL},          
  {"SDL.SRCCOLORKEY", SDL_SRCCOLORKEY}, 
  {"SDL.RLEACCEL", SDL_RLEACCEL},       
  {"SDL.SRCALPHA", SDL_SRCALPHA},       
  {"SDL.PREALLOC", SDL_PREALLOC},       
  //
  {"SDL.ACTIVEEVENT", SDL_ACTIVEEVENT},       
  {"SDL.KEYDOWN", SDL_KEYDOWN},               
  {"SDL.KEYUP", SDL_KEYUP},                   
  {"SDL.MOUSEMOTION", SDL_MOUSEMOTION},       
  {"SDL.MOUSEBUTTONDOWN", SDL_MOUSEBUTTONDOWN}, 
  {"SDL.MOUSEBUTTONUP", SDL_MOUSEBUTTONUP},     
  {"SDL.JOYAXISMOTION", SDL_JOYAXISMOTION},   
  {"SDL.JOYBALLMOTION", SDL_JOYBALLMOTION},   
  {"SDL.JOYHATMOTION", SDL_JOYHATMOTION},     
  {"SDL.JOYBUTTONDOWN", SDL_JOYBUTTONDOWN},   
  {"SDL.JOYBUTTONUP", SDL_JOYBUTTONUP},       
  {"SDL.QUIT", SDL_QUIT},                     
  {"SDL.SYSWMEVENT", SDL_SYSWMEVENT},         
  {"SDL.VIDEORESIZE", SDL_VIDEORESIZE},       
  {"SDL.VIDEOEXPOSE", SDL_VIDEOEXPOSE},       
  {"SDL.USEREVENT",  SDL_USEREVENT},          
  //
  {"SDL.ENABLE", SDL_ENABLE},   
  {"SDL.DISABLE", SDL_DISABLE}, 
  {"SDL.QUERY", SDL_QUERY},     
  //
  {"SDL.DEFAULT_REPEAT_DELAY", SDL_DEFAULT_REPEAT_DELAY},
  {"SDL.DEFAULT_REPEAT_INTERVAL", SDL_DEFAULT_REPEAT_INTERVAL},
  //
  {"SDL.GRAB_QUERY", SDL_GRAB_QUERY},
  {"SDL.GRAB_OFF", SDL_GRAB_OFF},
  {"SDL.GRAB_ON", SDL_GRAB_ON},
  //
  {"SDL.SDLK_BACKSPACE", SDLK_BACKSPACE},
  {"SDL.SDLK_TAB", SDLK_TAB},
  {"SDL.SDLK_CLEAR", SDLK_CLEAR},
  {"SDL.SDLK_RETURN", SDLK_RETURN},
  {"SDL.SDLK_PAUSE", SDLK_PAUSE},
  {"SDL.SDLK_ESCAPE", SDLK_ESCAPE},
  {"SDL.SDLK_SPACE", SDLK_SPACE},
  {"SDL.SDLK_EXCLAIM", SDLK_EXCLAIM},
  {"SDL.SDLK_QUOTEDBL", SDLK_QUOTEDBL},
  {"SDL.SDLK_HASH", SDLK_HASH},
  {"SDL.SDLK_DOLLAR", SDLK_DOLLAR},
  {"SDL.SDLK_AMPERSAND", SDLK_AMPERSAND},
  {"SDL.SDLK_QUOTE", SDLK_QUOTE},
  {"SDL.SDLK_LEFTPAREN", SDLK_LEFTPAREN},
  {"SDL.SDLK_RIGHTPAREN", SDLK_RIGHTPAREN},
  {"SDL.SDLK_ASTERISK", SDLK_ASTERISK},
  {"SDL.SDLK_PLUS", SDLK_PLUS},
  {"SDL.SDLK_COMMA", SDLK_COMMA},
  {"SDL.SDLK_MINUS", SDLK_MINUS},
  {"SDL.SDLK_PERIOD", SDLK_PERIOD},
  {"SDL.SDLK_SLASH", SDLK_SLASH},
  {"SDL.SDLK_0", SDLK_0},
  {"SDL.SDLK_1", SDLK_1},
  {"SDL.SDLK_2", SDLK_2},
  {"SDL.SDLK_3", SDLK_3},
  {"SDL.SDLK_4", SDLK_4},
  {"SDL.SDLK_5", SDLK_5},
  {"SDL.SDLK_6", SDLK_6},
  {"SDL.SDLK_7", SDLK_7},
  {"SDL.SDLK_8", SDLK_8},
  {"SDL.SDLK_9", SDLK_9},
  {"SDL.SDLK_COLON", SDLK_COLON},
  {"SDL.SDLK_SEMICOLON", SDLK_SEMICOLON},
  {"SDL.SDLK_LESS", SDLK_LESS},
  {"SDL.SDLK_EQUALS",SDLK_EQUALS},
  {"SDL.SDLK_GREATER", SDLK_GREATER},
  {"SDL.SDLK_QUESTION", SDLK_QUESTION},
  {"SDL.SDLK_AT", SDLK_AT},
  {"SDL.SDLK_LEFTBRACKET", SDLK_LEFTBRACKET},
  {"SDL.SDLK_BACKSLASH", SDLK_BACKSLASH},
  {"SDL.SDLK_RIGHTBRACKET", SDLK_RIGHTBRACKET},
  {"SDL.SDLK_CARET", SDLK_CARET},
  {"SDL.SDLK_UNDERSCORE", SDLK_UNDERSCORE},
  {"SDL.SDLK_BACKQUOTE", SDLK_BACKQUOTE},
  {"SDL.SDLK_A", SDLK_a},
  {"SDL.SDLK_B", SDLK_b},
  {"SDL.SDLK_C", SDLK_c},
  {"SDL.SDLK_D", SDLK_d},
  {"SDL.SDLK_E", SDLK_e},
  {"SDL.SDLK_F", SDLK_f},
  {"SDL.SDLK_G", SDLK_g},
  {"SDL.SDLK_H", SDLK_h},
  {"SDL.SDLK_I", SDLK_i},
  {"SDL.SDLK_J", SDLK_j},
  {"SDL.SDLK_K", SDLK_k},
  {"SDL.SDLK_L", SDLK_l},
  {"SDL.SDLK_M", SDLK_m},
  {"SDL.SDLK_N", SDLK_n},
  {"SDL.SDLK_O", SDLK_o},
  {"SDL.SDLK_P", SDLK_p},
  {"SDL.SDLK_Q", SDLK_q},
  {"SDL.SDLK_R", SDLK_r},
  {"SDL.SDLK_S", SDLK_s},
  {"SDL.SDLK_T", SDLK_t},
  {"SDL.SDLK_U", SDLK_u},
  {"SDL.SDLK_V", SDLK_v},
  {"SDL.SDLK_W", SDLK_w},
  {"SDL.SDLK_X", SDLK_x},
  {"SDL.SDLK_Y", SDLK_y},
  {"SDL.SDLK_Z", SDLK_z},
  {"SDL.SDLK_DELETE", SDLK_DELETE},
  {"SDL.SDLK_KP0", SDLK_KP0},
  {"SDL.SDLK_KP1", SDLK_KP1},
  {"SDL.SDLK_KP2", SDLK_KP2},
  {"SDL.SDLK_KP3", SDLK_KP3},
  {"SDL.SDLK_KP4", SDLK_KP4},
  {"SDL.SDLK_KP5", SDLK_KP5},
  {"SDL.SDLK_KP6", SDLK_KP6},
  {"SDL.SDLK_KP7", SDLK_KP7},
  {"SDL.SDLK_KP8", SDLK_KP8},
  {"SDL.SDLK_KP9", SDLK_KP9},
  {"SDL.SDLK_KP_PERIOD", SDLK_KP_PERIOD},
  {"SDL.SDLK_KP_DIVIDE", SDLK_KP_DIVIDE},
  {"SDL.SDLK_KP_MULTIPLY", SDLK_KP_MULTIPLY},
  {"SDL.SDLK_KP_MINUS", SDLK_KP_MINUS},
  {"SDL.SDLK_KP_PLUS", SDLK_KP_PLUS},
  {"SDL.SDLK_KP_ENTER", SDLK_KP_ENTER},
  {"SDL.SDLK_KP_EQUALS", SDLK_KP_EQUALS},
  {"SDL.SDLK_UP", SDLK_UP},
  {"SDL.SDLK_DOWN", SDLK_DOWN},
  {"SDL.SDLK_RIGHT", SDLK_RIGHT},
  {"SDL.SDLK_LEFT", SDLK_LEFT},
  {"SDL.SDLK_INSERT", SDLK_INSERT},
  {"SDL.SDLK_HOME", SDLK_HOME},
  {"SDL.SDLK_END", SDLK_END},
  {"SDL.SDLK_PAGEUP", SDLK_PAGEUP},
  {"SDL.SDLK_PAGEDOWN", SDLK_PAGEDOWN},
  {"SDL.SDLK_F1", SDLK_F1},
  {"SDL.SDLK_F2", SDLK_F2},
  {"SDL.SDLK_F3", SDLK_F3},
  {"SDL.SDLK_F4", SDLK_F4},
  {"SDL.SDLK_F5", SDLK_F5},
  {"SDL.SDLK_F6", SDLK_F6},
  {"SDL.SDLK_F7", SDLK_F7},
  {"SDL.SDLK_F8", SDLK_F8},
  {"SDL.SDLK_F9", SDLK_F9},
  {"SDL.SDLK_F10", SDLK_F10},
  {"SDL.SDLK_F11", SDLK_F11},
  {"SDL.SDLK_F12", SDLK_F12},
  {"SDL.SDLK_F13", SDLK_F13},
  {"SDL.SDLK_F14", SDLK_F14},
  {"SDL.SDLK_F15", SDLK_F15},
  {"SDL.SDLK_NUMLOCK", SDLK_NUMLOCK},
  {"SDL.SDLK_CAPSLOCK", SDLK_CAPSLOCK},
  {"SDL.SDLK_SCROLLOCK", SDLK_SCROLLOCK},
  {"SDL.SDLK_RSHIFT", SDLK_RSHIFT},
  {"SDL.SDLK_LSHIFT", SDLK_LSHIFT},
  {"SDL.SDLK_RCTRL", SDLK_RCTRL},
  {"SDL.SDLK_LCTRL", SDLK_LCTRL},
  {"SDL.SDLK_RALT", SDLK_RALT},
  {"SDL.SDLK_LALT", SDLK_LALT},
  {"SDL.SDLK_RMETA", SDLK_RMETA},
  {"SDL.SDLK_LMETA", SDLK_LMETA},
  {"SDL.SDLK_LSUPER", SDLK_LSUPER},
  {"SDL.SDLK_RSUPER", SDLK_RSUPER},
  {"SDL.SDLK_MODE", SDLK_MODE},
  {"SDL.SDLK_HELP", SDLK_HELP},
  {"SDL.SDLK_PRINT", SDLK_PRINT},
  {"SDL.SDLK_SYSREQ", SDLK_SYSREQ},
  {"SDL.SDLK_BREAK", SDLK_BREAK},
  {"SDL.SDLK_MENU", SDLK_MENU},
  {"SDL.SDLK_POWER", SDLK_POWER},
  {"SDL.SDLK_EURO", SDLK_EURO},
  //
  {"SDL.KMOD_NONE", KMOD_NONE},
  {"SDL.KMOD_NUM", KMOD_NUM},
  {"SDL.KMOD_CAPS", KMOD_CAPS},
  {"SDL.KMOD_LCTRL", KMOD_LCTRL},
  {"SDL.KMOD_RCTRL", KMOD_RCTRL},
  {"SDL.KMOD_RSHIFT", KMOD_RSHIFT},
  {"SDL.KMOD_LSHIFT", KMOD_LSHIFT},
  {"SDL.KMOD_RALT", KMOD_RALT},
  {"SDL.KMOD_LALT", KMOD_LALT},
  {"SDL.KMOD_CTRL", KMOD_CTRL},
  {"SDL.KMOD_SHIFT", KMOD_SHIFT},
  {"SDL.KMOD_ALT", KMOD_ALT},
  //
  {"SDL.HAT_CENTERED", SDL_HAT_CENTERED},
  {"SDL.HAT_UP", SDL_HAT_UP},
  {"SDL.HAT_RIGHT", SDL_HAT_RIGHT},
  {"SDL.HAT_DOWN", SDL_HAT_DOWN},
  {"SDL.HAT_LEFT", SDL_HAT_LEFT},
  {"SDL.HAT_RIGHTUP", SDL_HAT_RIGHTUP},
  {"SDL.HAT_RIGHTDOWN", SDL_HAT_RIGHTDOWN},
  {"SDL.HAT_LEFTUP", SDL_HAT_LEFTUP},
  {"SDL.HAT_LEFTDOWN", SDL_HAT_LEFTDOWN},
  //
  {"SDL.AUDIO_U8", AUDIO_U8},
  {"SDL.AUDIO_S8", AUDIO_S8},
  {"SDL.AUDIO_U16", AUDIO_U16},
  {"SDL.AUDIO_U16LSB", AUDIO_U16LSB},
  {"SDL.AUDIO_S16", AUDIO_S16},
  {"SDL.AUDIO_S16LSB", AUDIO_S16LSB},
  {"SDL.AUDIO_U16MSB", AUDIO_U16MSB},
  {"SDL.AUDIO_U16SYS", AUDIO_U16SYS},
  {"SDL.AUDIO_U16LSB", AUDIO_U16LSB},
  {"SDL.AUDIO_U16MSB", AUDIO_U16MSB},
  {"SDL.AUDIO_S16SYS", AUDIO_S16SYS},
  {"SDL.AUDIO_S16LSB", AUDIO_S16LSB},
  {"SDL.AUDIO_S16MSB", AUDIO_S16MSB},
  //
  {"SDL.AUDIO_STOPPED", SDL_AUDIO_STOPPED},
  {"SDL.AUDIO_PAUSED", SDL_AUDIO_PAUSED},
  {"SDL.AUDIO_PLAYING", SDL_AUDIO_PLAYING},
  //
  {"SDL.CD_TRAYEMPTY", CD_TRAYEMPTY},
  {"SDL.CD_STOPPED", CD_STOPPED},
  {"SDL.CD_PLAYING", CD_PLAYING},
  {"SDL.CD_PAUSED", CD_PAUSED},
  {"SDL.CD_ERROR", CD_ERROR},
  //
  {"SDL.GL_RED_SIZE", SDL_GL_RED_SIZE},
  {"SDL.GL_GREEN_SIZE", SDL_GL_GREEN_SIZE},
  {"SDL.GL_BLUE_SIZE", SDL_GL_BLUE_SIZE},
  {"SDL.GL_ALPHA_SIZE", SDL_GL_ALPHA_SIZE},
  {"SDL.GL_DOUBLEBUFFER", SDL_GL_DOUBLEBUFFER},
  {"SDL.GL_BUFFER_SIZE", SDL_GL_BUFFER_SIZE},
  {"SDL.GL_DEPTH_SIZE", SDL_GL_DEPTH_SIZE},
  {"SDL.GL_STENCIL_SIZE", SDL_GL_STENCIL_SIZE},
  {"SDL.GL_ACCUM_RED_SIZE", SDL_GL_ACCUM_RED_SIZE},
  {"SDL.GL_ACCUM_GREEN_SIZE", SDL_GL_ACCUM_GREEN_SIZE},
  {"SDL.GL_ACCUM_BLUE_SIZE", SDL_GL_ACCUM_BLUE_SIZE},
  {"SDL.GL_ACCUM_ALPHA_SIZE",SDL_GL_ACCUM_ALPHA_SIZE},
  {NULL}  // end of const data
};
 
KNHAPI(int) init(Ctx *ctx)
{
  KNH_NOTICE(ctx, "loading math...");
  konoha_loadIntConstData(ctx, IntConstData);
  return 1;
}

/*
class KeySym
{
	int scancode;
	int sym;
	int mode;
	int unicode;
	KeySym(int scancode, int sym, int mode, int unicode){
		   _scancode = scancode; _sym = sym; _mode = mode; _unicode = unicode;
	}
};

class KeyBoard
{
	int type;
	int state;
	KeySym keysym;
	KeyBoard(int type, int state, KeySym keysym){
		     _type = type; _state = state; _keysym = keysym;
	}
}

class MouseMotion
{
	int type;
	int state;
	int x;
	int y;
	int xrel;
	int yrel;
	MouseMotion(int type, int state, int x, int y, int xrel, int yrel){
			_type = type; _state = state;
			_x = x;
			_y = y;
			_xrel = xrel;
			_yrel = yrel;
	}
};

class MouseButton
{
	int type;
	int button;
	int state;
	int x;
	int y;
	MouseButton(int type, int button, int state, int x, int y){
			_type = type;
			_button = button;
			_state = state;
			_x = x;
			_y = y;
	}
};

class Active
{
	int type;
	int gain;
	int state;
	Active(int type, int gain, int state){
		   _type = type;
		   _gain = gain;
		   _state = state;
	}
};

class Resize
{
	int type;
	int w;
	int h;
	Resize(int type, int w, int h){
		   _type = type;
		   _w = w;
		   _h = h;
	}
};

class Expose
{
	int type;
	Expose(int type){
		   _type = type;
	}
};

class Quit
{
	int type;
	Quit(int type){
		 _type = type;
	}
};

class Event
{
	int type;
	Active active;
	KeyBoard key;
	MouseMotion motion;
	MouseButton button;
	Resize resize;
	Expose expose;
	Quit quit;
	Event(int type, Active active, KeyBoard key, MouseMotion motion, MouseButton button, Resize resize, Expose expose, Quit quit){
		  _type = type; _active = active; _key = key; _motion = motion; _button = button; _resize = resize; _expose = expose; _quit = quit;
	}

}

*/
