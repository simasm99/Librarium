#include "tileFloor.hpp"

tileFloor::tileFloor(int width, int height, int tileType, bool isSolid) {
	mBox = { 0, 0, height, width };

	mType = tileType;
	solidBlock = isSolid;
}
tileFloor::~tileFloor() {

}

//void tileFloor::updateTiles(double dt){

//}

