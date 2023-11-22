#pragma once

#include "Tile.h"
#include "../Display/Window.h"

class Map {

	private:
		Tile map[32 * 18];
		unsigned int tileSizeX, tileSizeY;
		SDL_Texture *apple, *bg;
		unsigned int appleX, appleY;

	public:
		Map ( const Window& win );
		~Map ();
		const unsigned int NUM_X_TILES_ACROSS = 32;
		const unsigned int NUM_Y_TILES_ACROSS = 18;
		inline Tile& GetTile ( unsigned int x, unsigned int y ) { return map[y*NUM_X_TILES_ACROSS + x]; }
		inline unsigned int GetTileSizeX () { return tileSizeX; }
		inline unsigned int GetTileSizeY () { return tileSizeY; }
		inline unsigned int GetAppleX () { return appleX; }
		inline unsigned int GetAppleY () { return appleY; }
		void Update ();
		void Render ( const Window& win );

};
