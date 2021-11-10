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
    if (mBox.x < 0)
    {
        mBox.x -= mVelX;
    }

    mBox.y += mVelY;
    if (mBox.y < 0) 
    {
        mBox.y -= mVelY;
    }
    
}

void player::update(){

}

void player::render(){
	SDL_RenderCopy(game::renderer, texture, NULL, &mBox);
}
