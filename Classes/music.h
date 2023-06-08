#ifndef MUSIC_H
#define MUSIC_H
#include <iostream>
#include <cstring>
#include "Media.h"
using namespace std;

/*
  Creator: Helen Wang
  Date: Nov 22, 2022
  Program: Header file for music child class.
 */

class music:public Media {
 public:
  music(char*t, char*a, int y, int d, char*p);
  ~music();

  //Intializing variabes & declaring functions
  char* artist;
  virtual char* getArtist();

  int duration;
  virtual int getDuration();

  char* publisher;
  virtual char* getPublisher();

  virtual void printM();
};

#endif
