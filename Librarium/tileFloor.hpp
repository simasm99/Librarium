#pragma once
#include "tile.hpp"

class tileFloor : public tile {
public:
	tileFloor(int width, int height, int tileType, bool isSolid);
	~tileFloor();

	//void updateTiles(double dt) override;
};