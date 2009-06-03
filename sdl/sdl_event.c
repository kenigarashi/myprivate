#include <konoha.h>
#include <SDL/SDL.h>

/* Event Event.new(void) */
METHOD Event_new(Ctx *ctx, knh_sfp_t *sfp)
{
  knh_Glue_t *glue = sfp[0].glue;
  glue->ptr = (void *)malloc(sizeof(SDL_Event));
  KNH_RETURN(ctx, sfp, sfp[0].o);

}

/* int Event.getType(void) */
METHOD Event_getType(Ctx *ctx, knh_sfp_t* sfp)
{
  knh_Glue_t *glue = sfp[0].glue;
  SDL_Event *event = (SDL_Event *)(glue->ptr);
  KNH_RETURN_Int(ctx, sfp, event->type);
}

/*void new_keysym_from_sdl(SDL_keysym *sdl, knh_sdl_keysym_t *knh)
{
  knh->scancode = sdl->scancode;
  knh->sym = sdl->sym;
  knh->mod = sdl->mod;
  knh->unicode = sdl->unicode;
  }*/

/*void new_keyboard_from_sdl(SDL_KeyboardEvent *sdl, knh_sdl_keyboard_t *knh)
{
  knh->type = sdl->type;
  knh->state = sdl->state;
  knh->keysym = malloc(sizeof(knh_sdl_keysym_t));
  new_keysym_from_sdl(&(sdl->keysym), knh->keysym);
  }*/

/* KeyBoard Event.getKeyBoard(void) */
METHOD Event_getKeyBoard(Ctx *ctx, knh_sfp_t *sfp)
{
  knh_Glue_t *glue = sfp[0].glue;
  SDL_Event *event = (SDL_Event *)(glue->ptr);
  //  knh_sdl_keyboard_t *keyboard = malloc(sizeof(knh_sdl_keyboard_t));
  //  new_keyboard_from_sdl(&(event->key), keyboard);
  
  KNH_RETURN(ctx, sfp, new_Glue(ctx, "sdl.KeyBoard", &event->key, NULL));
}

/* MouseMotion Event.getMouseMotion(void) */
METHOD Event_getMouseMotion(Ctx *ctx, knh_sfp_t *sfp)
{
  knh_Glue_t *glue = sfp[0].glue;
  SDL_Event *event = (SDL_Event *)(glue->ptr);

  KNH_RETURN(ctx, sfp, new_Glue(ctx, "sdl.MouseMotion", &event->motion, NULL));
}

/* MouseButton Event.getMouseButton(void) */
METHOD Event_getMouseButton(Ctx *ctx, knh_sfp_t *sfp)
{
  knh_Glue_t *glue = sfp[0].glue;
  SDL_Event *event = (SDL_Event *)(glue->ptr);

  KNH_RETURN(ctx, sfp, new_Glue(ctx, "sdl.MouseButton", &event->button, NULL));
}

/* void Event.pumpEvents(void) */
METHOD Event_pumpEvents(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_PumpEvents();

  KNH_RETURN_void(ctx,sfp);
}

/* int Event.peepEvents(Event evt, int num, int action, int mask) */
METHOD Event_peepEvents(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Event *event = (SDL_Event *)((sfp[1].glue)->ptr);
  int num = p_int(sfp[2]);
  int action = p_int(sfp[3]);
  Uint32 mask = p_int(sfp[4]);
  int ret = SDL_PeepEvents(event, num, action, mask);
  if( ret == -1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }

  KNH_RETURN_Int(ctx, sfp, ret);
}

/* void Event.pollEvent(Event evt) */
METHOD Event_pollEvent(Ctx* ctx,knh_sfp_t *sfp)
{
  SDL_Event *event = ((sfp[1].glue)->ptr);
  if(SDL_PollEvent(event)==0){
    printf("Nothing Event\n");
  }

  KNH_RETURN_void(ctx, sfp);
}

/* int Event.waitEvent(Event evt) */
METHOD Event_waitEvent(Ctx* ctx, knh_sfp_t *sfp)
{
  int ret;
  SDL_Event *event = ((sfp[1].glue)->ptr);
  if((ret = SDL_WaitEvent(event)) == 0){
    fprintf(stderr,"error:%s\n",SDL_GetError());
  }

  KNH_RETURN_Int(ctx, sfp, ret);
}

/* void Event.pushEvent(Event evt) */
METHOD Event_pushEvent(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Event *event = ((sfp[1].glue)->ptr);
  if(SDL_PushEvent(event)==-1){
    fprintf(stderr,"error:%s\n",SDL_GetError());
  }
  KNH_RETURN_void(ctx, sfp);
}

// METHOD Event_setEventFilter(Ctx* ctx, knh_sfp_t *sfp)
// METHOD Event_getEventFilter(Ctx* ctx, knh_sfp_t *sfp)


/* int Event.eventState(int type, int state) */
METHOD Event_eventState(Ctx* ctx, knh_sfp_t *sfp)
{
  Uint8 type = p_int(sfp[1]);
  int state = p_int(sfp[2]);
  int ret = SDL_EventState(type, state);

  KNH_RETURN_Int(ctx,sfp,ret);
}

/* 
METHOD Event_getKeyState(Ctx* ctx,knh_sfp_t *sfp)
{
  int* key = SDL_GetKeyState((sfp[1].glue)->ptr);
  KNH_RETURN_void(ctx,sfp);
}
 */

/* int Event.getModState(void) */
METHOD Event_getModstate(Ctx* ctx, knh_sfp_t *sfp)
{
  int ret = SDL_GetModState();

  KNH_RETURN_Int(ctx,sfp,ret);
}

/* void Event.setModState(int modstate) */
METHOD Event_setModstate(Ctx* ctx, knh_sfp_t *sfp)
{
  int modstate = p_int(sfp[1]);
  SDL_SetModState(modstate);

  KNH_RETURN_void(ctx,sfp);
}

/* String Event.getKeyName(int key) */
METHOD Event_getKeyname(Ctx* ctx, knh_sfp_t *sfp)
{
  int key = p_int(sfp[1]);
  char* ret = SDL_GetKeyName(key);

  KNH_RETURN(ctx, sfp, new_String(ctx, B(ret), NULL));
}


/* int Event.enableUNICODE(int enable) */
METHOD Event_enableUNICODE(Ctx* ctx, knh_sfp_t *sfp)
{
  int enable = p_int(sfp[1]);
  int ret = SDL_EnableUNICODE(enable);

  KNH_RETURN_Int(ctx,sfp,ret);
}

/* void Event.enableKeyRepeat(int delay, int interval) */
METHOD Event_enableKeyRepeat(Ctx* ctx, knh_sfp_t *sfp)
{
  int delay = p_int(sfp[1]);
  int interval = p_int(sfp[2]);
  if(SDL_EnableKeyRepeat(delay, interval)==-1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }

  KNH_RETURN_void(ctx,sfp);
}

//METHOD Event_getMouseState(Ctx* ctx, knh_sfp_t *sfp)
//METHOD Event_getRelativemouseState(Ctx* ctx, knh_sfp_t *sfp)

/* int Event.getAppState(void) */
METHOD Event_getAppState(Ctx* ctx, knh_sfp_t *sfp)
{
  int ret = SDL_GetAppState();

  KNH_RETURN_Int(ctx,sfp,ret);
}

/* int Event.joystickEventState(int state) */
METHOD Event_joystickEventState(Ctx* ctx, knh_sfp_t *sfp)
{
  int state = p_int(sfp[1]);
  int ret = SDL_JoystickEventState(state);

  KNH_RETURN_Int(ctx,sfp,ret);
}

