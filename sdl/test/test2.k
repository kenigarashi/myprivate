using sdl.*

Surface s = SDL.setVideoMode(333,333,32,SDL.SWSURFACE);
Event evt = new Event();

while(Event.waitEvent(evt) >= 0){
		if (evt.getType() == SDL.QUIT) {
		   		  print "good bye";
			     	  SDL.quit();
				  break;
		} else if (evt.getType() == SDL.KEYDOWN) {
		       	KeyBoard key = evt.getKeyBoard();
			KeySym keysym = key.getKeySym();
					  if (keysym.getSym() == SDL.SDLK_SPACE) {
		    			     print "helllO"
		    }
		} else if (evt.getType() == SDL.MOUSEMOTION) {
		       	  MouseMotion motion = evt.getMouseMotion();
				    	   if (motion.getState() != 0) {
					      print "state"
					   } 
		} else if (evt.getType() == SDL.MOUSEBUTTONDOWN) {
		       	  MouseButton button = evt.getMouseButton();
			  	      	   if (button.getButton() == 1){
			  	      	      print "button"
					   }   
		}
}

				     