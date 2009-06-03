#include<konoha.h>
#include<SDL/SDL.h>

/* Overlay SDL.createYUVoverlay(int width, int height, int fmt, Surface display) */
  /*
METHOD SDL_createYUVoverlay(Ctx* ctx, knh_sfp_t *sfp)
{
  int width = p_int(sfp[1]);
  int height = p_int(sfp[2]);
  int fmt = p_int(sfp[3]);
  SDL_Surface* display = ((sfp[4].glue)->ptr);
  SDL_Overlay* ret = SDL_CreateYUVOverlay(width, height, fmt, display);

  KNH_RETURN(ctx,sfp,new_Glue(ctx,"sdl.Overlay",ret,NULL));
}
  */

/* void SDL.lockYUVoverlay(Overlay ol) */
   /*
METHOD SDL_lockYUVoverlay(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Overlay* ol = ((sfp[1].glue)->ptr);
  if(SDL_LockYUVOverlay(ol) == -1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }

  KNH_RETURN_void(ctx,sfp);
}
   */

/* SDL.unLockYUVoverlay(Overlay ol) */
    /*
METHOD SDL_unLockYUVoverlay(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Overlay* ol = ((sfp[1].glue)->ptr);
  SDL_UnlockYUVOverlay(ol);

  KNH_RETURN_void(ctx,sfp);
}
    */

     /* void SDL.displayYUVoverlay(Overlay ol, Rect dstrect) */
     /*
METHOD SDL_displayYUVoverlay(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Overlay* ol = ((sfp[1].glue)->glue);
  SDL_Rect* dstrect = ((sfp[2].glue)->glue);
  if(SDL_DisplayYUVOverlay(ol, dstrect)!=0){
    fprintf(stderr,"%s\n",SDL_GetError());
  }

  KNH_RETURN_void(ctx,sfp);
}
*/

/* void SDL.freeYUVoverlay(Overlay ol) */ 
      /*
METHOD SDL_freeYUVoverlay(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Overlay* ol = ((sfp[1].glue)->ptr);
  SDL_FreeYUVOverlay(ol);

  KNH_RETURN_void(ctx,sfp);
}
*/
