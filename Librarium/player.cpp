#include "player.hpp"

player::player(int xpos, int ypos, int typenew){

	mBox = { xpos, ypos, CHARACTER_HEIGHT, CHARACTER_WIDTH };

	type = typenew;

	mVelX = 0;
	mVelY = 0;
}

player::~player(){

}

void player::handleKeyboard(SDL_Event& e){

    if(e.type == SDL_KEYDOWN && e.key.repeat == 0){
        switch (e.key.keysym.sym){
            case SDLK_UP: mVelY -= PLAYER_VEL; break;
            case SDLK_DOWN: mVelY += PLAYER_VEL; break;
            case SDLK_LEFT: mVelX -= PLAYER_VEL; break;
            case SDLK_RIGHT: mVelX += PLAYER_VEL; break;
        }
    }
    else if (e.type == SDL_KEYUP && e.key.repeat == 0){
        switch (e.key.keysym.sym) {
        case SDLK_UP: mVelY += PLAYER_VEL; break;
        case SDLK_DOWN: mVelY -= PLAYER_VEL; break;
        case SDLK_LEFT: mVelX += PLAYER_VEL; break;
        case SDLK_RIGHT: mVelX -= PLAYER_VEL; break;
        }
    }

}

void player::movePlayer(){

    
    mBox.x += mVelX;
    if ((mBox.x < 0) || (mBox.x + CHARACTER_WIDTH > LEVEL_WIDTH))
    {
        mBox.x -= mVelX;
    }

    mBox.y += mVelY;
    if ((mBox.y < 0) || (mBox.y + CHARACTER_HEIGHT > LEVEL_HEIGHT))
    {
        mBox.y -= mVelY;
    }
    
}

void player::update(){
    
}

void player::render(SDL_Rect camera){

    SDL_Rect renderQuad = { mBox.x - camera.x, mBox.y - camera.y, CHARACTER_WIDTH, CHARACTER_HEIGHT };
    SDL_RenderCopy(game::renderer, texture, NULL, &renderQuad);
}

void player::setCamera(SDL_Rect& camera){

    camera.x = (mBox.x + CHARACTER_WIDTH / 2) - SCREEN_WIDTH / 2;
    camera.y = (mBox.y + CHARACTER_HEIGHT / 2) - SCREEN_HEIGHT / 2;

    if (camera.x < 0)
    {
        camera.x = 0;
    }
    if (camera.y < 0)
    {
        camera.y = 0;
    }
    if (camera.x > LEVEL_WIDTH - camera.w)
    {
        camera.x = LEVEL_WIDTH - camera.w;
    }
    if (camera.y > LEVEL_HEIGHT - camera.h)
    {
        camera.y = LEVEL_HEIGHT - camera.h;
    }
    
}
