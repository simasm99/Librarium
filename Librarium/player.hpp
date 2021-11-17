#include "character.hpp"
#include <vector>
#include "game.hpp"
#include "entity.hpp"

#ifndef Player_HPP_INCLUDED
#define Player_HPP_INCLUDED

class player : public character{

public:
	
	player(int xpos, int ypos, int type);
	~player();
	
	void handleKeyboard(SDL_Event& e);
	void movePlayer(std::vector<entity*> entities);
	void update();
	void render(SDL_Rect camera);

	void setCamera(SDL_Rect& camera);
	bool entityCollision(SDL_Rect box, std::vector<entity*> entities) const;
	bool checkCollision(SDL_Rect a, SDL_Rect b) const;

private:
	int mVelX;
	int mVelY;

	const int PLAYER_VEL = 10;
};


#endif //Player
