//Enemy header
#ifndef	ENEMY_H
#define ENEMY_H
#include "GameCharacter.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

class Enemy : public GameCharacter	//inherits from GameCharacter
{
public:
	Enemy();
	void spawn(string typeId = "B", string icon = "E", int health = 20, int speed = 2, int x = 0, int y = 0);
	void update() override;	//making sure the enemy update function is called
	void render();
	void stats();
	bool isAlive();	//example of function prototype
	int getXCord();
	int getYCord();
	int isHit(int dmg = 0);

private:
	int m_Health;
};
#endif
