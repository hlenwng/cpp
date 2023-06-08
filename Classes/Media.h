#ifndef MEDIA_H
#define MEDIA_H
#include <iostream>
#include <cstring>
using namespace std;

/*
  Creator: Helen Wang
  Date: Nov 22, 2022
  Program: Header file for media parent class.
 */

class Media {
 public:
  Media();

  //Intializing variables & declaring functions
  Media(char*t, int y);
  virtual ~Media();
  char* title;
  virtual char* getTitle();

  int year;
  virtual int getYear();

  virtual void printM();
};

#endif
