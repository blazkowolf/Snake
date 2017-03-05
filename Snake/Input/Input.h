#pragma once

#include <SDL2\SDL.h>
#include "..\Event\Event.h"

class Input {

	private:
		/* Force instantiation within this class */
		Input ();

	public:
		inline static void HandleInput () {
			for ( SDL_Event e; SDL_PollEvent( &e ); ) {
				switch ( e.type ) {
					case SDL_QUIT:
						Event::Call( "CloseWindow" );
						break;
					case SDL_KEYDOWN:
						switch ( e.key.keysym.sym ) {
							case SDLK_ESCAPE:
								Event::Call( "CloseWindow" );
								break;
						}
				}
			}
		}

};