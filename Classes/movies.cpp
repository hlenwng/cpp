#include <iostream>
#include "movies.h"
using namespace std;

/*
  Creator: Helen Wang
  Date: Nov 22, 2022
  Program: cpp file for movies child class.
 */

movies::movies(char*t, char*di, int y, int d, int r):Media(t,y) {
  //cout << "movies constructor" << endl;
  //Creating and setting movies variables
  director = new char[20];
  strcpy(director, di);

  duration = d;
  rating = r;
}

//Movies destructor
movies::~movies() {
  delete[] director;
}

//Get director
char* movies::getDirector() {
  return director;
}

//Get duration
int movies::getDuration() {
  return duration;
}

//Get rating
int movies::getRating() {
  return rating;
}

//Print contents of movie
void movies::printM() {
  cout << "Movies" << endl;
  Media::printM();
  cout << "Director: " << director << endl;
  cout << "Duration: " << duration << endl;
  cout << "Rating: " << rating << endl;
}
