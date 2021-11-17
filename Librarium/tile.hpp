#pragma once
#include "texManager.hpp"

class tile {

public:
	tile();
	virtual ~tile();

	// getters and setters
	SDL_Rect getCollisionBox() const { return mBox; };

	void setTileTexture(SDL_Texture* newTexture) {
		if (this->tileTexture != newTexture) {
			this->tileTexture = newTexture;
		};
	}
	SDL_Texture* returnTileTexture() const { return tileTexture; };
	// getters and setters
protected:
	SDL_Rect mBox;
	SDL_Texture* tileTexture;

};
