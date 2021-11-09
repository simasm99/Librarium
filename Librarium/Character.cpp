#include "character.hpp"

character::character()
{
    mBox = { 0,0,0,0 };
    type = -1;

    texture = NULL;
    objectDelete = false; // true if object has to be deleted;

}

character::~character()
{
    texture = nullptr;
}

int character::returnType() const {

    return type;
}

SDL_Rect character::getCollisionBox() const {
    return mBox;
}

SDL_Texture* character::getTexture() const {
    return texture;
}

void character::setTexture(SDL_Texture* newTexture)
{
    if (this->texture != newTexture) {
        this->texture = newTexture;
    }
}

bool character::checkForDeletion() const {
    return objectDelete;
};

void character::deleteObject(bool deletion) {
    objectDelete = deletion;
};