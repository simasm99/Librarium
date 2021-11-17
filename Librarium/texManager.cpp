#include "texManager.hpp"
#include <iostream>

SDL_Texture* texManager::LoadTextureBMP(const char* filename, SDL_Renderer* rend)
{
    SDL_Surface* temp = SDL_LoadBMP(filename);
    SDL_Texture* temptex = SDL_CreateTextureFromSurface(rend, temp);
    //std::cout << SDL_GetError();
    SDL_FreeSurface(temp);
    temp = nullptr;
    return temptex;
}

SDL_Texture* texManager::LoadTextureIMG(const char* filename, SDL_Renderer* rend)
{
    SDL_Surface* temp = IMG_Load(filename);
    SDL_Texture* temptex = SDL_CreateTextureFromSurface(rend, temp);
    //std::cout << SDL_GetError();
    SDL_SetColorKey(temp, SDL_TRUE, SDL_MapRGB(temp->format, 255, 255, 255));
    SDL_FreeSurface(temp);
    temp = nullptr;
    return temptex;
}
