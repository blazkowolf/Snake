#include "Map.h"
#include <SDL2/SDL_image.h>
#include <iostream>
#include <stdlib.h>
#include "../Event/Event.h"

Map::Map ( const Window& win ) {
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
	bg = SDL_CreateTextureFromSurface( win.GetRenderer(), backgroundSurface );
	for ( size_t y = 0; y < 18; y++ ) {
		for ( size_t x = 0; x < 32; x++ ) {
			map[y*NUM_X_TILES_ACROSS + x] = Tile( x*tileSizeX, y*tileSizeY, tileSizeX, tileSizeY, 0.0f, bg );
		}
	}
	SDL_FreeSurface( backgroundSurface );
	appleX = ( rand() % 32 ); appleY = ( rand() % 18 );
	map[appleY*NUM_X_TILES_ACROSS + appleX].SetTexture( apple );
}

Map::~Map () {
	SDL_DestroyTexture( bg );
	SDL_DestroyTexture( apple );
}

void Map::Update () {
	map[appleY*NUM_X_TILES_ACROSS + appleX].SetTexture( bg );
	appleX = ( rand() % 32 ); appleY = ( rand() % 18 );
	map[appleY*NUM_X_TILES_ACROSS + appleX].SetTexture( apple );
}

void Map::Render ( const Window& win ) {
	for ( size_t y = 0; y < 18; y++ ) {
		for ( size_t x = 0; x < 32; x++ ) {
			if ( x == appleX && y == appleY ) {
				SDL_Rect renderArea = { x*tileSizeX, y*tileSizeY, tileSizeX, tileSizeY };
				SDL_RenderCopy( win.GetRenderer(), bg, NULL, &renderArea );
			}
			map[y*NUM_X_TILES_ACROSS + x].Render( win );
		}
	}
}
