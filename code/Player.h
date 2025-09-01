//Player header
#ifndef	PLAYER_H
#define PLAYER_H
#include "GameCharacter.h"

class Player : public GameCharacter	//inherits from GameCharacter
{
public:
	Player();
	void spawn(string typeId = "A", string icon = "P", int health = 40, int speed = 5, int x = 0, int y = 0);
	void update() override;	//making sure the player update function is called
	void render();
	void stats();	//example of function prototype
	bool isAlive();
	int getXCord();
	int getYCord();
	int isHit(int dmg = 0);

private:
	int m_Health;	//only accessible through function calls
};
#endif
