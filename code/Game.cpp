#include "Game.h"
#include "GameCharacter.h"
#include "Enemy.h"

Game::Game()
{
	
}

void Game::init()
{
	//game context
	cout << "=--------=" << "\n";
	cout << "" << "\n";
	cout << "Welcome to 'GRIM BATTLE BOARD GAME'!" << "\n";
	cout << "In this game you play as the Grim Reaper, on a journey to judge the living and the dead." << "\n";
	cout << "There are 4 sinners{Bones,Eyesoar,Bugger,Fader} that MUST be eliminated and their souls, RETRIEVED!" << "\n";
	cout << "Good luck out there!" << "\n";
	cout << "" << "\n";
	cout << "=--------=" << "\n";
	cout << "" << "\n";

	srand(time(0));	//random seed

	//creating the player
	pCharacterP = new Player();

	//creating enmeies[Bones,Eyesoar,Bugger,Fader]
	pEnemA = new Enemy();
	pEnemB = new Enemy();
	pEnemC = new Enemy();
	pEnemD = new Enemy();

	
	//initializing player and enemies
	pCharacterP->spawn("P-Reaper", "PP", 0, 0, 0, 0);
	pCharacterP->stats();
	
	pEnemA->spawn("E-Bones", "!", 1, 2, 2, 4);
	pEnemA->stats();

	pEnemB->spawn("E-Eyesoar", "@", 3, 4, 3, 6);
	pEnemB->stats();

	pEnemC->spawn("E-Bugger", "~", 5, 6, 5, 7);
	pEnemC->stats();

	pEnemD->spawn("E-Fader", "#", 7, 8, 4, 3);
	pEnemD->stats();


	lpGameCharacters.push_back(pCharacterP);	//adding player to list
	lpGameCharacters.push_back(pEnemA);	//adding enemies to list
	lpGameCharacters.push_back(pEnemB);
	lpGameCharacters.push_back(pEnemC);
	lpGameCharacters.push_back(pEnemD);

	
	
}


void Game::render()
{
	//everyone's IDs please!
	
	pCharacterP->render();
	
	pEnemA->render();
		
	pEnemB->render();
		
	pEnemC->render();
		
	pEnemD->render();
		
}


void Game::update()
{
	cout << "GAME UPDATE" << "\n";

	pCharacterP->update();

	if (pEnemA != nullptr)	//once an enemy is dead, they shouldn't need to be called as this would cause a crash
	{
		pEnemA->update();
	}
	else
	{
		cout << "RIP Bones :[" << "\n";
	}

	if (pEnemB != nullptr)
	{
		pEnemB->update();
	}
	else
	{
		cout << "RIP Eyesoar :[" << "\n";	//this specific pointer is gone
	}

	if (pEnemC != nullptr)
	{
		pEnemC->update();
	}
	else
	{
		cout << "RIP Bugger :[" << "\n";
	}

	if (pEnemD != nullptr)
	{
		pEnemD->update();
	}
	else
	{
		cout << "RIP Fader :[" << "\n";
	}
	
	
	
}

void Game::battle()	//this is where the fun begins...
{
	cout << "ANY CONFLICT HAPPENING?" << "\n";

	if (pCharacterP->getYCord() == pEnemA->getYCord())
	{
		cout << "BATTLE START!!" << "\n";
		cout << "about to do battle with Bones\n";

		//vs. Bones
		cout << "=-----------------------------------------=" << "\n";

		cout << "" << "\n";
		cout << "				-----------" << "\n";
		cout << "				--!-- --!--" << "\n";
		cout << "				--- [--] --" << "\n";
		cout << "				--- ==== --" << "\n";
		cout << "" << "\n";
		cout << "" << "\n";
		cout << "" << "\n";
		cout << "--------" << "\n";
		cout << "[------]" << "\n";
		cout << "-[----]-" << "\n";
		cout << "--[--]--" << "\n";
		cout << "" << "\n";


		cout << "=-----------------------------------------=" << "\n";

		//battle algorithm
		cout << "The foe Bones holds a D20" << "\n";
		int bonD20 = rand() % 20 + 1;
		cout << "They roll it..." << "\n";

		if (bonD20 == 20)	//critical hit
		{
			pCharacterP->isHit(20);
		}
		else if (bonD20 <= 15)
		{
			pCharacterP->isHit(bonD20);
		}
		else
		{
			cout << "Bones misses!" << "\n";
		}

		cout << "The enemy is about to flee" << "\n";
		cout << "Would you like to strike[y/n]?" << "\n";
		char q;
		cin >> q;

		if (q == 'y' || q == 'Y')
		{
			int pow = rand() % 15 + 10;
			cout << "The Player inflicted " << pow << " damage on Bones" << "\n";	//the player quickly slashes the enemy
			pEnemA->isHit(pow);

		}

		cout << "--BATTLE END--" << "\n";

	}

	if (pCharacterP->getYCord() == pEnemB->getYCord())	//checking if the player and enemy occupy the same space
	{
		cout << "BATTLE START!!" << "\n";
		cout << "about to do battle with Eyesoar\n";

		//vs. Eyesoar
		cout << "=-----------------------------------------=" << "\n";

		cout << "" << "\n";
		cout << "				-+---@---+-" << "\n";
		cout << "				-----@-----" << "\n";
		cout << "				-- {- -} --" << "\n";
		cout << "				-- = = = --" << "\n";
		cout << "" << "\n";
		cout << "" << "\n";
		cout << "" << "\n";
		cout << "--------" << "\n";
		cout << "[------]" << "\n";
		cout << "-[----]-" << "\n";
		cout << "--[--]--" << "\n";
		cout << "" << "\n";

		cout << "=-----------------------------------------=" << "\n";

		cout << "The foe Eyesoar holds a D20" << "\n";
		int eyeD20 = rand() % 20 + 1;
		cout << "They roll it..." << "\n";

		if (eyeD20 == 20)
		{
			pCharacterP->isHit(20);
		}
		else if (eyeD20 <= 15)
		{
			pCharacterP->isHit(eyeD20);
		}
		else
		{
			cout << "Eyesoar misses!" << "\n";
		}

		cout << "The enemy is about to flee" << "\n";
		cout << "Would you like to strike[y/n]?" << "\n";
		char q;
		cin >> q;

		if (q == 'y' || q == 'Y')
		{
			int pow = rand() % 15 + 10;
			cout << "The Player inflicted " << pow << " damage on Eyesoar" << "\n";
			pEnemB->isHit(pow);

		}

		cout << "--BATTLE END--" << "\n";

	}

	if (pCharacterP->getYCord() == pEnemC->getYCord())
	{

		cout << "BATTLE START!!" << "\n";
		cout << "about to do battle with Bugger\n";

		//vs. Bugger
		cout << "=-----------------------------------------=" << "\n";

		//Unique enemy ASCII graphic

		cout << "" << "\n";
		cout << "				---- ~ ----" << "\n";
		cout << "				--~-   -~--" << "\n";
		cout << "				--~~   ~~--" << "\n";
		cout << "				--~=~ ~=~--" << "\n";
		cout << "" << "\n";
		cout << "" << "\n";
		cout << "" << "\n";
		cout << "--------" << "\n";
		cout << "[------]" << "\n";
		cout << "-[----]-" << "\n";
		cout << "--[--]--" << "\n";
		cout << "" << "\n";

		cout << "=-----------------------------------------=" << "\n";

		cout << "The foe Bugger holds a D20" << "\n";
		int bugD20 = rand() % 20 + 1;
		cout << "They roll it..." << "\n";

		if (bugD20 == 20)
		{
			pCharacterP->isHit(20);
		}
		else if (bugD20 <= 15)
		{
			pCharacterP->isHit(bugD20);
		}
		else
		{
			cout << "Bugger misses!" << "\n";
		}

		cout << "The enemy is about to flee" << "\n";
		cout << "Would you like to strike[y/n]?" << "\n";
		char q;
		cin >> q;

		if (q == 'y' || q == 'Y')
		{
			int pow = rand() % 15 + 10;
			cout << "The Player inflicted " << pow << " damage on Bugger" << "\n";
			pEnemC->isHit(pow);

		}

		cout << "--BATTLE END--" << "\n";

	}

	if (pCharacterP->getYCord() == pEnemD->getYCord())
	{

		cout << "BATTLE START!!" << "\n";
		cout << "about to do battle with Fader\n";

		//vs. Fader
		cout << "=-----------------------------------------=" << "\n";

		cout << "" << "\n";
		cout << "				#- --# -- #-" << "\n";
		cout << "				--#- # # -~#-" << "\n";
		cout << "				#-#~ #  #~#-" << "\n";
		cout << "				--## ## ##-" << "\n";
		cout << "" << "\n";
		cout << "" << "\n";
		cout << "" << "\n";
		cout << "--------" << "\n";
		cout << "[------]" << "\n";
		cout << "-[----]-" << "\n";
		cout << "--[--]--" << "\n";
		cout << "" << "\n";

		cout << "=-----------------------------------------=" << "\n";

		cout << "The foe Fader holds a D20" << "\n";
		int fadD20 = rand() % 20 + 1;	//roll the 20-sided die
		cout << "They roll it..." << "\n";

		if (fadD20 == 20)
		{
			pCharacterP->isHit(20);
		}
		else if (fadD20 <= 15)
		{
			pCharacterP->isHit(fadD20);
		}
		else
		{
			cout << "Fader misses!" << "\n";
		}

		cout << "The enemy is about to flee" << "\n";
		cout << "Would you like to strike[y/n]?" << "\n";
		char q;
		cin >> q;

		if (q == 'y' || q == 'Y')
		{
			int pow = rand() % 15 + 10;
			cout << "The Player inflicted " << pow << " damage on Fader" << "\n";	//grim reaper can hurt the already dead
			pEnemD->isHit(pow);

		}

		cout << "--BATTLE END--" << "\n";

	}
	
}

void Game::stats()	//displaying the stats of the game characters
{
	cout << "GAME STATS" << "\n";

	/*
	for (auto* gchar : lpGameCharacters)
	{
		gchar->stats();
	}
	*/

	pCharacterP->stats();
	pEnemA->stats();
	pEnemB->stats();
	pEnemC->stats();
	pEnemD->stats();
	
}

void Game::clean()	//the hungry beast checks if any of the creatures are dead[including the player]
{
	cout << "CLEAN GRID" << "\n";


	if (pCharacterP->isAlive() <= 0)
	{
		cout << "Player is Dead" << "\n";
		delete pCharacterP;
		pCharacterP = nullptr;
	}
	else
	{
		cout << "Player is Alive" << "\n";	//the reaper gets to fight another day
	}

	if (pEnemA->isAlive() <= 0)
	{
		cout << "Enemy A is Dead" << "\n";	//refers to Bones
		delete pEnemA;
		pEnemA = nullptr;
	}
	else
	{
		cout << "Enemy A is Alive" << "\n";
	}

	if (pEnemB->isAlive() <= 0)
	{
		cout << "Enemy B is Dead" << "\n";	//this is Eyesoar
		delete pEnemB;
		pEnemB = nullptr;
	}
	else
	{
		cout << "Enemy B is Alive" << "\n";
	}

	if (pEnemC->isAlive() <= 0)
	{
		cout << "Enemy C is Dead" << "\n";	//and Bugger
		delete pEnemC;
		pEnemC = nullptr;
	}
	else
	{
		cout << "Enemy C is Alive" << "\n";
	}

	if (pEnemD->isAlive() <= 0)
	{
		cout << "Enemy D is Dead" << "\n";	//cannot forget Fader
		delete pEnemD;
		pEnemD = nullptr;
	}
	else
	{
		cout << "Enemy D is Alive" << "\n";
	}

	
}
