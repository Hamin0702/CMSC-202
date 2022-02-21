/******************************
** File: LinkedList.cpp
** Lab: CMSC 202 Lab7
** Author: Hamin Han
** Date: 10/13/2020
** Email: haminh1@umbc.edu
**
** Lab7 for cmsc 202
**
** This is the given cpp file for LinkedList for lab7 and two functions
** isPalindrome and reverse were added and made sure that
** there are no memory leaks.
** lab7.cpp and LinkedList.h were also given and remained unchanged.
******************************/

#include "LinkedList.h"

// Default constructor
LinkedList::LinkedList(): m_head(nullptr) {};

// Destructor (called with the word "delete")
LinkedList::~LinkedList() {
    Node* current = m_head;
    while (m_head) {
        m_head = m_head->next;
        delete current;
        current = m_head;
    }
}

// insertAtEnd
// Inserts node at the end of the linked list
void LinkedList::insertAtEnd(char letter){
    if(m_head == nullptr) {
        m_head = new Node(letter);
    }
    else {
        Node *current = m_head;
        while(current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node(letter);
    }
}

// insertAtFront
// Inserts node at the front of the linked list
void LinkedList::insertAtFront(char letter) {
    if(m_head == nullptr) {
        m_head = new Node(letter);
    }
    else {
        m_head = new Node(letter, m_head);
    }
}

// display
// Displays/Prints the linked list
void LinkedList::display() {
    Node* current = m_head;
    while(current) {
        cout << current->letter;
        current = current->next;
    }
    cout << endl;
}

// reverse
// Makes a copy of the linked list, reverses it, and returns the pointer
LinkedList* LinkedList::reverse() {
    
    //since the word "new" is called here, it needs to be deallocated in the future
    LinkedList* reversedList = new LinkedList;
    Node* current = m_head;
    
    //while not changing the original LinkedList, makes a new one with reversed values
    while(current!=nullptr){
        reversedList->insertAtFront(current->letter);
        current = current->next;
    }
    return reversedList;
}

// isPalindrome
// Uses reverse() to check if the word in the LinkedList is a palindrome, returns the bool
bool LinkedList::isPalindrome() {
    LinkedList* reversedList = reverse();
    Node* copy = reversedList->m_head;
    Node* original = m_head;
    bool flag = true;
    while(original!=nullptr){
        if(original->letter != copy->letter){
            flag = false;
        }
        original = original->next;
        copy = copy->next;
    }
    
    //since reversedList was a "new LinkedList", it needs to get deallocated in order to prevent memory leaks
    delete reversedList;
    
    return flag;
}
