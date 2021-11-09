#include "player.hpp"

player::player(int xpos, int ypos, int typenew){

	mBox = { xpos, ypos, CHARACTER_HEIGHT, CHARACTER_WIDTH };

	type = typenew;

}

player::~player(){

}

void player::movePlayer(){
}

void player::update(){

}

void player::render(){
	SDL_RenderCopy(game::renderer, texture, NULL, NULL);
}
