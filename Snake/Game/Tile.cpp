#include "Tile.h"
#include <iostream>
#include <SDL2\SDL_image.h>

Tile::Tile () {
}

Tile::Tile ( unsigned int x, unsigned int y, unsigned int width, unsigned int height, SDL_Texture *tex ) {
	this->x = x; this->y = y;
	this->width = width; this->height = height;
	/*SDL_Surface *imgSurface = IMG_Load( fileName.c_str() );
	if ( imgSurface == NULL ) {
		std::cerr << "Failed to load image! SDL_image Error: " << IMG_GetError() << std::endl;
		SDL_SetColorKey( imgSurface, SDL_TRUE, SDL_MapRGBA( imgSurface->format, 0xff, 0xff, 0xff, 0xff ) );
	}*/
	this->tex = tex;
	//SDL_FreeSurface( imgSurface );
}

void Tile::Render ( const Window& win ) {
	SDL_Rect renderArea = { x, y, width, height };
	SDL_RenderCopy( win.GetRenderer(), tex, NULL, &renderArea );
}