#include "Window.h"
#include <iostream>

Window::Window ( unsigned int width, unsigned int height, const std::string& title ) {
	running = true;
	this->width = width; this->height = height;
	this->title = title;
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

void Window::Update () {
	SDL_RenderPresent( rendererHandle );
}