#include<konoha.h>
#include<SDL/SDL.h>
#include"knh_sdl.h">


/* Joystick */

  /*
METHOD SDL_numJoysticks(Ctx* ctx, knh_sfp_t *sfp)
{
  KNH_RETURN_Int(ctx,sfp,SDL_NumJoysticks());
}
  */
//METHOD SDL_joystickName(Ctx* ctx, knh_sfp_t *sfp)
   /*
METHOD SDL_joystickOpen(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_Joystick* joy = SDL_JoystickOpen(sfp[1].ivalue);
  if(joy==NULL){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETURN(ctx,sfp,new_Glue(ctx,"sdl.Joystick",joy,NULL));
}

METHOD SDL_joystickOpened(Ctx* ctx, knh_sfp_t *sfp)
{
  int state = SDL_JoystickOpened(sfp[1].ivalue);
  if(state==0){
    printf("Joystick is closed\n");
  } else {
    printf("Joystick is opened\n");
  }
  KNH_RETURN_Int(ctx,sfp,state);
}

METHOD SDL_joystickIndex(Ctx* ctx, knh_sfp_t *sfp)
{
  KNH_RETURN_Int(ctx,sfp,SDL_JoystickIndex((sfp[1].glue)->ptr));
}

METHOD SDL_joystickNumaxes(Ctx* ctx, knh_sfp_t *sfp)
{
  KNH_RETURN_Int(ctx,sfp,SDL_JoystickNumAxes((sfp[1].glue)->ptr));
}

METHOD SDL_joystickNumballs(Ctx* ctx, knh_sfp_t *sfp)
{
  KNH_RETURN_Int(ctx,sfp,SDL_JoystickNumBalls((sfp[1].glue)->ptr));
}

METHOD SDL_joystickNumhats(Ctx* ctx, knh_sfp_t *sfp)
{
  KNH_RETURN_Int(ctx,sfp,SDL_JoystickNumHats((sfp[1].glue)->ptr));
}

METHOD SDL_joystickNumbuttons(Ctx* ctx, knh_sfp_t *sfp)
{
  KNH_RETURN_Int(ctx,sfp,SDL_JoystickButtons((sfp[1].glue)->ptr));
}

METHOD SDL_joystickUpdate(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_JoystickUpdate();
  KNH_RETURN_void(ctx,sfp);
}

METHOD SDL_joystickGetaxis(Ctx* ctx, knh_sfp_t *sfp)
{
  KNH_RETURN_Int(ctx,sfp,SDL_JoystickGetAxis((sfp[1].glue)->ptr,sfp[2].ivalue));
}

METHOD SDL_joystickGethat(Ctx* ctx, knh_sfp_t *sfp)
{
  KNH_RETURN_Int(ctx,sfp,SDL_JoystickGetHat((sfp[1].glue)->ptr,sfp[2].ivalue));
}

METHOD SDL_joystickGetbutton(Ctx* ctx, knh_sfp_t *sfp)
{
  KNH_RETURN_Int(ctx,sfp,SDL_JoystickGetButton((sfp[1].glue)->ptr,sfp[2].ivalue));
}

METHOD SDL_joystickGetball(Ctx* ctx, knh_sfp_t *sfp)
{
  if(SDL_JoystickGetBall((sfp[1].glue)->ptr,sfp[2].ivalue,(sfp[3].glue)->ptr,(sfp[4].glue)->ptr)==-1){
    fprintf(stderr,"%s\n",SDL_GetError());
  }
  KNH_RETRURN_void(ctx,sfp);
}

METHOD SDL_joystickClose(Ctx* ctx, knh_sfp_t *sfp)
{
  SDL_JoystickClose((sfp[1].glue)->ptr);
  KNH_RETURN_void(ctx,sfp);
}
*/
