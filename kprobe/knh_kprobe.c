#include<konoha.h>
#ifdef KONOHA_OS__MACOSX

#else
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kprobes.h>


METHOD Kprobe_init(Ctx* ctx, knh_sfp_t* sfp)
{
  int ret;
  char* symname = p_char(sfp[1]);
  struct kprobe kp = {
    .symbol_name = symname,
  };
  kp.pre_handler = handler_pre;
  kp.post_handler = handler_post;
  kp.fault_handler = handler_fault;
  ret = register_kprobe(&kp);
  if(ret < 0) {
    printk(KERN_INFO "register_kprobe failed, returned %d\n", ret);
    return ret;
  }
  printk(KERN_INFO "Planted kprobe at %p\n", kp.addr);
  
  //return
}

METHOD Kprobe_exit(Ctx* ctx, knh_sfp_t* sfp)
{
  struct kprobe kp = (kprobe)((sfp[1].glue)->ptr);
  unregister_kprobe(&kp);
  printk(KERN_INFO "kprobe at %p unregistered\n", kp.addr);
  KNH_RETURN_void(ctx, sfp);
}

  
  
