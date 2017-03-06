#include <iostream>
#include <SDL2\SDL_image.h>
#include "..\Display\Window.h"
#include "..\Input\Input.h"
#include "Tile.h"

unsigned int grid[32 * 18] = { 0 };

int main ( int argc, char *argv[] ) {
	std::cout << "Hello World!" << std::endl;
	Window win( 1280, 720, "Snake" );
	SDL_Texture *background = NULL;
	SDL_Surface *backgroundSurface = IMG_Load( "./Res/Images/BasicTile500x500.png" );
	if ( backgroundSurface == NULL ) {
		std::cerr << "Failed to load image! SDL_image Error: " << IMG_GetError() << std::endl;
	}
	background = SDL_CreateTextureFromSurface( win.GetRenderer(), backgroundSurface );
	Tile bg( 0, 0, win.GetWidth(), win.GetHeight(), background );
	SDL_FreeSurface( backgroundSurface );

	win.SetClearColor( 0xff0000ff );
	while ( win.IsRunning() ) {

		win.Clear();
		bg.Render( win );
		Input::HandleInput();
		win.Update();

	}

	return 0;
}