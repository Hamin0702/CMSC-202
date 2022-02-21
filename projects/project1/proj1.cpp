//  File: proj1.cpp
//  Project: CMSC 202 Project 1, Fall 2020
//  Author: Hamin Han
//  Date: 9/15/2020
//  Section: 202/30
//  Email: haminh1@umbc.edu
//
//  This file contains the main method and everything else for Project 1.
//  This program reads a text file and plays a game of Escalators.
//  It will tell the user if the file is valid or invalid.
//  It will tell the user why it's invalid as well.
//  If the user puts in an invalid input, it will tell the user to try again.
//  The program follows specific coding requirements specified in the project descriptions,
//  for example, it uses at lest 5 functions, it uses one multidimensional array,
//  passes an array to a function, does not use global variables, uses input validation,
//  uses do..while loop, and uses constants as needed.

#include <iostream>
#include <fstream>
using namespace std;

// Function prototypes
bool loadFile(string nameFile, string words[]);
void printWords(string words[]);
void clearList(string words[],int letters[][26]);
void countLetters(string words[],int letters[][26]);
void checkAnswer(string words[],int letters[][26]);
bool checkFrequency(int letters[][26]);

// The main method that plays the Escalator game
int main() {
    const int ALPHABET = 26;
    string wordList[] = {"","",""};
    int letterCount[3][ALPHABET] = {0};
    string fileName = "";
    string next = "";
    
    cout << "Welcome to Escalators" << endl;
    
    // The loop continues as long as the user wants to check another file
    do {
        
        // First part, reads the file given by the user input
        cout << "What is the file name of the list of words?" << endl;
        cin >> fileName;
        
        // Calls the functions to check if the words in the file is valid according to rules of Escalators
        // Does not need any cout statements since everything is being printed out by the functions.
        if(loadFile(fileName,wordList)){
            printWords(wordList);
            countLetters(wordList, letterCount);
            checkAnswer(wordList, letterCount);
        }
        
        // Asks the user if there is another file to check
        // Loops again if the user input is invalid
        do{
            cout << "Check another list? (y/n)" << endl;
            cin >> next;
            if(next!="y" && next!="n")
                cout << "invalid input, try again" << endl;
        } while(next!="y" && next!="n");
        
        // Resets all values of the arrays (wordList and letterCount)
        clearList(wordList, letterCount);
        
    } while (next == "y");
    
    cout << "Thank you for using Escalators" << endl;
    
    return 0;
}

//-----------------------------------------------------------
// Name: loadFile
// Precondition: the user enters the name of the file
// Postcondtion: if it is a valid file, it adds the words in
//  the file to the array "list" which modifies the "wordList"
//  array.
//-----------------------------------------------------------
bool loadFile(string nameFile, string list[]) {
    ifstream inFile;
    inFile.open(nameFile);
    
    // If the file does not exist, it tells the user and immediately returns false
    if(inFile.fail()) {
        cerr << "No file found" << endl;
        return false;
        
    // If the file is acceptable, add all three words to the array
    }else{
        for(int i = 0; i < 3; i++){
            inFile >> list[i];
        }
        return true;
    }
}

//-----------------------------------------------------------
// Name: printWords
// Precondition: the array words contains 3 words
// Postcondtion: prints out the list of words and their length
//-----------------------------------------------------------
void printWords(string words[]) {
  cout << "1. " << words[0] << " (" << (int) words[0].length() << " letters)" << endl;
  cout << "2. " << words[1] << " (" << (int) words[1].length() << " letters)" << endl;
  cout << "3. " << words[2] << " (" << (int) words[2].length() << " letters)" << endl;
}

//-----------------------------------------------------------
// Name: clearList
// Precondition: the function needs to get past both of the
//  arrays for the words and the letters
// Postcondtion: resets all the values of the array so that
//  a new file can be read
//-----------------------------------------------------------
void clearList(string words[],int letters[][26]) {
    words[0] = "";
    words[1] = "";
    words[2] = "";
    for(int i = 0; i < 26; i++){
        letters[0][i] = 0;
        letters[1][i] = 0;
        letters[2][i] = 0;
    }
}

//-----------------------------------------------------------
// Name: checkAnswer
// Precondition: has to be passed both the arrays for the words
//  and letters as a parameter
// Postcondtion: checks if the list of words is valid and prints
//  out the results
//-----------------------------------------------------------
void checkAnswer(string words[],int letters[][26]){

    // Checks the lengths of the words
    if(words[0].length() != 6 || words[1].length() != 5 || words[2].length() != 4){
        cout << "Words are not correct length" << endl;
        cout << "This list is not valid!" << endl;
        
    // Checks if the letter frequency is correct by using the checkFrequency function
    }else if(!checkFrequency(letters)){
        cout << "Words do not share appropriate letter frequency" << endl;
        cout << "The list is not valid!" << endl;
        
    // If it passed all the tests, the list is valid
    }else{
        cout << "This list is valid!" << endl;
    }
}

//-----------------------------------------------------------
// Name: checkFrequency
// Precondition: has the array of letters of all three words
// Postcondtion: returns true if it is valid if there is
//  nothing wrong with the letter frequency, else returns invalid
//-----------------------------------------------------------
bool checkFrequency(int letters[][26]){
        int counter = 0;
    
        // Checks word frequency between the first word and the second word
        for(int i = 0; i < 26; i++){
            int temp = 0;
            temp = letters[0][i] - letters[1][i];
            if(temp != 0 && temp != 1)
                return false;
            if(temp == 1)
                counter++;
        }
    
        // There should only be a difference of frequency by 1
        // If it isn't 1, return false
        if(counter != 1){
            return false;
        }
        counter = 0;
        
        // Checks word frequency between the second word and the third word
        for(int i = 0; i < 26; i++){
            int temp = 0;
            temp = letters[1][i] - letters[2][i];
            if(temp != 0 && temp != 1)
                return false;
            if(temp == 1)
                counter++;
        }
    
        // There should only be a difference of frequency by 1
        // If it isn't 1, return false
        if(counter != 1){
            return false;
        }
        
        // Return true if nothing is wrong with the letter frequency of the words
        return true;
}
             
//-----------------------------------------------------------
// Name: countLetters
// Precondition: needs the 3 words from the file
// Postcondtion: sets up the array for letter frequency
//-----------------------------------------------------------
void countLetters(string words[],int letters[][26]){
  int wordOneLength = words[0].length();
  int wordTwoLength = words[1].length();
  int wordThreeLength =	words[2].length();
  
  // Sets up the letter frequency for the first word of the 2d array
  for(int i = 0; i < wordOneLength; i++){
        string temp = words[0];
        if(temp[i]=='a')
            letters[0][0]++;
        if(temp[i]=='b')
            letters[0][1]++;
        if(temp[i]=='c')
            letters[0][2]++;
        if(temp[i]=='d')
            letters[0][3]++;
        if(temp[i]=='e')
            letters[0][4]++;
        if(temp[i]=='f')
            letters[0][5]++;
        if(temp[i]=='g')
            letters[0][6]++;
        if(temp[i]=='h')
            letters[0][7]++;
        if(temp[i]=='i')
            letters[0][8]++;
        if(temp[i]=='j')
            letters[0][9]++;
        if(temp[i]=='k')
            letters[0][10]++;
        if(temp[i]=='l')
            letters[0][11]++;
        if(temp[i]=='m')
            letters[0][12]++;
        if(temp[i]=='n')
            letters[0][13]++;
        if(temp[i]=='o')
            letters[0][14]++;
        if(temp[i]=='p')
            letters[0][15]++;
        if(temp[i]=='q')
            letters[0][16]++;
        if(temp[i]=='r')
            letters[0][17]++;
        if(temp[i]=='s')
            letters[0][18]++;
        if(temp[i]=='t')
            letters[0][19]++;
        if(temp[i]=='u')
            letters[0][20]++;
        if(temp[i]=='v')
            letters[0][21]++;
        if(temp[i]=='w')
            letters[0][22]++;
        if(temp[i]=='x')
            letters[0][23]++;
        if(temp[i]=='y')
            letters[0][24]++;
        if(temp[i]=='z')
            letters[0][25]++;
    }
    
    // Sets up the letter frequency for the first word of the 2d array
  for(int i = 0; i < wordTwoLength; i++){
        string temp = words[1];
        if(temp[i]=='a')
            letters[1][0]++;
        if(temp[i]=='b')
            letters[1][1]++;
        if(temp[i]=='c')
            letters[1][2]++;
        if(temp[i]=='d')
            letters[1][3]++;
        if(temp[i]=='e')
            letters[1][4]++;
        if(temp[i]=='f')
            letters[1][5]++;
        if(temp[i]=='g')
            letters[1][6]++;
        if(temp[i]=='h')
            letters[1][7]++;
        if(temp[i]=='i')
            letters[1][8]++;
        if(temp[i]=='j')
            letters[1][9]++;
        if(temp[i]=='k')
            letters[1][10]++;
        if(temp[i]=='l')
            letters[1][11]++;
        if(temp[i]=='m')
            letters[1][12]++;
        if(temp[i]=='n')
            letters[1][13]++;
        if(temp[i]=='o')
            letters[1][14]++;
        if(temp[i]=='p')
            letters[1][15]++;
        if(temp[i]=='q')
            letters[1][16]++;
        if(temp[i]== 'r')
            letters[1][17]++;
        if(temp[i]=='s')
            letters[1][18]++;
        if(temp[i]=='t')
            letters[1][19]++;
        if(temp[i]=='u')
            letters[1][20]++;
        if(temp[i]=='v')
            letters[1][21]++;
        if(temp[i]=='w')
            letters[1][22]++;
        if(temp[i]=='x')
            letters[1][23]++;
        if(temp[i]=='y')
            letters[1][24]++;
        if(temp[i]=='z')
            letters[1][25]++;
    }
    
    // Sets up the letter frequency for the first word of the 2d array
    for(int i = 0; i < wordThreeLength; i++){
        string temp = words[2];
        if(temp[i]=='a')
            letters[2][0]++;
        if(temp[i]=='b')
            letters[2][1]++;
        if(temp[i]=='c')
            letters[2][2]++;
        if(temp[i]=='d')
            letters[2][3]++;
        if(temp[i]=='e')
            letters[2][4]++;
        if(temp[i]=='f')
            letters[2][5]++;
        if(temp[i]=='g')
            letters[2][6]++;
        if(temp[i]=='h')
            letters[2][7]++;
        if(temp[i]=='i')
            letters[2][8]++;
        if(temp[i]=='j')
            letters[2][9]++;
        if(temp[i]=='k')
            letters[2][10]++;
        if(temp[i]=='l')
            letters[2][11]++;
        if(temp[i]=='m')
            letters[2][12]++;
        if(temp[i]=='n')
            letters[2][13]++;
        if(temp[i]=='o')
            letters[2][14]++;
        if(temp[i]=='p')
            letters[2][15]++;
        if(temp[i]=='q')
            letters[2][16]++;
        if(temp[i]== 'r')
            letters[2][17]++;
        if(temp[i]=='s')
            letters[2][18]++;
        if(temp[i]=='t')
            letters[2][19]++;
        if(temp[i]=='u')
            letters[2][20]++;
        if(temp[i]=='v')
            letters[2][21]++;
        if(temp[i]=='w')
            letters[2][22]++;
        if(temp[i]=='x')
            letters[2][23]++;
        if(temp[i]=='y')
            letters[2][24]++;
        if(temp[i]=='z')
            letters[2][25]++;
    }
    
}
