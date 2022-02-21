/******************************
** File: Sunflower.cpp
** CMSC 202 Project 4, Fall 2020
** Author: Hamin Han
** Date: 11/12/20
** Section: 202/30
** Email: haminh1@umbc.edu
**
** The Sunflower.cpp file contains the name and health
** of the plant type of Sunflower. It has its unique
** special attack function. And everything else is used
** from its parent classes.
******************************/

#include "Sunflower.h"

// Sunflower (Default Constructor)
// Creates a new sunflower ans sets the name and health
Sunflower::Sunflower(){
    SetName("Sunflower");
    SetHealth(15);
}

// Sunflower (Overloaded Constructor)
// Creates a new sunflower ans sets the name and health based on the parameters
Sunflower::Sunflower(string name, int hp):Plant(name, hp){
    
}

// ~Sunflower (Destructor)
// Everything dynamically allocated is deallocated
Sunflower::~Sunflower(){
    //Empty because no dynamically allocated memoery to be deallocated
}

// SpecialAttack
// Defines the Sunflower's special attack and returns damage from special attack
int Sunflower::SpecialAttack(){
    cout << GetName() << " uses a high beam turret - **SUNBEAM**" << endl;
    srand(time(0));
    int damage = (rand() % 8 + 1);
    return damage;
}
