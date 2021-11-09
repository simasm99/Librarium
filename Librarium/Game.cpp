#include "game.hpp"

SDL_Renderer* game::renderer = nullptr;
SDL_Event game::event;

game::game():
    gamePlayer(new player(32, 32, 1))
{
    isRunning = false;
    window = nullptr;
}

game::~game(){

}

void game::init(const char* title, int width, int height, bool fullscreen){

    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0){
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, flags);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }

        isRunning = true;
    }else{
        std::cout << "Failed to create window or inicialize SDL2\n";
        isRunning = false;
    }

    gamePlayer->setTexture(texManager::LoadTexture("Character.bmp", renderer));
}

void game::handleEvents(){
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    default:
        break;
    }
}

void game::updateEvents(){
    //handle input and update objects

}

void game::render(){
	SDL_RenderClear(renderer);
    // render
    
    gamePlayer->render();
    SDL_RenderCopy(renderer, gamePlayer->getTexture(), NULL, NULL);

    if (gamePlayer->getTexture() == NULL)
        std::cout << "NULL" << std::endl;

	SDL_RenderPresent(renderer);
}

void game::clean(){

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
