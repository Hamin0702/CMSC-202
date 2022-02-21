/*
** File: lab1.cpp
** Project: CMSC 202 Lab 1, Fall 2020
** Author: Hamin Han
** Date: 9/7/2020
** Section 202 - 30
** haminh1@umbc.edu
**
** lab1 asks the user for their dog's name (storing it as a c-string)
** and the dog's age (as an integer)
** The user can choose to pet the dog, feed the dog, or chase the dog
**
** If the user inputs invalid values, it will prompt the user again
** After any three choices, the program should exit
**
**
**
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
  int age = 0;
  string name = "";
  int choice = 0;

  cout << "What is your dog's name?" << endl;
  cin >> name;

  do{
    cout << "How old is your dog?" << endl;
    cin >> age;
  
    if(age < 0 || age > 22){
      cout << "Must be between 0 and 22" << endl;
    }else{
      cout << '\n' << endl;
    }
  }while(age < 0 || age > 22);

  cout << "Dog name = " << name << endl;
  cout << "Dog age = " << age << '\n' << endl;

  int counter = 3;
  while(counter > 0){
    cout << "What would you like to do?" << endl;
    cout << "1. Pet " << name << endl;
    cout << "2. Feed " << name << endl;
    cout << "3. Chase " << name << endl;
    
    do{
      cout << "Enter your choice (1-3):" << endl;
      cin >> choice;

      
      if(cin.fail()){
        cin.clear();
	cin.ignore();
       	cout << "INVALID" << endl;
	choice = 0;
      }
      
      
      if(choice < 1 || choice > 3){
       	cout << "Try again (1-3)" << '\n' << endl;
      }
      if(choice == 1){
	cout << name << " growls gently as you pet them." << '\n' << endl;
      }
      if(choice == 2){
	cout << name << " is full and happy." << '\n' << endl;
      }
      if(choice == 3){
	cout << name << " runs and plays with you." << '\n' << endl;
      }
    }while(choice < 1 || choice > 3);
    
    counter = counter -1;
  }
  cout << "That is enough for today. Goodbye." << endl;
  
  return 0;
}
