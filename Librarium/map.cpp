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

void map::render(SDL_Renderer* rend){ //nepasuot renderio

	for (int x = 0; x < xTiles; x++) {
		for (int y = 0; y < xTiles; y++) {

			tempTile = { x * 64, y * 64, tiles[0].getCollisionBox().h, tiles[0].getCollisionBox().w };
			SDL_RenderCopy(rend, tiles[0].returnTileTexture(), NULL, &tempTile);
			
		}
	}
}

void map::loadMap() {
	
	tileMap.resize(xTiles);
	for (int i = 0; i < xTiles; i++) {
		tileMap[i].resize(yTiles);
	}
	std::cout << tileMap.size() << std::endl;
	std::cout << yTiles << std::endl;

	for (int y = 0; y < yTiles; y++) {
		for (int x = 0; x < xTiles; x++) {
			//std::cout << "x value: " << x << " y value" << y << std::endl;
			tileMap[x][y] = 0;
		}
	}
}

void map::loadTilesTexture(const char* filename, SDL_Renderer* rend){

	loadMap();
	
	tileFloor tile1(64, 64, 0, false);									// Creating floor tile once and adding it to all
	tile1.setTileTexture(texManager::LoadTexture(filename, rend));		// possible tiles vector.
	tiles.push_back(tile1);

}
