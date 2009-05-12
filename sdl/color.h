//#include <konoha.h>

//#ifdef
//#include <SDL/SDL.h>
#include <konoha.h>

typedef struct knh_sdl_rect_t {
  knh_int_t x;
  knh_int_t y;
  knh_int_t w;
  knh_int_t h;
} knh_sdl_rect_t;

typedef struct knh_sdl_color_t {
  knh_int_t r;
  knh_int_t g;
  knh_int_t b;
} knh_sdl_color_t;

/*typedef union knh_sdl_event_t {
  knh_int_t type;
  knh_sdl_active_t active;
  knh_sdl_keyboard_t key;
  knh_sdl_mousemotion_t motion;
  knh_sdl_mousebutton_t button;
  knh_sdl_resize_t resize;
  knh_sdl_expose_t expose;
  knh_sdl_quit_t quit;
  } */

typedef struct knh_sdl_active_t {
  knh_int_t type;
  knh_int_t gain;
  knh_int_t state;
} knh_sdl_active_t;

/*typedef struct knh_sdl_keyboard_t {
  knh_int_t type;
  knh_int_t state;
  knh_sdl_keysym_t keysym;
} knh_sdl_keyboard_t;
*/
typedef struct knh_sdl_mousemotion_t {
  knh_int_t type;
  knh_int_t state;
  knh_int_t x;
  knh_int_t y;
  knh_int_t xrel;
  knh_int_t yrel;
} knh_sdl_mousemotion_t;

typedef struct knh_sdl_mousebutton_t {
  knh_int_t type;
  knh_int_t button;
  knh_int_t state;
  knh_int_t x;
  knh_int_t y;
} knh_sdl_mousebutton_t;

typedef struct knh_sdl_resize_t {
  knh_int_t type;
  knh_int_t w;
  knh_int_t h;
} knh_sdl_resize_t;

typedef struct knh_sdl_expose_t {
  knh_int_t type;
} knh_sdl_expose_t;

typedef struct knh_sdl_quit_t {
  knh_int_t type;
} knh_sdl_quit_t;

typedef struct knh_sdl_keysym_t {
  knh_int_t scancode;
  knh_int_t sym;
  knh_int_t mod;
  knh_int_t unicode;
} knh_sdl_keysym_t;
