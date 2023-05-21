#include "player.h"
#ifndef _WARRIOR_H
#define _WARRIOR_H


// Q1a: Create Warrior class (2.5 points)
// Part 1: Create a child class of the Player class named 'Warrior'
class Warrior: public Player {
    public:

// Part2: Declare constructor which accepts the same 3 parameters as the parent class Player's constructor.
// Pass the 3 parameters to the super constructor of the Player class.

        Warrior(string playerName, int levelInput, playerType archetypeInput): Player(playerName, levelInput, archetypeInput){};

// Part 3: Re-declare the method displayPlayer (virtual method found inside of parent class Player)

        virtual void displayPlayer();       
};




#endif // _WARRIOR_H
