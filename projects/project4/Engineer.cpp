/******************************
** File: Engineer.cpp
** CMSC 202 Project 4, Fall 2020
** Author: Hamin Han
** Date: 11/12/20
** Section: 202/30
** Email: haminh1@umbc.edu
**
** The Engineer.cpp file contains the name and health
** of the zombie type of Engineer. It has its unique
** special attack function. And everything else is used
** from its parent classes.
******************************/

#include "Engineer.h"

// Engineer (Default Constructor)
// Description: Creates a new engineer and sets name and health
Engineer::Engineer(){
    SetName("Engineer");
    SetHealth(5);
}

// Imp (Overloaded Constructor)
// Creates a new imp and sets name and health based on the parameters
Engineer::Engineer(string name, int hp):Zombie(name, hp){
    
}

// pecialAttack
// Defines the Engineer's special attack and returns damage from special attack
int Engineer::SpecialAttack(){
    cout << GetName() << " blasts you with their steam blaster!" << endl;
    return 2;
}
