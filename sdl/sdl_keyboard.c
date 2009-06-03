#include <konoha.h>
#include <SDL/SDL.h>

/*---------KeySym---------------------------------------------*/

/* int KeySym.getScanCode(void) */
METHOD KeySym_getScanCode(Ctx *ctx, knh_sfp_t* sfp)
{
  knh_Glue_t *glue = sfp[0].glue;
  SDL_keysym *sym = (SDL_keysym *)(glue->ptr);
  KNH_RETURN_Int(ctx, sfp, sym->scancode);
}

/* int KeySym.getSym(void) */
METHOD KeySym_getSym(Ctx *ctx, knh_sfp_t* sfp)
{
  knh_Glue_t *glue = sfp[0].glue;
  SDL_keysym *sym = (SDL_keysym *)(glue->ptr);
  KNH_RETURN_Int(ctx, sfp, sym->sym);
}

/* int KeySym.getMod(void) */
METHOD KeySym_getMod(Ctx *ctx, knh_sfp_t* sfp)
{
  knh_Glue_t *glue = sfp[0].glue;
  SDL_keysym *sym = (SDL_keysym *)(glue->ptr);
  KNH_RETURN_Int(ctx, sfp, sym->mod);
}

/* int KeySym.getUniCode(void) */
METHOD KeySym_getUniCode(Ctx *ctx, knh_sfp_t* sfp)
{
  knh_Glue_t *glue = sfp[0].glue;
  SDL_keysym *sym = (SDL_keysym *)(glue->ptr);
  KNH_RETURN_Int(ctx, sfp, sym->unicode);
}

/*----------KeyBoard-------------------------------------------*/

/* int KeyBoard.getType(void) */
METHOD KeyBoard_getType(Ctx *ctx, knh_sfp_t* sfp)
{
  knh_Glue_t *glue = sfp[0].glue;
  SDL_KeyboardEvent *key = (SDL_KeyboardEvent *)(glue->ptr);
  KNH_RETURN_Int(ctx, sfp, key->type);
}

/* int KeyBoard.getState(void) */
METHOD KeyBoard_getState(Ctx *ctx, knh_sfp_t* sfp)
{
  knh_Glue_t *glue = sfp[0].glue;
  SDL_KeyboardEvent *key = (SDL_KeyboardEvent *)(glue->ptr);
  KNH_RETURN_Int(ctx, sfp, key->state);
}

/* KeySym KeyBoard.getKeySym(void) */
METHOD KeyBoard_getKeySym(Ctx *ctx, knh_sfp_t* sfp)
{
  knh_Glue_t *glue = sfp[0].glue;
  SDL_KeyboardEvent *key = (SDL_KeyboardEvent *)(glue->ptr);
  KNH_RETURN(ctx, sfp, new_Glue(ctx, "sdl.KeySym", &key->keysym, NULL));
}
