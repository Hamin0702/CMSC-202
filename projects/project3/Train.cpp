/******************************
** File: Train.cpp
** CMSC 202 Project3, Fall 2020
** Author: Hamin Han
** Date: 10/22/20
** Section: 202/30
** Email: haminh1@umbc.edu
**
** Train.cpp defines all the methods specified in the class Train of the Train.h file.
** It contains the constructor, destructor, all the functions that it got from class Car.
** The file is used to load in passengers on the train, add extra cars when needed,
** disembark passengers on their stop,while being able to move to the next stop, reverse the route,
** and print out the details of the train to the user.
** All of these are used by the user in the main menu (proj3.cpp).
******************************/

#include "Train.h"
using namespace std;

// Train (contructor)
// Takes in a route pointer, sets the route of the train, adds a car to start with
Train::Train(Route* route){
    m_head = nullptr;
    m_totalCars = 0;
    AddCar();
    m_route = route;
}

// ~Train (destructor)
// Removes each car from the train and deallocates each passenger in each car, and resets pointers
Train::~Train(){
    cout << "Destructor" << endl;
    Car *curr = m_head;
    
    //Iterates through and deletes all nodes
    while(curr != nullptr){
        m_head = curr;
        curr = curr->m_next;
        
        //Deallocating each passenger in each car
        while(!m_head->m_passengers.empty()){
            delete m_head->m_passengers.front();
            m_head->m_passengers.erase(m_head->m_passengers.begin());
        }
        delete m_head;
    }
    
    //Resets the member variables to default values (nullptr/0)
    m_head = nullptr;
    m_route = nullptr;
    m_totalCars = 0;
}

// AddCar
// Adds a car to the end of the train
void Train::AddCar(){
    bool flag = true;
    
    //Adding a car in the beginning when no cars exist
    if(m_head == nullptr){
        m_head = new Car(CAR_CAPACITY, m_totalCars+1);
        
    //Adding a car to the end of the train
    }else{
        Car* counter = m_head;
        while(flag){
            if(counter->m_next == nullptr){
                counter->m_next = new Car(CAR_CAPACITY, m_totalCars+1);
                flag = false;
            }else{
                counter = counter->m_next;
            }
        }
    }
    
    //Increments the total number of cars
    m_totalCars++;
}

  // Name: RemoveCar(Car*)
  // Desc - Removes a car from either the beginning, middle or end of train linked list
  // Preconditions - Train exists
  // Postconditions - Removes specific car (including passengers)
  // UNUSED - 3 Bonus Pts for completing if rest of project is completed
void Train::RemoveCar(Car*){
    //extra credit
}

// TrainStatus
// Displays number of cars, number of passengers, and the route details
void Train::TrainStatus(){
    Car* flag = m_head;
    
    //Displays number of cars
    cout << "Number of cars: " << m_totalCars << endl;
    
    //Displays the number of cars in each car
    while(flag != nullptr){
        cout << "Car " << flag->m_carNumber << ": Number of Passengers: " << (int) flag->m_passengers.size() << endl;;
        flag = flag->m_next;
    }
    
    //Displays the route details
    m_route->PrintRouteDetails();
}

// LoadPassengers
// Reads in the file containing the list of passengers and load the ones with the right start location to the train
void Train::LoadPassengers(string passName){
    string firstName;
    string lastName;
    string fullName;
    string ageTemp;
    int age = 0;
    string startLocation;
    string finalDestination;
    int counter = 0;
    
    ifstream inFile;
    inFile.open(passName);
    while(!inFile.eof()){
        
        //Reading the file
        if(!inFile.eof()){
            getline(inFile,firstName,',');
            if(firstName != ""){
                getline(inFile,lastName,',');
                fullName = "" + firstName + " " + lastName;
                getline(inFile,ageTemp,',');
                age = stoi(ageTemp);
                getline(inFile,startLocation,',');
                getline(inFile,finalDestination,'\n');
                                
                //Loading the passengers onto the train if they got the corresponding start location
                if(startLocation == m_route->GetCurrentStop()->GetName()){
                    Passenger* passenger = new Passenger(fullName, age, startLocation, finalDestination);
                    BoardPassenger(passenger);
                    cout << fullName << " Boards the Train (Destination: " << finalDestination << ")" << endl;
                    counter++;
                }
                
            }
        }
    }
    cout << "Boarded " << counter << " passengers" << endl;
    inFile.close();
}

// BoardPassenger
// Loads a passenger onto the first open car of the train, adds a car for the passenger if needed
void Train::BoardPassenger(Passenger* passenger){
    bool flag = true;
    Car* checkCar = m_head;
    
    //If no cars exists
    if(m_head == nullptr){
        AddCar();
        if(!checkCar->IsFull()){
            checkCar->AddPassenger(passenger);
        }
    }else{
        while(flag){
            
            //Adds an additional car if the train is full
            if(IsTrainFull()){
                AddCar();
                
            //If the car it's checking is full, move on to the next car
            }else if(checkCar->IsFull() && checkCar->m_next != nullptr){
                checkCar = checkCar->m_next;
                
            //Stops the pointer at the car with the open spot
            }else if(!checkCar->IsFull()){
                flag = false;
            }
        }
        
        //Adds the passenger in the open spot
        checkCar->AddPassenger(passenger);
    }
}

// DisembarkPassengers
// If a passenger is at their final destination, the passenger is removed from the train and deallocated
void Train::DisembarkPassengers(){
    int counter = 0;
    Car* checkCar = m_head;
    while(checkCar != nullptr){
        for(int i = 0; i < (int) checkCar->m_passengers.size(); i++){
            if(checkCar->m_passengers.at(i)->GetFinalDestination() == m_route->GetCurrentStop()->GetName()){
                cout << checkCar->m_passengers.at(i)->GetName() << " Disembarks the Train (Destination: " << m_route->GetCurrentStop()->GetName() << ")" << endl;
                
                //Deallocate the passenger and erase it
                delete checkCar->m_passengers.at(i);
                checkCar->m_passengers.erase(checkCar->m_passengers.begin() + i);
                i = -1;
                counter++;
            }
        }
        checkCar = checkCar->m_next;
    }
    cout << counter << " passengers disembarked" << endl;
}

// TravelToNextStop
// Moves the train to the next stop
void Train::TravelToNextStop(){
    if(m_route->GetCurrentStop()->GetNextStop() == nullptr){
        cout << "You are at the end of the route, turn the train around" << endl;
    }else{
        m_route->SetCurrentStop(m_route->GetCurrentStop()->GetNextStop());
        cout << "Arriving at " << m_route->GetCurrentStop()->GetName() << endl;
        if(m_route->GetCurrentStop()->GetNextStop() == nullptr){
            cout << "This is the last stop" << endl;
        }
    }
}

// TurnTrainAround
// Reverses the route and the train restarts at the new front
void Train::TurnTrainAround(){
    if(m_route->GetCurrentStop()->GetNextStop() == nullptr){
        
        //Calls the ReverseRoute function in route.cpp
        m_route->ReverseRoute();
    }else{
        cout << "You can only reverse the route when at the end of the route" << endl;
    }
    
}

// IsTrainFull
// Returns true if the train is full (all cars are at max capacity), false else
bool Train::IsTrainFull(){
    bool flag = true;
    Car* start = m_head;

    while(start != nullptr){
        if(!start->IsFull()){
            flag = false;
        }
        start = start->m_next;
    }
    return flag;
}
