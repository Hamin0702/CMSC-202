/******************************
** File: Buckethead.cpp
** CMSC 202 Project 4, Fall 2020
** Author: Hamin Han
** Date: 11/12/20
** Section: 202/30
** Email: haminh1@umbc.edu
**
** The Buckethead.cpp file contains the name and health
** of the zombie type of Buckethead. It has its unique
** special attack function. And everything else is used
** from its parent classes.
******************************/

#include "Buckethead.h"

// Buckethead (Default Constructor)
// Creates a new buckethead type of zombie and sets name and health
Buckethead::Buckethead(){
    SetName("Buckethead");
    SetHealth(7);
}

// Buckethead (Overloaded Constructor)
// Creates a new buckethead type of zombie and sets name and health based on the parameters
Buckethead::Buckethead(string name, int hp):Zombie(name, hp){
    
}

// SpecialAttack
// Defines the Buckethead's special attack returns damage from special attack
int Buckethead::SpecialAttack(){
    cout << GetName() << " throws its bucket at you!" << endl;
    return 1;
}
