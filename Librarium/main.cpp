#include "game.hpp"
#include <iostream>

game* gameIni = nullptr;

int main(int argc, char* argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	gameIni = new game();
	gameIni->init("Librarium", 800, 640, false);


	while (gameIni->running())
	{
		frameStart = SDL_GetTicks();

		gameIni->handleEvents();
		gameIni->updateEvents();
		gameIni->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}

	}

	return 0;
   
}