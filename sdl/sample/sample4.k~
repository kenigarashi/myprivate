using sdl.*
using math.*

SDL.init(SDL.INIT_EVERYTHING)
Surface screen = SDL.setVideoMode(640, 480, 16, SDL.SWSURFACE)

Surface chara = SDL.loadBMP("bmp/icon.bmp")
int color = chara.mapRGB(255,255,255)
chara.setColorKey(SDL.SRCCOLORKEY, color)

Surface item = SDL.loadBMp("bmp/ruby.bmp")
item.setColorKey(SDL.SRCCOLORKEY, color)

Rect r1 = new Rect(0,0,640,480)
int i1 = screen.mapRGB(128, 255, 255)
Rect r2 = new Rect(0,400,640,80)
int i2 = screen.mapRGB(0,128,0)

Rect r3 = new Rect(0, 0, 32, 32)

int x = 600
int x2 = 300
int y = 0
float distance = Math.sqrt((x-x2)*(x-x2)+(375-y)*(375-y));
Rect r4 = new Rect(x, 375, 0, 0)
Rect r5 = new Rect(x2, y, 0, 0)

screen.fillRect(r1, i1)
screen.fillRect(r2, i2)
chara.blitSurface(r3, screen, r4)
item.blitSurface(r3, screen, r5)
screen.flip()

Event.enableKeyRepeat(SDL.DEFAULT_REPEAT_DELAY, SDL.DEFAULT_REPEAT_INTERVAL);

Event evt = new Event();
while(1){
  Event.pollEvent(evt);
  y ++;
  r5 = new Rect(x2, y, 0, 0)
  screen.fillRect(r1, i1);
  screen.fillRect(r2, i2);
  chara.blitSurface(r3, screen, r4);
  item.blitSurface(r3, screen, r5);
  screen.flip()
  if(evt.getType() == SDL.QUIT){
    print "end"
    break;
  } else if(evt.getType() == SDL.KEYDOWN){
    KeyBoard key = evt.getKeyBoard();
    KeySym keysym = key.getKeySym();
    if(keysym.getSym() == SDL.SDLK_ESCAPE){
      print "escape"
      break;
    } else if(keysym.getSym() == SDL.SDLK_LEFT){
      x = x-3;
      y++
      r4 = new Rect(x, 375, 0, 0)
      r5 = new Rect(x2, y, 0, 0)
      screen.fillRect(r1, i1)
      screen.fillRect(r2, i2)
      chara.blitSurface(r3, screen, r4);
      item.blitSurface(r3, screen, r5)
      screen.flip()
    } else if(keysym.getSym() == SDL.SDLK_RIGHT){
      x = x+3;
      y++
      r4 = new Rect(x, 375, 0, 0)
      r5 = new Rect(x2, y, 0, 0)
      screen.fillRect(r1, i1)
      screen.fillRect(r2, i2)
      chara.blitSurface(r3, screen, r4);
      item.blitSurface(r3, screen, r5);
      screen.flip()
    }
  } 
  distance = Math.sqrt((x-x2)*(x-x2)+(375-y)*(375-y));
  if(distance <= 16 && distance >=  -16){
    break;
  }
}  					    

// Timer

SDL.quit()