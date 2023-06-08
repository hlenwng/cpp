/*
  Using code of Jason Randolph
 */

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "student.h"
using namespace std;

class Node {
 public:
  Node(Student*);
  ~Node();
  void setNext(Node* nextNode);
  Node* getNext();
  Student* getStudent();
 private:
  Student* student;
  Node* next;
};

#endif
