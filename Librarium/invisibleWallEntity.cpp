#include "invisibleWallEntity.hpp"

invisibleWallEntity::invisibleWallEntity(SDL_Rect collBox, bool solid){
	mBox = collBox;
	isSolid = solid;
}

invisibleWallEntity::~invisibleWallEntity(){

}
