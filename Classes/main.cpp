#include <iostream>
#include <cstring>
#include "vgames.h"
#include "music.h"
#include "movies.h"
#include "Media.h"
#include <vector>
using namespace std;

/*
  Title: Classes
  Creator: Helen Wang
  Date: Nov 22, 2022
  Program: User can add and delete different types of media (videogames, music & movies)
  from data base, and search for specific ones using the title or year.
  */

//Intialiaze functions
void ADD(vector<Media*>& list, int &number);
void SEARCH(vector<Media*>& list, int &number);
void DELETE(vector<Media*>& list, int &number);

int main() {
  //Intialize variables
  bool playing = true;
  char asd[8];
  int number = 0;
  vector<Media*> list;

  //While player is still playing
  while (playing == true) {
  
    cout << "ADD, SEARCH, DELETE or QUIT" << endl;
    cin.get(asd, 7, '\n');
    cin.ignore();
    
    //Allows for all letter cases
    for(int i = 0; i < strlen(asd); i++) {
      asd[i] = toupper(asd[i]);
    }

    //User chooses to add, search for or delete media, or to quit program
    if (strcmp(asd, "ADD") == false) {
      ADD(list, number);
    }
    else if (strcmp(asd, "SEARCH") == false) {
      SEARCH(list, number);
    }
    else if (strcmp(asd, "DELETE") == false) {
      DELETE(list, number);
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

//Add different media types
void ADD(vector<Media*>& list, int &number) {
  Media* med = new Media();
  char* mediaT = new char[11];
  
  cout << "What type of media? (videogames, music, or movies)" << endl;
  cin.get(mediaT, 11);

  
  //If user wants to add a videogame
  if (strcmp(mediaT, "videogames") == false) {
    cin.ignore();
    char* t = new char[20];
    int y;
    char* p = new char[20];
    int r;

    //Get all the needed information
    cout << "Title: ";
    cin.getline (t, 20);
    //cin.ignore();
    cout << "Year: ";
    cin >> y;
    cin.ignore();
    cout << "Publisher: ";
    cin.getline (p, 20);
    //cin.ignore();
    cout << "Rating: ";
    cin >> r;
    cin.ignore();
    
    //Add to list
    vgames* newVg = new vgames(t, y, p, r);
    list.push_back(newVg);
    number++;
    return;
  }

  //If user wants to add music
  else if (strcmp(mediaT, "music") == false) {
    cin.ignore();
    char* t = new char[20];
    char* a = new char[20];
    int y, r;
    char* p = new char[20];

    //Get all the needed information
    cout << "Title: ";
    cin.get(t, 20, '\n');
    cin.ignore();
    cout << "Artist: ";
    cin.get(a, 20, '\n');
    //cin.ignore();
    cout << "Year: ";
    cin >> y;
    cin.ignore();
    cout << "Rating: ";
    cin >> r;
    cin.ignore();
    cout << "Publisher: ";
    cin.get(p, 20, '\n');
    cin.ignore();
    
    //Add to list
    music* newMu = new music(t, a, y, r, p);
    list.push_back(newMu);
    number++;
    return;
  }

  //If user wants to add movies
  else if (strcmp(mediaT, "movies") == false) {
    cin.ignore();
    char *t = new char[20];
    char* di = new char[20];
    int y;
    int d;
    int r;

    //Get all the needed information
    cout << "Title: ";
    cin.getline(t, 20);
    cout << "Director: ";
    cin.getline(di, 20);
    cout << "Year: ";
    cin >> y;
    cin.ignore();
    cout << "Duration: ";
    cin >> d;
    cin.ignore();
    cout << "Rating: ";
    cin >> r;
    cin.ignore();

    //Add to list
    movies* newMo = new movies(t, di, y, d, r);
    list.push_back(newMo);
    number++;
    return;
  }

  //Invalid media type input
  else {
    cout << "Please enter in a valid media type" << endl;
  }
}



//User can search for previously added medias
void SEARCH(vector<Media*>& list, int &number) {
  int media;
  char* ty = new char[6];
  int iyear = 0;
  char ititle[20];
  cout << "Search by title or year?" << endl;
  cin.getline(ty, 6, '\n');
  
  //Search by media title
  if (strcmp(ty, "title") == false) {
    cout << "Title: " << endl;
    cin.getline(ititle, 20, '\n');

    //Compare inputted media title with all exsisting media titles
    for (int i = 0; i < list.size(); i++) {
      if(strcmp(ititle, list[i]->getTitle())== false) {
	cout << endl;
	list[i]->printM();
	cout << endl;
      }
    }
  }

  //Search by year
  else if (strcmp(ty, "year") == false) {
    cout << "Year: " << endl;
    cin >> iyear;
    cin.ignore();

    //Compare inputted media year with all exsisting media years
    for (int i = 0; i < list.size(); i++) {
      if(iyear == list[i]-> getYear()) {
	cout << endl;
	list[i]->printM();
	cout << endl;
      }
      //Media with those characteristics doesn't exist
      else {
	cout << "That media doesn't exist" << endl;
      }
    }
  }
}



//User can delete a previously added media
void DELETE(vector<Media*>& list, int &number) {
  int media;
  bool exist = false;
  char ty[6];
  char yn[4];
  int iyear = 0;
  char ititle[20];
  cout << "Search by title or year?" << endl;
  cin >> ty;
  cin.ignore();
  
  //Search for by title
  if (strcmp(ty,"title") == false) {
    cout << "Title: " << endl;
    cin.getline(ititle, 20, '\n');
    cin.ignore();
    
    //Compare title with exsisting ones
    for (int i = 0; i < list.size(); i++) {
      if(strcmp(ititle, list[i]->getTitle()) == false) {
	cout << endl;
	list[i]->printM();
	cout << endl;
	media = i;
	exist = true;
	number--;
      }
    }
  }

  //Search for by year
  else if (strcmp(ty, "year") == false) {
    cout << "Year: " << endl;
    cin >> iyear;
    cin.ignore();

    //Compare year with exsisting ones
    for (int i = 0; i < list.size(); i++) {
      if (iyear == list[i]->getYear()) {
	cout << endl;
	list[i]->printM();
	media = i;
	exist = true;
	number--;
      }
    }
  }

  //If media exists, delete
  if(exist == true) {
    cout << endl;
    cout << "You want to delete " << list[media]-> getTitle() << endl;
    cout << "Are you sure? (yes or no)" << endl;
    cin.getline(yn, 4, '\n');
    
    if (strcmp(yn, "yes") == false) {
      list.erase(list.begin() + media);
      cout << list[media]-> getTitle() << " has been deleted" << endl;  
      cout << endl;
    }
  }
}
