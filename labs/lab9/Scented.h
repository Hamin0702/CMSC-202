/******************************
** File: Scented.h
** CMSC 202 Lab 9, Fall 2020
** Author: Hamin Han
** Date: 10/29/20
** Section: 202/30
** Email: haminh1@umbc.edu
**
** Scented.h file is the header class for candles that are..scented. It is a child
** class from the Candle class and uses its member variables as well as some
** of its functions. It added a member variable for flavor so the file also contains
** the getter and setter for that. It also extended the setLit function to meet
** the specific need for the scented candle. 
******************************/

#ifndef SCENTED_H
#define SCENTED_H
#include "Candle.h"

class Scented : public Candle {
public:
    
    //-------------------------------------------------------
    // Name: Scented (Constructor)
    // PreCondition:  Can use the constructor for Candle
    // PostCondition: Sets the member variabls
    //---------------------------------------------------------
    Scented(string name,double burnRate,string flavor);
    
    //-------------------------------------------------------
    // Name: GetFlavor()
    // PreCondition:  Member variable for flavor m_flavor exists
    // PostCondition: Gets the member variable m_flavor
    //---------------------------------------------------------
    string GetFlavor();
    
    //-------------------------------------------------------
    // Name: SetFlavor()
    // PreCondition:  Member variable for flavor m_flavor exists
    // PostCondition: Sets the member variable m_flavor
    //---------------------------------------------------------
    void SetFlavor(string flavor);
    
    //-------------------------------------------------------
    // Name: SetLit()
    // PreCondition:  member variable for lit m_isLit exists
    // PostCondition: Sets the member variable m_isLit and output a message to the user
    //---------------------------------------------------------
    void SetLit(bool isLit);

protected:
    string m_flavor;
};

#endif
