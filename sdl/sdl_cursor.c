#include<konoha.h>
#include<SDL/SDL.h>

/* Cursor Cursor.createCursor(int[] data, int[] mask, int width, int height, int hot_x, int hot_y) */
METHOD Cursor_createCursor(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Cursor* ret;
  Uint8 data = p_int(sfp[1]);
  Uint8 mask = p_int(sfp[2]);
  int width = p_int(sfp[3]);
  int height = p_int(sfp[4]);
  int hot_x = p_int(sfp[5]);
  int hot_y = p_int(sfp[6]);
  ret = SDL_CreateCursor(&data, &mask, width, height, hot_x, hot_y);

  KNH_RETURN(ctx,sfp, new_Glue(ctx,"sdl.Cursor", ret, NULL));
}

/* void Cursor.freeCursor(self) */
METHOD Cursor_freeCursor(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Cursor* self = ((sfp[0].glue)->ptr);
  SDL_FreeCursor(self);

  KNH_RETURN_void(ctx,sfp);
}

/* void Cursor.setCursor(self) */
METHOD Cursor_setCursor(Ctx* ctx, knh_sfp_t *sfp)
 {  
   SDL_Cursor* self = ((sfp[0].glue)->ptr);
   SDL_SetCursor(self);

   KNH_RETURN_void(ctx,sfp);
 }

/* Cursor Cursor.getCursor(void) */
METHOD Cursor_getCursor(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Cursor* ret = SDL_GetCursor();

  KNH_RETURN(ctx,sfp, new_Glue(ctx,"sdl.Cursor", ret, NULL));
}
  
/* int Cursor.showCursor(int toggle) */   
METHOD Cursor_showCursor(Ctx* ctx, knh_sfp_t *sfp)
{
  int toggle = p_int(sfp[1]);
  int ret = SDL_ShowCursor(toggle);

  KNH_RETURN_Int(ctx,sfp,ret);
}
