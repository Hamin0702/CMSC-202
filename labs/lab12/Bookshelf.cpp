/*****************************************
** File:    Bookshelf.cpp
** Project: CMSC 202 Lab 12, Fall 2020
** Author: Hamin Han
** Date: 11/19/20
** Section: 202/30
** Email: haminh1@umbc.edu
                                                                                                                                                                                                                                        
** This is the cpp file for the Bookshelf class in Lab 12. From the given code, I
** implemented  the Copy constructor, overloaded assignment operator, and
** the destructor in this file.
**
***********************************************/

#include "Bookshelf.h"

// Bookshelf
// Overloaded constructor
Bookshelf::Bookshelf(int cap, string name) {
  cout << "Bookshelf Constructor: Capacity=" << cap << " Name=" << name << endl;
  m_capacity = cap;
  m_used = 0;
  m_shelfName = name;
  m_books = new string[cap];
}

// Bookshelf
// Copy Constructor
Bookshelf::Bookshelf(const Bookshelf &B2){
    m_capacity = 0;
    m_used = 0;
    m_shelfName = "";
    m_books = new string[0];
    m_capacity = B2.m_capacity;
    m_used = B2.m_used;
    m_shelfName = B2.m_shelfName;
    delete[] m_books;
    m_books = new string[m_capacity];
    for (int i = 0; i < m_capacity; i++){
        m_books[i] = B2.m_books[i];
    }
}

// Bookshelf& operator=
// Overloaded Assignment Operator
Bookshelf& Bookshelf::operator=(const Bookshelf &B) {
    m_capacity = B.m_capacity;
    m_used = B.m_used;
    m_shelfName = B.m_shelfName;
    delete[] m_books;
    m_books = new string[m_capacity];
    for (int i = 0; i < m_capacity; i++){
        m_books[i] = B.m_books[i];
    }
    return *this;
}

// ~Bookshelf
// Destructor
Bookshelf::~Bookshelf() {
    delete[] m_books;
}

// Insert
// Inserts a new subject into the subject array
void Bookshelf::Insert(const string& itemName) {
  if(m_used == m_capacity) {
    cout << "The bookshelf is full. Cannot add any more books." << endl;
  }
  else  {
    m_books[m_used] = itemName;
    m_used++;
    cout << "Book:" << itemName << " added to the bookshelf." << endl;
  }
}

// DeleteLast
// Deletes the last subject in the subject array
void Bookshelf::DeleteLast() {
  if (m_used == 0) {
    cout << "The bookshelf is Empty!" << endl;
  }
  else{
    m_used--;
    cout << "Book:" << m_books[m_used] << " removed from the bookshelf." << endl;
    m_books[m_used] = "";
  }
}

// SetName
// Sets the name of the bookshelf
void Bookshelf::SetName(const string& name){
  m_shelfName = name;
}

// operator <<
// Overloaded << Operator
ostream& operator <<(ostream& os, const Bookshelf& fm) {
  os << "m_capacity: " << fm.m_capacity << endl;
  os << "m_used: " << fm.m_used << endl;

  os << fm.m_shelfName << " has the following books:" << endl << " | ";
  for(int i=0; i<fm.m_used; i++) {
    os << fm.m_books[i] + " | ";
  }
  return os << endl;
}

