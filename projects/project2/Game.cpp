/******************************
** File: Game.cpp
** CMSC 202 Project2, Fall 2020
** Author: Hamin Han
** Date: 10/3/20
** Section: 202/30
** Email: haminh1@umbc.edu
**
** Game.cpp defines all the methods specified by the Game.h file and utilizes
** them the way specified by the project document.
** This is responsible for the actual playing aspect of the game pirates
******************************/

#include "Game.h"
using namespace std;

//Displays the game title and loads all the ships and pirates
Game::Game(){
    GameTitle();
    LoadShips();
    LoadPirates();
}

//Loads each type of ship into m_ships from file proj2_ships.txt
void Game::LoadShips(){
    string type;
    string cannonTemp;
    int cannon = 0;
    string toughnessTemp;
    int toughness = 0;
    string speedTemp;
    int speed = 0;
    string desc;
    
    ifstream inFile;
    inFile.open(PROJ2_SHIPS);
    for(int i = 0; i < MAX_SHIPS; i++){
        string T;
        getline(inFile,type,',');
        getline(inFile,cannonTemp,',');
        cannon = stoi(cannonTemp);
        getline(inFile,toughnessTemp,',');
        toughness = stoi(toughnessTemp);
        getline(inFile,speedTemp,',');
        speed = stoi(speedTemp);
        getline(inFile,desc,'\n');
        m_ships[i] = Ship(type, cannon, toughness, speed, desc);
    }
    
    cout << MAX_SHIPS << " ships loaded." << endl;
    inFile.close();
}

//Loads each pirate into m_allPirates from file proj2_pirates.txt
void Game::LoadPirates(){
    string name;
    string ratingTemp;
    int rating = 0;
    string origin;
    string desc;
   
    ifstream inFile;
    inFile.open(PROJ2_PIRATES);
   
    for(int i = 0; i < MAX_PIRATES; i++){
        string T;
        getline(inFile,name,',');
        getline(inFile,ratingTemp,',');
        rating = stoi(ratingTemp);
        getline(inFile,origin,',');
        getline(inFile,desc,'\n');
        m_allPirates[i] = Pirate(name, rating, origin, desc);
    }
       
    cout << MAX_PIRATES << " pirates loaded." << endl;
    inFile.close();
}

//Assigns the pirate and the ship of the player
//Plays the game by bringing up MainMenu and calling other functions based on user input
void Game::StartGame(){
    
    //Setting up the user's data
    m_myPirate = m_allPirates[rand() % MAX_PIRATES];
    Ship myShip = m_ships[rand() % MAX_SHIPS];
    m_myPirate.SetCurShip(myShip);
    
    cout << "Congratulations! " << m_myPirate.GetName() << " is now avaiable to plunder!" << endl;
    cout << m_myPirate.GetName() << " is aboard a " << myShip.m_type << "." << endl;
    
    int gameCounter = 0;
    do {
        gameCounter = MainMenu();
        
        //When player wants to battle
        if(gameCounter == 1){
            SearchTreasure();
            
        //When player wants to repair ship
        }else if (gameCounter == 2){
            m_myPirate.RepairShip();
            
        //When player wants to look at score
        }else if(gameCounter == 3){
            m_myPirate.DisplayScore();
            
        //When player wants to retire their pirate
        }else if(gameCounter == 4){
            m_myPirate.DisplayScore();
            cout << m_myPirate.GetName() << " sails off into retirement!" << endl;
            cout << "Thanks for playing Pirates!" << endl;
        }
        
    //As long as the player didn't retire, the game will continue again
    } while (gameCounter != 4);
    
}

//Displays the main menu and returns the user's choice
int Game::MainMenu(){
    int userInput;
    do {
        cout << "What would you like to do?" << endl;
        cout << "1. Search for Treasure" << endl;
        cout << "2. Repair ship" << endl;
        cout << "3. See Score" << endl;
        cout << "4. Retire" << endl;
        cin >> userInput;
        if(userInput < 1 || userInput > 4)
            cout << "INVALID INPUT TRY AGAIN" << endl;
    } while (userInput < 1 || userInput > 4);
    
    return userInput;
}

//The user seaches for other ships and they get the choice to either battle them or flee
void Game::SearchTreasure(){
    int choice = 0;
    cout << "You scan the horizons for prospective targets..." << endl;
    Pirate enemyPirate = m_allPirates[rand() % MAX_PIRATES];
    Ship enemyShip = m_ships[rand() % MAX_SHIPS];
    cout << "Off in the distance, you see " << enemyPirate.GetName() << " on a " << enemyShip.m_type << "!" << endl;
    
    do {
        cout << "What would you like to do?" << endl;
        cout << "1. Attack " << enemyPirate.GetName() << endl;
        cout << "2. Attempt to Flee from " << enemyPirate.GetName() << endl;
        cin >> choice;
        if(choice!=1 && choice!=2)
            cout << "INVALID INPUT TRY AGAIN" << endl;
    } while (choice!=1 && choice!=2);
    
    //Calls the Battle or the Flee function based on whether the user wants to battle them or flee
    if(choice == 1)
        m_myPirate.Battle(enemyPirate, enemyShip);
    if(choice == 2)
        m_myPirate.Flee(enemyPirate, enemyShip);
    
}



