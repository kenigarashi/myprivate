using sdl.*
using math.*

class Apple{
      Surface item;
      Rect    r;
      Rect    size;

      Apple(int x, int y){
        _item = SDL.loadBMP("bmp/ruby.bmp");
	_r = new Rect(x,y, 0, 0);
	_size = new Rect(0, 0, 32, 32);
      }
      void update(Surface screen){
        _item.blitSurface(size, screen, r)
      }
}

class Chara{
      Surface chara;
      Rect    r;
      Rect    size;

      Chara(int x, int y){
        _chara = SDL.loadBMP("bmp/icon.bmp");
	_r = new Rect(x,y, 0, 0);
	_size = new Rect(0,0,32,32);
      }
      void update(Surface screen){
        _chara.blitSurface(size, screen, r)
      }
}

class Wall {
      Surface screen;
      Rect sky;
      Rect ground;
      int scolor;
      int gcolor;

      Wall(Surface screen){
        _screen = screen;
        _sky = new Rect(0, 0, 640, 480);
	_ground = new Rect(0, 400, 640, 80);
	_scolor = screen.mapRGB(128,255,255);
	_gcolor = screen.mapRGB(0,128,0);
      }
      void draw(){
        _screen.fillRect(sky, scolor);
	_screen.fillRect(ground, gcolor);
      }
}

int x = 600
int x2; 
int y = 0


SDL.init(SDL.INIT_EVERYTHING)

Surface screen = SDL.setVideoMode(640, 480, 16, SDL.SWSURFACE)




Chara c = new Chara(x, 375);
Apple a1 = new Apple(Int.random(640), y);
Apple a2 = new Apple(Int.random(640), y);
int color = c.chara.mapRGB(255, 255, 255);
c.chara.setColorKey(SDL.SRCCOLORKEY, color);
a1.item.setColorKey(SDL.SRCCOLORKEY, color);
a2.item.setColorKey(SDL.SRCCOLORKEY, color);
Rect size = new Rect(0, 0, 32, 32)

Wall wall = new Wall(screen);

wall.draw();
c.update(screen);
a1.update(screen);
a2.update(screen);
screen.flip()

Event.enableKeyRepeat(SDL.DEFAULT_REPEAT_DELAY, SDL.DEFAULT_REPEAT_INTERVAL);

Event evt = new Event();

while(1){
  Event.pollEvent(evt);
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
      c.r = new Rect(x, 375, 0, 0)
    } else if(keysym.getSym() == SDL.SDLK_RIGHT){
      x = x+3;
      c.r = new Rect(x, 375, 0, 0)
    }
  } 
  y++;
  a1.r = new Rect(Int.random(640), y, 0, 0)
  a2.r = new Rect(Int.random(640), y, 0, 0)
  wall.draw()
  c.update(screen);
  a1.update(screen);
  a2.update(screen);
  screen.flip();
  float distance = Math.sqrt((x-x2)*(x-x2)+(375-y)*(375-y));
  if(distance <= 20 && distance >=  -20){
    break;
  }
}  					    

// Timer

SDL.quit()