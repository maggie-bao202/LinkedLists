//STUDENT HEADER FILE; all functions and variables of Student class are declared
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

class Student {
 public://functions of Student.h, function prototype format
  Student(char* newfname, char* newlname, int newid, float newgpa);//Constructor
  ~Student();//destructor
  char* getFname();//get first name
  char* getLname();//get last name
  int getId();//get student id
  float getGPA();//get student gpa
  void print();//print out the student information
  
 private: //variables are private
  char* fname;
  char* lname;
  int id;
  float gpa;
};
#endif
