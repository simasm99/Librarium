#include "game.hpp"
#include <iostream>

game* gameIni = nullptr;

int main(int argc, char* argv[])
{
	gameIni = new game();
	gameIni->init("Librarium", 800, 640, false);

	while (gameIni->running())
	{
		gameIni->handleEvents();
		gameIni->updateEvents();
		gameIni->render();

	}

	return 0;
   
}