#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;

class Student{
 public:
  Student();
  Student(char* newName);

  char* getName();
 private:
  char* name;
};
#endif
