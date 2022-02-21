/*****************************************
** File: Lab13.cpp
** Project: CMSC 202 Lab 12, Fall 2020
** Author: Hamin Han
** Date: 11/24/20
** Section: 202/30
** Email: haminh1@umbc.edu
                                                                                                                                                                                                                                        
** This is the cpp file for Lab 13. From the given code, I only changed the
** recursiveDisplay function. The lab is focused on recursion where it uses
** Linked Lists to print out all the numbers from 0 to 99
***********************************************/

#include <iostream>
#include <string>
using namespace std;

const int START = 0;
const int END = 100;

struct Node {
  int num;
  Node * next;
};

class LinkedList{
public:
  LinkedList(){
    m_head = nullptr;
  }
  ~LinkedList(){
    Node * cur = m_head;
    while(m_head != nullptr){
      m_head = m_head->next;
      delete cur;
      cur = m_head;
    }
  }

  //Implement recursive Display function
  void Display(Node *curNode) {
    // Base Case
    if(curNode == nullptr){
	cout << "END";
	return;
    }
    // Recursive Case
      cout << curNode->num << "->";
      Display(curNode->next);
  }

  //Overloaded function to start displaying at m_head if not specified
  //DO NOT EDIT THIS FUNCTION
  void Display() {
    Display(m_head);
  }

  //Inserts node at end of linked list
  void Insert(int value, bool location){
    if(m_head == nullptr) {
      m_head = new Node();
      m_head->num = value;
      m_head->next = nullptr;
    }
    else {
      Node *cur = m_head;
      while(cur->next != nullptr) {
        cur = cur->next;
      }
      cur->next = new Node();
      cur->next->num = value;
      cur->next->next = nullptr;
    }
  }

private:
  Node* m_head;
};

//Creates linked list and inserts 0-99 then displays
int main (){
  LinkedList ll;
  for(int i = START; i < END;i++){
    ll.Insert(i, 1);
  }
  ll.Display();
  return 0;
}
