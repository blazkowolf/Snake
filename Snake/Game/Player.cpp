#include "Player.h"
#include <algorithm>
#include "..\Event\Event.h"

Player::Player ( unsigned int tileX, unsigned int tileY, unsigned int width, unsigned int height, SDL_Texture *tex ) {
	this->tileX = tileX; this->tileY = tileY;
	this->width = width; this->height = height;
	length = 4;
	for ( unsigned int i = 0; i < length; ++i ) {
		bodyTiles.push_back( std::make_pair( tileX, tileY - i ) );
	}
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
	for ( size_t i = length - 1; i > 0; --i ) {
		bodyTiles[i].first = bodyTiles[i - 1].first;
		bodyTiles[i].second = bodyTiles[i - 1].second;
	}
	tileX = std::max( 0, std::min( ( int ) tileX + xDir, 31 ) );
	tileY = std::max( 0, std::min( ( int ) tileY + yDir, 17 ) );
	bodyTiles[0].first = tileX; bodyTiles[0].second = tileY;
	screenX = tileX*width; screenY = tileY*height;
}

void Player::Render ( const Window& win ) {
	SDL_Rect renderArea;
	renderArea.w = width; renderArea.h = height;
	for ( size_t i = 0; i < bodyTiles.size(); ++i ) {
		renderArea.x = bodyTiles[i].first*width;
		renderArea.y = bodyTiles[i].second*height;
		SDL_RenderCopy( win.GetRenderer(), body, NULL, &renderArea );
	}
	/*SDL_Rect renderArea = { screenX, screenY, width, height };
	SDL_RenderCopy( win.GetRenderer(), body, NULL, &renderArea );*/
}