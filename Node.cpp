//NODE.CPP FILE
#include "Node.h"
#include <iostream>
using namespace std;

Node :: Node(Student* newstudent){
  student = newstudent;
  next = NULL;
}

Node :: ~Node(){
  delete student;
  next = NULL;
}

void Node :: setNext(Node* newnext){
  next = newnext;
}

Node* Node :: getNext(){
  return next;
}

Student* Node :: getStudent(){
  return student;
}

