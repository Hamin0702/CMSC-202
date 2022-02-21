/*****************************************
** File: Media.cpp
** Project: CMSC 202 Project 5, Fall 2020
** Author: Hamin Han
** Date: 12/1/20
** Section: 202/30
** Email: haminh1@umbc.edu
                                                                                                                                                                                                                                        
** This is the cpp file for the Media class in Project 5.
** A media object containts the name of the title, name of
** the artist, type of media, the year it came out, its rank.
** The cpp file implements all the mutators and accessors
** from the header file. And it includes overloaded operators,
** one is for displaying the mdeia (<<) and the other is used
** to compare two media objects (<)
***********************************************/

#include "Media.h"

// Media - Default Constructor
// Creates a default media
Media::Media(){
    m_title = "";
    m_artist = "";
    m_type = "";
    m_year = 0;
    m_rank = 0;
}

// Media - Overloaded Constructor
// Creates a media entry based on passed parameters
Media::Media(string title, string artist, string type, int year, int rank){
    m_title = title;
    m_artist = artist;
    m_type = type;
    m_year = year;
    m_rank = rank;
}

// GetTitle
// return title
string Media::GetTitle()const{
    return m_title;
}

// GetArtist
// return artist
string Media::GetArtist()const{
    return m_artist;
}

// GetType
//return type
string Media::GetType()const{
    return m_type;
}

// GetYear
// return year
int Media::GetYear()const{
    return m_year;
}

// GetRank
// return rank (1-100 from that year)
int Media::GetRank()const{
    return m_rank;
}

// SetTitle
// set title
void Media::SetTitle(string title){
    m_title = title;
}

// SetArtist
// set artist
void Media::SetArtist(string artist){
    m_artist = artist;
}

// SetType
// set type
void Media::SetType(string type){
    m_type = type;
}

// SetYear
// set year
void Media::SetYear(int year){
    m_year = year;
}

// SetRank
// set rank
void Media::SetRank(int rank){
    m_rank = rank;
}

// Overloaded << operator
// Returns output stream including title by artist from year
ostream& operator<<(ostream& out, Media& m){
    out << m.GetTitle() << " by " << m.GetArtist() << " from " << m.GetYear();
    return out << endl;
}

// Overloaded Relational Operator (<)
// if passed media's year is less than first, return true else false
bool Media::operator<(const Media& m){
    if(m.GetYear() < m_year){
        return false;
    }else{
        return true;
    }
}
