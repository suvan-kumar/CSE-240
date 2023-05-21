#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>
using namespace std;

enum playerType { warrior = 0, wizard, rogue };	// definition of playerType

class Player {
private:
	string name; // private data members
	int health;
	int mana;
	int armor;
	int magicResist;
	int attack;
	int magicAttack;
	int level;
	playerType archetype;

public:
	Player(string playerName, int levelInput, playerType archetypeInput); // constructor

	// accessor methods
	string getName();
	int getHealth();
	int getMana();
	int getArmor();
	int getMagicResist();
	int getAttack();
	int getMagicAttack();
	int getLevel();
	playerType getPlayerType();

	virtual void displayPlayer()
	{}

	// Q3-a: Declare Friend Function updateLevel()  (1 point)
	// Declare a friend function named updateLevel() which has 2 parameters and no return value.
	// The first parameter is a pointer to an instance of the Player class
	// The second is an int that represents the new level. Other attributes will be based on the playerType and level. 
	// You need to define this function in hw10.cpp and call this function in case 'c' of executeAction() in hw10.cpp file
	 
	 
	friend void updateLevel(Player* player, int newLevel);					//friend function declaration
};

#endif // _PLAYER_H_
