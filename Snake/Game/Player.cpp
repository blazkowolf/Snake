#include "Player.h"
#include <algorithm>
#include <iostream>
#include "..\Event\Event.h"

Player::Player ( unsigned int tileX, unsigned int tileY, unsigned int width, unsigned int height, SDL_Texture *head, SDL_Texture *bodyStraight, SDL_Texture *bodyAngle, SDL_Texture *tail ) {
	this->tileX = tileX; this->tileY = tileY;
	this->width = width; this->height = height;
	length = 4;
	bodyTiles.push_back( Tile( tileX*width, tileY*height, width, height, 180.0f, head ) );
	bodyTiles.push_back( Tile( tileX*width, ( tileY - 1 )*height, width, height, 180.0f, bodyStraight ) );
	bodyTiles.push_back( Tile( tileX*width, ( tileY - 2 )*height, width, height, 180.0f, bodyStraight ) );
	bodyTiles.push_back( Tile( tileX*width, ( tileY - 3 )*height, width, height, 180.0f, tail ) );
	screenX = tileX*width; screenY = tileY*height;
	lastxDir = xDir = 0; lastyDir = yDir = 1; angle = 180.0f; flip = SDL_FLIP_NONE;
	this->head = head;
	this->bodyStraight = bodyStraight;
	this->bodyAngle = bodyAngle;
	this->tail = tail;
	Event::StoreBehavior( "MoveNorth", [&]() { xDir = 0; yDir = -1; /*bodyTiles[1].SetFlip( ( lastxDir == -1 ) ? SDL_FLIP_VERTICAL : SDL_FLIP_NONE );*/ angle = 0.0f; } );
	Event::StoreBehavior( "MoveSouth", [&]() { xDir = 0; yDir = 1; /*bodyTiles[1].SetFlip( ( lastxDir == 1 ) ? SDL_FLIP_VERTICAL : SDL_FLIP_NONE );*/ angle = 180.0f; } );
	Event::StoreBehavior( "MoveWest", [&]() { xDir = -1; yDir = 0; /*bodyTiles[1].SetFlip( ( lastyDir == -1 ) ? SDL_FLIP_VERTICAL : SDL_FLIP_NONE );*/ angle = 270.0f; } );
	Event::StoreBehavior( "MoveEast", [&]() { xDir = 1; yDir = 0; /*bodyTiles[1].SetFlip( ( lastyDir == 1 ) ? SDL_FLIP_VERTICAL : SDL_FLIP_NONE );*/ angle = 90.0f; } );
}

Player::~Player () {
	SDL_DestroyTexture( tail );
	SDL_DestroyTexture( bodyAngle );
	SDL_DestroyTexture( bodyStraight );
	SDL_DestroyTexture( head );
}

void Player::Update () {
	/* Reset body tile values */
	for ( size_t i = length - 1; i > 0; --i ) {
		bodyTiles[i].SetX( bodyTiles[i - 1].GetX() );
		bodyTiles[i].SetY( bodyTiles[i - 1].GetY() );
		bodyTiles[i].SetAngle( bodyTiles[i - 1].GetAngle() );
	}

	/* Exclude the tail and tile before the head here */
	for ( size_t i = length - 2; i > 1; --i ) {
		bodyTiles[i].SetTexture( bodyTiles[i - 1].GetTexture() );
		bodyTiles[i].SetFlip( bodyTiles[i - 1].GetFlip() );
	}

	if ( lastxDir == xDir && lastyDir == yDir ) {
		bodyTiles[1].SetTexture( bodyStraight );
	} else if ( lastxDir != xDir && lastyDir != yDir ) {
		/* If snake was going west, and now going north... */
		if ( lastxDir == -1 ) {
			if ( yDir = -1 ) {
				std::cout << "Inside the if..." << std::endl;
				bodyTiles[1].SetFlip( SDL_FLIP_VERTICAL );
			}
		}
		bodyTiles[1].SetTexture( bodyAngle );
	}

	/* Set new head tile values */
	tileX = std::max( 0, std::min( ( int ) tileX + xDir, 31 ) );
	tileY = std::max( 0, std::min( ( int ) tileY + yDir, 17 ) );
	bodyTiles[0].SetX( tileX*width ); bodyTiles[0].SetY( tileY*height );
	bodyTiles[0].SetAngle( angle );

	lastxDir = xDir; lastyDir = yDir;
}

void Player::Render ( const Window& win ) {
	for ( size_t i = 0; i < bodyTiles.size(); ++i ) {
		bodyTiles[i].Render( win );
	}
}