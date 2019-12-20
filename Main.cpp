//MAIN
#include "Node.h"
#include "Student.h"
#include <iostream>
#include <cstring>
#include <iterator>
#include <iomanip>

using namespace std;
//12/9/19 Maggie Bao This is a program of sadness.
void add(Node* &head, Node* node, Student* student);
void print(Node* node);
void remove(Node* &head, Node* node, int id);

//if null checks if there is anything in the memory

int main() {
  Node* head = NULL;
  cout << "Beginning Additions" << endl;
  Student* Kevin = new Student("Kevin", "Park", 405249, 1.23);
  add(head, head, Kevin);
  print(head);
  cout << endl;
  Student* Emma = new Student("Emma", "Shu", 123456, 4.99);
  add(head, head, Emma);
  print(head);
  cout << endl;
  Student* Rita = new Student("Rita", "Thammakhoune", 334455, 5.00);
  add(head, head, Rita);
  print(head);
  cout << endl;
  cout << "Beginning Deletions"<< endl;
  remove(head, head, 405249);
  cout << endl;
  print(head);
  remove(head, head, 123456);
  cout << endl;
  print(head);
  cout << endl;
  remove(head, head, 334455);
  return 0;
}

void add(Node* &head, Node* node, Student* student){
  if (node == NULL){
    Node* current = new Node(student);
    head = current;
    return;
  }
  if (node->getNext() == NULL){
    Node* current = new Node(student);
    node->setNext(current);
    return;
  }
  add(head, node->getNext(), student);
}

void print(Node* node){
  if (node == NULL){
    return;
  }
  node->getStudent()->print();
  print(node->getNext());
}

void remove(Node* &head, Node* node, int id){
  if (node->getStudent()->getId() == id){
    if (node == head) {
      Node* temp = head;
      head = head->getNext();
      delete temp;
      cout << "Student Removed." << endl;
      return;
    }
  }
 if (node->getNext()->getStudent()->getId() == id) {
    node->setNext(node->getNext()->getNext());
    delete node->getNext();
    cout << "Student Removed." << endl;
    return;
  }
  remove(head, node->getNext(), id);
}
