#include<konoha.h>
#include<SDL.h>
#include<SDL_image.h>

/* ConstData */

static
knh_IntConstData_t IntConstData[] = {

  //
  {"SDL_INIT_TIMER", SDL_INIT_TIMER},             
  {"SDL_INIT_AUDIO", SDL_INIT_AUDIO},　           
  {"SDL_INIT_VIDEO", SDL_INIT_VIDEO},             
  {"SDL_INIT_CDROM", SDL_INIT_CDROM},　　　　     
  {"SDL_INIT_JOYSTICK", SDL_INIT_JOYSTICK},       
  {"SDL_INIT_EVERYTHING", SDL_INIT_EVERYTHING},   
  {"SDL_INIT_NOPARACHUTE", SDL_INIT_NOPARACHUTE}, 
  {"SDL_INIT_EVENTTHREAD", SDL_INIT_EVENTTHREAD}, 
  //
  {"SDL_SWSURFACE", SDL_SWSURFACE},     
  {"SDL_HWSURFACE", SDL_HWSURFACE},     
  {"SDL_ASYNCBLIT", SDL_ASYNCBLIT},     
  {"SDL_ANYFORMAT", SDL_ANYFORMAT},     
  {"SDL_HWPALETTE", SDL_HWPALETTE},     
  ("SDL_DOUBLEBUF", SDL_DOUBLEBUF},     
  {"SDL_FULLSCREEN", SDL_FULLSCREEN},   
  {"SDL_OPENGL", SDL_OPENGL},           
  {"SDL_OPENGLBLIT", SDL_OPENGLBLIT},   
  {"SDL_RESIZABLE",SDL_RESIZABLE},      
  {"SDL_HWACCEL",SDL_HWACCEL},          
  {"SDL_SRCCOLORKEY", SDL_SRCCOLORKEY}, 
  {"SDL_RLEACCEL", SDL_RLEACCEL},       
  {"SDL_SRCALPHA", SDL_SRCALPHE},       
  {"SDL_PREALLOC", SDL_PREALLOC},       
  //
  {"SDL_ACTIVEEVENT", SDL_ACTIVEEVENT},       
  {"SDL_KEYDOWN", SDL_KEYDOWN},               
  {"SDL_KEYUP", SDL_KEYUP},                   
  {"SDL_MOUSEMOTION", SDL_MOUSEMOTION},       
  {"SDL_MOUBUTTONDOWN", SDL_MOUSEBUTTONDOWN}, 
  {"SDL_MOUBUTTONUP", SDL_MOUSEBUTTONUP},     
  {"SDL_JOYAXISMOTION", SDL_JOYAXISMOTION},   
  {"SDL_JOYBALLMOTION", SDL_JOYBALLMOTION},   
  {"SDL_JOYHATMOTION", SDL_JOYHATMOTION},     
  {"SDL_JOYBUTTONDOWN", SDL_JOYBUTTONDOWN},   
  {"SDL_JOYBUTTONUP", SDL_JOYBUTTONUP},       
  {"SDL_QUIT", SDL_QUIT},                     
  {"SDL_SYSWMEVENT", SDL_SYSWMEVENT},         
  {"SDL_VIDEORESIZE", SDL_VIDEORESIZE},       
  {"SDL_VIDEOEXPOSE", SDL_VIDEOEXPOSE},       
  {"SDL_USEREVENT",  SDL_USEREVENT},          
  //
  {"SDL_ENABLE", SDL_ENABLE},   
  {"SDL_DISABLE", SDL_DISABLE}, 
  {"SDL_QUERY", SDL_QUERY},     
  //
  {"SDL_GRAB_QUERY", SDL_GRAB_QUERY},
  {"SDL_GRAB_OFF", SDL_GRAB_OFF},
  {"SDL_GRAB_ON", SDL_GRAB_ON},
  //
  {"SDLK_BACKSPACE", SDLK_BACKSPACE},
  {"SDLK_TAB", SDLK_TAB},
  {"SDLK_CLEAR", SDLK_CLEAR},
  {"SDLK_RETURN", SDLK_RETURN},
  {"SDLK_PAUSE", SDLK_PAUSE},
  {"SDLK_ESCAPE", SDLK_EXCAPE},
  {"SDLK_SPACE", SDLK_SPACE},
  {"SDLK_EXCLAIM", SDLK_EXCLAIM},
  {"SDLK_QUOTEDBL", SDLK_QUOTEDBL},
  {"SDLK_HASH", SDLK_HASH},
  {"SDLK_DOLLAR", SDLK_DOLLAR},
  {"SDLK_AMPERSAND", SDLK_AMPERSAND},
  {"SDLK_QUOTE", SDLK_QUOTE},
  {"SDLK_LEFTPAREN", SDLK_LEFTPAREN},
  {"SDLK_RIGHTPAREN", SDLK_RIGHTPAREN},
  {"SDLK_ASTERISK", SDLK_ASTERISK},
  {"SDLK_PLUS", SDLK_PLUS},
  {"SDLK_COMMA", SDLK_COMMA},
  {"SDLK_MINUS", SDLK_MINUS},
  {"SDLK_PERIOD", SDLK_PERIOD},
  {"SDLK_SLASH", SDLK_SLASH},
  {"SDLK_0", SDLK_0},
  {"SDLK_1", SDLK_1},
  {"SDLK_2", SDLK_2},
  {"SDLK_3", SDLK_3},
  {"SDLK_4", SDLK_4}
  {"SDLK_5", SDLK_5},
  {"SDLK_6", SDLK_6},
  {"SDLK_7", SDLK_7},
  {"SDLK_8", SDLK_8},
  {"SDLK_9", SDLK_9},
  {"SDLK_COLON", SDLK_COLON},
  {"SDLK_SEMICOLON", SDLK_SEMICOLON},
  {"SDLK_LESS", SDLK_LESS},
  {"SDLK_EQUALS",SDLK_EQUALS},
  {"SDLK_GREATER", SDLK_GREATER},
  {"SDLK_QUESTION", SDLK_QUESTION},
  {"SDLK_AT", SDLK_AT},
  {"SDLK_LEFTBRACKET", SDLK_LEFTBRACKET},
  {"SDLK_BACKSLASH", SDLK_BACKSLASH},
  {"SDLK_RIGHTBRACKET", SDLK_RIGHTBRACKET},
  {"SDLK_CARET", SDLK_CARET},
  {"SDLK_UNDERSCORE", SDLK_UNDERSCORE},
  {"SDLK_BACKQUOTE", SDLK_BACKQUOTE},
  {"SDLK_A", SDLK_a},
  {"SDLK_B", SDLK_b},
  {"SDLK_C", SDLK_c},
  {"SDLK_D", SDLK_d},
  {"SDLK_E", SDLK_e},
  {"SDLK_F", SDLK_f},
  {"SDLK_G", SDLK_g},
  {"SDLK_H", SDLK_h},
  {"SDLK_I", SDLK_i},
  {"SDLK_J", SDLK_j},
  {"SDLK_K", SDLK_k},
  {"SDLK_L", SDLK_l},
  {"SDLK_M", SDLK_m},
  {"SDLK_N", SDLK_n},
  {"SDLK_O", SDLK_o},
  {"SDLK_P", SDLK_p},
  {"SDLK_Q", SDLK_q},
  {"SDLK_R", SDLK_r},
  {"SDLK_S", SDLK_s},
  {"SDLK_T", SDLK_t},
  {"SDLK_U", SDLK_u},
  {"SDLK_V", SDLK_v},
  {"SDLK_W", SDLK_w},
  {"SDLK_X", SDLK_x},
  {"SDLK_Y", SDLK_y},
  {"SDLK_Z", SDLK_z},
  {"SDLK_DELETE", SDLK_DELETE},
  {"SDLK_KP0", SDLK_KP0},
  {"SDLK_KP1", SDLK_KP1},
  {"SDLK_KP2", SDLK_KP2},
  {"SDLK_KP3", SDLK_KP3},
  {"SDLK_KP4", SDLK_KP4},
  {"SDLK_KP5", SDLK_KP5},
  {"SDLK_KP6", SDLK_KP6},
  {"SDLK_KP7", SDLK_KP7},
  {"SDLK_KP8", SDLK_KP8},
  {"SDLK_KP9", SDLK_KP9},
  {"SDLK_KP_PERIOD", SDLK_KP_PERIOD},
  {"SDLK_KP_DIVIDE", SDLK_KP_DIVIDE},
  {"SDLK_KP_MULTIPLY", SDLK_KP_MULTIPLY},
  {"SDLK_KP_MINUS", SDLK_KP_MINUS},
  {"SDLK_KP_PLUS", SDLK_KP_PLUS},
  {"SDLK_KP_ENTER", SDLK_KP_ENTER},
  {"SDLK_KP_EQUALS", SDLK_KP_EQUALS},
  {"SDLK_UP", SDLK_UP},
  {"SDLK_DOWN", SDLK_DOWN},
  {"SDLK_RIGHT", SDLK_RIGHT},
  {"SDLK_LEFT", SDLK_LEFT},
  {"SDLK_INSERT", SDLK_INSERT},
  {"SDLK_HOME", SDLK_HOME},
  {"SDLK_END", SDLK_END},
  {"SDLK_PAGEUP", SDLK_PAGEUP},
  {"SDLK_PAGEDOWN", SDLK_PAGEDOWN},
  {"SDLK_F1", SDLK_F1},
  {"SDLK_F2", SDLK_F2},
  {"SDLK_F3", SDLK_F3},
  {"SDLK_F4", SDLK_F4},
  {"SDLK_F5", SDLK_F5},
  {"SDLK_F6", SDLK_F6},
  {"SDLK_F7", SDLK_F7},
  {"SDLK_F8", SDLK_F8},
  {"SDLK_F9", SDLK_F9},
  {"SDLK_F10", SDLK_F10},
  {"SDLK_F11", SDLK_F11},
  {"SDLK_F12", SDLK_F12},
  {"SDLK_F13", SDLK_F13},
  {"SDLK_F14", SDLK_F14},
  {"SDLK_F15", SDLK_F15},
  {"SDLK_NUMLOCK", SDLK_NUMLOCK},
  {"SDLK_CAPSLOCK", SDLK_CAPSLOCK},
  {"SDLK_SCROLLOCK", SDLK_SCROLLOCK},
  {"SDLK_RSHIFT", SDLK_RSHIFT},
  {"SDLK_LSHIFT", SDLK_LSHIFT},
  {"SDLK_RCTRL", SDLK_RCTRL},
  {"SDLK_LCTRL", SDLK_LCTRL},
  {"SDLK_RALT", SDLK_RALT},
  {"SDLK_LALT", SDLK_LALT},
  {"SDLK_RMETA", SDLK_RMETA},
  {"SDLK_LMETA", SDLK_LMETA},
  {"SDLK_LSUPER", SDLK_LSUPER},
  {"SDLK_RSUPER", SDLK_RSUPER},
  {"SDLK_MODE", SDLK_MODE},
  {"SDLK_HELP", SDLK_HELP},
  {"SDLK_PRINT", SDLK_PRINT},
  {"SDLK_SYSREQ", SDLK_SYSREQ},
  {"SDLK_BREAK", SDLK_BREAK},
  {"SDLK_MENU", SDLK_MENU},
  {"SDLK_POWER", SDLK_POWER},
  {"SDLK_EURO", SDLK_EURO},
  //
  {"KMOD_NONE", KMOD_NONE},
  {"KMOD_NUM", KMOD_NUM},
  {"KMOD_CAPS", KMOD_CAPS},
  {"KMOD_LCTRL", KMOD_LCTRL},
  {"KMOD_RCTRL", KMOD_RCTRL},
  {"KMOD_RSHIFT", KMOD_RSHIFT},
  {"KMOD_LSHIFT", KMOD_LSHIFT},
  {"KMOD_RALT", KMOD_RALT},
  {"KMOD_LALT", KMOD_LALT},
  {"KMOD_CTRL", KMOD_CTRL},
  {"KMOD_SHIFT", KMOD_SHIFT},
  {"kMOD_ALT", KMOD_ALT},
  //
  {"SDL_HAT_CENTERED", SDL_HAT_CENTERED},
  {"SDL_HAT_UP", SDL_HAT_UP},
  {"SDL_HAT_RIGHT", SDL_HAT_RIGHT},
  {"SDL_HAT_DOWN", SDL_HAT_DOWN},
  {"SDL_HAT_LEFT", SDL_HAT_LEFT},
  {"SDL_HAT_RIGHTUP", SDL_HAT_RIGHTUP},
  {"SDL_HAT_RIGHTDOWN", SDL_HAT_RIGHTDOWN},
  {"SDL_HAT_LEFTUP", SDL_HAT_LEFTUP},
  {"SDL_HAT_LEFTDOWN", SDL_HAT_LEFTDOWN},
  //
  ["AUDIO_U8", AUDIO_U8},
  {"AUDIO_S8", AUDIO_S8},
  {"AUDIO_U16", AUDIO_U16},
  {"AUDIO_U16LSB", AUDIO_U16LSB},
  {"AUDIO_S16", AUDIO_S16}
  {"AUDIO_S16LSB", AUDIO_S16LSB},
  {"AUDIO_U16MSB", AUDIO_U16MSB},
  {"AUDIO_U16SYS", AUDIO_U16SYS},
  {"AUDIO_U16LSB", AUDIO_U16LSB},
  {"AUDIO_U16MSB", AUDIO_U16MSB},
  {"AUDIO_S16SYS", AUDIO_S16SYS},
  {"AUDIO_S16LSB", AUDIO_S16LSB},
  {"AUDIO_S16MSB", AUDIO_S16MSB},
  //
  {"SDL_AUDIO_STOPPED", SDL_AUDIO_STOPPED},
  {"SDL_AUDIO_PAUSED", SDL_AUDIO_PAUSED},
  {"SDL_AUDIO_PLAYING", SDL_AUDIO_PLAYING},
  //
  {"CD_TRAYEMPTY", CD_TRAYEMPTY},
  {"CD_STOPPED", CD_STOPPED},
  {"CD_PLAYING", CD_PLAYING},
  {"CD_PAUSED", CD_PAUSED},
  {"CD_ERROR", CD_ERROR},
  {NULL}  // end of const data
};


/* General */

METHOD SDL_init(Ctx* ctx,knh_sfp_t* sfp)
{
  if(SDL_Init(sfp[1].ivalue)==-1){
    fprintf(stderr,"initialize error %s\n",SDL_GetError());
  }
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_initSubsystem(Ctx* ctx,knh_sfp_t* sfp)
{
  if(SDL_InitSubSystem(sfp[1].ivalue)==-1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_quit(Ctx* ctx,knh_sfp_t *sfp)
{
  SDL_Quit();
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_quitSubsystem(Ctx* ctx,knh_sfp_t* sfp)
{
  SDL_quitSubsystem(sfp[1].ivalue);
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_wasInit(Ctx* ctx,knh_sfp_t* sfp)
{
  if(SDL_WasInit(sfp[1].ivalue)!=0){
    printf("It is initialized\n");
  } else {
    printf("It is not initialized\n");
  }
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_getError(Ctx* ctx,knh_sfp_t* sfp)
{
  printf("%s\n",SDL_GetError());
  KNH_RETURN_void(ctx,sfp);
}


/* Video */

METHOD SDL_getVideosurface(Ctx* ctx,knh_sfp_t *sfp)
{
  SDL_Surface* surface;
  surface SDL_GetVideoSurface();
  KNH_RETURN(ctx,sfp,new_Glue(ctx,"sdl.Surface",surface,NULL));
}

METHOD SDL_getVideoinfo(Ctx* ctx,knh_sfp_t *sfp)
{
  SDL_VideoInfo* info;
  info = SDL_GetVideoInfo();
  KNH_RETURN(ctx,sfp,new_Glue(ctx,"sdl.VideoInfo",info,NULL));
}

METHOD SDL_videoDrivername(Ctx* ctx,knh_sfp_t *sfp)
{
  char* namebuf;
  namebuf = SDL_VideoDriverName(sfp[1].s,sfp[2].ivalue);
  if(namebuf == NULL){
    printf("Video is initialized\n");
  }
  KNH_RETURN_void(ctx,sfp);
}

// METHOD SDL_listModes(Ctx* ctx,knh_sfp_t *sfp)

METHOD SDL_videoModeOK(Ctx* ctx,knh_sfp_t *sfp)
{
  int bpp = SDL_VideoModeOK(sfp[1].ivalue,sfp[2].ivalue,sfp[3].ivalue,sfp[4].ivalue);
  if(bpp==0){
    printf("Unusable mode\n");
  } else {
    printf("Reccommend %dbpp\n",bpp);
  }
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_setVideoMode(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Surface *screen;
  screen=SDL_SetVideoMode(sfp[1].ivalue,sfp[2].ivalue,32,SDL_SWSURFACE);  
  if(screen==NULL){
    fprintf(stderr,"create screen error %s\n",SDL_GetError());
    SDL_Quit();
  }
  KNH_RETURN(ctx, sfp, new_Glue(ctx, "sdl.Surface", screen, NULL));
}

METHOD SDL_updateRect(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_UpdateRect((sfp[1].glue)->ptr,0,0,0,0);
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_updateRects(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_UpdateRects((sfp[1].glue)->ptr,sfp[2].ivalue,(sfp[3].glue)->ptr);
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_flip(Ctx* ctx, knh_sfp_t *sfp)
{
  if(SDL_Flip((sfp[1].glue)->ptr)==-1){
    fprintf(stderr,"flip error %s\n",SDL_GetError());
  }
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_setColors(Ctx* ctx,knh_sfp_t *sfp)
{
  if(SDL_SetColors((sfp[1].glue)->ptr,(sfp[2].glue)->ptr,sfp[3].ivalue,sfp[4].ivalue)==0){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_setPalette(Ctx* ctx,knh_sfp_t *sfp)
{
  if(SDL_SetPalette((sfp[1].glue)->ptr,sfp[2].ivalue,(sfp[3].glue)->ptr,sfp[4].ivalue,sfp[5].ivalue)==0){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_setGamma(Ctx* ctx, knh_sfp_t *sfp)
{
  if(SDL_GetGammaRamp(sfp[1].fvalue,sfp[2].fvalue,sfp[3].fvalue)==-1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_getGammaramp(Ctx* ctx, knh_sfp_t *sfp)
{
  if(SDL_GetGammaRamp(sfp[1].ivalue,sfp[2].ivalue,sfp[3].ivalue)==-1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_setGammaramp(Ctx* ctx, knh_sfp_t *sfp)
{
  if(SDL_SetGammaRamp(sfp[1].ivalue,sfp[2].ivalue,sfp[3].ivalue==-1)){
      fprintf(stderr,"%s\n",SDL_GetError());
    }
    KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_mapRGB(Ctx* ctx, knh_sfp_t *sfp)
{
  int pixel;
  pixel = SDL_MapRGB((sfp[1].glue)->ptr,sfp[2].ivalue,sfp[3].ivalue,sfp[4].ivalue);
  KNH_RETURN_Int(ctx,sfp,pixel);
}

METHOD SDL_mapRGBA(Ctx* ctx, knh_sfp_t *sfp)
{
  int pixel;
  pixel = SDL_MapRGBA((sfp[1].glue)->ptr,sfp[2].ivalue,sfp[3].ivalue,sfp[4].ivalue,sfp[5].ivalue);
  KNH_RETURN_Int(ctx,sfp,pixel);
}

METHOD SDL_getRGB(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_GetRGB(sfp[1].ivalue,(sfp[2].glue)->ptr,sfp[3].ivalue,sfp[4].ivalue,sfp[5].ivalue);
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_getRGBA(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_GetRGBA(sfp[1].ivalue,(sfp[2].glue)->ptr,sfp[3].ivalue,sfp[4].ivalue,sfp[5].ivalue,sfp[6].ivalue);
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_createRGBsurface(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Surface* surface;
  surface = SDL_CreateRGBSurface(sfp[1].ivalue,sfp[2].ivalue,sfp[3].ivalue,sfp[4].ivalue,sfp[5].ivalue,sfp[6].ivalue,sfp[7].ivalue,sfp[8].ivalue);
  if(surface == NULL){
    fprintf(stderr,"%s\n",SDL_GetError);
  }
  KNH_RETURN(ctx, sfp, new_Glue(ctx, "sdl.Surface", surface, NULL));
}

// METHOD SDL_createRGBsurfacefrom(Ctx* ctx, knh_sfp_t *sfp)

METHOD SDL_freeSurface(Ctx* ctx,knh_sfp_t *sfp)
{
  SDL_FreeSurface((sfp[1].glue)->ptr);
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_lockSurface(Ctx* ctx, knh_sfp_t *sfp)
{
  if(SDL_LockSurface((sfp[1].glue)->ptr)== -1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_unLockSurface(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_UnlockSurface((sfp[1].glue)->ptr);
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_loadbmp(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Surface *image;
  image=SDL_LoadBMP("sample.bmp");
  if(image==NULL){
    fprintf(stderr,"%s\n",SDL_GetError());
    SDL_Quit();
  }
  KNH_RETURN(ctx,sfp,new_Glue(ctx,"sdl.Surface",image,NULL));
}

METHOD SDL_saveBMP(Ctx* ctx, knh_sfp_t *sfp)
{
  if(SDL_SaveBMP((sfp[1].glue)->ptr,sfp[2].s)==-1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_setColorkey(Ctx* ctx, knh_sfp_t *sfp)
{
  if(SDL_SetColorKey((sfp[1].glue)->ptr,sfp[2].ivalue,sfp[3].ivalue)==-1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_setAlpha(Ctx* ctx,knh_sfp_t *sfp)
{
  SDL_Surface *image = (sfp[1].glue)->ptr;
  if(SDL_SetAlpha(image,sfp[2].ivalue,sfp[3].ivalue)==-1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_setCliprect(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_SetClipRect((sfp[1].glue)->ptr,(sfp[2].glue)->ptr);
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_getCliprect(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_GetClipRect((sfp[1].glue)->ptr,(sfp[2].glue)->ptr);
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_convertSurface(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Surface *surface = SDL_ConvertSurface((sfp[1].glue)->ptr,(sfp[2].glue)->ptr,sfp[3].ivalue);
  if(surface == NULL){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN(ctx,sfp,new_Glue(ctx,"sdl.Surface",surface,NULL));
}

METHOD SDL_blitSurface(Ctx* ctx,knh_sfp_t *sfp)
{
  SDL_Surface *screen = (sfp[1].glue)->ptr;
  SDL_Surface *image = (sfp[2].glue)->ptr;
  if((SDL_BlitSurface(image,NULL,screen,NULL))!=0){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_fillRect(Ctx* ctx, knh_sfp_t *sfp)
{
  if(SDL_FillRect((sfp[1].glue)->ptr,(sfp[2].glue)->ptr,sfp[3].ivalue)==-1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_displayFormat(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Surface *surface = SDL_DisplayFormat((sfp[1].glue)->ptr);
  if(surface == NULL){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN(ctx,sfp,new_Glue(ctx,"sdl.Surface",surface,NULL));
}

METHOD SDL_displayFormatalpha(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Surface *surface = SDL_DisplayFormatAlpha((sfp[1].glue)->ptr);
  if(surface == NULL){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN(ctx,sfp,new_Glue(ctx,"sdl.Surface",surface,NULL));
}

METHOD SDL_warpMouse(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_WarpMouse(sfp[1].ivalue,sfp[2].ivalue);
  KNH_RETURN_void(ctx,sfp);
}

// METHOD SDL_createCursor(Ctx* ctx, knh_sfp_t *sfp)

METHOD SDL_freeCursor(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_FreeCursor((sfp[1].glue)->ptr);
  KNH_RETURN_void(ctx,sfp);
}

// METHOD SDL_setCursor(Ctx* ctx, knh_sfp_t *sfp)

METHOD SDL_getCursor(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Cursor* c = SDL_GetCursor();
  KNH_RETURN(ctx,sfp,new_Glue(ctx,"sdl.Cursor",c,NULL));
}

METHOD SDL_showCursor(Ctx* ctx, knh_sfp_t *sfp)
{
  int state = SDL_ShowCursor(sfp[1].ivalue);
  KNH_RETURN_Int(ctx,sfp,state);
}

METHOD SDL_glLoadlibrary(Ctx* ctx, knh_sfp_t *sfp)
{
  if(SDL_GL_LoadLibrary(sfp[1].s)==-1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN_void(ctx,sfp);
}

// METHOD SDL_glGetprocaddress(Ctx* ctx, knh_sfp_t *sfp)
// METHOD SDL_glGetattribute(Ctx* ctx, knh_sfp_t *sfp)

METHOD SDL_glSetattribute(Ctx* ctx, knh_sfp_t *sfp)
{
  if(SDL_GL_SetAttribute((sfp[1].glue)->ptr,sfp[2].ivalue)==-1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_glSwapbuffers(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_GL_SwapBuffers();
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_createYUVoverlay(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Overlay* overlay = SDL_CreateYUVOverlay(sfp[1].ivalue,sfp[2].ivalue,sfp[3].ivalue,(sfp[4].glue)->ptr);
  KNH_RETURN(ctx,sfp,new_Glue(ctx,"sdl.Overlay",overlay,NULL));
}

METHOD SDL_lockYUVoverlay(Ctx* ctx, knh_sfp_t *sfp)
{
  if(SDL_LockYUVOverlay((sfp[1].glue)->ptr)==-1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_unlockYUVoverlay(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_UnlockYUVOverlay((sfp[1].glue)->ptr);
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_displayYUVoverlay(Ctx* ctx, knh_sfp_t *sfp)
{
  if(SDL_DisplayYUVOverlay((sfp[1].glue)->ptr,(sfp[2].glue)->ptr)!=0){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_freeYUVoverlay(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_FreeYUVOverlay((sfp[1].glue)->ptr);
  KNH_RETURN_void(ctx,sfp);
}


/* Window Management */

METHOD SDL_wmSetcaption(Ctx* ctx, knh_sfp_t *sfp)
{
  char* title;
  char* icon;
  title = (char*)sfp[1].s;
  icon = (char*)sfp[2].s;
  SDL_WM_SetCaption(title,icon);
  KNH_RETURN_void(ctx,sfp);
}

// METHOD SDL_wmGetcaption(Ctx* ctx, knh_sfp_t *sfp)
// METHOD SDL_wmSeticon(Ctx* ctx, knh_sfp_t *sfp)

METHOD SDL_wmIconifywindow(Ctx* ctx, knh_sfp_t *sfp)
{
  if(SDL_WM_IconifyWindow()==0){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_wmTogglefullscreen(Ctx* ctx, knh_sfp_t *sfp)
{
  if(SDL_WM_ToggleFullScreen((sfp[1].glue)->ptr)==0){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_wmGrabinput(Ctx* ctx, knh_sfp_t *sfp)
{
  int mode = SDL_WM_GrabInput(sfp[1].ivalue);
  KNH_RETURN_Int(ctx,sfp,mode);
}


/* Event */

METHOD SDL_pumpEvents(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_PumpEvents();
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_peepEvents(Ctx* ctx, knh_sfp_t *sfp)
{
  if(SDL_PeepEvents((sfp[1].glue)->ptr, sfp[2].ivalue, sfp[3].ivalue, sfp[4].ivalue)==-1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_pollEvent(Ctx* ctx,knh_sfp_t *sfp)
{
  if(SDL_PollEvent((sfp[1].glue)->ptr)==0){
    printf("Nothing Event\n");
  }
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_waitEvent(Ctx* ctx, knh_sfp_t *sfp)
{
  if(SDL_WaitEvent((sfp[1].glue)->ptr)==0){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_pushEvent(Ctx* ctx, knh_sfp_t *sfp)
{
  if(SDL_PushEvent((sfp[1].glue)->ptr)==-1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN_void(ctx,sfp);
}

// METHOD SDL_setEventfilter(Ctx* ctx, knh_sfp_t *sfp)
// METHOD SDL_getEventfilter(Ctx* ctx, knh_sfp_t *sfp)

METHOD SDL_eventState(Ctx* ctx, knh_sfp_t *sfp)
{
  int state = SDL_EventState(sfp[1].ivalue, sfp[2].ivalue);
  KNH_RETURN_Int(ctx,sfp,state);
}

/*
METHOD SDL_getKeyState(Ctx* ctx,knh_sfp_t *sfp)
{
  int* key = SDL_GetKeyState((sfp[1].glue)->ptr);
  KNH_RETURN_void(ctx,sfp);
}
*/

METHOD SDL_getModstate(Ctx* ctx, knh_sfp_t *sfp)
{
  KNH_RETURN_Int(ctx,sfp,SDL_GetModState());
}

METHOD SDL_setModstate(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_SetModState(sfp[1].ivalue);
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_getKeyname(Ctx* ctx, knh_sfp_t *sfp)
{
  printf("%s\n",SDL_GetKeyName(sfp[1].ivalue));
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_enableUNICODE(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_EnableUNICODE(sfp[1].ivalue);
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_enableKeyrepeat(Ctx* ctx, knh_sfp_t *sfp)
{
  if(SDL_EnableKeyRepeat(sfp[1].ivalue,sfp[2].ivalue)==-1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN_void(ctx,sfp);
}

//METHOD SDL_getMousestate(Ctx* ctx, knh_sfp_t *sfp)
//METHOD SDL_getRelativemousestate(Ctx* ctx, knh_sfp_t *sfp)

METHOD SDL_getAppstate(Ctx* ctx, knh_sfp_t *sfp)
{
  KNH_RETURN_Int(ctx,sfp,SDL_GetAppState());
}

METHOD SDL_joystickEventstate(Ctx* ctx, knh_sfp_t *sfp)
{
  int state = SDL_JoystickEventState(sfp[1].ivalue);
  if(state == SDL_QUERY){
    printf("keep state\n");
  } else {
    printf("change state\n");
  }
  KNH_RETURN_void(ctx,sfp);
}


/* Joystick */

METHOD SDL_numJoysticks(Ctx* ctx, knh_sfp_t *sfp)
{
  KNH_RETURN_Int(ctx,sfp,SDL_NumJoysticks());
}

//METHOD SDL_joystickName(Ctx* ctx, knh_sfp_t *sfp)

METHOD SDL_joystickOpen(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Joystick* joy = SDL_JoystickOpen(sfp[1].ivalue);
  if(joy==NULL){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN(ctx,sfp,new_Glue(ctx,"sdl.Joystick",joy,NULL));
}

METHOD SDL_joystickOpened(Ctx* ctx, knh_sfp_t *sfp)
{
  int state = SDL_JoystickOpened(sfp[1].ivalue);
  if(state==0){
    printf("Joystick is closed\n");
  } else {
    printf("Joystick is opened\n");
  }
  KNH_RETURN_Int(ctx,sfp,state);
}

METHOD SDL_joystickIndex(Ctx* ctx, knh_sfp_t *sfp)
{
  KNH_RETURN_Int(ctx,sfp,SDL_JoystickIndex((sfp[1].glue)->ptr));
}

METHOD SDL_joystickNumaxes(Ctx* ctx, knh_sfp_t *sfp)
{
  KNH_RETURN_Int(ctx,sfp,SDL_JoystickNumAxes((sfp[1].glue)->ptr));
}

METHOD SDL_joystickNumballs(Ctx* ctx, knh_sfp_t *sfp)
{
  KNH_RETURN_Int(ctx,sfp,SDL_JoystickNumBalls((sfp[1].glue)->ptr));
}

METHOD SDL_joystickNumhats(Ctx* ctx, knh_sfp_t *sfp)
{
  KNH_RETURN_Int(ctx,sfp,SDL_JoystickNumHats((sfp[1].glue)->ptr));
}

METHOD SDL_joystickNumbuttons(Ctx* ctx, knh_sfp_t *sfp)
{
  KNH_RETURN_Int(ctx,sfp,SDL_JoystickButtons((sfp[1].glue)->ptr));
}

METHOD SDL_joystickUpdate(Ctx* ctx, knh_sfp_t *sfp)
{
  KNH_RETURN_Int(ctx,sfp,SDL_JoystickUpdate());
}

METHOD SDL_joystickGetaxis(Ctx* ctx, knh_sfp_t *sfp)
{
  KNH_RETURN_Int(ctx,sfp,SDL_JoystickGetAxis((sfp[1].glue)->ptr,sfp[2].ivalue));
}

METHOD SDL_joystickGethat(Ctx* ctx, knh_sfp_t *sfp)
{
  KNH_RETURN_Int(ctx,sfp,SDL_JoystickGetHat((sfp[1].glue)->ptr,sfp[2].ivalue));
}

METHOD SDL_joystickGetbutton(Ctx* ctx, knh_sfp_t *sfp)
{
  KNH_RETURN_Int(ctx,sfp,SDL_JoystickGetButton((sfp[1].glue)->ptr,sfp[2].ivalue));
}

METHOD SDL_joystickGetball(Ctx* ctx, knh_sfp_t *sfp)
{
  if(SDL_JoystickGetBall((sfp[1].glue)->ptr,sfp[2].ivalue,(sfp[3].glue)->ptr,(sfp[4].glue)->ptr)==-1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETRURN_void(ctx,sfp);
}

METHOD SDL_joystickClose(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_JoystickClose((sfp[1].glue)->ptr);
  KNH_RETURN_void(ctx,sfp);
}


/* Audio */

METHOD SDL_openAudio(Ctx* ctx, knh_sfp_t *sfp)
{
  if(SDL_OpenAudio((sfp[1].glue)->ptr,(sfp[2].glue)->ptr)==-1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_pauseAudio(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_PauseAudio(sfp[1].ivalue);
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_getAudiostatus(Ctx* ctx, knh_sfp_t *sfp)
{
  KNH_RETURN_Int(ctx,sfp,SDL_GetAudioStatus());
}

// METHO SDL_loadWAV(Ctx* ctx, knh_sfp_t *sfp)
		      		      
METHOD SDL_freeWAV(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_FreeWAV((sfp[1].glue)->ptr);
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_buildAudioCVT(Ctx* ctx, knh_sfp_t *sfp)
{
  if(SDL_BuildAudioCVT((sfp[1].glue)->ptr, sfp[2].ivalue, sfp[3].ivalue, sfp[4].ivalue, sfp[5].ivalue, sfp[6].ivalue, sfp[7].ivalue)==-1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_convertAudio(Ctx* ctx, knh_sfp_t *sfp)
{
  if(SDL_ConvertAudio((sfp[1].glue)->ptr)==-1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_mixAudio(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_MixAudio((sfp[1].glue)->ptr,(sfp[2].glue)->ptr,sfp[3].ivalue,sfp[4].ivalue);
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_lockAudio(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_LockAudio();
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_unLockAudio(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_UnlockAudio();
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_closeAudo(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_CloseAudio();
  KNH_RETURN_void(ctx,sfp);
}


/* CD-ROM */

METHOD SDL_cdNumDrives(Ctx* ctx, knh_sfp_t *sfp)
{
  KNH_RETURN_Int(ctx,sfp,SDL_CDNumDrives());
}

//METHOD SDL_cdName(Ctx* ctx, knh_sfp_t *sfp)

METHOD SDL_cdOpen(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_CD cd;
  cd = SDL_CDOpen(sfp[1].ivalue);
  if(cd == NULL){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN(ctx,sfp,new_Glue(ctx,"sdl.CD",cd,NULL));
}

METHOD SDL_cdStatus(Ctx* ctx, knh_sfp_t *sfp)
{
  KNH_RETURN_Int(ctx,sfp,SDL_CDStatus((sfp[1].glue)->ptr));
}

METHOD SDL_cdPlay(Ctx* ctx, knh_sfp_t *sfp)
{
  if(SDL_CDPlay((sfp[1].glue)->ptr,sfp[2].ivalue,sfp[3].ivalue)==-1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_cdPlayTracks(Ctx* ctx, knh_sfp_t *sfp)
{
  if(SDL_CDPlayTracks((sfp[1].glue)->ptr,sfp[2].ivalue,sfp[3].ivalue,sfp[4].ivalue,sfp[5].ivalue)==-1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN_void(ctx,sfp);
}






METHOD SDL_delay(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Delay(sfp[1].ivalue);
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_getTicks(Ctx* ctx, knh_sfp_t *sfp)
{
  float next_frame;
  next_frame = SDL_GetTicks();
  KNH_RETURN_Float(ctx,sfp,next_frame);
}

METHOD SDL_imgLoad(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Surface *image;
  image=IMG_Load("sample.bmp");
  if(image==NULL){
    fprintf(stderr,"%s\n",IMG_GetError());
    SDL_Quit();
  }
  KNH_RETURN(ctx,sfp,new_Glue(ctx,"sdl.Surface",image,NULL));
}

METHOD SDL_imgLoadRW(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Surface *image;
  image=IMG_Load_RW(SDL_RWFromFile("sample.png","rb"),1);
  if(image==NULL){
    fprintf(stderr,"%s\n",IMG_GetError());
  }
  KNH_RETURN(ctx,sfp,new_Glue(ctx,"sdl.Surface",image,NULL));
}

/*METHOD SDL_setIColor(Ctx *ctx, knh_sfp_t *sfp)
{
  int i=0;
  SDL_Color palette[0];
  SDL_Surface *screen=(sfp[1].glue)->ptr;
  //    for(i=0;i<256;i++){
    palette[i].r=(sfp[2].ivalue);
    palette[i].g=(sfp[3].ivalue);
    palette[i].b=(sfp[4].ivalue);
    //     }
  SDL_SetColors(screen,palette,0,21);
  KNH_RETURN_void(ctx,sfp);
  }*/

/*METHOD Sdl_screen(){
  while(!done&&SDL_WaitEvent(&event)){
    switch(event.type){
    case SDL_MOUSEBUTTONDOWN:
    break;
    case SDL_QUIT:
      done=1;
      break;
    case SDL_VIDEOEXPOSE:
      DrawBackground(screen);
      break;
    default:
      break;
  }*/
