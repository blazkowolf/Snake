#include <iostream>
#include "Display\Window.h"

int main ( int argc, char *argv[] ) {
	std::cout << "Hello World!" << std::endl;
	Window win( 1280, 720, "Snake" );

	while ( win.IsRunning() ) {

		win.Update();

		for ( SDL_Event e; SDL_PollEvent( &e ); ) {
			switch ( e.type ) {
				case SDL_QUIT:
					win.Close();
					break;
				case SDL_KEYUP:
					switch ( e.key.keysym.sym ) {
						case SDLK_ESCAPE:
							win.Close();
							break;
					}
			}
		}

	}

	return 0;
}