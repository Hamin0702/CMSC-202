/******************************
** File: lab5.cpp
** CMSC 202 Lab5, Fall 2020
** Author: Hamin Han
** Date: 9/28/20
** Section: 202/30
** Email: haminh1@umbc.edu
**
** This file contains lab5.cpp which creates two instances of Course and
** sets the initial values specified by the document and uses all the methods
** in Course.cpp to test the Course Class specified by the document.
******************************/



#include <iostream>
#include "Course.h"
using namespace std;

int main() {
    //**Student Requirement**
    //Part 1: Create 2 courses by instantiating them
    Course Course1;
    Course Course2;

    //**Student Requirement**
    //Part 2: Set their values for course name, section number, and enrolled students.
    Course1.setCourseName("Course 1");
    Course1.setSectionNum(100);
    Course1.setEnrolledStudents(0);
    cout << "\n";
    
    Course2.setCourseName("Course 2");
    Course2.setSectionNum(200);
    Course2.setEnrolledStudents(50);
    cout << "\n";

    //**Student Requirement**
    //Part 3: Output their information:  Name, section, and enrolled students
    cout << "Data of course1:\n";
    cout << "Course Name: " << Course1.getCourseName() << endl;
    cout << "Section: " << Course1.getSectionNum() << endl;
    cout << "Enrolled Students: " << Course1.getEnrolledStudents() << endl;
    cout << "\n";

    cout << "Data of course2:\n";
    cout << "Course Name: " << Course2.getCourseName() << endl;
    cout << "Section: " << Course2.getSectionNum() << endl;
    cout << "Enrolled Students: " << Course2.getEnrolledStudents() << endl;
    cout << "\n";

    //**Student Requirement**
    //Part 4: Call a custom function: Check if courses are large or not
    Course1.checkLarge();
    Course2.checkLarge();
    cout << "\n";

    //**Student Requirement**
    //Part 5: Update data members with custom function: Drop a student from each course
    //Display updated enrolled students
    cout << Course1.getCourseName() << ": ";
    if(!Course1.dropStudent()) {
        cout << "The course is already empty!" << endl;
    }else{
        cout << "Student successfully dropped the course!" << endl;
    }
    cout << "Remaining students: " << Course1.getEnrolledStudents() << endl;
    cout << "\n";
    
    cout << Course2.getCourseName() << ": ";
    if(!Course2.dropStudent()) {
        cout << "The course is already empty!" << endl;
    }else{
        cout << "Student successfully dropped the course!" << endl;
    }
    cout << "Remaining students: " << Course2.getEnrolledStudents() << endl;
    cout << "\n";

  return 0;
}

