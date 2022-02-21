/******************************
** File: Entity.cpp
** CMSC 202 Project 4, Fall 2020
** Author: Hamin Han
** Date: 11/12/20
** Section: 202/30
** Email: haminh1@umbc.edu
**
** The Entity.cpp file contains the data describing
** a general entiy which just has a name and health.
** These functions are used in its child classes.
******************************/

#include "Entity.h"

// Entity (Default constructor)
// Creates an entity and sets up the member variables
Entity::Entity(){
    m_name = "Entity";
    m_health = 10;
}

// Entity (Overloaded Constructor)
// Creates an entity and sets up the member variables based on the parameters
Entity::Entity(string name, int hp){
    m_name = name;
    m_health = hp;
}

// ~Entity (Destructor)
// Everything dynamically allocated is deallocated
Entity::~Entity(){
   //Empty because no dynamically allocated memoery to be deallocated
}

// GetName
// Returns the member variable m_name
string Entity::GetName(){
    return m_name;
}

// GetHealth
// Returns the member variabl m_health
int Entity::GetHealth(){
    return m_health;
}

// SetName
// Sets the member variable m_name
void Entity::SetName(string name){
    m_name = name;
}

// SetHealth
// Sets the member variable m_health
void Entity::SetHealth(int health){
    m_health = health;
}
  
// Overloaded Operator <<
// Prints out the name and health of the entity
ostream& operator<<(ostream &output, Entity &E){
    output << "Name: " << E.GetName() << "Health: " << E.GetHealth();
    return output;
}
