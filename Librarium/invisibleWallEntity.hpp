#pragma once
#include "entity.hpp"
#ifndef invisibleWallEntity_HPP_INCLUDED
#define invisibleWallEntity_HPP_INCLUDED

class invisibleWallEntity : public entity {
public:
	invisibleWallEntity(SDL_Rect mBox, bool solid);
	~invisibleWallEntity();


};

#endif