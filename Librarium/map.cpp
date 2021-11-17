#include "map.hpp"
#include <iostream>

map::map(int xWidth, int yWidth){

	xTiles = xWidth;
	yTiles = yWidth;

}

map::~map(){

}

void map::update(){

}

void map::handleEvents(){

}

void map::render(SDL_Renderer* rend, SDL_Rect camera){ //nepasuot renderio

    int leftA = camera.x;
    int rightA = camera.x + camera.w;
    int topA = camera.y;
    int bottomA = camera.y + camera.h;
	for (int y = 0; y < yTiles; y++) {
		for (int x = 0; x < xTiles; x++) {
            tempTile = { x * 64, y * 64, tiles[tileMap[x][y]].getCollisionBox().h, tiles[tileMap[x][y]].getCollisionBox().w };

            bool render = true;

            int leftB;
            int rightB;
            int topB;
            int bottomB;

            leftB = tempTile.x;
            rightB = tempTile.x + tempTile.w;
            topB = tempTile.y;
            bottomB = tempTile.y + tempTile.h;

            if (bottomA <= topB)
            {
                render = false;
            }

            if (topA >= bottomB)
            {
                render = false;
            }

            if (rightA <= leftB)
            {
                render = false;
            }

            if (leftA >= rightB)
            {
                render = false;
            }

            if (render)
            {
                SDL_Rect renderQuad = { tempTile.x - camera.x, tempTile.y - camera.y, 64, 64 };
                SDL_RenderCopy(rend, tiles[tileMap[x][y]].returnTileTexture(), NULL, &renderQuad);
            }
		}
	}
}

void map::loadMap() {
	
	tileMap.resize(xTiles);
	for (int i = 0; i < xTiles; i++) {
		tileMap[i].resize(yTiles);
	}
	
    // Yes, it would be better to load it from external memory and not hardcode it, but the data amount 
    // is small, there are no other levels, so there should be no issues. Maybe later TM.
    tileMap = 
    {
       { 11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11 },
       { 11, 8, 2, 2, 2, 2, 2, 2, 2, 2, 6,11,11,11,11,11 },
       { 11, 4, 0, 0, 0, 0, 0, 0, 0, 0, 1,11,11,11,11,11 },
       { 11, 4, 0, 0, 0, 0, 0, 0, 0, 0, 1,11,11,11,11,11 },
       { 11, 4, 0, 0, 0, 0, 0, 0, 0, 0, 1,11,11,11,11,11 },
       { 11, 4, 0, 0, 0, 0, 0, 0, 0, 0, 9, 2, 2, 2, 2, 2},
       { 11, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       { 11, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       { 11, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       { 11, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       { 11, 4, 0, 0, 0, 0, 0, 0, 0, 0,10, 3, 3, 3, 3, 3},
       { 11, 4, 0, 0, 0, 0, 0, 0, 0, 0, 1,11,11,11,11,11 },
       { 11, 4, 0, 0, 0, 0, 0, 0, 0, 0, 1,11,11,11,11,11 },
       { 11, 4, 0, 0, 0, 0, 0, 0, 0, 0, 1,11,11,11,11,11 },
       { 11, 7, 3, 3, 3, 3, 3, 3, 3, 3, 5,11,11,11,11,11 },
       { 11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11 },
    };    
}

void map::loadTileTexture(const char* filename, SDL_Renderer* rend, int h, int w){
	
	tileFloor tile1(0, 0, 64, 64);									        // Creating floor tile once and adding it to all
	tile1.setTileTexture(texManager::LoadTextureBMP(filename, rend));		// possible tiles vector.
	tiles.push_back(tile1);

}
