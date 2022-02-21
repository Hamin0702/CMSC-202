/*****************************************
** File: MediaPlayer.cpp
** Project: CMSC 202 Project 5, Fall 2020
** Author: Hamin Han
** Date: 12/1/20
** Section: 202/30
** Email: haminh1@umbc.edu
                                                                                                                                                                                                                                        
** This is the cpp file for the MediaPlayer class in Project 5.
** A media player object contains a vector for the catalog,
** and the Tqueue that holds all of the media of the playlist.
** This file will load in the media files from a given text file and
** ask the user to either 1. Display Media by Type and Year,
** 2. Add Media to Playlist, 3. Display Playlist, 4. Sort Playlist by Year
** or 5. Quit.
***********************************************/

#include "MediaPlayer.h"

// MediaPlayer - Default Constructor
// Creates a new MediaPlayer
MediaPlayer::MediaPlayer(){
    string filename;
    cout << "What is the media file name?" << endl;
    cin >> filename;
    LoadCatalog(filename);
}

// MediaPlayer - Overloaded Constructor
// Creates a new MediaPlayer and passes the media filename
MediaPlayer::MediaPlayer(string filename){
    //m_playList = new Tqueue <Media*, 3000> ();
    LoadCatalog(filename);
}

// ~MediaPlayer - Destructor
// Destructs existing MediaPlayer
MediaPlayer::~MediaPlayer(){
    
    //deleting media* in the vector and then clearing the vector itself
    for(int i = 0; i < m_mediaCatalog.size(); i++){
        delete m_mediaCatalog.at(i);
        m_mediaCatalog.at(i) = nullptr;
    }
    m_mediaCatalog.clear();
}

// LoadCatalog
// Loads the file into the m_mediaCatalog (as media)
void MediaPlayer::LoadCatalog(string filename){
    string title = "";
    string artist = "";
    string type = "";
    string yearTemp = "";
    string rankTemp = "";
    int year = 0;;
    int rank = 0;
    int totalMedia = 0;
    
    ifstream inFile;
    inFile.open(filename);
    while(!inFile.eof()){
        
        //Reading the file
        if(!inFile.eof()){
            getline(inFile,title,';');
            if(title != ""){
                getline(inFile,artist,';');
                getline(inFile,type,';');
                getline(inFile,yearTemp,';');
                getline(inFile,rankTemp,'\n');
                year = stoi(yearTemp);
                rank = stoi(rankTemp);
                
                // Adding to m_mediaCatalog
                m_mediaCatalog.push_back(new Media(title, artist, type, year, rank));
                totalMedia++;
            }
        }
    }
    inFile.close();
    cout << totalMedia << " media files loaded." << endl;
}

// MainMenu
// Manages the application and the menu
void MediaPlayer::MainMenu(){
    int menuChoice = 0;
    
    while(menuChoice != 5){
        do {
            
            //Menu choices
            menuChoice = 0;
            cout << "What would you like to do?" << endl;
            cout << "1. Display Media by Type and Year" << endl;
            cout << "2. Add Media to Playlist" << endl;
            cout << "3. Display Playlist" << endl;
            cout << "4. Sort Playlist by Year" << endl;
            cout << "5. Quit" << endl;
            cin >> menuChoice;
            if(menuChoice < 1 || menuChoice > 5)
                cout << "Try again, invalid input" << endl;
        } while (menuChoice < 1 || menuChoice > 5);
        
        //Display media
        if(menuChoice == 1){
            cout << DisplayMedia() << " media found." << endl;
            
        //Add Media
        }else if(menuChoice == 2){
            AddMedia();
            
        //Display playlist
        }else if(menuChoice == 3){
            DisplayPlaylist();
            
        //Sort playlist
        }else if(menuChoice == 4){
            SortPlaylist();
            
        //Quit
        }else if(menuChoice == 5){
            cout << "Thank you for using the UMBC Media Player" << endl;
        }
    }
}

// DisplayMedia
// Lists all media (numbered) for that year and returns int
//  of number found with that criteria
int MediaPlayer::DisplayMedia(){
    string type;
    int year;
    int counter = 0;
    
    //User chooses media type
    do {
        type = "";
        cout << "Which media type do you want to display?" << endl;
        cout << "music" << endl;
        cout << "podcast" << endl;
        cin >> type;
        if(type != "music" && type != "podcast")
            cout << "Invalid type, try again" << endl;
    } while (type != "music" && type != "podcast");
    
    //User chooses year
    do {
        year = 0;
        cout << "Which year would you like to display? (1958-2020)" << endl;
        cin >> year;
        if(year < MIN_YEAR || year > MAX_YEAR)
            cout << "Invalid year, try again" << endl;
    } while (year < MIN_YEAR || year > MAX_YEAR);
    
    //Displaying all of the media of the matching type and year
    cout << "******" << year << "******" << endl;
    
    //Goes through the catalog and only displays the ones that fits the criteria
    for(int i = 0; i < m_mediaCatalog.size(); i++){
        if(m_mediaCatalog.at(i)->GetYear() == year && m_mediaCatalog.at(i)->GetType() == type){
            cout << i+1 << ". " << m_mediaCatalog.at(i)->GetTitle() << " by " << m_mediaCatalog.at(i)->GetArtist() << endl;
            counter++;
        }
    }
    
    //returns how many valid media files there are
    return counter;
}

// AddMedia
// Displays the current list and adds media to m_playList
void MediaPlayer::AddMedia(){
    int availableMedia = 0;
    int mediaNumber = 0;
    
    //If the playlist is empty
    if(m_playList.IsEmpty()){
        cout << "The playlist is currently empty" << endl;
    }
    
    //Displays the media that user wants to look at
    cout << "Choose the media you would like to add to the playlist." << endl;
    availableMedia = DisplayMedia();
    cout << availableMedia << " media found." << endl;
    
    //If there are valid media files
    if(availableMedia != 0){
        do {
            
            //Asks the user to choose the media
            cout << "Enter the number of the media you would like to add:" << endl;
            cin >> mediaNumber;
            if(mediaNumber < 1 || mediaNumber > m_mediaCatalog.size())
                cout << "Invalid number of media, try again" << endl;
        } while (mediaNumber < 1 || mediaNumber > m_mediaCatalog.size());
        
        //Adding the media chosen by the user to the playlist
        mediaNumber--;
        m_playList.Enqueue(m_mediaCatalog.at(mediaNumber));
        cout << m_mediaCatalog.at(mediaNumber)->GetTitle() << " by " << m_mediaCatalog.at(mediaNumber)->GetArtist() << " added to the playlist" << endl;
    }
}

// DisplayPlaylist
// Displays the playlist (will indicate if list is empty)
void MediaPlayer::DisplayPlaylist(){
    
    //If the playlist is empty
    if(m_playList.IsEmpty()){
        cout << "The playlist is currently empty" << endl;
    }else{
        
        //Displays the playlist (using the << overloaded assignment operator)
        for(int i = 0; i < m_playList.Size(); i++){
            cout << i+1 << ". " << *m_playList.At(i);
        }
    }
}

// SortPlaylist
// Sorts the playlist by year
void MediaPlayer::SortPlaylist(){
    
    //If the playlist is empty
    if(m_playList.IsEmpty()){
        cout << "The playlist is currently empty" << endl;
    }else{
        
        //Sorts the playlist by using the Sort() function from media
        m_playList.Sort();
        cout << "Done sorting by year" << endl;
        cout << m_playList.Size() << " items sorted." << endl;
    }
}
