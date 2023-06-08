#include <iostream>
#include <string>
#include "Media.h"
using namespace std;

/*
  Creator: Helen Wang
  Date: Nov 22, 2022
  Program: cpp file for media parent class.
 */

Media::Media() {
  title = new char[60];
}

//Creating and setting media variables
Media::Media(char*t, int y) {
  title = new char[60];
  strcpy(title, t);
  year = y;
}

//Media destructor
Media::~Media() {
  delete[] title;
}

//Get title
char* Media::getTitle() {
  return title;
}

//Get year
int Media::getYear() {
  return year;
}

//Print contents of media
void Media::printM() {
  cout << "Title: " << title << endl;
  cout << "Year: " << year << endl;
}
