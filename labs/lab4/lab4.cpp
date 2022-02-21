//  File: lab4.cpp
//  Project: CMSC 202 Lab 4, Fall 2020
//  Author: Hamin Han
//  Date: 9/20/2020
//  Section: 202/30
//  Email: haminh1@umbc.edu
//
//  This file contains lab4.
//  This program simulates fishing where the user starts the day with a specific
//  number of gold and 0 fish. The user then buys bait and catches fish, then later
//  sells the fish.
//  The program displays the number of fish and how much gold the user has in the
//  format specified by the lab description

#include <iostream>
using namespace std;

// Constants go here
int START_GOLD = 500;
int COST_BAIT = 5;
int PRICE_FISH = 10;

// Function prototypes
void goFishing(int&, int&);
void sellFish(int*, int*);

// The main method that does the fishing simulation
int main(){

  // Starting values
  int fish = 0;
  int gold = START_GOLD;

  // Displays the initial value of fish and gold
  cout << "You wake up at 6 am." << endl;
  cout << "You have " << fish << " fish" << endl;
  cout << "You have " << gold << " gold coins" << endl;
  cout << endl;

  // Call goFishing by reference
  goFishing(fish,gold);

  // Displays the updated values of fish and gold after going fishing
  cout << endl;
  cout << "You now have " << fish << " fish" << endl;
  cout << "You now have " << gold << " gold coins" << endl;
  cout << endl;

  // Call sellFish by pointer
  sellFish(&fish, &gold);

  // Displays the final values of fish and gold after selling all the fish
  cout << endl;
  cout << "It is 10 pm and you decide to go to bed" << endl;
  cout << "You end the day with " << fish << " fish" << endl;
  cout << "You end the day with " << gold << " gold coins" << endl;

  return 0;
}

// Implement goFishing and sellFish below

//-----------------------------------------------------------
// Name: goFishing
// Precondition: takes two references(&) of the fish and gold
//               the user inputs an integer
// Postcondtion: updates the value of fish and gold
//-----------------------------------------------------------
void goFishing(int &myFish , int &myGold){
    int bait = 0;
    int *gold = &myGold;
    do{
        cout << "How much bait would you like to buy? (5 gold per bait)" << endl;
        cin >> bait;
        if(bait*COST_BAIT > *gold)
            cout << "You do not have enough gold" << endl;
    } while(bait*COST_BAIT > *gold);

    cout << "You bought " << bait << " bait and went fishing." << endl;
    
    myFish = myFish + bait;
    myGold = myGold - (bait * COST_BAIT);
}

//-----------------------------------------------------------
// Name: sellFish
// Precondition: takes two pointers(*) of the fish and gold
// Postcondtion: updates the value of fish and gold
//               displays how much fish was sold and how
//               much gold the user ends up with
//-----------------------------------------------------------
void sellFish(int *myFish, int *myGold){
    cout << "You sold " << *myFish << " fish." << endl;
    *myGold = *myGold + (PRICE_FISH * (*myFish));
    *myFish = 0;
    cout << "You now have " << *myGold << " gold coins.";
    cout << endl;
}
