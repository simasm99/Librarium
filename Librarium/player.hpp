#include "character.hpp"
#include "game.hpp"

#ifndef Player_HPP_INCLUDED
#define Player_HPP_INCLUDED

class player : public character{

public:
	
	player(int xpos, int ypos, int type);
	~player();

	void handleKeyboard(SDL_Event& e);
	void movePlayer();
	void update();
	void render();

private:
	int mVelX;
	int mVelY;

	const int PLAYER_VEL = 10;
};


#endif //Player
