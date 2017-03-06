#pragma once

#include <SDL2\SDL.h>
#include <string>
#include "..\Display\Window.h"

class Tile {

	private:
		unsigned int x, y, width, height;
		SDL_Texture	*tex, *bg;

	public:
		Tile ();
		Tile ( unsigned int x, unsigned int y, unsigned int width, unsigned int height, SDL_Texture *tex, SDL_Texture *bg );
		void Render ( const Window& win );
		inline void SetTexture ( SDL_Texture *tex ) { this->tex = tex; }
		inline void setBGTexture ( SDL_Texture *bg ) { this->bg = bg; }
		inline unsigned int GetWidth () { return width; }
		inline unsigned int GetHeight () { return height; }

};