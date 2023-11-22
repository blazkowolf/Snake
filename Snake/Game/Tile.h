#pragma once

#include <SDL2/SDL.h>
#include <string>
#include "../Display/Window.h"

class Tile {

	private:
	unsigned int x, y, width, height;
	float angle;
	SDL_RendererFlip flip;
	SDL_Texture	*tex;

	public:
		Tile ();
		Tile ( unsigned int x, unsigned int y, unsigned int width, unsigned int height, float angle, SDL_Texture *tex );
		void Render ( const Window& win );
		inline void SetX ( unsigned int x ) { this->x = x; }
		inline void SetY ( unsigned int y ) { this->y = y; }
		inline void SetAngle ( float angle ) { this->angle = angle; }
		inline void SetFlip ( SDL_RendererFlip flip ) { this->flip = flip; }
		inline void SetTexture ( SDL_Texture *tex ) { this->tex = tex; }
		inline unsigned int GetX () { return x; }
		inline unsigned int GetY () { return y; }
		inline float GetAngle () { return angle; }
		inline SDL_RendererFlip GetFlip () { return flip; }
		inline SDL_Texture* GetTexture () { return tex; }
		inline unsigned int GetWidth () { return width; }
		inline unsigned int GetHeight () { return height; }

};
