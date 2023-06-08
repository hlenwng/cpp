#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;

/*
  Name: Helen Wang
  Date: Jan 27, 2023
  Program: Header file for student class.
 */

class Student{
 public:
  Student();
  Student(char*fn, char*ln, int i, float g);

  char* getFirstName();
  char* getLastName();
  int getID();
  float getGPA();
  void printS();
 private:
  char* firstName;
  char* lastName;
  int id;
  float gpa;
};
#endif
