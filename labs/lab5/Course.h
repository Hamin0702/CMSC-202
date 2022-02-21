/******************************
** File: Course.h
** CMSC 202 Lab5, Fall 2020
** Author: Hamin Han
** Date: 9/28/20
** Section: 202/30
** Email: haminh1@umbc.edu
**
** This file contains Course.h, which is the header file of Lab5.
** It declares all the member variables and functions specified by the document.
******************************/

#ifndef COURSE_H //Header or Include Guards
#define COURSE_H //Header or Include Guards

#include <iostream>
#include <string>
using namespace std;

class Course {
public:
    //Default constructor, already implemented.
    Course();

    //**Student Requirement**
    //Do the prototype for each of the functions described in the lab document

    //Returns name of the course
    string getCourseName();

    //Sets name of the course
    void setCourseName(string nameCourse);

    //Returns the course's section number
    int getSectionNum();

    //Sets the course's section number
    void setSectionNum(int numSection);

    //Returns course's enrolled students
    int getEnrolledStudents();

    //Sets course's enrolled students
    void setEnrolledStudents(int numStudents);

    //Outputs whether the course is large or not
    void checkLarge();

    //Removes one student from the course
    bool dropStudent();

private:
    //**Student Requirement**
    //Create the member variables below as described in the lab document
    //name of course
    string m_courseName;
    //section number
    int m_sectionNum;
    //enrolled students
    int m_enrolledStudents;
};

#endif //End of Header Guard
