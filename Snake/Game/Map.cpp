#include "Map.h"
#include <SDL2\SDL_image.h>
#include <iostream>
#include <stdlib.h>
#include "..\Event\Event.h"

Map::Map ( unsigned int *grid, const Window& win ) {
	Event::StoreBehavior( "UpdateApple", [=]() { Update(); } );
	tileSizeX = 1280 / 32; tileSizeY = 720 / 18;
	SDL_Surface *appleSurface = IMG_Load( "./Res/Images/Apple.png" );
	if ( appleSurface == NULL ) {
		std::cerr << "Failed to load image! SDL_image Error: " << IMG_GetError() << std::endl;
	}
	apple = SDL_CreateTextureFromSurface( win.GetRenderer(), appleSurface );
	SDL_FreeSurface( appleSurface );
	SDL_Surface *backgroundSurface = IMG_Load( "./Res/Images/BasicTile500x500.png" );
	if ( backgroundSurface == NULL ) {
		std::cerr << "Failed to load image! SDL_image Error: " << IMG_GetError() << std::endl;
	}
	SDL_Texture *bg = SDL_CreateTextureFromSurface( win.GetRenderer(), backgroundSurface );
	for ( size_t y = 0; y < 18; y++ ) {
		for ( size_t x = 0; x < 32; x++ ) {
			map[y*NUM_X_TILES_ACROSS + x] = Tile( x*tileSizeX, y*tileSizeY, tileSizeX, tileSizeY, bg, bg );
		}
	}
	SDL_FreeSurface( backgroundSurface );
	Update();
}

Map::~Map () {
	SDL_DestroyTexture( apple );
}

void Map::Update () {
	map[( rand() % 18 )*NUM_X_TILES_ACROSS + ( rand() % 32 )].SetTexture( apple );
}

void Map::Render ( const Window& win ) {
	for ( size_t y = 0; y < 18; y++ ) {
		for ( size_t x = 0; x < 32; x++ ) {
			map[y*NUM_X_TILES_ACROSS + x].Render( win );
		}
	}
}