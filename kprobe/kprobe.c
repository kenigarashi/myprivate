#include<konoha.h>

/* void Kernel.insmod(String filename) */

METHOD Kernel_insmod(Ctx* ctx, knh_sfp_t* sfp)
{
  char *str = "insmod";
  char *filename = p_char(sfp[1]);
  int len = strlen(str)+strlen(filename)+2;
  char *cmd = (char*)alloca(len);
  snprintf(cmd, len, "%s %s", str, filename);
  system(cmd);

  KNH_RETURN_void(ctx, sfp);
}

/*void Kernel.rmmod(String modname) */

METHOD Kernel_rmmod(Ctx* ctx, knh_sfp_t* sfp)
{
  char *str = "rmmod";
  char *modname = p_char(sfp[1]);
  int len = strlen(str)+strlen(modname)+2;
  char *cmd = (char*)alloca(len);
  snprintf(cmd, len, "%s %s", str, modname);
  system(cmd);

  KNH_RETURN_void(ctx, sfp);
}
