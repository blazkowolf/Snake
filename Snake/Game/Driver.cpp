#include <iostream>
#include <SDL2\SDL_image.h>
#include "..\Display\Window.h"
#include "..\Input\Input.h"
#include "Tile.h"
#include "Map.h"
#include "Player.h"

unsigned int grid[32 * 18] = {

};

int main ( int argc, char *argv[] ) {
	std::cout << "Hello World!" << std::endl;
	Window win( 1280, 720, "Snake" );
	Map map( grid, win );
	SDL_Surface *playerSurface = IMG_Load( "./Res/Images/SnakeBody.png" );
	if ( playerSurface == NULL ) {
		std::cerr << "Failed to load image! SDL_image Error: " << IMG_GetError() << std::endl;
	}
	Player player( 15, 8, 1280 / 32, 720 / 18, SDL_CreateTextureFromSurface( win.GetRenderer(), playerSurface ) );
	SDL_FreeSurface( playerSurface );

	win.SetClearColor( 0xff0000ff );
	while ( win.IsRunning() ) {

		win.Clear();
		map.Render( win );
		player.Render( win );
		Input::HandleInput();
		std::cout << "tilex: " << player.GetTileX() << "\ttiley: " << player.GetTileY() << std::endl;
		win.Update();
		player.Update();

	}

	return 0;
}