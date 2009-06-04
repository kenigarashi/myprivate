#include<konoha.h>
#include<SDL/SDL.h>

/* void Color.setColors(Surface screen, int firstcolor, int ncolors) */
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

/* void Color.setPalette(Surface screen, int flags, int firstcolor, int ncolors) */
METHOD Color_setPalette(Ctx* ctx,knh_sfp_t *sfp)
{
  SDL_Color *self = ((sfp[0].glue)->ptr);
  SDL_Surface *screen = ((sfp[1].glue)->ptr);
  int flags = p_int(sfp[2]);
  int firstcolor = p_int(sfp[3]);
  int ncolors = p_int(sfp[4]);
  if(SDL_SetPalette(screen, flags, self, firstcolor, ncolors) == 0){
    fprintf(stderr,"%s\n",SDL_GetError());
  }

  KNH_RETURN_void(ctx,sfp);
}
 

