#pragma once

class Map {

	private:
		unsigned int grid[32 * 18];

	public:
		Map ();
		const unsigned int NUM_X_TILES_ACROSS = 32;
		const unsigned int NUM_Y_TILES_ACROSS = 18;
		inline unsigned int GetTile ( unsigned int x, unsigned int y ) { return grid[y*NUM_X_TILES_ACROSS + x]; }

};