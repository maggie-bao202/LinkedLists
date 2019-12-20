//STUDENT.CPP FILE
#include "Student.h"
#include <iostream>

using namespace std;

Student :: Student(char* newfname, char* newlname, int newid, float newgpa){//constructor
  fname = newfname;
  lname = newlname;
  id = newid;
  gpa = newgpa;
}

Student :: ~Student(){//have to do with string initialization, removing char array lines fixes "abort" error
  //delete fname;
  //delete lname;
}

//getters
char* Student :: getFname(){
  return fname;
}

char* Student :: getLname(){
  return lname;
}

int Student :: getId(){
  return id;
}

float Student :: getGPA(){
  return gpa;
}

void Student :: print(){//prints student information
  cout << fname << " " << lname << "," << id << "," << gpa << endl;
}
