#include "game.hpp"

SDL_Renderer* game::renderer = nullptr;

game::game():
    gamePlayer(new player(512, 960, 1)),
    gameMap(new map(16, 16))
{
    isRunning = false;
    window = nullptr;
    camera = { 0, 0, 800, 640 };
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

            if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
            {
                std::cout << "Image.h does not work" << std::endl;
                isRunning = false;
            }
            else {
                isRunning = true;
            }
        }
    }else{
        std::cout << "Failed to create window or inicialize SDL2\n";
        isRunning = false;
    }

    gamePlayer->setTexture(texManager::LoadTextureIMG("../Librarium/Textures/Character.png", renderer));
    gameMap->loadMap();
    gameMap->loadTileTexture("../Librarium/Textures/floorTile.bmp", renderer, 64, 64);
    gameMap->loadTileTexture("../Librarium/Textures/sideWall.bmp", renderer, 64, 64);
    gameMap->loadTileTexture("../Librarium/Textures/sideWall2.bmp", renderer, 64, 64);
    gameMap->loadTileTexture("../Librarium/Textures/sideWall3.bmp", renderer, 64, 64);
    gameMap->loadTileTexture("../Librarium/Textures/sideWall4.bmp", renderer, 64, 64);
    gameMap->loadTileTexture("../Librarium/Textures/sideWallCorner.bmp", renderer, 64, 64);
    gameMap->loadTileTexture("../Librarium/Textures/sideWallCorner2.bmp", renderer, 64, 64);
    gameMap->loadTileTexture("../Librarium/Textures/sideWallCorner3.bmp", renderer, 64, 64);
    gameMap->loadTileTexture("../Librarium/Textures/sideWallCorner4.bmp", renderer, 64, 64);
    gameMap->loadTileTexture("../Librarium/Textures/sideWallBoth.bmp", renderer, 64, 64);
    gameMap->loadTileTexture("../Librarium/Textures/sideWallBoth1.bmp", renderer, 64, 64);
    gameMap->loadTileTexture("../Librarium/Textures/black.bmp", renderer, 64, 64);

    
    entities.push_back(new invisibleWallEntity({ 320, 640, 64, 384 }, true));
    entities.push_back(new invisibleWallEntity({ 128, 640, 192, 64 }, true));
    entities.push_back(new invisibleWallEntity({ 64, 128, 64, 512 }, true));
    entities.push_back(new invisibleWallEntity({ 64, 64, 864, 64 }, true));
    entities.push_back(new invisibleWallEntity({ 896, 64, 64, 576 }, true));
    entities.push_back(new invisibleWallEntity({ 704, 640, 192, 64 }, true));
    entities.push_back(new invisibleWallEntity({ 640, 640, 64, 384 }, true));
}

void game::handleEvents(){

    SDL_Event e;

    while (SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_QUIT)
        {
            isRunning = false;
        }
        gamePlayer->handleKeyboard(e);
    }
}

void game::updateEvents(){
    //handle input and update objects
    gamePlayer->movePlayer(entities);
    gamePlayer->setCamera(camera);
    std::cout << "Player x: " << gamePlayer->getCollisionBox().x << "Player y: " << gamePlayer->getCollisionBox().y << std::endl;

}

void game::render(){
	SDL_RenderClear(renderer);
    // render
    
    gameMap->render(renderer, camera);
    gamePlayer->render(camera);    
	SDL_RenderPresent(renderer);
}

void game::clean(){

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
