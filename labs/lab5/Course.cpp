/******************************
** File: Course.cpp
** CMSC 202 Lab5, Fall 2020
** Author: Hamin Han
** Date: 9/28/20
** Section: 202/30
** Email: haminh1@umbc.edu
**
** This file contains Course.cpp which defines all the functions declared
** in the Course.h header file as well as having the dafault configuration for the constructor.
******************************/

#include "Course.h"
#include <iostream>
using namespace std;

//Constructor -- Already Implemented
Course::Course() {
  cout << "Creating a course..." << endl;
  m_courseName = "CMSC 202";
  m_sectionNum = 1;
  m_enrolledStudents = 50;
}

//Here is an example for a getter and a setter

// Returns number of students
int Course::getEnrolledStudents() {
  return m_enrolledStudents;
}

// Sets new number of students
void Course::setEnrolledStudents(int numStudents) {
  //If number of students is negative, set to 0.
  if (numStudents < 0){
    m_enrolledStudents = 0;
  } else {
    m_enrolledStudents = numStudents;
  }
}

//**Student Requirement**
//Implement getters and setters for courseName and sectionNum here

// Return course name
string Course::getCourseName() {
    return m_courseName;
}

// Sets new course number
void Course::setCourseName(string nameCourse){
    m_courseName = nameCourse;
}

// Returns section number
int Course::getSectionNum() {
    return m_sectionNum;
}

// Sets new section number
void Course::setSectionNum(int numSection) {
    m_sectionNum = numSection;
}


//**Student Requirement**
//Custom Functions -- Implement checkLarge and dropStudent

// Checks how many students are enrolled
// Say large course if more than 40 students, or small course
void Course::checkLarge() {
    if(getEnrolledStudents() > 40) {
        cout << getCourseName() << " Section " << getSectionNum() << " is a large course!" << endl;
    }else{
        cout << getCourseName() << " Section " << getSectionNum() << " is a small course!" << endl;
    }
}

// Drop one student and return true if there are students enrolled,
// return false if there are no students
bool Course::dropStudent() {
    if(getEnrolledStudents() > 0) {
        setEnrolledStudents(getEnrolledStudents() - 1);
        return true;
    }else{
        return false;
    }
}
