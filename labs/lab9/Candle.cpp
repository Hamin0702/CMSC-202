/******************************
** File: Candle.cpp
** CMSC 202 Lab 9, Fall 2020
** Author: Hamin Han
** Date: 10/29/20
** Section: 202/30
** Email: haminh1@umbc.edu
**
** Candle.cpp  file define everything made in its header file. It is the parent class
** for the other child classes Birthday and Scented. Every candle has a name,
** burn rate, and a bool to see if its lit or not. This parent class contains the
** basic setters and getters that can be used by any candle.
******************************/

#include "Candle.h"

// Candle (Constructor)
// Sets up the member variables
Candle::Candle(string name, double burnRate) {
    m_isLit = false;
    m_name = name;
    m_burnRate = burnRate;
}

// GetName
// Returns the member variable for name, m_name
string Candle::GetName() {
    return m_name;
}

// GetBurnRate
// Returns the member variable for burn rate, m_burnRate
double Candle::GetBurnRate() {
    return m_burnRate;
}

// SetName
// Sets the member variable for name, m_name
void Candle::SetName(string name) {
    m_name = name;
}

// SetBurnRate
// Sets the member variable for burn rate, m_burnRate
void Candle::SetBurnRate(double burnRate){
    m_burnRate = burnRate;
}

// GetLit
// If the candle is lit, returns "Yes" or "No" if it's not lit
string Candle::GetLit() {
    if(m_isLit == true)
        return "Yes";
    return "No";
}

// SetLit
// Sets the member variable for the bool member variable for being lit, m_isLit
void Candle::SetLit(bool isLit) {
    m_isLit = isLit;
}

