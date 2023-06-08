#include <iostream>
#include "music.h"
using namespace std;

/*
  Creator: Helen Wang
  Date: Nov 22, 2022
  Program: cpp file for music child class.
 */

music::music(char*t, char*a, int y, int d, char*p):Media(t,y) {
  //cout << "music contructor" << endl;
  //Creating and setting music variables
  artist = new char[20];
  strcpy(artist, a);

  duration = d;

  publisher = new char[20];
  strcpy(publisher, p);
}

//Music destructor
music::~music() {
  delete[] artist;
  delete[] publisher;
}

//Get artist
char* music::getArtist() {
  return artist;
}

//Get publisher
char* music::getPublisher() {
  return publisher;
}

//Get duration
int music::getDuration() {
  return duration;
}

//Print contents of music
void music::printM() {
  cout << "Music" << endl;
  Media::printM();
  cout << "Artist: " << artist << endl;
  cout << "Duration: " << duration << endl;
  cout << "Publisher: " << publisher << endl;
}
