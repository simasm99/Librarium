#pragma once
#include "texManager.hpp"

class character{

public:
	static const int CHARACTER_WIDTH = 64;
	static const int CHARACTER_HEIGHT = 64;

	character();
	virtual ~character();

	virtual void update() = 0;
	virtual void render(SDL_Rect camera) = 0;

    SDL_Rect getCollisionBox() const;
    void setCollisionBox(SDL_Rect rect) const;

    SDL_Texture* getTexture() const;
    void setTexture(SDL_Texture* newTexture);

    bool checkForDeletion() const;

    void deleteObject(bool deletion);
    int returnType() const;

protected:

    SDL_Rect mBox;
    SDL_Texture* texture; //uzloaidintt viena karta kazkur vektoriui pvz
    int type;

    bool objectDelete = false; // true if object has to be deleted;
};

