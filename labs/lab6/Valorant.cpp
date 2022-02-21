/******************************
** File: Valorant.cpp
** CMSC 202 Lab6, Fall 2020
** Author: Hamin Han
** Date: 10/5/20
** Section: 202/30
** Email: haminh1@umbc.edu
**
** This file contains Valorant.cpp which defines all the functions declared
** in the Valorant.h header file, all the getters and setters are defined.
******************************/

#include "Valorant.h"
#include <iostream>
using namespace std;

//Default constructor
Valorant::Valorant(){
    m_name = "Default";
    m_HP = 100;
    m_isDefender = false;
}

//Overloaded constructor where it is passed specific values for the member variables
Valorant::Valorant(string setName, int setHP, bool setSide){
    m_name = setName;
    m_HP = setHP;
    m_isDefender = setSide;
}

//Sets the name of the character
void Valorant::SetName(string toSet){
    m_name = toSet;
}

//Sets the HP of the character
void Valorant::SetHP(int hp){
    m_HP = hp;
}

//Sets whether the character is on defender side
void Valorant::SetSide(bool toSet){
    m_isDefender = toSet;
}

//Gets the name of the character
string Valorant::GetName(){
    return m_name;
}

//Gets the HP of the character
int Valorant::GetHP(){
    return m_HP;
}

//Gets the boolean of whether the character is on the defender side
bool Valorant::GetSide(){
    return m_isDefender;
}
