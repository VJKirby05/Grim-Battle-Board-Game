#pragma once
#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H

#include <iostream>
using namespace std;

class GameCharacter  //abstract class
{
public:
	GameCharacter();
	void spawn(string typeID, string icon, int health, int speed, int x, int y);
	void render();
	virtual void update();	//to be overridden by derived classes
	void stats();
	bool isAlive();

protected:
	string m_typeID;
	string m_icon;	//For both player and enemy graphics on board
	int m_Health;
	int m_Speed;	//how fast is each game character?
	int m_X;	//coordinate x
	int m_Y;	//coordinate y
};
#endif

