#include <iostream>
#include <SDL2\SDL_image.h>
#include "..\Display\Window.h"
#include "..\Input\Input.h"
#include "Tile.h"
#include "Map.h"

unsigned int grid[32 * 18] = {

};

int main ( int argc, char *argv[] ) {
	std::cout << "Hello World!" << std::endl;
	Window win( 1280, 720, "Snake" );
	Map map( grid, win );

	win.SetClearColor( 0xff0000ff );
	while ( win.IsRunning() ) {

		win.Clear();
		map.Render( win );
		Input::HandleInput();
		win.Update();

	}

	return 0;
}