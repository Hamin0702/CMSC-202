/*
File: lab3.cpp
Project: CMSC 202 Lab 3, Fall 2020
Author: Hamin Han
Date: 9/14/20
Section: 202/30
Email: hamih1@umbc.edu

This code will take user inputs and store it as an array of integers.
And with the array, it will:
Display all entered values,
Find the smallest number, largest number, and the average number and display all of it.
*/

#include <iostream>
using namespace std;

//smallestNum: returns the smallest number within the array
int smallestNum(int[], int);
//largestNum: returns the largest number within the array
int largestNum(int[], int);
//avgNum: returns the average (or the mean) of the array
int avgNum(int[], int);

int main(){
  const int MAXSIZE = 100;      //Constant maximum size of the array
  int myArray[MAXSIZE] = {0};   //Initializes the values of the array to 0's (default number)
  int currSize = 0;      //Keeps track of current size of the array
  int inputValue;       //Used to get the input in order to store it in the array

  //Code up the user's input, print out the array and then call the functions and return the expected output
  cout << "Enter a value (0 when done): ";
  cin >> inputValue;

  while(inputValue > 0 && currSize < 100) {
    myArray[currSize] = inputValue;
    currSize++;
    
    cout << "Enter a value (0 when done): ";
    cin >> inputValue;
  }

  cout << "Original Array: ";
  for(int i = 0; i < currSize; i++){
    cout << myArray[i] << " ";
  }
  cout << endl;

  cout << "Smallest number in the array: " << smallestNum(myArray,currSize) << endl;
  cout << "Largest number in the array: " << largestNum(myArray,currSize) << endl;
  cout << "Average number in the array: " << avgNum(myArray,currSize) << endl;

  
  return 0;
}

//implement smallestNum function
int smallestNum(int array[], int size){
  int currentMin = array[0];
  for (int i = 1; i < size; i++){
    if(array[i] < currentMin)
      currentMin = array[i];
  }
  return currentMin;
}
//implement largestNum function
int largestNum(int array[], int size){
  int currentMax = array[0];
  for (int i = 1; i < size; i++){
    if(array[i] > currentMax)
      currentMax = array[i];
  }
  return currentMax;
}
//implement avgNum function
int avgNum(int array[], int size){
  int avgNum = 0;
  for (int i = 0; i < size; i++){
    avgNum = avgNum + array[i];
  }
  avgNum = avgNum/size;
  return avgNum;
}
