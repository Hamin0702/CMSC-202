/******************************
** File: Song.h
** CMSC 202 Lab 10, Fall 2020
** Author: Hamin Han
** Date: 11/5/20
** Section: 202/30
** Email: haminh1@umbc.edu
**
** The Song.h file creates three classes, the Song class, which is the
** super/parent class, and the Hiphop and Pop class, which are child
** classes of the Song Class. They all have the member variables for
** the name of the song and the name of the artist. And they have functions
** for playing the song, requesting a song, and liking a song. Each class
** has slightly different outputs based on what type of song it is.
** Since we want to use the different versions of Play, Request, and Like
** in the subclasses, we want to use the virtual keyword in the parent class.
** But we must remember to implement the virtual functions in the header file
** since the main cpp file only includes the header file.
******************************/

#ifndef Song_h
#define Song_h

#include <string>
#include <iostream>
using namespace std;

// Parent class
class Song {
public:
    
    //----------------------------------------
    // Name: Song (Constructor)
    // PreCondition: Takes in two strings as parameters for the name of the artist and name of the song
    // PostCondition: The member variable is updated
    //----------------------------------------
    Song(string songName, string artistName);
    
    //----------------------------------------
    // Name: Play
    // PreCondition: Member variables are set up correctly
    // PostCondition: Outputs a messgae for the user saying which song is playing
    //----------------------------------------
    // the virtual function has to be implemented in this .h file since the main cpp file includes Song.h
    virtual void Play(){
        cout << "Listen I got just what you need, brand new " << m_artist << ", this is " << m_song << "." << endl;
    }
    
    //----------------------------------------
    // Name: Request
    // PreCondition: The funciton is called when a song is requested
    // PostCondition: Outputs a messgae for acknowledging the request
    //----------------------------------------
    // the virtual function has to be implemented in this .h file since the main cpp file includes Song.h
    virtual void Request(){
        cout << "We got a caller asking for another song." << endl;
    }
    
    //----------------------------------------
    // Name: Like
    // PreCondition: Member variables are set up correctly
    // PostCondition: Outputs a message for the user saying the song is added to the liked song list
    //----------------------------------------
    // the virtual function has to be implemented in this .h file since the main cpp file includes Song.h
    virtual void Like(){
        cout << "I knew you'd like that, we're adding " << m_song << " by " << m_artist << " to your liked songs list." << endl;
    }
    
// Member variables for name of the song and name of the artist
protected:
    string m_artist;
    string m_song;
};

// Child class of Song
class Hiphop: public Song{
public:
    
    //----------------------------------------
    // Name: Hiphop (Constructor)
    // PreCondition: Takes in two strings as parameters for the name of the artist and name of the song
    // PostCondition: The member variable is updated
    //----------------------------------------
    Hiphop(string songName, string artistName);
    
    //----------------------------------------
    // Name: Play
    // PreCondition: Member variables are set up correctly
    // PostCondition: Outputs a messgae for the user saying which hiphop song is playing
    //----------------------------------------
    void Play();
    
    //----------------------------------------
    // Name: Request
    // PreCondition: The funciton is called when a hiphop song is requested
    // PostCondition: Outputs a messgae for acknowledging the request
    //----------------------------------------
    void Request();
    
    //----------------------------------------
    // Name: Like
    // PreCondition: Member variables are set up correctly
    // PostCondition: Outputs a message for the user saying the hiphop song is added to the liked song list
    //----------------------------------------
    void Like();
};

// Child class of Song
class Pop: public Song{
public:
    
    //----------------------------------------
    // Name: Pop (Constructor)
    // PreCondition: Takes in two strings as parameters for the name of the artist and name of the song
    // PostCondition: The member variable is updated
    //----------------------------------------
    Pop(string songName, string artistName);
    
    //----------------------------------------
    // Name: Play
    // PreCondition: Member variables are set up correctly
    // PostCondition: Outputs a messgae for the user saying which pop song is playing
    //----------------------------------------
    void Play();
    
    //----------------------------------------
    // Name: Request
    // PreCondition: The funciton is called when a pop song is requested
    // PostCondition: Outputs a messgae for acknowledging the request
    //----------------------------------------
    void Request();
    
    //----------------------------------------
    // Name: Like
    // PreCondition: Member variables are set up correctly
    // PostCondition: Outputs a message for the user saying the pop song is added to the liked song list
    //----------------------------------------
    void Like();
};
#endif
