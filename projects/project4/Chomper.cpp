/******************************
** File: Chomper.cpp
** CMSC 202 Project 4, Fall 2020
** Author: Hamin Han
** Date: 11/12/20
** Section: 202/30
** Email: haminh1@umbc.edu
**
** The Chomper.cpp file contains the name and health
** of the plant type of Chomper. It has its unique
** special attack function. And everything else is used
** from its parent classes.
******************************/

#include "Chomper.h"

// Chomper (Default Constructor)
// Creates a new chomper ans sets the name and health
Chomper::Chomper(){
    SetName("Chomper");
    SetHealth(12);
}

// Chomper (Overloaded Constructor)
// Creates a new chomper ans sets the name and health based on the parameters
Chomper::Chomper(string name, int hp):Plant(name, hp){
    
}

// ~Chomper (Destructor)
// Everything dynamically allocated is deallocated
Chomper::~Chomper(){
    //Empty because no dynamically allocated memoery to be deallocated
}
// SpecialAttack
// Defines the Chomper's special attack and returns damage from special attack
int Chomper::SpecialAttack(){
    cout << GetName() << " performs a sneak attack! CHOMP" << endl;
    srand(time(0));
    int damage = (rand() % 11 + 2);
    return damage;
}
