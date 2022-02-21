/******************************
** File: Imp.cpp
** CMSC 202 Project 4, Fall 2020
** Author: Hamin Han
** Date: 11/12/20
** Section: 202/30
** Email: haminh1@umbc.edu
**
** The Imp.cpp file contains the name and health
** of the zombie type of Imp. It has its unique
** special attack function. And everything else is used
** from its parent classes.
******************************/

#include "Imp.h"

// Imp (Default Constructor)
// Creates a new imp and sets name and health
Imp::Imp(){
    SetName("Imp");
    SetHealth(10);
}

// Imp (Overloaded Constructor)
// Creates a new imp and sets name and health based on the parameters
Imp::Imp(string name, int hp):Zombie(name, hp){
    
}

// SpecialAttack
// Defines the Imp's special attack returns damage from special attack
int Imp::SpecialAttack(){
    cout << GetName() << " blasts you with their Impkata attack!" << endl;
    return 4;
}
