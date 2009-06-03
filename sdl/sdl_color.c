#include<konoha.h>
#include<SDL/SDL.h>

METHOD Color_setColors(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Color *c = ((sfp[0].glue)->ptr);
  SDL_Surface *s = ((sfp[1].glue)->ptr);
  int fstcolor = p_int(sfp[2]);
  int ncolor = p_int(sfp[3]);
  if(SDL_SetColors(s,c,fstcolor,ncolor) == 0){
    fprintf(stderr,"%s\n",SDL_GetError());
  }

  KNH_RETURN_void(ctx, sfp);
}

/* void SDL.setPalette(Surface screen, int flags, Color color, int firstcolor, int ncolors) */
 /*
METHOD SDL_setPalette(Ctx* ctx,knh_sfp_t *sfp)
{
  if(SDL_SetPalette((sfp[1].glue)->ptr,sfp[2].ivalue,(sfp[3].glue)->ptr,sfp[4].ivalue,sfp[5].ivalue)==0){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN_void(ctx,sfp);
}
 */

