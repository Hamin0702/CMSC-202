/******************************
** File: Song.cpp
** CMSC 202 Lab 10, Fall 2020
** Author: Hamin Han
** Date: 11/5/20
** Section: 202/30
** Email: haminh1@umbc.edu
**
** The Song.cpp implements all the functions made in the
** Song.h header file. All the outputs from the Play, Request,
** and Like functions differ slightly. And the constructors of the
** subclasses uses the constructor of the parent class.
******************************/

#include "Song.h"
    
// Song (Constructor)
// Sets up the member variables
Song::Song(string songName, string artistName){
    m_song = songName;
    m_artist = artistName;
}

// Hiphop (Constructor)
// Sets up the member variables by calling the Song constructor
Hiphop::Hiphop(string songName, string artistName):Song(songName, artistName){}

// Play
// Prints out what hiphop song is playing
void Hiphop::Play(){
    cout << "We love rap music, here's another one from " << m_artist << ", " << m_song << "." << endl;
}

// Request
// Prints out that there is a request for a hiphop song
void Hiphop::Request(){
    cout << "We got a caller on line one asking for more hip-hop." << endl;
}
    
// Like
// Prints out that the hiphop song was added to the liked songs list
void Hiphop::Like(){
    cout << "I knew you'd like that, we're adding " << m_song << " by " << m_artist << " to your liked hip-hop songs list." << endl;
}

// Pop (Constructor)
// Sets up the member variables by calling the Song constructor
Pop::Pop(string songName, string artistName):Song(songName, artistName){}
    
// Play
// Prints out what pop song is playing
void Pop::Play(){
    cout << "We love pop music too, coming up we got " << m_song << " by " << m_artist << "." << endl;
}
    
// Request
// Prints out that there is a request for a pop song
void Pop::Request(){
    cout << "We got a caller in the building requesting some pop music this time." << endl;
}
    
// Like
// Prints out that the pop song was added to the liked songs list
void Pop::Like(){
    cout << "I knew you'd like that, we're adding " << m_song << " by " << m_artist << " to your liked pop songs list." << endl;
}

