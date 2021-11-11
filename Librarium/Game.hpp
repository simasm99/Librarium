#pragma once
#include <iostream>
#include "player.hpp"
#include "map.hpp"

#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

const int SCREEN_HEIGHT = 640;
const int SCREEN_WIDTH = 800;
const int LEVEL_WIDTH = 3072;
const int LEVEL_HEIGHT = 2048;

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
	SDL_Rect camera;

	player* gamePlayer;
	map* gameMap;
};

#endif