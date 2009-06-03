#include<konoha.h>
#include<SDL/SDL.h>

/* void SDL.glLoadLibrary(String path) */

/*METHOD SDL_glLoadLibrary(Ctx* ctx, knh_sfp_t *sfp)
{
  char* path = p_char(sfp[1]);
  if(SDL_GL_LoadLibrary(path) == -1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }

  KNH_RETURN_void(ctx,sfp);
}
*/

/* void[] SDL.glGetProcAddress(String proc) */

/*METHOD SDL_glGetprocaddress(Ctx* ctx, knh_sfp_t *sfp)
{
  char* proc = p_char(sfp[1]);
  void* ret = SDL_GL_GetProcAddress(proc);


  }*/

/* void SDL.glGetAttribute(int attr) */

 /*METHOD SDL_glGetAttribute(Ctx* ctx, knh_sfp_t *sfp)
{
  int attr = p_int(sfp[1]);
  int* ret = NULL;
  if(SDL_GL_GetAttribute(attr, ret) == -1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }

  KNH_RETURN_void(ctx,sfp);
}
 */

/* void SDL.glSetAttribute(int attr, int value) */

  /*METHOD SDL_glSetAttribute(Ctx* ctx, knh_sfp_t *sfp)
{
  int i1 = p_int(sfp[1]);
  int i2 = p_int(sfp[2]);
  if(SDL_GL_SetAttribute(i1, i2)==-1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }

  KNH_RETURN_void(ctx,sfp);
}
  */

/* void SDL.glSwapBuffers(void) */
 /*
METHOD SDL_glSwapBuffers(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_GL_SwapBuffers();

  KNH_RETURN_void(ctx,sfp);
}
 */
