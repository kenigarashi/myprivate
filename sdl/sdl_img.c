#include<konoha.h>
//#include<SDL/SDL.h>
#include"knh_sdl.h"

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

