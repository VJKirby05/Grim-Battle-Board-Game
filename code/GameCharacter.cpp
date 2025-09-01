#include "GameCharacter.h"

GameCharacter::GameCharacter()
{
	//Constructor
}

//member variables
void GameCharacter::spawn(string typeID, string icon, int health, int speed, int x, int y)
{
	m_typeID = typeID;
	m_icon = icon;
	m_Health = health;
	m_Speed = speed;
	m_X = x;
	m_Y = y;
}

void GameCharacter::update()	//polymorphic virtual function
{
	cout << "UPDATE" << "\n";
}

void GameCharacter::render()
{
	cout << "RENDER" << "\n";
}

void GameCharacter::stats()
{
	cout << "STATS" << "\n";
}