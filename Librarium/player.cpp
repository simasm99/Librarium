#include "player.hpp"

player::player(int xpos, int ypos, int typenew){

	mBox = { xpos, ypos, 32, 64 };

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

void player::movePlayer(std::vector<entity*> entities){

    //SDL_HasIntersection(&mBox, &bulletBox)
    mBox.x += mVelX;
    if ((mBox.x < 0) || (mBox.x + CHARACTER_WIDTH > LEVEL_WIDTH) || entityCollision({ mBox.x + 16, mBox.y, mBox.w, mBox.h }, entities))
    {
        mBox.x -= mVelX;
    }

    mBox.y += mVelY;
    if ((mBox.y < 0) || (mBox.y + CHARACTER_HEIGHT > LEVEL_HEIGHT) || entityCollision({ mBox.x + 16, mBox.y, mBox.w, mBox.h }, entities))
    {
        mBox.y -= mVelY;
    }
   
}

void player::update(){
    
}

void player::render(SDL_Rect camera){

    SDL_Rect renderQuad = { mBox.x - camera.x, mBox.y - camera.y, CHARACTER_WIDTH, CHARACTER_HEIGHT };
    SDL_RenderCopy(game::renderer, texture, NULL, &renderQuad);

    renderQuad = { mBox.x - camera.x + 16, mBox.y - camera.y, mBox.w, mBox.h };
    SDL_SetRenderDrawColor(game::renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderDrawRect(game::renderer, &renderQuad);
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

bool player::entityCollision(SDL_Rect box, std::vector<entity*> entities) const
{
    for (int i = 0; i < entities.size(); ++i)
    {
        if (entities[i]->getSolid())
        {
            if (checkCollision(box, entities[i]->getCollisionBox()))
            {
                /*if (tiles[i]->checkTilePurpose()) {
                    if (box.y >= tiles[i]->getBox().y) {
                        if (dynamic_cast<diamondBlock*>(tiles[i]) != NULL) {
                            diamondBlock* temp = dynamic_cast<diamondBlock*>(tiles[i]);
                            temp->setSpawnDiamonds(true);
                            temp = nullptr;
                        }
                        if (dynamic_cast<gunBlock*>(tiles[i]) != NULL) {
                            gunBlock* temp = dynamic_cast<gunBlock*>(tiles[i]);
                            temp->setSpawnGun(true);
                            temp = nullptr;
                        }
                    }
                }
                else if ((tiles[i]->getType() == 51) || (tiles[i]->getType() == 52)) {
                    collapsingTile* temp = dynamic_cast<collapsingTile*>(tiles[i]);
                    temp->setCollapse(true);
                    temp = nullptr;
                }*/
                return true;
            }
        }
    }

    return false;
}

bool player::checkCollision(SDL_Rect a, SDL_Rect b) const
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    if (bottomA <= topB)
    {
        return false;
    }

    if (topA >= bottomB)
    {
        return false;
    }

    if (rightA <= leftB)
    {
        return false;
    }

    if (leftA >= rightB)
    {
        return false;
    }

    return true;
}
