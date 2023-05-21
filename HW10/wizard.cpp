#include <iostream>
#include <string>
#include "wizard.h"

// Q2b: Define displayPlayer() for Wizard class (2.5 points)
// Define the function displayPlayer() that you declared within the Wizard class in the header file
// See expected output in question file.
void Wizard::displayPlayer() {
    cout << "Player name: " << Player::getName() << endl;                           //displaying name
    cout << "Health: " << Player::getHealth() << endl;                              //displaying health
    cout << "Mana: " << Player::getMana() << endl;                                  //displaying mana
    cout << "Armor: " << Player::getArmor() << endl;                                //displaying armor
    cout << "Magic Resist: " << Player::getMagicResist() << endl;                   //displaying magic resist
    cout << "Attack: " << Player::getAttack() << endl;                              //displaying attack
    cout << "Magic Attack: " << Player::getMagicAttack() << endl;                   //displaying magic attack
    cout << "Level: " << Player::getLevel() << endl;                                //displaying level
    cout << "Archetype: Wizard" << endl;                                            //displaying archetype

}
// (displayList() function in hw10.cpp should call this function.)
// Include necessary header files
// Gradescope will expect output in this format: "Attribute: "<<attribute<<endl
// This is a read check. If you read this, you should be fine.  You should follow the order in player.h
// capitalize each word in your output. 
