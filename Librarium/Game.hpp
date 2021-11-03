#pragma once
#include <SDL.h>
#include <iostream>

class Game {

public:
	Game();
	~Game();

	void init(const char* title, int width, int height, bool fullscreen);

	void handleEvents();
	void updateEvents();
	void render();
	void clean();

	bool running() { return isRunning; };

	static SDL_Event event;
	static SDL_Renderer* renderer;

private:

	bool isRunning;
	SDL_Window* window;
};