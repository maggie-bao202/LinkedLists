//MAIN
#include "Node.h"
#include "Student.h"
#include <iostream>
#include <cstring>
#include <iterator>
#include <iomanip>

using namespace std;
/*12/9/19 Author: Maggie Bao Description: This is a program of sadness. Program prints out the list of students while adding a new student each time, then removes them one by one, printing out the list in between.*/

//function prototypes
void add(Node* &head, Node* node, Student* student);
void print(Node* node);
void remove(Node* &head, Node* node, int id);

int main() {
  Node* head = NULL;
  //add student
  cout << "Beginning Additions..." << endl;
  Student* Kevin = new Student("Kevin", "Park", 405249, 1.23); //declare initialize new student
  add(head, head, Kevin); //add student to add function
  print(head); //print out the nodes in student list
  cout << endl;
  Student* Emma = new Student("Emma", "Shu", 123456, 4.99);
  add(head, head, Emma);
  print(head);
  cout << endl;
  Student* Rita = new Student("Rita", "Thammakhoune", 334455, 5.00);
  add(head, head, Rita);
  print(head);
  cout << endl;
  cout << endl;

  //remove student
  cout << "Beginning Deletions..."<< endl;
  remove(head, head, 405249);//pass id through remove function to delete the student
  cout << endl;
  print(head);
  remove(head, head, 123456);
  cout << endl;
  print(head);
  cout << endl;
  remove(head, head, 334455);
  return 0; //program ends
}

void add(Node* &head, Node* node, Student* student){
  if (node == NULL){ //if node pointer does not exist
    Node* current = new Node(student); //make student the current node pointer
    head = current; //make current the head
    return;
  }
  if (node->getNext() == NULL){//if next node pointer does not exist
    Node* current = new Node(student);
    node->setNext(current); //set next node pointer as the current
    return;
  }
  add(head, node->getNext(), student); //recursive function returns itself
}

void print(Node* node){
  if (node == NULL){
    return;
  }
  node->getStudent()->print();//print out the node from the student function
  print(node->getNext()); //recursive function
}

void remove(Node* &head, Node* node, int id){
  if (node->getStudent()->getId() == id){
    if (node == head) {
      Node* temp = head; 
      head = head->getNext();
      delete temp; //clear memory
      cout << "Student Removed." << endl;
      return;
    }
  }
 if (node->getNext()->getStudent()->getId() == id) {
    node->setNext(node->getNext()->getNext());
    delete node->getNext(); //clear memory
    cout << "Student Removed." << endl;
    return;
  }
 remove(head, node->getNext(), id); //recursive function
}
