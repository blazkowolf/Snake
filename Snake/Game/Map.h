#pragma once

#include "Tile.h"

class Map {

	private:
		Tile map[32 * 18];

	public:
		Map ( unsigned int *grid );
		const unsigned int NUM_X_TILES_ACROSS = 32;
		const unsigned int NUM_Y_TILES_ACROSS = 18;
		inline Tile& GetTile ( unsigned int x, unsigned int y ) { return map[y*NUM_X_TILES_ACROSS + x]; }
		void Render ();

};