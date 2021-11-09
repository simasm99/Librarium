#include "texManager.hpp"
#include <iostream>

SDL_Texture* texManager::LoadTexture(const char* filename, SDL_Renderer* rend)
{
    SDL_Surface* temp = SDL_LoadBMP("Character.bmp");
    SDL_Texture* temptex = SDL_CreateTextureFromSurface(rend, temp);
    //std::cout << SDL_GetError();
    //SDL_SetColorKey(temp, SDL_TRUE, SDL_MapRGB(temp->format, 255, 255, 255));
    SDL_FreeSurface(temp);
    temp = nullptr;
    return temptex;
}
