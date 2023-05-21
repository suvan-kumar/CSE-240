#include <string>
using namespace std;

class Enemy {
private:
	string name;		// data members
	int level, health, damage;


public:
	Enemy();			 // constructor

	// member functions. Function definition in enemy.cpp
	void setName(string name_input);
	void setLevel(int level_input);
	void setHealth(int health_input);
	void setDamage(int damage_input);
	void displayEnemy();
	string getName();
	int getLevel();
	int getHealth();
	int getDamage();
};

#pragma once
