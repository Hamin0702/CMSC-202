/******************************
** File: Passenger.cpp
** CMSC 202 Project2, Fall 2020
** Author: Hamin Han
** Date: 10/22/20
** Section: 202/30
** Email: haminh1@umbc.edu
**
** Passenger.cpp defines all the methods specified in the Passenger.h file.
** It contains the constructor that sets the member variables and get methods
** that accesses these member variables (passenger name, age, start location and
** final destination)
******************************/

#include "Passenger.h"
using namespace::std;

// Passsenger
// Given the values from the parameter list, sets up all the member variables, creating a new Passenger
Passenger::Passenger(string name, int age, string start, string finish){
    m_fullName = name;
    m_age = age;
    m_startLocation = start;
    m_finalDestination = finish;
}

// GetName
// Returns the member variable for the name of the passenger
string Passenger::GetName(){
    return m_fullName;
}

// GetStartLocation
// Returns the member variable for the starting location of the passenger
string Passenger::GetStartLocation(){
    return m_startLocation;
}

// GetFinalDestination
// Returns the member variable for the final destination of the passenger
string Passenger::GetFinalDestination(){
    return m_finalDestination;
}
