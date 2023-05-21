// CSE240 Spring 2023 HW9
// Suvan Kumar
// Visual Studio

#include "enemy.h"
#include <iostream>
#include <string>

using namespace std;

// Q1 Enemy (2 points)
// Enemy() constructor assigns the following default values to class data members
// name: Goblin
// level: 1
// Health: 4
// Damage: 2
Enemy::Enemy()
{
	// Constructor
	name = "Goblin";
	level = 1;
	health = 4;
	damage = 2;
}

// Q2 (18 points)
// 2 points for each function. Setters and getters will be tested together. 

// Define all the class member functions.
// While defining member functions, note that these functions will be called using 
// an 'Enemy' object which will represent one enemy.
// Eg-  Enemy p[10]; creates 10 Enemy objects
//		p[2].setLevel(19); will set 3rd Enemy's level to 19

// setName assigns 'name_input' to class data member 'name'
void Enemy::setName(string name_input)
{
	// set Enemy name to input
	name = name_input;
}

// setLevel assigns level_input to class data member 'level'
void Enemy::setLevel(int level_input)
{
	// set Enemy level to input
	level = level_input;

}

// setHealth assigns 'health_input' to class data member 'health'
void Enemy::setHealth(int health_input)
{
	// set Enemy health to input
	health = health_input;
}

// setDamage assigns 'damage_input' to class data member 'damage'
void Enemy::setDamage(int damage_input)
{
	// set Enemy damage to input
	damage = damage_input;
}

// displayEnemy displays the name, level, health, and damage of the enemy
// See expected output in question file. Put each attribute on one line.
// Hint: End each line with an endl.
void Enemy::displayEnemy()
{
	// printing Enemy details
	cout << "Name: " << getName() << endl;
	cout << "Level: " << getLevel() << endl;
	cout << "Health: " << getHealth() << endl;
	cout << "Damage: " << getDamage() << endl;
}

// getName returns the class data member 'name'.
string Enemy::getName()
{
	// returning Enemy name
	return name;
}

// getLevel returns the class data member 'level'.
int Enemy::getLevel()
{
	// returning Level 
	return level;
}

// getHealth returns the class data member 'health'.
int Enemy::getHealth()
{
	// returning health
	return health;
}

// getDamage returns the class data member 'damage'.
int Enemy::getDamage()
{	
	// returning damage
	return damage;
}
