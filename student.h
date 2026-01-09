#ifndef student_H
#define student_H

#include <iostream>
#include <cstring>

using namespace std;

//student class
class student{
 public:
  student(float inGPA, char* inName, int inID); //set GPA and name

  char* getName(); //retrieve name
  float getGPA(); //retrieve gpa
  int getID(); //retrieve ID

  char* name;
  float gpa;
  int id;
};

#endif
