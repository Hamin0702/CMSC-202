/******************************
** File: Birthday.cpp
** CMSC 202 Lab 9, Fall 2020
** Author: Hamin Han
** Date: 10/29/20
** Section: 202/30
** Email: haminh1@umbc.edu
**
** Birthday.cpp  file define everything made in its header file. It is a child
** class from the Candle class and uses its member variables as well as some
** of its functions. It added a member variable for being extinguishable so the file also contains
** the getter and setter for that. It also extended the setLit function to meet
** the specific need for the birthday candle. When the constructor is called,
** it uses its parent functions to set the variable for name and burnRate.
******************************/
#include "Birthday.h"

// Birthday (Constructor)
// Sets up the member variables, uses the Candle constructor as well
Birthday::Birthday(string name,double burnRate,bool isNoExtinguish): Candle(name, burnRate){
    m_isNoExtinguish = isNoExtinguish;
    m_isLit = true;
}

// GetIsNoExtinguish
// Returns the bool member variable for candle being extinguishable, m_isNoExtinguish
bool Birthday::GetIsNoExtinguish(){
    return m_isNoExtinguish;
}

// SetIsNoExtinguish
// Sets the bool member variable for candle being extinguishable, m_isNoExtinguish
void Birthday::SetIsNoExtinguish(bool isNoExtinguish){
    m_isNoExtinguish = isNoExtinguish;
}

// SetLit
// Tries to lit/put out the candle and returns a string depending on the resulr of what happened
string Birthday::SetLit(bool isLit){
    
    //If they try to put out the candle when it cannot be extinguished
    if (!isLit && m_isNoExtinguish){
        return "You cannot blow the birthday candle out!";
        
    //Any other time it sets the member variable and returns the outcome in string
    }else{
        m_isLit = isLit;
        if(m_isLit){
            return "Candle is lit";
        }else{
            return "Candle is not lit";
        }
    
    }
}

