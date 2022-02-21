/******************************
** File: Pirate.cpp
** CMSC 202 Project2, Fall 2020
** Author: Hamin Han
** Date: 10/3/20
** Section: 202/30
** Email: haminh1@umbc.edu
**
** Pirate.cpp defines all the methods specified in the Pirate.h file.
** Besides all the getters and setters, it defines all the other methods
** specified by the document (ex: Battle, RepairShip, Flee, DisplayScore).
** These functions are used to play the game and edit the data based on the outcome.
******************************/


#include "Pirate.h"
using namespace std;

//Default constructor
Pirate::Pirate(){}

//Overloaded constructor
Pirate::Pirate(string name, int rating, string origin, string desc){
    m_pirateName = name;
    m_pirateRating = rating;
    m_pirateOrigin = origin;
    m_pirateDesc = desc;
    m_pirateCargo = 0;
}

//Getter for pirate name
string Pirate::GetName(){
    return m_pirateName;
}

//Getter for pirate rating
int Pirate::GetRating(){
    return m_pirateRating;
}

//Setter for pirate rating
//Not used*
void Pirate::SetRating(int rating){
    m_pirateRating = rating;
}

//Getter for pirate origin
string Pirate::GetOrigin(){
    return m_pirateOrigin;
}

//Getter for pirate description
string Pirate::GetDesc(){
    return m_pirateDesc;
}

//Setter for pirate's ship
void Pirate::SetCurShip(Ship curShip){
    m_curShip = curShip;
}

//Updates pirate's cargo by adding  a third of the sum of enemy cannons + enemy toughness + enemy speed
void Pirate::CalcTreasure(Ship enemyShip){
    m_pirateCargo = (enemyShip.m_cannon + enemyShip.m_toughness + enemyShip.m_speed) / 3;
}

//The main battle function that plays out the battle between two pirates
void Pirate::Battle(Pirate enemyPirate, Ship enemyShip){
    cout << "A naval battle of the ages commences between " << m_pirateName << " and " << enemyPirate.GetName() << endl;
    
    //While both of the ships have toughness over 0
    while(enemyShip.m_curToughness > 0 && m_curShip.m_curToughness > 0){
        
        //The player shoots first always
        if(m_curShip.m_curToughness > 0){
            int tempShots = 0;
            cout << m_pirateName << " fires " << m_curShip.m_cannon << " cannons!" << endl;
            for(int i = 0; i < m_curShip.m_cannon; i++){
                //Using the rating of the pirate to see how many cannons would hit
                if(rand() % 100 < m_pirateRating)
                    tempShots++;
            }
            enemyShip.m_curToughness = enemyShip.m_curToughness - tempShots;
            cout << tempShots << " shots hit!" << endl;
        }
        
        //The computer pirate shoots second
        if(enemyShip.m_curToughness > 0){
            int tempShots = 0;
            cout << enemyPirate.GetName() << " fires " << enemyShip.m_cannon << " cannons!" << endl;
            for(int i = 0; i < enemyShip.m_cannon; i++){
                //Using the rating of the pirate to see how many cannons would hit
                if(rand() % 100 < enemyPirate.GetRating())
                    tempShots++;
            }
            m_curShip.m_curToughness = m_curShip.m_curToughness - tempShots;
            cout << tempShots << " shots hit!" << endl;
        }
    }
    
    //When the battle is over announces the outcome and updates the data
    if(m_curShip.m_curToughness < 1){
        cout << "You lose!" << endl;
        m_curShip.m_curToughness = 0;
        m_pirateCargo = m_pirateCargo / 2;
        RepairShip();
    }else if(enemyShip.m_curToughness < 1){
        cout << "You win!" << endl;
        m_pirateCargo = m_pirateCargo + ( (enemyShip.m_cannon + enemyShip.m_toughness + enemyShip.m_speed) / 3);
    }
    
    m_pirateDays++;
        
}
    
//The function called to repair a ship
//The toughness returns back to the maximum value and one day is spent per point of damage
void Pirate::RepairShip(){
    m_pirateDays +=  m_curShip.m_toughness - m_curShip.m_curToughness;
    cout << "It takes " << m_curShip.m_toughness - m_curShip.m_curToughness << " days to repair your " << m_curShip.m_type << endl;
    m_curShip.m_curToughness = m_curShip.m_toughness;
}

//Based on the speed of the two ships, either flee successfully or start battle
//The user is returned back to main menu
void Pirate::Flee(Pirate enemyPirate, Ship enemyShip){
    cout << "You attempt to flee from " << enemyPirate.GetName() << "!" << endl;
    
    //When enemy ship catches up and starts a battle
    if(enemyShip.m_speed > m_curShip.m_speed){
        cout << "Enemy ship has a higher speed and attacks!" << endl;;
        Battle(enemyPirate, enemyShip);
        m_pirateDays = m_pirateDays + 2;
        
    //When the player escapes
    }else{
        cout << "You narrowly escaped from " << enemyPirate.GetName() << endl;
        m_pirateDays++;
    }
}

//Just a simple function that outputs all the data for the user to see
void Pirate::DisplayScore(){
    cout << "************************" << endl;
    cout << "Name: " << m_pirateName << endl;
    cout << "Rating: " << m_pirateRating << endl;
    cout << "Country of Origin: " << m_pirateOrigin << endl;
    cout << "Description: " << m_pirateDesc << endl;
    cout << "Days Sailing: " << m_pirateDays << endl;
    cout << "Cargo Captured: " << m_pirateCargo << endl;
    cout << "Cargo Per Day: " <<(double) m_pirateCargo / (double) m_pirateDays << endl;
    cout << "Ship Type: " << m_curShip.m_type << endl;
    cout << "Ship Cannons: " << m_curShip.m_cannon << endl;
    cout << "Ship Current Toughness: " << m_curShip.m_curToughness << endl;
    cout << "Ship Max Toughness: " << m_curShip.m_toughness << endl;
    cout << "Ship Speed: " << m_curShip.m_speed << endl;
    cout << "************************" << endl;
}
