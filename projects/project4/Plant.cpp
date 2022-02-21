/******************************
** File: Plant.cpp
** CMSC 202 Project 4, Fall 2020
** Author: Hamin Han
** Date: 11/12/20
** Section: 202/30
** Email: haminh1@umbc.edu
**
** The Plant.cpp file contains the date for the name
** and the health of the plant. It can attack which is
** used by the child classes and it has a function for a
** special attack even thought it doesn't have a special
** attack itself but it's later defined in the child classes.
******************************/

#include "Plant.h"

// Plant (Default Constructor_
// Creates a new plant and sets the name and health
Plant::Plant(){
    SetName("Plant");
    SetHealth(10);
}

// Plant (Overloaded constructor)
// Creates a new plant and sets the name and health based on the parameters
Plant::Plant(string name, int hp):Entity(name, hp){
   
}

// ~Plant (Destructor)
// Everything dynamically allocated is deallocated
Plant::~Plant(){
    //Empty because no dynamically allocated memoery to be deallocated
}

// Attack
// Describes attack statements for plant
int Plant::Attack(){
    srand(time(0));
    int damage = (rand() % 6 + 1);
    cout <<  GetName() << " attacks dealing " << damage << " damage!" << endl;
    return damage;
}

// SpecialAttack()
// Tells player that plant does not have special attack
int Plant::SpecialAttack(){
    cout << GetName() << " does not have special attack" << endl;
    return 0;
}
