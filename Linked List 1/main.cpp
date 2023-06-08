#include <iostream>
#include <cstring>
#include "node.h"
#include "student.h"
using namespace std;

void add(char* name);
void print(Node* next);

Node* head = NULL;

int main() {

  char* name = new char[20];
  strcpy(name, "Fiona");
  Student* stu1 = new Student(name);
  strcpy(name, "Angie");
  Student* stu2 = new Student(name);
  strcpy(name, "Jimmy");
  Student* stu3 = new Student(name);
  
  Node* head = NULL;
  head = new Node(stu1);
  head->setStudent(stu1);
  cout << "Student names: ";
  cout << head->getStudent() << endl;

  Node* current = head;
  current->setNext(new Node(stu2));
  current->getNext()->setStudent(stu2);
  cout << "Student names: ";
  cout << head->getStudent() << ", " << head->getNext()->getStudent() << endl;

  current = current->getNext();
  current->setNext(new Node(stu3));
  current->getNext()->setStudent(stu3);
  cout << "Student names: ";
  cout << head->getStudent() << ", " << head->getNext()->getStudent() << ", " << head->getNext()->getNext()->getStudent() << endl;
    
  
  
}

/*
void add(char* name) {
  char* name = new char[20];
  Node* current = head;
  if (current == NULL) {
    head = new node();
    head->setStudent(name);
  }
  else {
    //iteration
    while (current->getNext() != NULL) {
      current = current->getNext();
    }
    current->setNext(new node());
    current->getNext()->setStudent(newStudent);
  }
}

void print(Node* next) {
  if (next == head) {
    cout << "Students: ";
  }
  if (next!= NULL) {
    cout << next->getStudent() << " ";
    //recursion (calling itself)
    print(next->getNext());
  }
}
*/
