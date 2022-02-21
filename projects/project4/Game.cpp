/******************************
** File: Game.cpp
** CMSC 202 Project 4, Fall 2020
** Author: Hamin Han
** Date: 11/12/20
** Section: 202/30
** Email: haminh1@umbc.edu
**
** The Game.cpp file contains all the methods needed to
** play a game. It loads in a map and lets the player create
** the plant and then starts the game. When in the game,
** the user is shown a menu and the options are look,
** move, attack zombie, rest, check stats, and quit.
** There are functions for each choice that the user can make
** and they use every class defined before to make the game work.
******************************/

#include "Game.h"

// Game (Default Constructor)
// After asking for a file name, loads map, creates plant and starts game
Game::Game(){
    string file;
    cout << "What is the file name? (Include .txt)" << endl;
    cin >> file;
    LoadMap(file);
    PlantCreation();
    StartGame();
}

// Game (Overloaded Constructor)
// Loads map, creates plant, and starts game
Game::Game(string filename){
    LoadMap(filename);
    PlantCreation();
    StartGame();
}

// ~Game (Destructor)
// Postconditions: Deallocates anything dynamically allocated in Game
Game::~Game(){
    
    // Deallocating m_myPlant and m_curZombie
    delete m_myPlant;
    delete m_curZombie;
    m_myPlant = nullptr;
    m_curZombie = nullptr;
    
    // Deallocating everyroom in m_myMap
    for(int i = 0; i < m_myMap.size(); i++){
        delete m_myMap.at(i);
        m_myMap.at(i) = nullptr;
    }
    m_myMap.clear();
    
}

// LoadMap
// Reads in a file and m_myMap vector is populated with Room objects
void Game::LoadMap(string fileName){
    string IDtemp, roomName, desc, northTemp, eastTemp, southTemp, westTemp, temp;
    int ID = 0;
    int north = 0;
    int east = 0;
    int south = 0;
    int west = 0;

    ifstream inFile;
    inFile.open(fileName);
    while(!inFile.eof()){
        
        //Reading the file
        if(!inFile.eof()){
            getline(inFile,IDtemp,'|');
            if(IDtemp != ""){
                getline(inFile,roomName,'|');
                getline(inFile,desc,'|');
                getline(inFile,northTemp,'|');
                getline(inFile,eastTemp,'|');
                getline(inFile,southTemp,'|');
                getline(inFile,westTemp,'|');
                getline(inFile,temp,'\n');
                ID = stoi(IDtemp);
                north = stoi(northTemp);
                east = stoi(eastTemp);
                south = stoi(southTemp);
                west = stoi(westTemp);
               
                // Adding to m_myMap
                m_myMap.push_back(new Room(ID, roomName, desc, north, east, south, west));
            }
        }
    }
    inFile.close();
}

// PlantCreation
// Allows user to create a new plant to play with. May be either plant, sunflower, chomper, or peashooter.
// m_myPlant is populated
void Game::PlantCreation(){
    string plantName;
    int plantChoice = 0;
    
    // Menu for user
    cout << "Welcome to Plants vs Zombies!" << endl;
    cout << "Plant Name: ";
    cin >> plantName;
    cout << "1. Peashooter" << endl;
    cout << "2. Chomper" << endl;
    cout << "3. Sunflower" << endl;
    cout << "4. No Class" << endl;
    do {
        cin >> plantChoice;
        if(plantChoice < 1 || plantChoice > 4)
            cout << "Please try again!" << endl;
    } while (plantChoice < 1 || plantChoice > 4);
    
    // Populating m_myPlant based on user input
    if(plantChoice == 1){
        m_myPlant = new Peashooter(plantName, PEASHOOTER_HEALTH);
    }else if(plantChoice == 2){
        m_myPlant = new Chomper(plantName, CHOMPER_HEALTH);
    }else if(plantChoice == 3){
        m_myPlant = new Sunflower(plantName, SUNFLOWER_HEALTH);
    }else if(plantChoice == 4){
        m_myPlant = new Plant(plantName, PLANT_HEALTH);
    }
}

// StartGame()
// m_numRests, m_numSpecial and curRoom populated and Action() is called to start the game
void Game::StartGame(){
    m_curRoom = 0;
    m_numRests = NUM_RESTS;
    m_numSpecial = NUM_SPECIAL;
    Action();
}

// Action()
// Menu for the game, this is where the game is played out.
// Game continues until quit or player dies
void Game::Action(){
    int gameChoice = 0;
    
    // Prints room information
    m_myMap.at(m_curRoom)->PrintRoom();
    
    // Loads zombie and outputs messge based on what happened
    m_curZombie = RandomZombie();
    
    // Menu for the game where the entire game is being played
    while(m_myPlant->GetHealth() != 0 && gameChoice != 6){
        do {
            
            // Menu choices
            gameChoice = 0;
            cout << endl;
            cout << "What would you like to do?" << endl;
            cout << "1. Look" << endl;
            cout << "2. Move" << endl;
            cout << "3. Attack Zombie" << endl;
            cout << "4. Rest" << endl;
            cout << "5. Check Stats" << endl;
            cout << "6. Quit" << endl;
            cin >> gameChoice;
            if(gameChoice < 1 || gameChoice > 6)
                cout << "Try Again! Invalid input" << endl;
        } while (gameChoice < 1 || gameChoice > 6);
    
        // Look
        if(gameChoice == 1){
            // Prints out room information
            m_myMap.at(m_curRoom)->PrintRoom();
            
        // Move
        }else if(gameChoice == 2){
            // Calls the Move() function
            Move();
            
        // Attack zombie
        }else if(gameChoice == 3){
            // Calls the Attack() function if there's a zombie in the room
            if(m_curZombie == nullptr){
                cout << "There are no zombies in this room." << endl;
            }else{
                Attack();
            }
            
        // Rest
        }else if(gameChoice == 4){
            // Calls the Rest() function if there's no zombie in the room
            if(m_curZombie != nullptr){
                cout << "You cannot rest here, there is a zombie in the room!" << endl;
            }else{
                Rest();
            }
            
        // Check stats
        }else if(gameChoice == 5){
            // Displays stats
            Stats();
            
        // Quit
        }else if(gameChoice == 6){
            // Ends the game
            cout << "Good bye!" << endl;
        }
        
    }
    
}

// RandomZombie
// Used to randomly create a dynamically allocated zombie of Buckethead, Imp, or Engineer.Or there might be no zombie
// Displays a message based on what spawned
Entity* Game::RandomZombie(){
    srand(time(0));
    int type = (rand() % 4 + 1);
    Entity* zombie = nullptr;
    
    // When Buckethead is spawned
    if(type == 1){
        zombie = new Buckethead("Buckethead", BUCKETHEAD_HEALTH);
        cout << "A buckethead zombie teaters here with a bucket on his head." << endl;
        
    // When Imp is spawned
    }else if(type == 2){
        zombie = new Imp("Imp", IMP_HEALTH);
        cout << "A dirty imp licks his lips and glares at you." << endl;
        
    // When Engineer is spawned
    }else if(type == 3){
        zombie = new Engineer("Engineer", ENGINEER_HEALTH);
        cout << "A large zombie stands here wearing khakis with a sign that says ENGINEER." << endl;
        
    // When no zombies are spawned
    }else if(type == 4){
        zombie = nullptr;
        cout << "It is peaceful here." << endl;
    }
    return zombie;
}

// Rest
// If no zombies in current room, allows player to rest and reduces available rests by one and increases hp by 10 REST_HEAL
void Game::Rest(){
    if(m_numRests != 0){
        cout << "You decided to rest." << endl;
        m_numRests = m_numRests - 1;
        m_myPlant->SetHealth(m_myPlant->GetHealth() + REST_HEAL);
        cout << "Number of rests remaining: " << m_numRests << endl;
        cout << m_myPlant->GetName() << "'s health: " << m_myPlant->GetHealth() << endl;;
    }else{
        cout << "You are out of rests!" << endl;
    }
}

// Move
// Moves a player from one room to another, updates m_curRoom, displays room information, checks for new zombie (deletes old)
void Game::Move(){
    string direction = "";
    int nextRoom = -1;

    // Asks user which direction to move
    while(nextRoom == -1){
        
        // Menu
        do {
            cout << "Which direction? (N E S W)" << endl;
            cin >> direction;
            if(direction != "N" && direction != "n" && direction != "E" && direction != "e" && direction != "S" && direction != "s" && direction != "W" && direction != "w")
                cout << "Try again! Invalid input" << endl;
        } while (direction != "N" && direction != "n" && direction != "E" && direction != "e" && direction != "S" && direction != "s" && direction != "W" && direction != "w");
    
        
        if(direction == "N" || direction == "n"){
            nextRoom = m_myMap.at(m_curRoom)->CheckDirection('n');
        }else if(direction == "E" || direction == "e"){
            nextRoom = m_myMap.at(m_curRoom)->CheckDirection('e');
        }else if(direction == "S" || direction == "s"){
            nextRoom = m_myMap.at(m_curRoom)->CheckDirection('s');
        }else if(direction == "W" || direction == "w"){
            nextRoom = m_myMap.at(m_curRoom)->CheckDirection('w');
        }
        
        // Checks if the room is valid
        if(nextRoom == -1)
            cout << "Try again! Invalid room" << endl;
    }

    //Deallocating the old zombie
    delete m_curZombie;
    m_curZombie = nullptr;
        
    //Moving to the new room
    m_curRoom = nextRoom;
    
    //Displaying room information
    m_myMap.at(m_curRoom)->PrintRoom();
    
    //Checking for new zombies
    m_curZombie = RandomZombie();
    
}

// Attack
// Allows player to attack an zombie while indicating who wins and updates health as battle continues.
void Game::Attack(){
    int attackChoice;
    int plantAttack;
    int zombieAttack;
    
    // Repeats the round when both plant and zombie are still alive
    while(m_myPlant->GetHealth() != 0 && m_curZombie->GetHealth() !=0){
        
        //Menu for choosing the type of attack
        do {
            attackChoice = 0;
            cout << "1. Normal Attack" << endl;
            cout << "2. Special Attack" << endl;
            cin >> attackChoice;
            if(attackChoice < 1 || attackChoice > 2)
                cout << "Try Again!" << endl;
        } while (attackChoice < 1 || attackChoice > 2);
    
        plantAttack = 0;
        zombieAttack = 0;
    
        //Normal attack
        if(attackChoice == 1){
            plantAttack = m_myPlant->Attack();
            zombieAttack = m_curZombie->Attack();
            
        //Special attack
        }else if(attackChoice == 2){
            if(m_numSpecial != 0){
                plantAttack = m_myPlant->SpecialAttack();
                cout << m_myPlant->GetName() << " deals " << plantAttack << " damage!" << endl;
                zombieAttack = m_curZombie->SpecialAttack();
                m_numSpecial--;
            }else{
                cout << "You are out of special attacks!" << endl;
            }
        }
    
        //Updating the health after the attacks
        m_myPlant->SetHealth(m_myPlant->GetHealth() - zombieAttack);
        m_curZombie->SetHealth(m_curZombie->GetHealth() - plantAttack);
    
        //Outcomes after the fight
        if(m_myPlant->GetHealth() > 0 && m_curZombie->GetHealth() > 0){
            cout << m_myPlant->GetName() << "'s health: " << m_myPlant->GetHealth() << endl;
            cout << m_curZombie->GetName() << "'s health: " << m_curZombie->GetHealth() << endl;
        }else if(m_myPlant->GetHealth() <= 0){
            cout << "You died. Game Over" << endl;
            m_myPlant->SetHealth(0);
        }else if(m_curZombie->GetHealth() <= 0){
            cout << "You have defeated the " << m_curZombie->GetName() << endl;
            m_curZombie->SetHealth(0);
        }
        
    }
    
    //Deallocating the zombie since it was created with the word "new"
    delete m_curZombie;
    m_curZombie = nullptr;
}

// Stats()
// Displays the information about the player (name, hp, rests, specials)
void Game::Stats(){
    cout << "Name: " << m_myPlant->GetName() << endl;
    cout << "HP: " << m_myPlant->GetHealth() << endl;
    cout << "Rests: " << m_numRests << endl;
    cout << "Special: " << m_numSpecial << endl;
}
