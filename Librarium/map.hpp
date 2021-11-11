#pragma once
#include "tile.hpp"
#include "tileFloor.hpp"
#include <vector>

class map {
public:
	map(int xWidth, int yWidth);					// Amount of tiles. 48x32 map.
	~map();

	void update();
	void handleEvents();
	void render(SDL_Renderer* rend, SDL_Rect camera);

	void loadMap();
	void loadTilesTexture(const char* filename, SDL_Renderer* rend);

private:
	int xTiles, yTiles;

	SDL_Rect tempTile;

	std::vector<tile> tiles;						// All possible tiles loaded one time.
	std::vector< std::vector<int> > tileMap;		// Map of tile types
};