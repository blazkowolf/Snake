#include <iostream>
#include <SDL2\SDL_timer.h>
#include <SDL2\SDL_image.h>
#include "..\Display\Window.h"
#include "..\Input\Input.h"
#include "Tile.h"
#include "Map.h"
#include "Player.h"

int main ( int argc, char *argv[] ) {
	std::cout << "Hello World!" << std::endl;
	Window win( 1280, 720, "Snake" );
	Map map( win );
	SDL_Surface *playerSurface = IMG_Load( "./Res/Images/SnakeBody.png" );
	if ( playerSurface == NULL ) {
		std::cerr << "Failed to load image! SDL_image Error: " << IMG_GetError() << std::endl;
	}
	Player player( 15, 8, 1280 / 32, 720 / 18, SDL_CreateTextureFromSurface( win.GetRenderer(), playerSurface ) );
	SDL_FreeSurface( playerSurface );

	auto Update = [&]() -> void {
		win.Update();
		player.Update();
	};

	Uint32 currentTime = SDL_GetTicks();
	float totalTime = 0.0f;	// In seconds
	float delay = 0.05f;	// In seconds

	win.SetClearColor( 0xff0000ff );
	while ( win.IsRunning() ) {

		totalTime += ( ( SDL_GetTicks() - currentTime ) / 1000.0f );
		currentTime = SDL_GetTicks();

		win.Clear();
		map.Render( win );
		player.Render( win );
		Input::HandleInput();

		if ( totalTime > delay ) {
			totalTime = 0.0f;
			Update();
		}

	}

	return 0;
}