#ifndef VGAMES_H
#define VGAMES_H
#include <iostream>
#include <cstring>
#include "Media.h"
using namespace std;

/*
  Creator: Helen Wang
  Date: Nov 22, 2022
  Program: Header file for videogame child class.
 */

class vgames:public Media {
public:
  vgames(char*t, int y, char*p, int r);
  ~vgames();

  //Intializing variabes & declaring functions
  char* publisher;
  virtual char* getPublisher();

  int rating;
  virtual int getRating();

  virtual void printM();
  
};

#endif
