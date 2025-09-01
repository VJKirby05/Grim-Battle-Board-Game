//Player class
#include "Player.h"
Player::Player() : GameCharacter()
{

}

//relevant member variables for player class
void Player::spawn(string typeId, string icon, int health, int speed, int x, int y) 
{
	m_typeID = "P";
	m_icon = "PP";
	m_Health = health;
	m_Speed = speed;
	m_X = x;
	m_Y = y;
}

void Player::update()	//this allows the player to move on the grid
{
	cout << "Player can move on grid through user input" << "\n";
	cout << "--	--	--	--	--	--" << "\n";
	cout << ":N key - Moves player North[up]" << "\n";
	cout << ":S key - Moves player South[down]" << "\n";
	cout << ":E key - Moves player East[right]" << "\n";
	cout << ":W key - Moves player West[left]" << "\n";
	cout << "Where are you heading?" << "\n";
	char opt;
	cin >> opt;

	
	switch (opt)	//different cases for player movement
	{
		//north and south movement assumes the origin is at the top left corner of the grid
		case 'N':
			cout << "Player moves North by 1" << "\n";
			if (m_Y > 0)	//player moves within bounds
			{
				m_Y--;
			}
			else
			{
				cout << "Player bashed into a northern wall" << "\n";
				m_Health -= m_Speed * 2;	//player is deducted health for hitting a wall[like they got injured]
			}
			break;

		case 'S':
			cout << "Player moves South by 1" << "\n";
			if (m_Y < 11)	//player moves within bounds
			{
				m_Y++;
			}
			else
			{
				cout << "Player bashed into a southern wall" << "\n";
				m_Health -= m_Speed * 2;
			}
			break;


		case 'E':
			cout << "Player moves East by 1" << "\n";
			if (m_X < 11)
			{
				m_X++;
			}
			else
			{
				cout << "Player bashed into an eastern wall" << "\n";
				m_Health -= m_Speed * 2;
			}
			break;

		case 'W':
			cout << "Player moves West by 1" << "\n";
			if(m_X > 0)
			{
				m_X--;
			}
			else
			{
				cout << "Player bashed into a western wall" << "\n";
				m_Health -= m_Speed * 2;
			}
			break;

		default:
			cout << "-NOT ALLOWED!-" << "\n";	//there are only 4 directions to move otherwise the player stays in place
			break;

	}
}

void Player::render()
{
	//here are the player's unique ID and coordinates
	cout << "--PLAYER DETAILS--" << "\n";
	cout << "Player ID: " << m_typeID << "\n";
	cout << "Player Coordinates: " << m_X << "," << m_Y << "\n";

}

int Player::isHit(int dmg)	//for when the player is hit in combat
{
	cout << "Player is hit by enemy" << "\n";
	cout << "Player loses health" << "\n";
	m_Health -= dmg;
	return m_Health;
}

void Player::stats()	//all other stats are called here
{
	cout << "PLAYER STATS" << "\n";

	srand(time(0));

	//generating health and speed stats[using min and max values]
	int pMinh = 140;
	int pMaxh = 270;

	int pH = rand() % (pMaxh - pMinh + 1) + pMinh;
	m_Health = pH;

	int pMins = 2;
	int pMaxs = 4;

	int pS = rand() % (pMaxs - pMins + 1) + pMins;
	m_Speed = pS;

	cout << "HEALTH: " << m_Health << "\n";
	cout << "SPEED: " << m_Speed << "\n";
}

int Player::getXCord()	//player x coordinate
{
	return m_X;
}

int Player::getYCord()	//player y coordinate
{
	return m_Y;
}

bool Player::isAlive()	//checks if player is alive
{
	return (m_Health > 0);
}