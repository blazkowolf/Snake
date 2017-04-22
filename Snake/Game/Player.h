#pragma once

#include <vector>
#include "Tile.h"
#include "..\Display\Window.h"

class Player {

	private:
		unsigned int screenX, screenY;
		unsigned int tileX, tileY;
		unsigned int width, height;
		int xDir, yDir;
		int lastxDir, lastyDir;
		float angle, lastAngle;
		/* Number of tiles the snake's body occupies */
		unsigned int length;
		//std::vector<std::pair<unsigned int, unsigned int>> bodyTiles;
		std::vector<Tile> bodyTiles;
		SDL_RendererFlip flip;
		SDL_Texture *head, *bodyStraight, *bodyAngle, *tail;

	public:
		Player ( unsigned int tileX, unsigned int tileY, unsigned int width, unsigned int height, SDL_Texture *head, SDL_Texture *bodyStraight, SDL_Texture *bodyAngle, SDL_Texture *tail );
		~Player ();
		void Update ();
		void Render ( const Window& win );
		inline void SetAngle ( float angle ) { this->angle = angle; }
		inline unsigned int GetX () { return screenX; }
		inline unsigned int GetY () { return screenY; }
		inline unsigned int GetTileX () { return tileX; }
		inline unsigned int GetTileY () { return tileY; }
		inline int GetXDir () { return xDir; }
		inline int GetYDir () { return yDir; }
		inline float GetAngle () { return angle; }

};