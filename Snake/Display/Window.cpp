#include "Window.h"
#include <iostream>
#include <SDL2/SDL_image.h>
#include "../Input/Input.h"
#include "../Event/Event.h"

Window::Window ( unsigned int width, unsigned int height, const std::string& title ) {
	running = true;
	this->width = width; this->height = height;
	this->title = title;
	/* Store close window behavior */
	Event::StoreBehavior( "CloseWindow", [=]() { Close(); } );
	/* Initialize SDL */
	if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) {
		std::cout << "SDL failed to initialize! SDL Error: " << SDL_GetError() << std::endl;
		exit( EXIT_FAILURE );
	}
	/* Initialize the window handle */
	winHandle = SDL_CreateWindow( title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, NULL );
	if ( winHandle == NULL ) {
		std::cout << "Window creation failed! SDL Error: " << SDL_GetError() << std::endl;
		exit( EXIT_FAILURE );
	}
	/* Create a software renderer to draw on the specfied window */
	rendererHandle = SDL_CreateRenderer( winHandle, -1, SDL_RENDERER_SOFTWARE );
	if ( rendererHandle == NULL ) {
		std::cout << "Renderer creation failed! SDL Error: " << SDL_GetError() << std::endl;
		exit( EXIT_FAILURE );
	}
	/* Initialize the SDL image library for PNG loading */
	if ( !( IMG_Init( IMG_INIT_PNG ) & IMG_INIT_PNG ) ) {
		std::cout << "SDL_image failed to initialize! SDL_image Error: " << IMG_GetError() << std::endl;
		exit( EXIT_FAILURE );
	}
}

Window::~Window () {
	SDL_DestroyRenderer( rendererHandle );
	SDL_DestroyWindow( winHandle );
	SDL_Quit();
}

void Window::SetClearColor ( Uint32 color ) {
	Uint8 r, g, b, a;
	r = ( color >> (3 * 8) ) & 0xff;
	g = ( color >> (2 * 8) ) & 0xff;
	b = ( color >> (1 * 8) ) & 0xff;
	a = ( color >> (0 * 8) ) & 0xff;
	SDL_SetRenderDrawColor( rendererHandle, r, g, b, a );
}

void Window::Update () {
	/* Swap the buffers */
	SDL_RenderPresent( rendererHandle );
}
