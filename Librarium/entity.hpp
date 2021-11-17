#pragma once

#ifndef entity_HPP_INCLUDED
#define entity_HPP_INCLUDED

#include "texManager.hpp"

class entity {

public:
	entity();
	virtual ~entity();

	SDL_Rect getCollisionBox() const { return mBox; };
	bool getSolid() const { return isSolid; };
	
protected:
	SDL_Rect mBox;
	bool isSolid;
};

#endif