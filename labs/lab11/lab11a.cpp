/******************************
** File: lab11a.cpp
** CMSC 202 Lab 10, Fall 2020
** Author: Hamin Han
** Date: 11/9/20
** Section: 202/30
** Email: haminh1@umbc.edu
**
** The lab11a.cpp file implements two templated functions.
** These two functions are used to compare two objects
** and output the result based on if the first variable is
** less than second variable.
******************************/

#include <iostream>
using namespace std;

// Use this file to implement two functions.
// Function 1: A templated function to display information about two variables
//             and the results of a function all to a templated IsLessThan function
//             Should display "10 < 5: (the result of IsLessThan)"
// Function 2: A templated IsLessThan function
//             IsLessThan function returns a bool:
//             true if a is less than b
//             false if a is greater than or equal to b
// Both functions take two args:
//   a: object of type T (where T is the templated class type)
//   b: object of type T (where T is the templated class type)
//


// Implement the templated IsLessThan function here:
// IsLessThan
// Compares the two objects and if a is less than b return 1 and 0 otherwise
template <class T>
int IsLessThan(T a, T b){
    if(a < b){
        return 1;
    }else{
        return 0;
    }
}

// Implement the templated DisplayInfo function here:
// DisplayInfo
// Outputs a message containing the results of the IsLessThan function
template <class T>
void DisplayInfo(T a, T b){
    cout << a << " < " << b << ": " << IsLessThan(a, b) << endl;
}

int main(){
  DisplayInfo(10,5);
  DisplayInfo(20,20);
  DisplayInfo(5,10);
  DisplayInfo('a','b');
  DisplayInfo(true,true);
  return 0;
}

