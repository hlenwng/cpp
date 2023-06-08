#include "student.h"
#include "node.h"
#include <iostream>
using namespace std;

/*
  Name: Helen Wang
  Date: Jan 27, 2023
  Program: cpp file for student class.
 */

Student::Student(char*fn, char*ln, int i, float g) {
  firstName = new char[20];
  strcpy (firstName, fn);
  lastName = new char[20];
  strcpy (lastName, ln);

  id = i;
  gpa = g;
  //  cout << "It works!";
  
}

/*
Student::~Student() {
  delete[] firstName;
  delete[] lastName;
  }*/

char* Student::getFirstName() {
  return firstName;
}

char* Student::getLastName() {
  return lastName;
}

int Student::getID() {
  return id;
}

float Student::getGPA() {
  return gpa;
}

void Student::printS() {
  cout.setf(ios::fixed, ios::floatfield);
  cout.setf(ios::showpoint);
  cout.precision(2);
  //  cout << "Student info: " << endl;
  cout << "First name: " << firstName << endl;
  cout << "Last name: " << lastName << endl;
  cout << "ID: " << id << endl;
  cout << "GPA: " << gpa << endl;
  cout << endl;
}
