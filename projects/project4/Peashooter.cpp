/******************************
** File: Peashooter.cpp
** CMSC 202 Project 4, Fall 2020
** Author: Hamin Han
** Date: 11/12/20
** Section: 202/30
** Email: haminh1@umbc.edu
**
** The Peashooter.cpp file contains the name and health
** of the plant type of Peashooter. It has its unique
** special attack function. And everything else is used
** from its parent classes.
******************************/

#include "Peashooter.h"

// Peashooter (Default Constructor)
// Creates a new peashooter and sets the name and health
Peashooter::Peashooter(){
    SetName("Peashooter");
    SetHealth(10);
}

// Peashooter (Overloaded Constructor)
// Creates a new peashooter and sets the name and health based on the parameters
Peashooter::Peashooter(string name, int hp):Plant(name, hp){
    
}

// ~Peashooter (Destructor)
// Everything dynamically allocated is deallocated
Peashooter::~Peashooter(){
    //Empty because no dynamically allocated memoery to be deallocated
}

// SpecialAttack
// Defines the Peashooter's special attack returns damage from special attack
int Peashooter::SpecialAttack(){
    cout << GetName() << " spins up doing GATLING DAMAGE!" << endl;
    srand(time(0));
    int damage = (rand() % 10 + 3);
    return damage;
}
