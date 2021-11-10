#pragma once
#include <iostream>
#include "player.hpp"

#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

class game {

public:
	game();
	~game();

	void init(const char* title, int width, int height, bool fullscreen);

	void handleEvents();
	void updateEvents();
	void render();
	void clean();

	bool running() { return isRunning; };

	static SDL_Renderer* renderer;

private:

	bool isRunning;
	SDL_Window* window;
	player* gamePlayer;
};

#endif