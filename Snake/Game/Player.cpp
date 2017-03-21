#include "Player.h"
#include <algorithm>
#include "..\Event\Event.h"

Player::Player ( unsigned int tileX, unsigned int tileY, unsigned int width, unsigned int height, SDL_Texture *tex ) {
	this->tileX = tileX; this->tileY = tileY;
	this->width = width; this->height = height;
	screenX = tileX*width; screenY = tileY*height;
	xDir = 0; yDir = 1;
	this->body = tex;
	Event::StoreBehavior( "MoveUp", [&]() { xDir = 0; yDir = -1; } );
	Event::StoreBehavior( "MoveDown", [&]() { xDir = 0; yDir = 1; } );
	Event::StoreBehavior( "MoveLeft", [&]() { xDir = -1; yDir = 0; } );
	Event::StoreBehavior( "MoveRight", [&]() { xDir = 1; yDir = 0; } );
}

Player::~Player () {
	SDL_DestroyTexture( body );
}

void Player::Update () {
	//tileX += xDir*moveSpeed; tileY += yDir*moveSpeed;
	tileX = std::max( 0, std::min( ( int ) tileX + xDir, 31 ) );
	tileY = std::max( 0, std::min( ( int ) tileY + yDir, 17 ) );
	screenX = tileX*width; screenY = tileY*height;
}

void Player::Render ( const Window& win ) {
	SDL_Rect renderArea = { screenX, screenY, width, height };
	SDL_RenderCopy( win.GetRenderer(), body, NULL, &renderArea );
}