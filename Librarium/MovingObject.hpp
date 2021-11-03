#pragma once
#include <SDL.h>

class MovingObject {

public:
	MovingObject();
	virtual ~MovingObject();

	int getType() const;

	SDL_Rect getCollisionBox() const;
	void setCollisionBox(SDL_Rect rect) const;

	SDL_Texture* getTexture() const;
	void setTexture(SDL_Texture* newTexture);

	bool checkForDeletion() const;
	void deleteObject(bool del);

protected:
	SDL_Rect mBox;
	SDL_Texture* texture;

	int type;		// 1 Player, 2 Librarian

	bool objectDelete;

};