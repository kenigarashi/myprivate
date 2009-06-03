#include<konoha.h>
#include<SDL/SDL.h>
#include"knh_sdl.h"


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
