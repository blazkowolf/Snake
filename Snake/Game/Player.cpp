#include "Player.h"

#include "..\Event\Event.h"

Player::Player ( unsigned int tileX, unsigned int tileY, unsigned int width, unsigned int height, SDL_Texture *tex ) {
	this->tileX = tileX; this->tileY = tileY;
	this->width = width; this->height = height;
	screenX = tileX*width; screenY = tileY*height;
	moveSpeed = 10;
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
	screenX += xDir*moveSpeed;
	screenY += yDir*moveSpeed;
	tileX = screenX / width; tileY = screenY / height;
}

void Player::Render ( const Window& win ) {
	SDL_Rect renderArea = { ( unsigned int ) screenX, ( unsigned int ) screenY, width, height };
	SDL_RenderCopy( win.GetRenderer(), body, NULL, &renderArea );
}