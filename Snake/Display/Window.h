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
		void SetClearColor ( Uint32 color );
		inline void SetClearColor ( Uint8 r, Uint8 g, Uint8 b, Uint8 a ) { SDL_SetRenderDrawColor( rendererHandle, r, g, b, a ); }
		inline void Clear () { SDL_RenderClear( rendererHandle ); }
		inline SDL_Window* GetWindow () { return winHandle; }
		inline SDL_Renderer* GetRenderer () { return rendererHandle; }
		inline unsigned int GetWidth () { return width; }
		inline unsigned int GetHeight () { return height; }
		inline std::string GetTitle () { return title; }

};