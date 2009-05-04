#include<konoha.h>
#ifdef KONOHA_OS__MACOSX
#include <SDL.h>
#else
#include<SDL/SDL.h>
#endif
//#include<SDL/SDL_image.h>

/* General */

/* void SDL.init(int flags) */

METHOD SDL_init(Ctx* ctx,knh_sfp_t* sfp)
{
  int i1 = p_int(sfp[1]);
  if(SDL_Init((Uint32)i1) == -1){
    fprintf(stderr,"initialize error %s\n",SDL_GetError());
  }

  KNH_RETURN_void(ctx,sfp);
}

/* void SDL.initSubSystem(int flags) */

METHOD SDL_initSubSystem(Ctx* ctx,knh_sfp_t* sfp)
{
  int i1 = p_int(sfp[1]);
  if(SDL_InitSubSystem(i1)==-1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }

  KNH_RETURN_void(ctx,sfp);
}

/* void SDL.quit() */

METHOD SDL_quit(Ctx* ctx,knh_sfp_t *sfp)
{
  SDL_Quit();

  KNH_RETURN_void(ctx,sfp);
}

/* void SDL.quitSubSystem(int flags) */

METHOD SDL_quitSubSystem(Ctx* ctx,knh_sfp_t* sfp)
{
  int i1 = p_int(sfp[1]);
  SDL_QuitSubSystem((Uint32)i1);

  KNH_RETURN_void(ctx,sfp);
}

/* void SDL.wasInit(int flags) */

METHOD SDL_wasInit(Ctx* ctx,knh_sfp_t* sfp)
{
  int i1 = p_int(sfp[1]);
  if(SDL_WasInit(i1)!=0){
    printf("It is initialized\n");
  } else {
    printf("It is not initialized\n");
  }

  KNH_RETURN_void(ctx,sfp);
}

/* void SDL.getError */

METHOD SDL_getError(Ctx* ctx,knh_sfp_t* sfp)
{
  printf("%s\n",SDL_GetError());

  KNH_RETURN_void(ctx,sfp);
}

/* Video */

/* Surface SDL.getVideoSurface() */

METHOD SDL_getVideoSurface(Ctx* ctx,knh_sfp_t *sfp)
{
  SDL_Surface* ret;
  ret = SDL_GetVideoSurface();

  KNH_RETURN(ctx,sfp,new_Glue(ctx,"sdl.Surface",ret,NULL));
}

/* VideoInfo SDL.getVideoInfo() */

METHOD SDL_getVideoInfo(Ctx* ctx,knh_sfp_t *sfp)
{
  SDL_VideoInfo *ret;
  ret = SDL_GetVideoInfo();

  KNH_RETURN(ctx,sfp,new_Glue(ctx,"sdl.Surface",ret,NULL));
}


/* void SDL.videoDriveName(String namebuf, int maxlen) */

METHOD SDL_videoDrivername(Ctx* ctx,knh_sfp_t *sfp)
{
  char* ret;
  char* s1 = p_char(sfp[1]);
  int i1 = p_int(sfp[2]);
  ret = SDL_VideoDriverName(s1,i1);
  if(ret == NULL){
    printf("Video is initialized\n");
    KNH_RETURN_void(ctx,sfp);
  }

  KNH_RETURN(ctx,sfp,ret);
}

/*
METHOD SDL_listModes(Ctx* ctx,knh_sfp_t *sfp)
{
  SDL_PixelFormat* fmt = ((sfp[1].glue)->ptr);
  int i1 = p_int(sfp[2]);
  SDL_Rect** ret = SDL_ListModes(fmt,i1);
  if(ret == (SDL_Rect**)0){
      fprintf(stderr,"%s\n", SDL_GetError());
    }

    KNH_RETURN(ctx,sfp,ret);
}
*/



/* void SDL.videoModeOK(int width, int height, int bpp, int flags) */

METHOD SDL_videoModeOK(Ctx* ctx,knh_sfp_t *sfp)
{
  int i1 = p_int(sfp[1]);
  int i2 = p_int(sfp[2]);
  int i3 = p_int(sfp[3]);
  int i4 = p_int(sfp[4]);
  int bpp = SDL_VideoModeOK(i1,i2,i3,i4);
  if(bpp == 0){
    printf("Unusable mode\n");
  } else {
    printf("Reccommend %dbpp\n",bpp);
  }

  KNH_RETURN_void(ctx,sfp);
}

/* Suface SDL.setVideoMode(int width, int height, int bpp, int flags) */   

METHOD SDL_setVideoMode(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Surface *ret;
  int i1 = p_int(sfp[1]);
  int i2 = p_int(sfp[2]);
  int i3 = p_int(sfp[3]);
  int i4 = p_int(sfp[4]);
  ret = SDL_SetVideoMode(i1,i2,i3,i4);  
  if(ret == NULL){
    fprintf(stderr,"create screen error %s\n",SDL_GetError());
    SDL_Quit();
  }

  KNH_RETURN(ctx, sfp, new_Glue(ctx, "sdl.Surface", ret, NULL));
}

/* void Surface.updateRect(self, int x, int y, int w, int h) */

METHOD Surface_updateRect(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Surface *self = ((sfp[0].glue)->ptr);
  int i1 = p_int(sfp[1]);
  int i2 = p_int(sfp[2]);
  int i3 = p_int(sfp[3]);
  int i4 = p_int(sfp[4]);
  SDL_UpdateRect(self,i1,i2,i3,i4);

  KNH_RETURN_void(ctx,sfp);
}

/*
METHOD SDL_updateRects(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_UpdateRects((sfp[1].glue)->ptr,sfp[2].ivalue,(sfp[3].glue)->ptr);
  KNH_RETURN_void(ctx,sfp);
}
*/
      
 /* void Surface.flip(self) */ 
 
METHOD Surface_flip(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Surface *self = ((sfp[0].glue)->ptr);
  if( SDL_Flip(self) ==-1){
    fprintf(stderr,"flip error %s\n",SDL_GetError());
  }

  KNH_RETURN_void(ctx,sfp);
}

/*
METHOD SDL_setColos(Ctx* ctx,knh_sfp_t *sfp)
{
  if(SDL_SetColors((sfp[1].glue)->ptr,(sfp[2].glue)->ptr,sfp[3].ivalue,sfp[4].ivalue)==0){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN_void(ctx,sfp);
}
*/
 /*
METHOD SDL_setPalette(Ctx* ctx,knh_sfp_t *sfp)
{
  if(SDL_SetPalette((sfp[1].glue)->ptr,sfp[2].ivalue,(sfp[3].glue)->ptr,sfp[4].ivalue,sfp[5].ivalue)==0){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN_void(ctx,sfp);
}
 */
/*
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
*/
/*
METHOD SDL_mapRGB(Ctx* ctx, knh_sfp_t *sfp)
{
  int pixel;
  pixel = SDL_MapRGB((sfp[1].glue)->ptr,sfp[2].ivalue,sfp[3].ivalue,sfp[4].ivalue);
  KNH_RETURN_Int(ctx,sfp,pixel);
}
*/
 /*
METHOD SDL_mapRGBA(Ctx* ctx, knh_sfp_t *sfp)
{
  int pixel;
  pixel = SDL_MapRGBA((sfp[1].glue)->ptr,sfp[2].ivalue,sfp[3].ivalue,sfp[4].ivalue,sfp[5].ivalue);
  KNH_RETURN_Int(ctx,sfp,pixel);
}
 */
/*
METHOD SDL_getRGB(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_GetRGB(sfp[1].ivalue,(sfp[2].glue)->ptr,sfp[3].ivalue,sfp[4].ivalue,sfp[5].ivalue);
  KNH_RETURN_void(ctx,sfp);
}
*/
 /*
METHOD SDL_getRGBA(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_GetRGBA(sfp[1].ivalue,(sfp[2].glue)->ptr,sfp[3].ivalue,sfp[4].ivalue,sfp[5].ivalue,sfp[6].ivalue);
  KNH_RETURN_void(ctx,sfp);
}
 */
  /*
METHOD SDL_createRGBsurface(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Surface* surface;
  surface = SDL_CreateRGBSurface(sfp[1].ivalue,sfp[2].ivalue,sfp[3].ivalue,sfp[4].ivalue,sfp[5].ivalue,sfp[6].ivalue,sfp[7].ivalue,sfp[8].ivalue);
  if(surface == NULL){
    fprintf(stderr,"%s\n",SDL_GetError);
  }
  KNH_RETURN(ctx, sfp, new_Glue(ctx, "sdl.Surface", surface, NULL));
}
  */
// METHOD SDL_createRGBsurfacefrom(Ctx* ctx, knh_sfp_t *sfp)

 
   /* void Surface.freeSurface(self) */

METHOD Surface_freeSurface(Ctx* ctx,knh_sfp_t *sfp)
{
  SDL_Surface* self = ((sfp[0].glue)->ptr);
  SDL_FreeSurface(self);
  KNH_RETURN_void(ctx,sfp);
}

/* void Surface.lockSurface(self) */

METHOD Surface_lockSurface(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Surface* self = ((sfp[0].glue)->ptr);
  if(SDL_LockSurface(self)== -1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }

  KNH_RETURN_void(ctx,sfp);
}

/* void Surface.unLockSurface(self) */

METHOD Surface_unLockSurface(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Surface* self = ((sfp[0].glue)->ptr);
  SDL_UnlockSurface(self);

  KNH_RETURN_void(ctx,sfp);
}


/* Surface SDL.loadBMP(String file) */ 

METHOD SDL_loadBMP(Ctx* ctx, knh_sfp_t *sfp)
{
  char* s1 = p_char(sfp[1]);
  SDL_Surface *image = SDL_LoadBMP(s1);
  if(image == NULL){
    fprintf(stderr,"%s\n",SDL_GetError());
    SDL_Quit();
  }

  KNH_RETURN(ctx,sfp,new_Glue(ctx, "sdl.Surface",image,NULL));
}


/* void Suface.saveBMP(self, String file) */

METHOD Surface_saveBMP(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Surface* self = ((sfp[0].glue)->ptr);
  char* s1 = p_char(sfp[1]);
  if(SDL_SaveBMP(self,s1)==-1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }

  KNH_RETURN_void(ctx,sfp);
}


/* void Surface.setColorKey(self, int flag, int key) */
/*
METHOD SDL_setColorKey(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Surface* self = ((sfp[0].glue)->ptr);
  int i1 = p_int(sfp[1]);
  int i2 = p_int(sfp[2]);
  if(SDL_SetColorKey(self,i1,i2)==-1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }

  KNH_RETURN_void(ctx,sfp);
}
*/

 /* void Surface.setAlpha(self, int flag, int alpha) */

METHOD Surface_setAlpha(Ctx* ctx,knh_sfp_t *sfp)
{
  SDL_Surface* self = ((sfp[0].glue)->ptr);
  int i1 = p_int(sfp[1]);
  int i2 = p_int(sfp[2]);
  if(SDL_SetAlpha(self, i1, i2)==-1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN_void(ctx,sfp);
}

/*
METHOD SDL_setCliprect(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_SetClipRect((sfp[1].glue)->ptr,(sfp[2].glue)->ptr);
  KNH_RETURN_void(ctx,sfp);
}
*/
 /*
METHOD SDL_getCliprect(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_GetClipRect((sfp[1].glue)->ptr,(sfp[2].glue)->ptr);
  KNH_RETURN_void(ctx,sfp);
}
 */
  /*
METHOD SDL_convertSurface(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Surface *surface = SDL_ConvertSurface((sfp[1].glue)->ptr,(sfp[2].glue)->ptr,sfp[3].ivalue);
  if(surface == NULL){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN(ctx,sfp,new_Glue(ctx,"sdl.Surface",surface,NULL));
}
  */
  
   /* void Surface.blitSurface(self, Surface image) */
 
METHOD Surface_blitSurface(Ctx* ctx,knh_sfp_t *sfp)
{

  SDL_Surface *s = (SDL_Surface*)((sfp[1].glue)->ptr);
  SDL_Surface *i = (SDL_Surface*)((sfp[0].glue)->ptr);
  if(SDL_BlitSurface(i,NULL,s,NULL) != 0){
    fprintf(stderr,"%s\n",SDL_GetError());
  }

  KNH_RETURN_void(ctx,sfp);
}
/*
METHOD Surface_fillRect(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Surface* self = ((sfp[0].glue)->ptr);
  SDL_Rect* rect = ((sfp[1].glue)->ptr);
  int i1 = p_int(sfp[2]);
  if(SDL_FillRect(self, rect, i1)==-1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }

  KNH_RETURN_void(ctx,sfp);
}
*/

 /* void Surface.displayFormat(self) 
 // TODO
METHOD Surface_displayFormat(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Surface *self = ((sfp[0].glue)->ptr);
  SDL_Surface *ret = SDL_DisplayFormat(self);
  if(ret == NULL){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN_void(ctx,sfp);
}
 */
/*
METHOD SDL_displayFormatalpha(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Surface *surface = SDL_DisplayFormatAlpha((sfp[1].glue)->ptr);
  if(surface == NULL){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN(ctx,sfp,new_Glue(ctx,"sdl.Surface",surface,NULL));
}
*/

 /* void SDL.warpMouse(int x, int y) */

METHOD SDL_warpMouse(Ctx* ctx, knh_sfp_t *sfp)
{
  int i1 = p_int(sfp[1]);
  int i2 = p_int(sfp[2]);
  SDL_WarpMouse(i1,i2)
;
  KNH_RETURN_void(ctx,sfp);
}

/*
METHOD SDL_createCursor(Ctx* ctx, knh_sfp_t *sfp)
{
 int i1 = p_int(sfp[1]);
 int i2 = p_int(sfp[2]);
 int i3 = p_int(sfp[3]);
 int i4 = p_int(sfp[4]);


 SDL_Cursor* ret = SDL_CreateCursor( , , i1, i2, i3, i4);

 KNH_RETURN(ctx,sfp,ret);
}
*/
 /*
METHOD SDL_freeCursor(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_FreeCursor((sfp[1].glue)->ptr);
  KNH_RETURN_void(ctx,sfp);
}
 */
// METHOD SDL_setCursor(Ctx* ctx, knh_sfp_t *sfp)
  
  /* Cursor SDL.getCursor(void) */
  /*METHOD SDL_getCursor(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Cursor* ret = SDL_GetCursor();

  KNH_RETURN(ctx,sfp,ret);
  }*/
  

   /* int SDL.showCursor(int toggle) */   

METHOD SDL_showCursor(Ctx* ctx, knh_sfp_t *sfp)
{
  int i1 = p_int(sfp[1]);
  int ret = SDL_ShowCursor(i1);

  KNH_RETURN_Int(ctx,sfp,ret);
}
   
/* void SDL.glLoadLibrary(String path) */

METHOD SDL_glLoadLibrary(Ctx* ctx, knh_sfp_t *sfp)
{
  char* s1 = p_char(sfp[1]);
  if(SDL_GL_LoadLibrary(s1)==-1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }

  KNH_RETURN_void(ctx,sfp);
}

// METHOD SDL_glGetprocaddress(Ctx* ctx, knh_sfp_t *sfp)
// METHOD SDL_glGetattribute(Ctx* ctx, knh_sfp_t *sfp)

/* void SDL.glSetAttribute(int attr, int value) */

/*METHOD SDL_glSetAttribute(Ctx* ctx, knh_sfp_t *sfp)
{
  int i1 = p_int(sfp[1]);
  int i2 = p_int(sfp[2]);
  if(SDL_GL_SetAttribute(i1, i2)==-1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN_void(ctx,sfp);
}
*/
 /*
METHOD SDL_glSwapbuffers(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_GL_SwapBuffers();
  KNH_RETURN_void(ctx,sfp);
}
 */
  /*
METHOD SDL_createYUVoverlay(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Overlay* overlay = SDL_CreateYUVOverlay(sfp[1].ivalue,sfp[2].ivalue,sfp[3].ivalue,(sfp[4].glue)->ptr);
  KNH_RETURN(ctx,sfp,new_Glue(ctx,"sdl.Overlay",overlay,NULL));
}
  */
   /*
METHOD SDL_lockYUVoverlay(Ctx* ctx, knh_sfp_t *sfp)
{
  if(SDL_LockYUVOverlay((sfp[1].glue)->ptr)==-1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN_void(ctx,sfp);
}
   */
    /*
METHOD SDL_unlockYUVoverlay(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_UnlockYUVOverlay((sfp[1].glue)->ptr);
  KNH_RETURN_void(ctx,sfp);
}
    */
     /*
METHOD SDL_displayYUVoverlay(Ctx* ctx, knh_sfp_t *sfp)
{
  if(SDL_DisplayYUVOverlay((sfp[1].glue)->ptr,(sfp[2].glue)->ptr)!=0){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN_void(ctx,sfp);
}
*/
      /*
METHOD SDL_freeYUVoverlay(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_FreeYUVOverlay((sfp[1].glue)->ptr);
  KNH_RETURN_void(ctx,sfp);
}
*/

/* Window Management */

       /* void SDL.wmSetCaption(String title) */       

METHOD SDL_wmSetCaption(Ctx* ctx, knh_sfp_t *sfp)
{
  char* s1 = p_char(sfp[1]);
  SDL_WM_SetCaption(s1, s1);
  
  KNH_RETURN_void(ctx,sfp);
}

// METHOD SDL_wmGetcaption(Ctx* ctx, knh_sfp_t *sfp)
// METHOD SDL_wmSeticon(Ctx* ctx, knh_sfp_t *sfp)

/* void SDL.wmIconifyWindow(void) */

METHOD SDL_wmIconifyWindow(Ctx* ctx, knh_sfp_t *sfp)
{
  if(SDL_WM_IconifyWindow()==0){
    fprintf(stderr,"%s\n",SDL_GetError());
  }

  KNH_RETURN_void(ctx,sfp);
}


 /* void Surface.wmToggleFullScreen(self) */ 

METHOD Surface_wmToggleFullScreen(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Surface* self = ((sfp[0].glue)->ptr);
  if(SDL_WM_ToggleFullScreen(self)==0){
    fprintf(stderr,"%s\n",SDL_GetError());
  }

  KNH_RETURN_void(ctx,sfp);
}

/* Grubmode SDL.wmGrabInput(Grubmod grabmode) */
METHOD SDL_wmGrabInput(Ctx* ctx, knh_sfp_t *sfp)
{
  int i1 = p_int(sfp[1]);
  int grabmode = SDL_WM_GrabInput(i1);

  KNH_RETURN_Int(ctx,sfp,grabmode);
}


/* Event */
   /*
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
   */
/*
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
*/
 /*
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
*/
 /*
METHOD SDL_getKeyState(Ctx* ctx,knh_sfp_t *sfp)
{
  int* key = SDL_GetKeyState((sfp[1].glue)->ptr);
  KNH_RETURN_void(ctx,sfp);
}
 */
 /*
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
 */
//METHOD SDL_getMousestate(Ctx* ctx, knh_sfp_t *sfp)
//METHOD SDL_getRelativemousestate(Ctx* ctx, knh_sfp_t *sfp)
/*
METHOD SDL_getAppstate(Ctx* ctx, knh_sfp_t *sfp)
{
  KNH_RETURN_Int(ctx,sfp,SDL_GetAppState());
}
*/
 /*
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

*/
/* Joystick */
  /*
METHOD SDL_numJoysticks(Ctx* ctx, knh_sfp_t *sfp)
{
  KNH_RETURN_Int(ctx,sfp,SDL_NumJoysticks());
}
  */
//METHOD SDL_joystickName(Ctx* ctx, knh_sfp_t *sfp)
   /*
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
  SDL_JoystickUpdate();
  KNH_RETURN_void(ctx,sfp);
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
*/

/* Audio */
/*
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
*/

/* CD-ROM */
/*
METHOD SDL_cdNumDrives(Ctx* ctx, knh_sfp_t *sfp)
{
  KNH_RETURN_Int(ctx,sfp,SDL_CDNumDrives());
}

//METHOD SDL_cdName(Ctx* ctx, knh_sfp_t *sfp)

METHOD SDL_cdOpen(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_CD *cd;
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
*/



/* void SDL.delay(int ms) */

METHOD SDL_delay(Ctx* ctx, knh_sfp_t *sfp)
{
  int i1 = p_int(sfp[1]);
  SDL_Delay(i1);

  KNH_RETURN_void(ctx,sfp);
}

/* float SDL.getTicks(void) */

METHOD SDL_getTicks(Ctx* ctx, knh_sfp_t *sfp)
{
   SDL_GetTicks();
  
   KNH_RETURN_Float(ctx,sfp,SDL_GetTicks());
}

METHOD SDL_sample(Ctx* ctx, knh_sfp_t *sfp)
{
  //  SDL_Flip(s);
  KNH_RETURN_void(ctx,sfp);
}

/*
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
*/
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
  }
*/


/* ConstData */
 
static
knh_IntConstData_t IntConstData[] = {
  // init
  {"SDL.SDL_INIT_TIMER", SDL_INIT_TIMER},
  {"SDL.SDL_INIT_AUDIO", SDL_INIT_AUDIO},
  {"SDL.SDL_INIT_VIDEO", SDL_INIT_VIDEO},
  {"SDL.SDL_INIT_CDROM", SDL_INIT_CDROM},
  {"SDL.SDL_INIT_JOYSTICK", SDL_INIT_JOYSTICK},
  {"SDL.SDL_INIT_EVERYTHING", SDL_INIT_EVERYTHING},
  {"SDL.SDL_INIT_NOPARACHUTE", SDL_INIT_NOPARACHUTE},
  {"SDL.SDL_INIT_EVENTTHREAD", SDL_INIT_EVENTTHREAD}, 
  // 
  {"SDL.SDL_SWSURFACE", SDL_SWSURFACE},
  {"SDL.SDL_HWSURFACE", SDL_HWSURFACE},
  {"SDL.SDL_ASYNCBLIT", SDL_ASYNCBLIT},
  {"SDL.SDL_ANYFORMAT", SDL_ANYFORMAT},
  {"SDL.SDL_HWPALETTE", SDL_HWPALETTE},     
  {"SDL.SDL_DOUBLEBUF", SDL_DOUBLEBUF},     
  {"SDL.SDL_FULLSCREEN", SDL_FULLSCREEN},   
  {"SDL.SDL_OPENGL", SDL_OPENGL},           
  {"SDL.SDL_OPENGLBLIT", SDL_OPENGLBLIT},   
  {"SDL.SDL_RESIZABLE",SDL_RESIZABLE},      
  {"SDL.SDL_HWACCEL",SDL_HWACCEL},          
  {"SDL.SDL_SRCCOLORKEY", SDL_SRCCOLORKEY}, 
  {"SDL.SDL_RLEACCEL", SDL_RLEACCEL},       
  {"SDL.SDL_SRCALPHA", SDL_SRCALPHA},       
  {"SDL.SDL_PREALLOC", SDL_PREALLOC},       
  //
  {"SDL.SDL_ACTIVEEVENT", SDL_ACTIVEEVENT},       
  {"SDL.SDL_KEYDOWN", SDL_KEYDOWN},               
  {"SDL.SDL_KEYUP", SDL_KEYUP},                   
  {"SDL.SDL_MOUSEMOTION", SDL_MOUSEMOTION},       
  {"SDL.SDL_MOUBUTTONDOWN", SDL_MOUSEBUTTONDOWN}, 
  {"SDL.SDL_MOUBUTTONUP", SDL_MOUSEBUTTONUP},     
  {"SDL.SDL_JOYAXISMOTION", SDL_JOYAXISMOTION},   
  {"SDL.SDL_JOYBALLMOTION", SDL_JOYBALLMOTION},   
  {"SDL.SDL_JOYHATMOTION", SDL_JOYHATMOTION},     
  {"SDL.SDL_JOYBUTTONDOWN", SDL_JOYBUTTONDOWN},   
  {"SDL.SDL_JOYBUTTONUP", SDL_JOYBUTTONUP},       
  {"SDL.SDL_QUIT", SDL_QUIT},                     
  {"SDL.SDL_SYSWMEVENT", SDL_SYSWMEVENT},         
  {"SDL.SDL_VIDEORESIZE", SDL_VIDEORESIZE},       
  {"SDL.SDL_VIDEOEXPOSE", SDL_VIDEOEXPOSE},       
  {"SDL.SDL_USEREVENT",  SDL_USEREVENT},          
  //
  {"SDL.SDL_ENABLE", SDL_ENABLE},   
  {"SDL.SDL_DISABLE", SDL_DISABLE}, 
  {"SDL.SDL_QUERY", SDL_QUERY},     
  //
  {"SDL.SDL_GRAB_QUERY", SDL_GRAB_QUERY},
  {"SDL.SDL_GRAB_OFF", SDL_GRAB_OFF},
  {"SDL.SDL_GRAB_ON", SDL_GRAB_ON},
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
  {"SDL.SDL_HAT_CENTERED", SDL_HAT_CENTERED},
  {"SDL.SDL_HAT_UP", SDL_HAT_UP},
  {"SDL.SDL_HAT_RIGHT", SDL_HAT_RIGHT},
  {"SDL.SDL_HAT_DOWN", SDL_HAT_DOWN},
  {"SDL.SDL_HAT_LEFT", SDL_HAT_LEFT},
  {"SDL.SDL_HAT_RIGHTUP", SDL_HAT_RIGHTUP},
  {"SDL.SDL_HAT_RIGHTDOWN", SDL_HAT_RIGHTDOWN},
  {"SDL.SDL_HAT_LEFTUP", SDL_HAT_LEFTUP},
  {"SDL.SDL_HAT_LEFTDOWN", SDL_HAT_LEFTDOWN},
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
  {"SDL.SDL_AUDIO_STOPPED", SDL_AUDIO_STOPPED},
  {"SDL.SDL_AUDIO_PAUSED", SDL_AUDIO_PAUSED},
  {"SDL.SDL_AUDIO_PLAYING", SDL_AUDIO_PLAYING},
  //
  {"SDL.CD_TRAYEMPTY", CD_TRAYEMPTY},
  {"SDL.CD_STOPPED", CD_STOPPED},
  {"SDL.CD_PLAYING", CD_PLAYING},
  {"SDL.CD_PAUSED", CD_PAUSED},
  {"SDL.CD_ERROR", CD_ERROR},
  //
  {"SDL.SDL_GL_RED_SIZE", SDL_GL_RED_SIZE},
  {"SDL.SDL_GL_GREEN_SIZE", SDL_GL_GREEN_SIZE},
  {"SDL.SDL_GL_BLUE_SIZE", SDL_GL_BLUE_SIZE},
  {"SDL.SDL_GL_ALPHA_SIZE", SDL_GL_ALPHA_SIZE},
  {"SDL.SDL_GL_DOUBLEBUFFER", SDL_GL_DOUBLEBUFFER},
  {"SDL.SDL_GL_BUFFER_SIZE", SDL_GL_BUFFER_SIZE},
  {"SDL.SDL_GL_DEPTH_SIZE", SDL_GL_DEPTH_SIZE},
  {"SDL.SDL_GL_STENCIL_SIZE", SDL_GL_STENCIL_SIZE},
  {"SDL.SDL_GL_ACCUM_RED_SIZE", SDL_GL_ACCUM_RED_SIZE},
  {"SDL.SDL_GL_ACCUM_GREEN_SIZE", SDL_GL_ACCUM_GREEN_SIZE},
  {"SDL.SDL_GL_ACCUM_BLUE_SIZE", SDL_GL_ACCUM_BLUE_SIZE},
  {"SDL.SDL_GL_ACCUM_ALPHA_SIZE",SDL_GL_ACCUM_ALPHA_SIZE},
  {NULL}  // end of const data
};
 
KNHAPI(int) init(Ctx *ctx)
{
  KNH_NOTICE(ctx, "loading math...");
  konoha_loadIntConstData(ctx, IntConstData);
  return 1;
}
