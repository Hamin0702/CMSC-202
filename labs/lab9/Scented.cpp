/******************************
** File: Scented.cpp
** CMSC 202 Lab 9, Fall 2020
** Author: Hamin Han
** Date: 10/29/20
** Section: 202/30
** Email: haminh1@umbc.edu
**
** Scented.cpp  file define everything made in its header file. It is a child
** class from the Candle class and uses its member variables as well as some
** of its functions. It added a member variable for flavor so the file also contains
** the getter and setter for that. It also extended the setLit function to meet
** the specific need for the scented candle. When the constructor is called,
** it uses its parent functions to set the variable for name and burnRate.
******************************/

#include "Scented.h"

// Scented (Constructor)
// Initializes membervariables, uses Candle for name and burnRate
Scented::Scented(string name,double burnRate,string flavor):Candle(name,burnRate){
    m_flavor = flavor;
    m_isLit = true;
}

// GetFlavor
// Returns the member variabl for flavor, m_flavor
string Scented::GetFlavor(){
    return m_flavor;
}

// SetFlavor
// Sets the member variable for flavor, m_flavor
void Scented::SetFlavor(string flavor){
    m_flavor = flavor;
}

// SetLit
// Takes in a bool, sets that for m_isLit, and if it is lit, outputs a message for the user
void Scented::SetLit(bool isLit){
    m_isLit = isLit;
    if(m_isLit){
        cout << "The delicious smell of " << m_flavor << " wafts from the scented candle." << endl;
    }
}
