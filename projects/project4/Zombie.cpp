/******************************
** File: Zombie.cpp
** CMSC 202 Project 4, Fall 2020
** Author: Hamin Han
** Date: 11/12/20
** Section: 202/30
** Email: haminh1@umbc.edu
**
** The Zombie.cpp file contains the name and health
** of the zombie. The class contains pureley virtual
** functions so you cannot make a plain zombie
** but this is used by the child classes.
******************************/

#include "Zombie.h"

// Zombie (Default Constructor)
// Would be used to create a zombie but abstracted
Zombie::Zombie(){
    SetName("Zombie");
    SetHealth(10);
}

// Zombie (Overloaded Constructor)
// Would be used to create a zombie but abstracted
Zombie::Zombie(string name, int hp):Entity(name, hp){

}

// Attack
// Describes attack statements for zombie and returns damage
int Zombie::Attack(){
    cout << GetName() << " deals 1 point of damage!" << endl;
    return 1;
}
