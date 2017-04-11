#include "Tile.h"
#include <iostream>
#include <SDL2\SDL_image.h>

Tile::Tile () {
}

Tile::Tile ( unsigned int x, unsigned int y, unsigned int width, unsigned int height, float angle, SDL_Texture *tex ) {
	this->x = x; this->y = y;
	this->width = width; this->height = height;
	this->angle = angle;
	this->tex = tex;
}

void Tile::Render ( const Window& win ) {
	SDL_Rect renderArea = { x, y, width, height };
	//SDL_RenderCopy( win.GetRenderer(), tex, NULL, &renderArea );
	SDL_RenderCopyEx( win.GetRenderer(), tex, NULL, &renderArea, angle, NULL, flip );
}