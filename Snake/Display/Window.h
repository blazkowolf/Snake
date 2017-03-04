#pragma once

#include <SDL2\SDL.h>
#include <string>

class Window {

	private:
		SDL_Window *winHandle;
		SDL_Renderer *rendererHandle;
		unsigned int width, height;
		std::string title;
		bool running;

	public:
		Window ( unsigned int width, unsigned int height, const std::string& title );
		~Window ();
		void Update ();
		inline bool IsRunning () { return running; }
		inline void Close () { running = false; }
		inline SDL_Window* GetWindow () { return winHandle; }
		inline SDL_Renderer* GetRenderer () { return rendererHandle; }
		inline unsigned int GetWidth () { return width; }
		inline unsigned int GetHeight () { return height; }
		inline std::string GetTitle () { return title; }

};