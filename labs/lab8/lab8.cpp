#include <iostream>
using namespace std;

struct Node{
public:
  int m_info; //Data
  Node *m_next; //Node pointer
};

class LinkedList{
public:
  LinkedList(); //constructor
  ~LinkedList(); //destructor
  void insert_begin(int data); //insert function
  void removeAt(int); //Remove at location
  void display(); //iterating function
private:
  Node *m_head; //Track front of linked list
  Node *m_tail; //Track back of linked list
  int m_size; //Track size of linked list
};

LinkedList::LinkedList(){ //Constructor for linked list
  m_head = nullptr; //Intialize head to nullptr
  m_tail = nullptr; //Initialize tail to nullptr

  //Error 1: Conditional Jump
  //Correction: m_size wasn't initialized in the constructor
  m_size = 0;

}

LinkedList::~LinkedList(){ //Removes all nodes in linked list
  cout << "Destructor" << endl;
  Node *curr = m_head;
  while(curr != nullptr){ //Iterates through and deletes all nodes
    m_head = curr;
    curr = curr->m_next;
    delete m_head;
  }
  m_head = nullptr; //Resets m_head to nullptr
  m_tail = nullptr; //Resets m_tail to nullptr
  m_size = 0; //Resets m_size = 0
}

void LinkedList::insert_begin(int data){ //Creates and inserts new node at the beginning of the linked list
  Node *newNode = new Node();
  newNode->m_info = data; //Sets data in node
  newNode->m_next = m_head; //Points new node to what m_head is pointing at
  m_head = newNode; //Points m_head to new node
  if(m_size == 0){ //If first node, sets m_tail to the first node
    m_tail = newNode; //Sets m_tail pointer to point at new node
  }
  m_size++; //Increments size

}

void LinkedList::removeAt(int location){ //Should iterate to location (m_head is 0) and remove that node
  Node *curr = m_head;
  Node *prev = m_head;
  int counter = 0;
  while(curr != nullptr){ //Iterates through linked list
    if(counter == location){ //Checks to see if node count matches location
      prev->m_next = curr->m_next; //Bypasses node to be removed
      m_size--;
      //Error 3: Memory Leak
      //Correction: Need to delete the pointer curr to avoid memory leak
      delete curr;
      return;
    }
    prev = curr;
    curr = curr->m_next;
    counter++;
  }
  
  if(m_size == 0){ //If the linked list is empty, resets linked list pointers
    m_head = nullptr;
    m_tail = nullptr;
  }
}

void LinkedList::display(){ //Iterates through linked list and displays the data in each node
  if((m_size == 0) || (m_head == nullptr)){ //Can't display if no nodes exist
    cout << "No nodes to display" << endl;
    return;
  }else{
    cout << "Your linked list has " << m_size << " nodes." << endl;
    Node *curr = m_head;
    while(curr != nullptr){
      //Error 2: Segmentation Fault
      //Correction: swaped these two lines
      //Program received signal SIGSEGV, Segmentation fault.0x000000000040142f in LinkedList::display (this=0x7fffffffe190) at lab8.cpp:86
      //86	      cout << curr->m_info << "->";
      cout << curr->m_info << "->";
      curr = curr->m_next;
    }
    cout << "END" << endl;
  }
}

int main () {
  LinkedList list1; //Creates new linked list
  list1.insert_begin(10); //Creates and inserts new node with a value of 10
  list1.insert_begin(20); //Creates and inserts new node with a value of 20
  list1.insert_begin(30); //Creates and inserts new node with a value of 30
  list1.display(); //Displays the linked list
  list1.removeAt(1); //Removes the node with the value of 20 (position 1)
  list1.display(); //Displays the linked list
  return 0;
}

