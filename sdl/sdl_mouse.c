#include<konoha.h>
#include<SDL/SDL.h>



/*---------Motion---------------------------------------------*/

/* int MouseMotion.getType(void) */
METHOD MouseMotion_getType(Ctx *ctx, knh_sfp_t *sfp)
{
  knh_Glue_t *glue = sfp[0].glue;
  SDL_MouseMotionEvent *motion = (SDL_MouseMotionEvent *)(glue->ptr);
  KNH_RETURN_Int(ctx, sfp, motion->type);
}

/* int MouseMotion.getState(void) */
METHOD MouseMotion_getState(Ctx *ctx, knh_sfp_t *sfp)
{
  knh_Glue_t *glue = sfp[0].glue;
  SDL_MouseMotionEvent *motion = (SDL_MouseMotionEvent *)(glue->ptr);
  KNH_RETURN_Int(ctx, sfp, motion->state);
}

/* int MouseMotion.getX(void) */
METHOD MouseMotion_getX(Ctx *ctx, knh_sfp_t *sfp)
{
  knh_Glue_t *glue = sfp[0].glue;
  SDL_MouseMotionEvent *motion = (SDL_MouseMotionEvent *)(glue->ptr);
  KNH_RETURN_Int(ctx, sfp, motion->x);
}

/* int MouseMotion.getY(void) */
METHOD MouseMotion_getY(Ctx *ctx, knh_sfp_t *sfp)
{
  knh_Glue_t *glue = sfp[0].glue;
  SDL_MouseMotionEvent *motion = (SDL_MouseMotionEvent *)(glue->ptr);
  KNH_RETURN_Int(ctx, sfp, motion->y);
}

/* int MouseMotion.getXrel(void) */
METHOD MouseMotion_getXrel(Ctx *ctx, knh_sfp_t *sfp)
{
  knh_Glue_t *glue = sfp[0].glue;
  SDL_MouseMotionEvent *motion = (SDL_MouseMotionEvent *)(glue->ptr);
  KNH_RETURN_Int(ctx, sfp, motion->xrel);
}

/* int MouseMotion.getYrel(void) */
METHOD MouseMotion_getYrel(Ctx *ctx, knh_sfp_t *sfp)
{
  knh_Glue_t *glue = sfp[0].glue;
  SDL_MouseMotionEvent *motion = (SDL_MouseMotionEvent *)(glue->ptr);
  KNH_RETURN_Int(ctx, sfp, motion->yrel);
}



/*---------Button----------------------------------------------*/

/* int MouseButton.getType(void) */
METHOD MouseButton_getType(Ctx *ctx, knh_sfp_t *sfp)
{
  knh_Glue_t *glue = sfp[0].glue;
  SDL_MouseButtonEvent *button = (SDL_MouseButtonEvent *)(glue->ptr);
  KNH_RETURN_Int(ctx, sfp, button->type);
}

/* int MouseButton.getButton(void) */
METHOD MouseButton_getButton(Ctx *ctx, knh_sfp_t *sfp)
{
  knh_Glue_t *glue = sfp[0].glue;
  SDL_MouseButtonEvent *button = (SDL_MouseButtonEvent *)(glue->ptr);
  KNH_RETURN_Int(ctx, sfp, button->button);
}

/* int MouseButton.getState(void) */
METHOD MouseButton_getState(Ctx *ctx, knh_sfp_t *sfp)
{
  knh_Glue_t *glue = sfp[0].glue;
  SDL_MouseButtonEvent *button = (SDL_MouseButtonEvent *)(glue->ptr);
  KNH_RETURN_Int(ctx, sfp, button->state);
}

/* int MouseButton.getX(void) */
METHOD MouseButton_getX(Ctx *ctx, knh_sfp_t *sfp)
{
  knh_Glue_t *glue = sfp[0].glue;
  SDL_MouseButtonEvent *button = (SDL_MouseButtonEvent *)(glue->ptr);
  KNH_RETURN_Int(ctx, sfp, button->x);
}

/* int MouseButton.getY(void) */
METHOD MouseButton_getY(Ctx *ctx, knh_sfp_t *sfp)
{
  knh_Glue_t *glue = sfp[0].glue;
  SDL_MouseButtonEvent *button = (SDL_MouseButtonEvent *)(glue->ptr);
  KNH_RETURN_Int(ctx, sfp, button->y);
}
