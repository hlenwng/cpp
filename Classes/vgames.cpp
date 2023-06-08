#include <iostream>
#include "vgames.h"
using namespace std;

/*
  Creator: Helen Wang
  Date: Nov 22, 2022
  Program: cpp file for videogames child class.
 */

vgames::vgames(char*t, int y, char*p, int r):Media(t,y) {
  //cout << "vgames contructor" << endl;
  //Creating and setting videogame variables
  publisher = new char[20];
  strcpy(publisher, p);

  rating = r;
}

//Videogame Destructor 
vgames::~vgames() {
  delete[] publisher;
}

//Get publisher
char* vgames::getPublisher() {
  return publisher;
}

//Get rating
int vgames::getRating() {
  return rating;
}

//Print contents of videogame
void vgames::printM() {
  cout << "Videogame" << endl;
  Media::printM();
  cout << "Publisher: " << publisher << endl;
  cout << "Rating: " << rating << endl;
}
