#include "Tile.h"
#include <iostream>
#include <SDL2\SDL_image.h>

Tile::Tile () {
}

Tile::Tile ( unsigned int x, unsigned int y, unsigned int width, unsigned int height, SDL_Texture *tex, SDL_Texture *bg ) {
	this->x = x; this->y = y;
	this->width = width; this->height = height;
	this->tex = tex;
	this->bg = bg;
}

void Tile::Render ( const Window& win ) {
	SDL_Rect renderArea = { x, y, width, height };
	SDL_RenderCopy( win.GetRenderer(), bg, NULL, &renderArea );
	SDL_RenderCopy( win.GetRenderer(), tex, NULL, &renderArea );
}