#pragma once

#ifndef TEXMANAGER_HPP_INCLUDED
#define TEXMANAGER_HPP_INCLUDED

#include <SDL.h>
#include <SDL_image.h>

class texManager {

public:
	static SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* rend);
};

#endif