//NODE.CPP FILE
#include "Node.h"
#include <iostream>
using namespace std;

Node :: Node(Student* newstudent){//contructor
  student = newstudent;
  next = NULL;//must null next node
}

Node :: ~Node(){//destructor
  delete student;
  next = NULL;
}

void Node :: setNext(Node* newnext){//set next to current
  next = newnext;
}

//getters
Node* Node :: getNext(){
  return next;
}

Student* Node :: getStudent(){
  return student;
}

