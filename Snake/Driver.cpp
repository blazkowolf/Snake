#include <iostream>
#include "Display\Window.h"
#include "Input\Input.h"

int main ( int argc, char *argv[] ) {
	std::cout << "Hello World!" << std::endl;
	Window win( 1280, 720, "Snake" );

	win.SetClearColor( 0xff0000ff );
	while ( win.IsRunning() ) {

		win.Clear();
		win.Update();
		Input::HandleInput();

	}

	return 0;
}