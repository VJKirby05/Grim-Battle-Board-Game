//Enemy class
#include "Enemy.h"
Enemy::Enemy() : GameCharacter()
{
	srand(time(0));
}

//relevant member variables for enemy class
void Enemy::spawn(string typeId, string icon, int health, int speed, int x, int y)
{
	m_typeID = typeId;
	m_icon = icon;
	m_Health = health;
	m_Speed = speed;
	m_X = x;
	m_Y = y;
}

void Enemy::update()	//enemy movement on the grid
{
	// Generate a random value between 1 and 10
	int rndNumY = rand() % 10 + 1;

	
	// If rndNumY is 8 or less, move the enemy by 1 (up or down)
	if (rndNumY <= 8) 
	{
		// Randomly decide whether to move up or down
		int pathDirUD = rand() % 2;  // 0 for down, 1 for up
		if (pathDirUD == 0)
		{
			if (m_Y > 0)	//ensuring that the enemies y cord remains in bounds
			{
				m_Y -= m_Y;  // Move down
			}
			else 
			{
				cout << "Enemy is out of bounds DOWNWARDS" << "\n";
				cout << "SHIFTING DIRECTION.." << "\n";
				m_Y++;
				m_Health -= m_Speed * 3;	//enemy loses health for hitting a wall
			}
			
		}
		else 
		{
			if (m_Y < 11)	//ensuring that the enemies y cord remains in bounds
			{
				m_Y += m_Y;		// Move up
			}					
			else
			{
				cout << "Enemy is out of bounds UPWARDS" << "\n";
				cout << "SHIFTING DIRECTION.." << "\n";
				m_Y--;
				m_Health -= m_Speed * 3;
			}
			
		}
	}
}

void Enemy::render()
{
	//here are the enemy's unique ID and coordinates
	cout << "--ENEMY " << m_icon << " DETAILS--" << "\n";
	cout << "Enemy ID: " << m_typeID << "\n";
	cout << "Enemy Coordinates: " << m_X << "," << m_Y << "\n";
}

int Enemy::isHit(int dmg)	//for when the enemy is damaged
{
	cout << "Enemy is hit by player" << "\n";
	cout << "Enemy loses health" << "\n";
	cout << "Tis but a scratch, they said proudly" << "\n";
	m_Health -= dmg;
	return m_Health;
}

void Enemy::stats()	//other enemy stats
{
	cout << "ENEMY STATS" << "\n";

	srand(time(0));

	int eMinh = 90;
	int eMaxh = 150;

	int eH = rand() % (eMaxh - eMinh + 1) + eMinh;
	m_Health = eH;

	int eMins = 1;
	int eMaxs = 3;

	int eS = rand() % (eMaxs - eMins + 1) + eMins;
	m_Speed = eS;

	cout << "HEALTH: " << m_Health << "\n";
	cout << "SPEED: " << m_Speed << "\n";
}

int Enemy::getXCord()	//enemy x coordinate
{
	return m_X;
}

int Enemy::getYCord()	//enemy y coordinate
{
	return m_Y;
}

bool Enemy::isAlive()	//checks if enemy is alive
{
	return (m_Health > 0);
}