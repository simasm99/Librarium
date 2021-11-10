#pragma once
#include "texManager.hpp"

class tile {

public:
	tile();
	virtual ~tile();

	void render(SDL_Rect& camera);
	//virtual void updateTiles(double dt) = 0;

	// getters and setters
	int getType() const { return mType; };
	bool checkBlockSolid() const { return solidBlock; };
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

	bool solidBlock;
	int mType;

};
