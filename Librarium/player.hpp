#include "character.hpp"
#include "game.hpp"

#ifndef Player_HPP_INCLUDED
#define Player_HPP_INCLUDED

class player : public character{

public:
	
	player(int xpos, int ypos, int type);
	~player();

	void movePlayer();
	void update();
	void render();

};


#endif //Player
