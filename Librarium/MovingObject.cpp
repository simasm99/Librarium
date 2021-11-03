#include "MovingObject.hpp"

MovingObject::MovingObject(){
	mBox = { 0, 0 ,0 ,0 };
	type = -1;

	texture = NULL;
	objectDelete = false;
}

MovingObject::~MovingObject(){

	texture = NULL;
}

bool MovingObject::checkForDeletion() const{
	return objectDelete;
}

void MovingObject::deleteObject(bool del){
	objectDelete = del;
}


