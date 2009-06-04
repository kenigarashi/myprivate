#include<konoha.h>
#ifdef KONOHA_OS__MACOSX
#include <SDL.h>
#else
#include<SDL/SDL.h>
#include"knh_sdl.h"
#endif

/* void SDL.init(int flags) */
METHOD SDL_init(Ctx* ctx,knh_sfp_t* sfp)
{
  int flags = p_int(sfp[1]);
  if(SDL_Init((Uint32)flags) == -1){
    fprintf(stderr,"initialize error %s\n",SDL_GetError());
  }

  KNH_RETURN_void(ctx,sfp);
}

/* void SDL.initSubSystem(int flags) */
METHOD SDL_initSubSystem(Ctx* ctx,knh_sfp_t* sfp)
{
  int flags = p_int(sfp[1]);
  if(SDL_InitSubSystem(flags)==-1){
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
  int flags = p_int(sfp[1]);
  SDL_QuitSubSystem((Uint32)flags);

  KNH_RETURN_void(ctx,sfp);
}

/* void SDL.wasInit(int flags) */
METHOD SDL_wasInit(Ctx* ctx,knh_sfp_t* sfp)
{
  int flags = p_int(sfp[1]);
  if(SDL_WasInit(flags)!=0){
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
  SDL_VideoInfo* ret;
  ret = SDL_GetVideoInfo();

  KNH_RETURN(ctx,sfp,new_Glue(ctx,"sdl.VideoInfo",ret,NULL));
}


/* void SDL.videoDriveName(String namebuf, int maxlen) */
METHOD SDL_videoDriverName(Ctx* ctx,knh_sfp_t *sfp)
{
  char* ret;
  char* namebuf = p_char(sfp[1]);
  int maxlen = p_int(sfp[2]);
  ret = SDL_VideoDriverName(namebuf, maxlen);
  if(ret == NULL){
    printf("Video is initialized\n");
    KNH_RETURN_void(ctx,sfp);
  }

  KNH_RETURN(ctx,sfp,ret);
}

/* void SDL.listModes(PixelFormat fmt, int flags) */
/*METHOD SDL_listModes(Ctx* ctx,knh_sfp_t *sfp)
{
  SDL_PixelFormat* fmt = ((sfp[1].glue)->ptr);
  int flags = p_int(sfp[2]);
  int i;
  SDL_Rect** ret = SDL_ListModes(NULL,flags);
  if(ret == (SDL_Rect**)0){
    fprintf(stderr,"%s\n", SDL_GetError());
  } else if((SDL_Rect**)-1){
    printf("Enable All\n");
  } else {
    printf("Enable Mode\n");
    for(i = 0; ret[i]; ++i){
      printf("%d x %d\n", ret[i]->w, ret[i]->h);
    } 
  }
   
  KNH_RETURN_void(ctx,sfp);
}
*/

/* void SDL.videoModeOK(int width, int height, int bpp, int flags) */
METHOD SDL_videoModeOK(Ctx* ctx,knh_sfp_t *sfp)
{
  int width = p_int(sfp[1]);
  int height = p_int(sfp[2]);
  int bpp = p_int(sfp[3]);
  int flags = p_int(sfp[4]);
  int chk = SDL_VideoModeOK(width, height, bpp, flags);
  if(chk == 0){
    printf("Unusable mode\n");
  } else {
    printf("Reccommend %dbpp\n",chk);
  }

  KNH_RETURN_void(ctx,sfp);
}

/* Suface SDL.setVideoMode(int width, int height, int bpp, int flags) */   
METHOD SDL_setVideoMode(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Surface *ret;
  int width = p_int(sfp[1]);
  int height = p_int(sfp[2]);
  int bpp = p_int(sfp[3]);
  int flags = p_int(sfp[4]);
  ret = SDL_SetVideoMode(width, height, bpp, flags);  
  if(ret == NULL){
    fprintf(stderr,"create screen error %s\n",SDL_GetError());
    SDL_Quit();
  }

  KNH_RETURN(ctx, sfp, new_Glue(ctx, "sdl.Surface", ret, NULL));
}

/* void Surface.updateRect(self, int x, int y, int width, int height) */
METHOD Surface_updateRect(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Surface *self = ((sfp[0].glue)->ptr);
  int x = p_int(sfp[1]);
  int y = p_int(sfp[2]);
  int width = p_int(sfp[3]);
  int height = p_int(sfp[4]);
  SDL_UpdateRect(self, x, y, width, height);

  KNH_RETURN_void(ctx,sfp);
}

/* void Surface.updateRects(self, int numrects, Rect rects) */
METHOD Surface_updateRects(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Surface *screen = ((sfp[0].glue)->ptr);
  int numrects = p_int(sfp[1]);
  SDL_Rect *rects = ((sfp[2].glue)->ptr);
  SDL_UpdateRects(screen, numrects, rects);

  KNH_RETURN_void(ctx,sfp);
}

      
/* void Surface.flip(self) */ 
METHOD Surface_flip(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Surface *self = ((sfp[0].glue)->ptr);
  if( SDL_Flip(self) ==-1){
    fprintf(stderr,"flip error %s\n",SDL_GetError());
  }

  KNH_RETURN_void(ctx,sfp);
}

/* void SDL.setGamma(float redgamma, float greengamma, float bluegamma) */
METHOD SDL_setGamma(Ctx* ctx, knh_sfp_t *sfp)
{
  float redgamma = p_float(sfp[1]);
  float greengamma = p_float(sfp[2]);
  float bluegamma = p_float(sfp[3]);
  if(SDL_SetGamma(redgamma, greengamma, bluegamma) == -1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }

  KNH_RETURN_void(ctx,sfp);
}


/* void SDL.getGammaRamp(int redtable, int greentable, int bluetable) */
 /*METHOD SDL_getGammaRamp(Ctx* ctx, knh_sfp_t *sfp)
{
  int redtable = p_int(sfp[1]);
  int greentable = p_int(sfp[2]);
  int bluetable = p_int(sfp[3]);
  if(SDL_GetGammaRamp(&redtable. &greentable. &bluetable)==-1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }

  KNH_RETURN_void(ctx,sfp);
}
*/

/* void SDL.setGammaRamp(int redtable, int greentable, int bluetable) */
  /*METHOD SDL_setGammaramp(Ctx* ctx, knh_sfp_t *sfp)
{
  int redtable = p_int(sfp[1]);
  int greentable = p_int(sfp[2]);
  int bluetable = p_int(sfp[3]);
  if(SDL_SetGammaRamp(&redtable, &greentable, &bluetable)==-1)){
      fprintf(stderr,"%s\n",SDL_GetError());
    }

    KNH_RETURN_void(ctx,sfp);
}
*/

/* int Surface.mapRGB(int red, int green, int blue) */
METHOD Surface_mapRGB(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Surface *screen = ((sfp[0].glue)->ptr);
  Uint8 red = p_int(sfp[1]);
  Uint8 green = p_int(sfp[2]);
  Uint8 blue = p_int(sfp[3]);
  Uint32 ret ;
  ret = SDL_MapRGB(screen->format, red, green, blue);

  KNH_RETURN_Int(ctx, sfp, ret);
}

/* int Surface.mapRGBA(int red, int green, int blue, int alpha) */
METHOD Surface_mapRGBA(Ctx* ctx, knh_sfp_t *sfp)
{
  Uint32 ret;
  SDL_Surface *screen = ((sfp[0].glue)->ptr);
  Uint8 red = p_int(sfp[2]);
  Uint8 green = p_int(sfp[3]);
  Uint8 blue = p_int(sfp[4]);
  Uint8 alpha = p_int(sfp[5]);
  ret = SDL_MapRGBA(screen->format, red, green, blue, alpha);

  KNH_RETURN_Int(ctx,sfp,ret);
}
 

/* void SDL.getRGB(int pixel, PixelFormat fmt, int red, int green, int blue) */
 /*METHOD SDL_getRGB(Ctx* ctx, knh_sfp_t *sfp)
{
  int pixel = p_int(sfp[1]);
  SDL_PixelFormat* fmt = ((sfp[2].glue)->glue);
  int red = p_int(sfp[3]);
  int green = p_int(sfp[4]);
  int blue = p_int(sfp[5]);
  SDL_GetRGB(pixel, fmt, red, green, blue);

  KNH_RETURN_void(ctx,sfp);
}
*/

/* void SDL.getRGBA(int pixel, PixelFormat fmt, int red, int green, int blue, int alpha) */
  /*METHOD SDL_getRGBA(Ctx* ctx, knh_sfp_t *sfp)
{
  int pixel = p_int(sfp[1]);
  SDL_PixelFormat* fmt = ((sfp[2].glue)->ptr);
  int red = p_int(sfp[3]);
  int green = p_int(sfp[4]);
  int blue = p_int(sfp[5]);
  int alpha = p_int(sfp[6]);
  SDL_GetRGBA(pixel, fmt, red, green, blue, alpha);

  KNH_RETURN_void(ctx,sfp);
}
 */

/* Surface SDL.createRGBSurface(int flags, int w, int h, int d, int rmask, int gmask, int bmask, int amask) */
METHOD SDL_createRGBSurface(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Surface* ret;
  Uint32 flags = p_int(sfp[1]);
  int width = p_int(sfp[2]);
  int height = p_int(sfp[3]);
  int depth = p_int(sfp[4]);
  Uint32 rmask = p_int(sfp[5]);
  Uint32 gmask = p_int(sfp[6]);
  Uint32 bmask = p_int(sfp[7]);
  Uint32 amask = p_int(sfp[8]);
  ret = SDL_CreateRGBSurface(flags, width, height, depth, rmask, gmask, bmask, amask);
  if(ret == NULL){
    fprintf(stderr,"%s\n",SDL_GetError());
  }

  KNH_RETURN(ctx, sfp, new_Glue(ctx, "sdl.Surface", ret, NULL));
}

/* Surface SDL.createRGBsurfaceFrom(void[] pixels, int width, int height, int depth, int pitch, int rmask, int gmask, int bmask, int amask) */
//TODO
METHOD SDL_createRGBsurfaceFrom(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Surface* ret;
  void* pixels = ((sfp[1].glue)->ptr);
  int width = p_int(sfp[2]);
  int height = p_int(sfp[3]);
  int depth = p_int(sfp[4]);
  int pitch = p_int(sfp[5]);
  int rmask = p_int(sfp[6]);
  int gmask = p_int(sfp[7]);
  int bmask = p_int(sfp[8]);
  int amask = p_int(sfp[9]);
  ret = SDL_CreateRGBSurfaceFrom(pixels, width, height, depth, pitch, rmask, gmask, bmask, amask);
  if(ret == NULL){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN(ctx, sfp, new_Glue(ctx, "sdl.Surface", ret, NULL));
}
 
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
  char* file = p_char(sfp[1]);
  SDL_Surface *image = SDL_LoadBMP(file);
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
  char* file = p_char(sfp[1]);
  if(SDL_SaveBMP(self, file) == -1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }

  KNH_RETURN_void(ctx,sfp);
}

/* void Surface.setColorKey(self, int flag, int key) */
METHOD Surface_setColorKey(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Surface* self = ((sfp[0].glue)->ptr);
  int flag = p_int(sfp[1]);
  if(SDL_SetColorKey(self, flag, (*(Uint8*)self->pixels) ) == -1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }

  KNH_RETURN_void(ctx,sfp);
}

/* void Surface.setAlpha(self, int flag, int alpha) */
METHOD Surface_setAlpha(Ctx* ctx,knh_sfp_t *sfp)
{
  SDL_Surface* self = ((sfp[0].glue)->ptr);
  Uint32 flag = p_int(sfp[1]);
  Uint8 alpha = p_int(sfp[2]);
  if(SDL_SetAlpha(self, flag, alpha) == -1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }

  KNH_RETURN_void(ctx,sfp);
}

/* void Suface.setClipRect(self, Rect rect) */
METHOD Surface_setClipRect(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Surface* screen = ((sfp[0].glue)->ptr);
  SDL_Rect* rect = ((sfp[1].glue)->ptr);
  SDL_SetClipRect(screen, rect);

  KNH_RETURN_void(ctx,sfp);
}


/* void Surface.getClipRect(self, Rect rect) */
METHOD Surface_getClipRect(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Surface *screen = ((sfp[0].glue)->ptr);
  SDL_Rect *rect = ((sfp[1].glue)->ptr);
  SDL_GetClipRect(screen, rect);

  KNH_RETURN_void(ctx,sfp);
}


/* Surface SDL.convertSurface(Surface screen, PixelFormat fmt, int flags) */
  /*METHOD SDL_convertSurface(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Surface* screen = ((sfp[1].glue)->ptr);
  SDL_PixelFormat* fmt = ((sfp[2].glue)->ptr);
  int flags = p_int(sfp[3]);
  SDL_Surface* ret = SDL_ConvertSurface(screen, fmt, flags);
  if(ret == NULL){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN(ctx,sfp,new_Glue(ctx,"sdl.Surface",ret,NULL));
}
  */
  
/* void Surface.blitSurface(self, Surface screen) */
METHOD Surface_blitSurface(Ctx* ctx,knh_sfp_t *sfp)
{

  SDL_Surface *self = (SDL_Surface*)((sfp[0].glue)->ptr);
  knh_sdl_rect_t* rect1 = (knh_sdl_rect_t*)((sfp[1].glue)->ptr);
  SDL_Surface *screen = (SDL_Surface*)((sfp[2].glue)->ptr);
  knh_sdl_rect_t* rect2 = (knh_sdl_rect_t*)((sfp[3].glue)->ptr);
  SDL_Rect srcrect;
  SDL_Rect dstrect;
  srcrect.x = (Sint16)rect1->x;
  srcrect.y = (Sint16)rect1->y;
  srcrect.w = (Uint16)rect1->w;
  srcrect.h = (Uint16)rect1->h;
  dstrect.x = (Sint16)rect2->x;
  dstrect.y = (Sint16)rect2->y;
  dstrect.w = (Uint16)rect2->w;
  dstrect.h = (Uint16)rect2->h;
  if(SDL_BlitSurface(self, &srcrect, screen, &dstrect) != 0){
    fprintf(stderr,"%s\n",SDL_GetError());
  }

  KNH_RETURN_void(ctx,sfp);
}

/* void Surface.fillRect(self, Rect dstrect, int color) */
METHOD Surface_fillRect(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Surface* self = ((sfp[0].glue)->ptr);
  SDL_Rect* rect = ((sfp[1].glue)->ptr);
  int color = p_int(sfp[2]);
  if(SDL_FillRect(self, rect, color) == -1){
    fprintf(stderr,"error:%s\n",SDL_GetError());
  }

  KNH_RETURN_void(ctx,sfp);
}


/* Surface Surface.displayFormat(self) */
METHOD Surface_displayFormat(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Surface *self = ((sfp[0].glue)->ptr);
  if((SDL_DisplayFormat(self)) == NULL ){
    fprintf(stderr,"%s\n",SDL_GetError());
  }

  KNH_RETURN(ctx,sfp, new_Glue(ctx,"sdl.Surface",self,NULL));
}

/* Surface Surface.displayFormatAlpha(self) */
METHOD Surface_displayFormatAlpha(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Surface *self = SDL_DisplayFormatAlpha((sfp[0].glue)->ptr);
  if(self == NULL){
    fprintf(stderr,"%s\n",SDL_GetError());
  }

  KNH_RETURN(ctx,sfp, new_Glue(ctx,"sdl.Surface",self,NULL));
}


/* void SDL.warpMouse(int x, int y) */
METHOD SDL_warpMouse(Ctx* ctx, knh_sfp_t *sfp)
{
  int x = p_int(sfp[1]);
  int y = p_int(sfp[2]);
  SDL_WarpMouse(x, y);

  KNH_RETURN_void(ctx,sfp);
}



/* Window Management */

/* String SDL.wmSetCaption(String title) */       
METHOD SDL_wmSetCaption(Ctx* ctx, knh_sfp_t *sfp)
{
  char* title = p_char(sfp[1]);
  SDL_WM_SetCaption(title, title);
  
  KNH_RETURN(ctx, sfp, new_String(ctx, B(title), NULL));
}

/* void String.wmGetCaption(String title) */
METHOD String_wmGetCaption(Ctx* ctx, knh_sfp_t *sfp)
{
  char* title = p_char(sfp[0]);
  SDL_WM_GetCaption(&title,&title);
  if(title){
    printf("Title was set to: %s\n",title);
  } else {
    printf("No window title was set !\n");
  }

  KNH_RETURN_void(ctx, sfp);
}

/* void SDL.wmSetIcon(Surface icon, int mask) */
METHOD SDL_wmSetIcon(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Surface* icon = ((sfp[1].glue)->ptr);
  Uint8 mask = p_int(sfp[2]);
  SDL_WM_SetIcon(icon, &mask);

  KNH_RETURN_void(ctx,sfp);
}

/* int SDL.wmIconifyWindow(void) */
METHOD SDL_wmIconifyWindow(Ctx* ctx, knh_sfp_t *sfp)
{
  int ret = SDL_WM_IconifyWindow();
  if(ret == 0){
    fprintf(stderr,"%s\n",SDL_GetError());
  }

  KNH_RETURN_Int(ctx, sfp, ret);
}


/* void SDL.wmToggleFullScreen(Surface screen) */ 
METHOD SDL_wmToggleFullScreen(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Surface* screen = ((sfp[1].glue)->ptr);
  if(SDL_WM_ToggleFullScreen(screen) == 0){
    fprintf(stderr,"%s\n",SDL_GetError());
  }

  KNH_RETURN_void(ctx,sfp);
}

/* Grubmode SDL.wmGrabInput(Grubmod grabmode) */
METHOD SDL_wmGrabInput(Ctx* ctx, knh_sfp_t *sfp)
{
  int grabmode = p_int(sfp[1]);
  int ret = SDL_WM_GrabInput(grabmode);

  KNH_RETURN_Int(ctx, sfp, ret);
}

/* void SDL.delay(int ms) */
METHOD SDL_delay(Ctx* ctx, knh_sfp_t *sfp)
{
  int ms = p_int(sfp[1]);
  SDL_Delay(ms);

  KNH_RETURN_void(ctx,sfp);
}

/* float SDL.getTicks(void) */
METHOD SDL_getTicks(Ctx* ctx, knh_sfp_t *sfp)
{
   SDL_GetTicks();
  
   KNH_RETURN_Float(ctx,sfp,SDL_GetTicks());
}

