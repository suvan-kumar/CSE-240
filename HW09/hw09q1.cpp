// CSE240 Spring 2023 HW9
// Suvan Kumar
// Visual Studio

// READ BEFORE YOU START:
// You are given a partially completed program which consist of a class 'Enemy' defined in enemy.h
// The definitions of class member functions are to be filled in enemy.cpp
// hw09q1.cpp (this file) creates an array of objects 'p[]' and uses a menu driven program to add an enemy, display enemy info, 
// sort the enemy list and to find the highest level enemy(by level).
// You should start completing the program from from Q1. Question numbers are given around line 33.
// To begin, you should trace through the given code and understand how it works.
// Please read the instructions above each required function and follow the directions carefully.
// If you modify any of the given code, the return types, or the parameters, you risk getting compile error.
// You are not allowed to modify main ().

// ***** WRITE COMMENTS FOR IMPORANT STEPS OF YOUR CODE. *****
// ***** GIVE MEANINGFUL NAMES TO VARIABLES. *****

#include "enemy.h"
#include <iostream>
#include <string>

#define MAX_ENEMIES 10

using namespace std;

// forward declaration of functions (already implmented)
void executeAction(char);

// functions that need implementation:
// in enemy.cpp :
// Q1 Enemy constructor			// 2 points
// Q2 Enemy member functions		// 18 points

// in this file (hw09q1.cpp) : Q3 to Q6
int addEnemy(string name_input, int level_input, int health_input, int damage_input);	// 10 points
void displayEnemies();																// 5 points
void sort();																	// 10 points
void highestLevel();																// 5 points

Enemy e[MAX_ENEMIES];			// array of objects
int currentCount = 0;				// number of enemies in the list

int main()
{
	char choice = 'i';		// initialized to a dummy value
	do
	{
		cout << "\nCSE240 HW9\n";
		cout << "Please select an action:\n";
		cout << "\t a: add a new enemy\n";
		cout << "\t d: display enemy list\n";
		cout << "\t s: sort the enemies in descending order based on level and display a range\n";
		cout << "\t n: display the highest level enemy whose name starts with a specific letter\n";
		cout << "\t q: quit\n";
		cin >> choice;
		cin.ignore();			// ignores the trailing \n
		executeAction(choice);
	} while (choice != 'q');

	return 0;
}


// Ask for details from user for the given selection and perform that action
// Read the function case by case
void executeAction(char c)
{
	string name_input;
	int level_input, health_input, damage_input, result = 0;

	switch (c)
	{
	case 'a':	// add enemy
			// input enemy details from user
		cout << "Please enter enemy name: ";
		getline(cin, name_input);
		cout << "Please enter level: ";
		cin >> level_input;
		cin.ignore();
		cout << "Please enter health: ";
		cin >> health_input;
		cin.ignore();
		cout << "Please enter damage: ";
		cin >> damage_input;
		cin.ignore();

		// add the enemy to the list
		result = addEnemy(name_input, level_input, health_input, damage_input);
		if (result == 0)
			cout << "\nThat enemy is already in the list or list is full! \n\n";
		else
			cout << "\nThe enemy was successfully added to the list! \n\n";
		break;

	case 'd':		// display the list
		displayEnemies();
		break;

	case 's':		// sort the list
		sort();
		break;

	case 'n':		// find and display the highest level enemy
		highestLevel();
		break;

	case 'q':		// quit
		break;

	default: cout << c << " is invalid input!\n";
	}

}

// Q3 addEnemy (10 points)
// This function adds a new enemy with the details given in function arguments.
// Add the enemy in 'e' (array of objects) only if there is remaining capacity in the array and if the enemy does not already exist in the list
// This function returns 1 if the enemy is added successfully, else it returns 0 for the cases mentioned above.
// Assume user enters level in any positive integer range.
int addEnemy(string name_input, int level_input, int health_input, int damage_input)
{
	int count = 0;
	int exists = 0;

	while (e[count].getName().compare("Goblin") != 0 && count < MAX_ENEMIES) {				//check if enemy exists or default
		if (e[count].getName().compare(name_input) == 0) {									//enemy already exists in list
			return 0;												
		}
		else {
			count++;																		//increment count to check 
		}
	}

	if (count == MAX_ENEMIES) {															//array is full
		return 0;
	}
	else {
		e[count].setName(name_input);														//overriding details at e[count] with input
		e[count].setLevel(level_input);
		e[count].setHealth(health_input);
		e[count].setDamage(damage_input);
		currentCount++;
		return 1;
	}
}

// Q4 displayEnemies (5 points)
// This function displays the list of enemies.
// Parse the object array 'e' and display the details of all enemies in the array. See expected output given in question file.
// You can call the class function 'displayEnemy()' here. Note that these are two different functions.
// Enemy::displayEnemy() displays details of one Enemy object, while displayEnemies() should display all enemies
// If you are jumping to a new line, please use endl.
void displayEnemies()
{
	for (int i = 0; i < MAX_ENEMIES; i++) {									//iterate through list of enemies
		e[i].displayEnemy();												//calling the class displayEnemy function
		cout << endl;														//new line
	}	
}

// Q5 sort (10 points)
// This function sorts the enemies in descending order of level, and then display the enemies within a given range.
// You may use the 'tempEnemy' object for sorting logic, if needed.
// If you are jumping to a new line, please use endl. 
void sort()
{
	Enemy tempEnemy;
	int lowerBound;
	int upperBound;
	// Write the code below
	cout << "Please enter the lower level bound: ";
	cin >> lowerBound;
	cout << "Please enter the upper level bound: ";
	cin >> upperBound;

	//iterate through the list swapping when necessary to get in order
	for (int i = 0; i < currentCount; i++) {
		for (int j = i - 1; j < currentCount - 1; j++) {
			if (e[j].getLevel() < e[j + 1].getLevel()) {
				tempEnemy = e[j];
				e[j] = e[j + 1];
				e[j + 1] = tempEnemy;				
			} 
		}
	}

	//looping to display enemies that fit in the bounds
	int count = 0; 
	while (count < currentCount) {
		if (e[count].getLevel() > lowerBound && e[count].getLevel() < upperBound) {
			e[count].displayEnemy();
		}
		count++;
	}
}

// Q6 highestLevel (5 points)
// This functions displays enemies who have the highest level and whose name starts with a specific letter
// Parse the array to check if the enemy has the highest level based of a character input
// If the enemy has the highest level, then copy that enemy's details (object's data members) 
// to the 'newEnemy' object created using 'new' and display those enemy details using the 'newEnemy' object.
// Finally delete the 'newEnemy' object.
// NOTE: You MUST use the 'newPatient' object to store the enemy details and you MUST delete it after displaying.
//       You should not display enemy details using 'e[]'.
void highestLevel()
{
	char startingCharacter;				// Ask the user for a character
	Enemy* newEnemy = new Enemy;
	// Write the code below
	cout << "Enter the first letter of the enemy's name: ";							//handling user input
	cin >> startingCharacter;
	for (int i = 0; i < MAX_ENEMIES; i++) {											//iterate through enemy list
		if (e[i].getName().at(0) == startingCharacter) {							//check first letter
			if (e[i].getLevel() > newEnemy->getLevel()) {							//check if level of enemy is higher than the previous highest
				newEnemy->setName(e[i].getName());									//set newEnemy details
				newEnemy->setLevel(e[i].getLevel());
				newEnemy->setDamage(e[i].getDamage());
				newEnemy->setHealth(e[i].getHealth()); 
			}
		}
	}
	if (newEnemy->getName() == "Goblin") {										//exit if empty enemy
		return;
	}
	else {
		newEnemy->displayEnemy();												//calling display function
		cout << endl;															//new line
	}
	//deleting newEnemy
	newEnemy = NULL;
	delete newEnemy;
}
