/******************************
** File: Room.cpp
** CMSC 202 Project 4 Fall 2020
** Author: Hamin Han
** Date: 11/12/20
** Section: 202/30
** Email: haminh1@umbc.edu
**
** The Room.cpp file contains the data of room ID, room name,
** room description, and the ID of the rooms surrounding it
******************************/

#include "Room.h"

// Room (constructor)
// Creates a new room and sets up all the member variables
Room::Room(int id, string name, string description, int north, int east, int south, int west){
    m_ID = id;
    m_name = name;
    m_desc = description;
    m_direction[0] = north;
    m_direction[1] = east;
    m_direction[2] = south;
    m_direction[3] = west;
}

// GetName
// Returns the room name as string
string Room::GetName(){
    return m_name;
}

// GetID
// Returns room id as int
int Room::GetID(){
    return m_ID;
}

// GetDesc
// Returns room description as string
string Room::GetDesc(){
    return m_desc;
}

// CheckDirection
// Returns id of room in that direction if the exit exists, If there is no exit in that direction, returns -1
int Room::CheckDirection(char direction){
    int ID = -1;
    if(direction == 'N' || direction == 'n'){
        ID = m_direction[0];
    }else if(direction == 'E' || direction == 'e'){
        ID = m_direction[1];
    }else if(direction == 'S' || direction == 's'){
        ID = m_direction[2];
    }else if(direction == 'W' || direction == 'w'){
        ID = m_direction[3];
    }
    return ID;
}

// PrintRoom
// Outputs the room name, room desc, then possible exits
void Room::PrintRoom(){
    string exits = "";
    if(m_direction[0]!=-1)
        exits = exits + "N";
    if(m_direction[1]!=-1)
        exits = exits + "E";
    if(m_direction[2]!=-1)
        exits = exits + "S";
    if(m_direction[3]!=-1)
        exits = exits + "W";
    cout << m_name << endl;
    cout << m_desc << endl;
    cout << "Possible Exits: " << exits << endl;
}
