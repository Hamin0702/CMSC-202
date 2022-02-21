/******************************
** File: lab6.cpp
** CMSC 202 Lab6, Fall 2020
** Author: Hamin Han
** Date: 10/5/20
** Section: 202/30
** Email: haminh1@umbc.edu
**
** This file contains lab6.cpp which defines all the functions described by the
** document for lab 6, fillVector and printVector.
** The main method uses these methods and vectors to get user input for Valorant
** characters and print them out to them.
******************************/
#include <iostream>
#include <string>
#include <vector>
#include "Valorant.h"
using namespace std;

//fillVector prototype here:
//Desc: Prompts the user with the number of characters they want to enter and adds each character to the vector
//Pre-condition: Accepts a vector
//Post-condition: Updates the vector passed to it
void fillVector(vector<Valorant>&);

//printVector
//Desc: Prints the contents of the vector (without using an iterator)
//Pre-condition: Accepts a vector (but don't make a copy of it)
//Post-condition: Displays information about the characters in the vector
void printVector(vector<Valorant>);


int main(){

  //Vector that stores the user input
  vector<Valorant> list;

  //fills the vector
  fillVector(list);
  //prints the vector
  printVector(list);
  cout << endl;

  return 0;
}

//Insert fillVector here - we want to change the vector permanently!
void fillVector(vector<Valorant> &characters){
    
    int numCharacters = 0;
    cout << "How many Valorant characters?" << endl;
    cin >> numCharacters;
    
    for(int i = 0; i < numCharacters; i++){
        string nameTemp = "";
        int hpTemp = 0;
        bool defTemp = true;
        int defCheck = 0;
        cout << "Character " << i+1 << " name:" << endl;
        cin >> nameTemp;
        cout << "Character " << i+1 << " hp:" << endl;
        cin >> hpTemp;
        cout << "Is Character " << i+1 << " a defender? (0 or 1)" << endl;
        cin >> defCheck;
        if(defCheck == 0)
            defTemp = false;
        if(defCheck == 1)
            defTemp = true;
        
        characters.push_back(Valorant(nameTemp, hpTemp, defTemp));
    }
    

}



//Insert printVector - we do not want to make a copy of the vector
void printVector(vector<Valorant> characters){
   
    for(unsigned int i = 0; i < characters.size(); i++){
        int teamNum = 0;
        if(characters[i].GetSide())
            teamNum = 1;
            
        cout << characters[i].GetName() << " is on team " << teamNum << " and has " << characters[i].GetHP() << " HP." << endl;
    }
}
