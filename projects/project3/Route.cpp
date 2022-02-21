/******************************
** File: Route.cpp
** CMSC 202 Project3, Fall 2020
** Author: Hamin Han
** Date: 10/22/20
** Section: 202/30
** Email: haminh1@umbc.edu
**
** Route.cpp defines all the methods specified in the Route.h file.
** It contains the constructor, destructor, loadRoute which loads all
** the stops from a text file and creates a linked list, AddStop which
** adds a stop to the end of the linked list, printRouteDetail which
** prints the details of the current and the next stop, the setter and getter
** for m_currentStop, and ReverseRoute which reveres the order of the
** stops in the route.
******************************/

#include "Route.h"
#include <vector>
using namespace std;

// Route
// Default constructor that initializes all the member variabls
Route::Route() {
    m_head = nullptr;
    m_tail = nullptr;
    m_currentStop = nullptr;
    m_totalStops = 0;
}

// ~Route
// Destructor that cleans up after using the program to prevent memoery leaks
Route::~Route(){
    cout << "Destructor" << endl;
    Stop *curr = m_head;
    
    //Iterates through and deletes all nodes
    while(curr != nullptr){
      m_head = curr;
      curr = curr->GetNextStop();
      delete m_head;
    }
    
    //Resets the member variables to default values (nullptr/0)
    m_head = nullptr;
    m_tail = nullptr;
    m_currentStop = nullptr;
    m_totalStops = 0;
}

// LoadRoute
// Reads in a text file containing the information about the route
// and creates a linked list of stops with them
void Route::LoadRoute(string fileName){
    string stopName;
    string stopNumberTemp;
    int stopNumber = 0;
    
    ifstream inFile;
    inFile.open(fileName);
    while(!inFile.eof()){
        if(!inFile.eof()){
            getline(inFile,stopName,',');
            if(stopName != ""){
                getline(inFile,stopNumberTemp,'\n');
                stopNumber = stoi(stopNumberTemp);
                //cout << stopName << ", " << stopNumber << endl;
                AddStop(stopName, stopNumber);
                m_totalStops++;
            }
        }
    }
    inFile.close();
    
    //Indicates how many stops were added (should be 30)
    cout << "Route loaded with " << m_totalStops << " stops" << endl;
}

// AddStop
// Takes in the name and the number of the stop and creates a new stop and adds
// it to the end of the linked list
void Route::AddStop(string name, int number){
    Stop* newStop = new Stop(name, number);
    
    //If it is the first stop being added
    if(m_totalStops == 0){
        m_head = newStop;
        m_currentStop = m_head;
        m_tail = newStop;
        m_tail->SetNextStop(nullptr);
        
    //If it is adding it to the end of the route
    }else{
        m_tail->SetNextStop(newStop);
        m_tail = newStop;
        m_tail->SetNextStop(nullptr);
    }
}

// PrintRouteDetails
// Displays the name of the current stop and the next stop
void Route::PrintRouteDetails(){
    cout << "Current stop: " << m_currentStop->GetName() << " (" << m_currentStop->GetNumber() << ")" << endl;
    if(m_currentStop->GetNextStop() != nullptr){
    cout << "Next stop is: " << (m_currentStop->GetNextStop())->GetName() << " (" << (m_currentStop->GetNextStop())->GetNumber() << ")" << endl;
    }
}

// GetCurrentStop
// Returns the member variabl m_currentStop
Stop* Route::GetCurrentStop(){
    return m_currentStop;
}

// SetCurrentStop
// Takes in a Stop pointer and sets it as m_currentStop
void Route::SetCurrentStop(Stop* curr){
    m_currentStop = curr;
}

// ReverseRoute
// Reverses the orders of the stops in the route
void Route::ReverseRoute(){
    Stop* flag = m_head;
    Stop* temp = flag;
    vector<Stop*> newRoute;
    
    //Creates a vector and adds all the stops seperately
    for(int i = 0; i < m_totalStops; i++){
        newRoute.push_back(temp);
        temp = temp->GetNextStop();
    }
    
    //Reorders the route by starting from the back of the vector
    Stop* newHead = nullptr;
    while(!newRoute.empty()){
        
        //If no Stop is added to the route yet
        if(newHead == nullptr){
            newHead = newRoute.back();
            newRoute.pop_back();
            m_head = newHead;
            m_currentStop = m_head;
            m_tail = newHead;
            
        //When it adds the Stop from the back of the vector to the front of the route
        }else{
            newHead->SetNextStop(newRoute.back());
            newRoute.pop_back();
            newHead = newHead->GetNextStop();
            m_tail = newHead;
        }
    }
    m_tail->SetNextStop(nullptr);
    
    cout << m_totalStops << " stops reversed." << endl;
}
