#include "Window.h"
#include <iostream>
#include "..\Input\Input.h"
#include "..\Event\Event.h"

Window::Window ( unsigned int width, unsigned int height, const std::string& title ) {
	running = true;
	this->width = width; this->height = height;
	this->title = title;
	/* Store close window behavior */
	Event::StoreBehavior( "CloseWindow", [=]() { Close(); } );
	/* Initialize keyboard key states */
	//Input::Init();
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
}

Window::~Window () {
	SDL_DestroyRenderer( rendererHandle );
	SDL_DestroyWindow( winHandle );
	SDL_Quit();
}

void Window::SetClearColor ( Uint32 color ) {
	Uint8 r, g, b, a;
	r = ( color >> 24 ) & 0xff;
	g = ( color >> 16 ) & 0x00ff;
	b = ( color >> 8 ) & 0x0000ff;
	a = ( color >> 0 ) & 0x000000ff;
	SDL_SetRenderDrawColor( rendererHandle, r, g, b, a );
}

void Window::Update () {
	/* Swap the buffers */
	SDL_RenderPresent( rendererHandle );
}