#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
#include <iterator>
using namespace std;

/*
  Title: Student List
  Name: Helen Wang
  Date: Oct 17, 2022
  Program: User can add and delete students from data base, and print out all students.
  Includes student first & last name, id# and gpa.
  */

//Intialize Struct
struct Student {
  char firstName[10];
  char lastName[10];
  int id;
  float gpa;
};

//Intialize functions
void ADD(vector<Student*>& info, int &number);
void PRINT(vector<Student*>& info);
void DELETE(vector<Student*>& info, int &number);

int main() {
  //Intialize variables
  int number = 0;
  bool stillPlaying = true;
  string apd;
  vector<Student*> info;
  vector<Student*>::iterator it;

  //While user still wants to run the program
  while (stillPlaying == true) {

    //User chooses to add, print, delete or quit
    cout << "ADD, PRINT, DELETE or QUIT" << endl;
    cin >> apd;
    cin.ignore();
    
    if (apd == "ADD" || apd == "add") {
      ADD(info, number);
    } else if (apd == "PRINT" || apd == "print") {
      PRINT(info);
    } else if (apd == "DELETE" || apd == "delete") {
      DELETE(info, number);
    } else if (apd == "QUIT" || apd == "quit") {
      stillPlaying = false;
    } else {
      cout << "Enter in a valid command: " << endl;
    }
  }
  return 0;
}

//User can add a student to list
void ADD(vector<Student*>& info, int &number) {
  //Add a new Student struct
  Student* stu = new Student(); 

  //Add first name to vector
  char fname[10];
  cout << "Enter first name: ";
  cin.getline (fname, 10);
  strcpy(stu->firstName, fname);
      
  //Add last name to vector
  char lname[10];
  cout << "Enter last name: ";
  cin.getline (lname, 10);
  strcpy(stu->lastName, lname);  
  
  //Add ID number to vector
  int id;
  cout << "Enter id : ";
  cin >> id;

  //Make sure student id is unique 
  for (int i = 0; i < info.size(); i++) {
    while (id == info[i]->id) {
      cout << "Please enter a new ID number: " << endl;
      cin >> id;
    }
  }
  stu->id = id;
  
  // Add GPA to vector
  float gpa;
  cout << "Enter gpa: ";
  cin >> gpa;
  stu-> gpa = gpa;
  info.push_back(stu);
  
  cout << endl;
  number++;
}

//User can print out all existing students' info
void PRINT(vector<Student*>& info) {
  vector<Student*>::iterator it;

  //Check if there are any students to print in database
  if (info.size() == 0) {
    cout << "There are no students in database" << endl;
  }

  //Set gpa decimal point to hundredths place
  cout.setf(ios::fixed, ios::floatfield);
  cout.setf(ios::showpoint);
  cout.precision(2);

  //Prints out all of one student's info, and then moves on to next student
  for (it = info.begin(); it != info.end(); it++) {
    cout << (*it)-> firstName << " ";
    cout << (*it)-> lastName << " ";
    cout << ", ";
    cout << (*it)-> id << " ";
    cout << ", ";
    cout << (*it)-> gpa << " ";
    cout << endl;
  }
  cout << endl;
}

//User can delete a student from database
void DELETE(vector<Student*>& info, int &number) {
  int student;
  int ridStu = 0;
  bool exist = false;
  cout << "Enter in the ID of the student you'd like to delete" << endl;
  cin >> ridStu;

  //Make sure that student exists (from id#)
  for (int i = 0; i < info.size(); i++) {
    if(ridStu == info[i]-> id) {
      student = i;
      exist = true;
      number--;
    }
  }

  //If student does exist, delete them from database
  if (exist == true) {
    info.erase(info.begin() + student);
    cout << "Student id# " << ridStu << " has been deleted" << endl;
  } else { //If student doesn't exist, have them enter a valid id#
    cout << "This student id# doesn't exist, please enter in a valid id#" << endl;
    cin >> ridStu;
  }

  cout << endl;
}
