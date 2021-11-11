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
	
	for (int y = 0; y < yTiles; y++) {
		for (int x = 0; x < xTiles; x++) {
			tileMap[x][y] = 0;
            if ((x > 8) && (x <= 16)) {
                tileMap[x][y] = 1;
            }
            if ((x > 16) && (x <= 24)) {
                tileMap[x][y] = 2;
            }
            if ((x > 24) && (x <= 32)) {
                tileMap[x][y] = 0;
            }
            if ((x > 32) && (x <= 40)) {
                tileMap[x][y] = 1;
            }
            if ((x > 40) && (x <= 48)) {
                tileMap[x][y] = 2;
            }
		}
	}
}

void map::loadTilesTexture(const char* filename, SDL_Renderer* rend){
	
	tileFloor tile1(64, 64, 0, false);									// Creating floor tile once and adding it to all
	tile1.setTileTexture(texManager::LoadTexture(filename, rend));		// possible tiles vector.
	tiles.push_back(tile1);

}
