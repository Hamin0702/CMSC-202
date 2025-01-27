/*****************************************
** File: Tqueue.cpp
** Project: CMSC 202 Project 5, Fall 2020
** Author: Hamin Han
** Date: 12/1/20
** Section: 202/30
** Email: haminh1@umbc.edu
                                                                                                                                                                                                                                        
** This is the cpp file for the Tqueue class in Project 5.
** It is a templated queue, so it has all the functionalities
** of a queue and it can be used by any data type.
** the function signatures are already included so
** I just needed to implement the functions below.
** The queue is set up for a specific data type and
** with a maximum capacity of the queue. It can enqueue,
** dequeue, sort, and check its contents and size.
** There are also the copy constructor and the overloaded
** assignment operator that will be handy later.
** The destructor is also implemented to prevent memory
** leaks.
***********************************************/

#ifndef TQUEUE_H
#define TQUEUE_H

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

template <class T, int N> //T is the data type and N is the container's capacity
class Tqueue {
public:
  //Name: Tqueue - Default Constructor
  //Precondition: None (Must be templated)
  //Postcondition: Creates a queue using dynamic array
  Tqueue(); //Default Constructor
  //Name: Copy Constructor
  //Precondition: Existing Tqueue
  //Postcondition: Copies an existing Tqueue
  Tqueue( const Tqueue<T,N>& x ); //Copy Constructor
  //Name: Destructor
  //Desc: Empties m_data
  //Precondition: Existing Tqueue
  //Postcondition: Destructs existing Tqueue
  ~Tqueue(); //Destructor
  //Name: Enqueue
  //Desc: Adds item to the back of queue (checks for capacity)
  //Precondition: Existing Tqueue
  //Postcondition: Size is incremented if successful and m_back increases
  void Enqueue(T data); //Adds item to queue (to back)
  //Name: Dequeue
  //Desc: Removes item from queue (from front)
  //      **Automatically moves all data to start at index 0 (using loop**
  //Precondition: Existing Tqueue
  //Postcondition: Size is decremented if successful.
  //               Data in m_front is removed and remaining data is move to the front.
  void Dequeue();
  //Name: Sort
  //Desc: Sorts the contents of the Tqueue (any algorithm you like)
  //Precondition: Existing Tqueue
  //Postcondition: Contents of Tqueue is sorted (low to high)
  void Sort();
  //Name: IsEmpty
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is empty else 0
  int IsEmpty(); //Returns 1 if queue is empty else 0
  //Name: IsFull
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is full else 0
  int IsFull(); //Returns 1 if queue is full else 0
  //Name: Size
  //Desc: Returns size of queue
  //Precondition: Existing Tqueue
  //Postcondition: Returns size of queue (difference between m_back and m_front)
  int Size();
  //Name: Overloaded assignment operator
  //Precondition: Existing Tqueue
  //Postcondition: Sets one Tqueue to same as a second Tqueue using =
  Tqueue<T,N>& operator=( Tqueue<T,N> y); //Overloaded assignment operator for queue
  //Name: At
  //Precondition: Existing Tqueue with index starting at 0
  //Postcondition: Returns object from Tqueue using At()
  T& At(int x);//Returns data from queue at location
  //Name: DisplayAll()
  //Precondition: Existing Tqueue (not used in MediaPlayer)
  //Postcondition: Outputs all items in Tqueue (must be cout compatible -
  //               may require overloaded << in object)
  void DisplayAll();
private:
  T* m_data; //Data of the queue (Must be dynamically allocated array)
  int m_front; //Front of the queue (for this project should always remain at 0)
  int m_back; //Back of the queue (will increase as the size increases)
};

//**** Add class definition below ****

// Tqueue - Default Constructor
// Creates a queue using dynamic array
template <class T, int N>
Tqueue<T,N>::Tqueue(){
    m_data = new T[N];
    m_front = 0;
    m_back = 0;
}

// Tqueue - Copy Constructor
// Copies an existing Tqueue
template <class T, int N>
Tqueue<T,N>::Tqueue( const Tqueue<T,N>& x ){
    m_data = new T[N];
    m_front = x.m_front;
    m_back = x.m_back;
    for (int i = 0; i < N; i++){
        m_data[i] = x.m_data[i];
    }
}

// ~Tqueue - Destructor
// Destructs existing Tqueue, Empties m_data
template <class T, int N>
Tqueue<T,N>::~Tqueue(){
    cout << "Size: " << Size() << endl;
    for (int i = 0; i < N; i++){
        //delete m_data[i];
    }
    delete[] m_data;
    m_data = nullptr;
    
}

// Enqueue
// Adds item to the back of queue (checks for capacity)
// Size is incremented if successful and m_back increases
template <class T, int N>
void Tqueue<T,N>::Enqueue(T data){
    if(IsFull()){
        cout << "Queue Overflow" << endl;
    }else{
        m_data[m_back] = data;
        m_back++;
    }
}

// Dequeue
// Removes item from queue (from front)
// Automatically moves all data to start at index 0 (using loop**
// Size is decremented if successful.
template <class T, int N>
void Tqueue<T,N>::Dequeue(){
    if(IsEmpty()){
        cout << "Queue Empty" << endl;
    }else{
        for(int i = 1; i < m_back; i++){
            m_data[i-1] = m_data[i];
        }
        m_back--;
    }
}

// Sort
// Sorts the contents of the Tqueue (low to high)
template <class T, int N>
void Tqueue<T,N>::Sort(){
    for(int i = 0; i < m_back; i++){
        for(int j = i+1; j < m_back; j++){
            if(*m_data[j] < *m_data[i]){
                T temp = m_data[i];
                m_data[i] = m_data[j];
                m_data[j] = temp;
            }
        }
    }
}

// IsEmpty
// Returns 1 if queue is empty else 0
template <class T, int N>
int Tqueue<T,N>::IsEmpty(){
    if(Size()==0){
        return 1;
    }else{
        return 0;
    }
}

// IsFull
// Returns 1 if queue is full else 0
template <class T, int N>
int Tqueue<T,N>::IsFull(){
    if(Size()==N){
        return 1;
    }else{
        return 0;
    }
}

// Size
// Returns size of queue
template <class T, int N>
int Tqueue<T,N>::Size(){
    int size = m_back - m_front;
    return size;
}

// Overloaded assignment operator =
// Sets one Tqueue to same as a second Tqueue using =
template <class T, int N>
Tqueue<T,N>& Tqueue<T,N>::operator=( Tqueue<T,N> y){
    for (int i = 0; i < N; i++){
        //delete m_data[i];
    }
    delete[] m_data;
    m_data = nullptr;
    
    m_data = new T[N];
    m_front = y.m_front;
    m_back = y.m_back;
    for (int i = 0; i < N; i++){
        m_data[i] = y.m_data[i];
    }
    return *this;
}

// At
// Returns data from queue at location
template <class T, int N>
T& Tqueue<T,N>::At(int x){
    return m_data[x];
}

// DisplayAll()
// Outputs all items in Tqueue
template <class T, int N>
void Tqueue<T,N>::DisplayAll(){
    for(int i = 0; i < m_back; i++){
        cout << m_data[i] << endl;
    }
}

#endif
