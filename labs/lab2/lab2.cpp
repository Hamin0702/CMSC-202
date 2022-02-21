/*
** File: lab2.cpp
** Project: CMSC 202 Lab 2, Fall 2020
** Author: Hamin Han
** Date: 9/7/2020
** Section 202 - 30
** haminh1@umbc.edu
**
**
**
**
**
** There will be two functions, multiplyByThree() and divisibleByNine().
** With these two functions, we ask the user to input three numbers.
** By using the multiplyByThree() function, we multiply each of those numbers by three and add them all up.
** And we use divisibleByNine() to check if the sum is divisible by nine.
*/

#include <iostream>
#include <cmath>

using namespace std;

//function prototypes

// Name: multiplyByThree
// preCondition: it should get an integer as a parameter
// postCondition: returns the number multiplied by 3
int multiplyByThree(int num);

// Name: divisibleByNine
// preCondition: it should get an integer as a parameter
// postCOndition: returns a boolean based on whether or not the number is divisible by nine
bool divisibleByNine(int num);

int main() {

  int num1 = 0;
  int num2 = 0;
  int num3 = 0;
  int total = 0;

  cout << "Enter an integer: ";
  cin >> num1;
  cout << "Enter an integer: "; 
  cin >> num2;
  cout << "Enter an integer: "; 
  cin >> num3;

  total = multiplyByThree(num1) + multiplyByThree(num2) + multiplyByThree(num3);

  cout << "Total: " << total << endl;

  if(divisibleByNine(total)){
    cout << "The final value is divisible by 9." << endl;
  }else{
    cout << "The final value is not divisible by 9." << endl;
  }
		     
  return 0;
}

//Name: multiplyByThree
//Purpose: Given the number of integers to enter as a parameter, the function
//         will request the user to enter that many integers. The function
//         then multiplies the sum by 3 and displays that result. Finally,
//         the function returns the result.

int multiplyByThree(int num){
  return num * 3;
}

//Name: divisibleByNine()
//Purpose: Given an integer as a parameter, the function will say
//         if divisible by nine or not.

bool divisibleByNine(int num){
  if(num % 9 == 0)
    return true;
  return false;
}




























































