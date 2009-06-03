#include<konoha.h>
#include<SDL/SDL.h>
#include"knh_sdl.h"

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
