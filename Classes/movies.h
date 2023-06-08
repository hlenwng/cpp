#ifndef MOVIES_H
#define MOVIES_H
#include <iostream>
#include <cstring>
#include "Media.h"
using namespace std;

/*
  Creator: Helen Wang
  Date: Nov 22, 2022
  Program: Header file for movies child class.
 */

class movies:public Media {
 public:
  movies(char*t, char*di, int y, int d, int r);
  ~movies();

  //Intializing variables & declaring functions
  char* director;
  virtual char* getDirector();

  int duration;
  virtual int getDuration();

  int rating;
  virtual int getRating();

  virtual void printM();
};

#endif
