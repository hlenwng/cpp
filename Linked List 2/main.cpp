#include "student.h"
#include "node.h"
#include <iostream>
#include <cstring>
using namespace std;

/*
  Title: Linked List pt 2
  Name: Helen Wang
  Date: Jan 27, 2023
  Program: User creates a linked list storing student's info (first/last name, id#, gpa),
  with options to add, delete, print out students, average the GPA's, and quit the program.
 */

//Intialize functions
void ADD(Node* current, Node* pre, Student* newStu, Node* &head);
void PRINT(Node* head);
void DELETE(Node* current, Node* pre, int id, Node* &head);
void AVERAGE(Node* current, Node* head, int count, float average);

int main() {
  //Intialize variables
  Node* head = NULL;
  Node* current = head;
  bool playing = true;
  char asd[10];
  
  while (playing == true) {

    //User chooses to add, print, delete, average or quit
    cout << "ADD, PRINT, DELETE, AVERAGE or QUIT" << endl;
    cin.get(asd, 10, '\n');
    cin.ignore();

    //Allows for all letter cases
    for (int i = 0; i < strlen(asd); i++) {
      asd[i] = toupper(asd[i]);
    }

    //User chooses to add, search for or delete media, or to quit program     
    if (strcmp(asd, "ADD") == false) {
      char* first = new char[20];
      char* last = new char[20];
      int id = 0;
      float gpa = 0.0;

      cout << "first name: ";
      cin.getline(first, 20);
      
      cout << "last name: ";
      cin.getline(last, 20);
      
      cout << "id #: ";
      cin >> id;
      
      cout << "gpa: ";
      cin >> gpa;
      cin.ignore();

      Student* newStu = new Student(first, last, id, gpa);
      cout << endl;
      
      ADD(head, head, newStu, head);
    }
    else if (strcmp(asd, "PRINT") == false) {
      PRINT(head);
    }
    else if (strcmp(asd, "DELETE") == false) {
      cout << "Enter in the id of the student you'd like to delete: " << endl;
      int delid = 0;
      cin >> delid;
      cin.ignore();
      
      cout << "You're deleting: " << delid << endl;
      
      DELETE(head, head, delid, head);
    }
    else if (strcmp(asd, "AVERAGE") == false) {
      AVERAGE(head, head, 0, 0);
    }
    else if (strcmp(asd, "QUIT") == false) {
      playing = false;
    }
    else {
      cout << "Enter in a valid command: " << endl;
    }

  }
  return 0;
}

//Add a new student, allocate a new Node spot
void ADD(Node* current, Node* pre, Student* newStu, Node* &head) {

  //If list is empty
  if (head == NULL) {
    head = new Node(newStu);
    //Node* current = head;
  }

  //If new student has largest number
  else if(current == NULL) {
    pre->setNext(new Node(newStu));
  }

  //If id is smaller than head
  else if (newStu->getID() <= head->getStudent()->getID()) {
    Node* temp = head; 
    head = new Node(newStu);
    head->setNext(temp);
  }
  
  //If id is bigger than head and smaller than next
  else if (newStu->getID() < current->getStudent()->getID()) {
    pre->setNext(new Node(newStu));
    pre->getNext()->setNext(current);  
  }
  
  //Recursion
  else {
    ADD(current->getNext(), current, newStu, head);
  }
}

//Print out all students in database
void PRINT(Node* head) {
  if (head == NULL) {
    cout << "Nothing in database" << endl;
  }
  else {
    cout << "Students: " << endl;
    cout << endl;
    if (head!= NULL) {
      head->getStudent()->printS();
      //recursion (calling itself)
      PRINT(head->getNext());
    }
  }
}

//Delete a given student (node) based on ID number
void DELETE(Node* current, Node* pre, int id, Node* &head) {
  if (head == NULL) {
    cout << "Nothing in database" << endl;
  }

  else if (current->getStudent()->getID() == id) {
    //If there's only one student in list
    if (head->getNext() == NULL) {
      delete current;
      head = NULL;
    }
    //If student is head
    else if (head == current) {
      current = head->getNext();
      delete head;
      head = current;
    }
    //If student isn't head
    else if (current != NULL) {
      Node* temp = current->getNext();
      delete current;
      current = temp;
    }
  }
  
  //Recursion
  else {
    DELETE(current->getNext(), current, id, head);
  }
}

//Average's all the students' GPAs
void AVERAGE(Node* current, Node* head, int count, float average) {
  if (head == NULL) {
    cout << "Nothing in database" << endl;
  }

  //Only one student in list
  else if (head->getNext() == NULL) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "Average GPA: " << current->getStudent()->getGPA() << endl;
    average = average + current->getStudent()->getGPA();
  }

  //More than one student in list
  else if (current == NULL) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "Total GPA: " << average << ", " << "# students: " << count << endl;
    cout << "Average GPA: " << average/count << endl;
  }
  else {
    count++;
    //Recursion
    AVERAGE(current->getNext(), head, count, average+current->getStudent()->getGPA());
  }
}
