#include "Game.hpp"
#include <iostream>

Game* game = nullptr;

int main(int argc, char* argv[])
{
    game = new Game();
    game->init("Librarium", 800, 640, false);

	while (game->running())
	{

		game->handleEvents();
		game->updateEvents();
		game->render();

	}

	return 0;
   
}