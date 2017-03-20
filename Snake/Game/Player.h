#pragma once

#include <vector>
#include "..\Display\Window.h"

class Player {

	private:
		unsigned int screenX, screenY;
		unsigned int tileX, tileY;
		unsigned int width, height;
		unsigned int moveSpeed;
		int xDir, yDir;
		/* Number of tiles the snake's body occupies */
		unsigned int length;
		std::vector<std::pair<unsigned int, unsigned int>> bodyTiles;
		SDL_Texture *head, *body;

	public:
		Player ( unsigned int tileX, unsigned int tileY, unsigned int width, unsigned int height, SDL_Texture *tex );
		~Player ();
		void Update ();
		void Render ( const Window& win );
		inline float GetX () { return screenX; }
		inline float GetY () { return screenY; }
		inline unsigned int GetTileX () { return tileX; }
		inline unsigned int GetTileY () { return tileY; }
		inline int GetXDir () { return xDir; }
		inline int GetYDir () { return yDir; }

};