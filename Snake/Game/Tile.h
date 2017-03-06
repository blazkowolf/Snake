#pragma once

#include <SDL2\SDL.h>
#include <string>
#include "..\Display\Window.h"

class Tile {

	private:
		unsigned int x, y, width, height;
		SDL_Texture	*tex;

	public:
		Tile ( unsigned int x, unsigned int y, unsigned int width, unsigned int height, SDL_Texture *tex );
		void Render ( const Window& win );
		inline unsigned int GetWidth () { return width; }
		inline unsigned int GetHeight () { return height; }

};