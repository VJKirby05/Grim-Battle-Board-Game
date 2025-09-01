#ifndef GAME_H
#define GAME_H
#include "GameCharacter.h"
#include "Player.h"
#include "Enemy.h"
#include <list>

class Game : public GameCharacter	//inherits from GameCharacter
{
public:
	Game();	//constructor
	void init();	//setting up the game
	void render();
	void update();
	void battle();
	void stats();
	void clean();
	
	

private:
	
	Player* pCharacterP; //player
	Enemy* pEnemA;	//bones
	Enemy* pEnemB;	//eyesoar
	Enemy* pEnemC;	//bugger
	Enemy* pEnemD;	//fader
	list<GameCharacter*> lpGameCharacters; //created a list of Game Character pointers

};
#endif