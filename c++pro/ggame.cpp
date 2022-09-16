/*
 * User guesses a computer generated number (1-100), and the computer will tell user
 * if it is too high, low, or correct. If correct, it'll show how many guesses it took.
 * Then it will give the user an option to play again. 
 *
 * Author: Helen Wang
 * Sep 16, 2022
 *
 * Three rules for C++ class: No global variables, No strings, and include <iostream>
 * (not stdio).
 *
 */ 

#include <iostream> // include iostream library

using namespace std; // use standard namespace

int main() {
  bool stillPlaying = true;

  while (stillPlaying == true) {
    int randomNum, guess, numGuess = 0;
    char yn = 'y';
    srand(time(NULL)); // random number generator
    randomNum = (rand() % (100-1) +1); // number between 1-100
    cout << "Guessing Game " << endl;

    // keep guessing the number till it equals the random number 
    do {
      cout << "Guess a number between 1-100... " << endl;
      cin >> guess;
      numGuess++;

      if (guess < randomNum) {
	cout << "Too low! " << endl;
      } else if (guess > randomNum) {
	cout << "Too high! " << endl;
      } else {
	cout << "You got it right! It took you " << numGuess << " tries! " << endl;
      }
	
    } while (guess != randomNum);

	cout << "Do you want to play again? Y or N? " << endl;
	cin >> yn;

	if (yn == 'y' || yn == 'Y') {
	  stillPlaying = true;
	  continue; // breaks loop, returns to beginning
	} else {
	  stillPlaying = false;
	}

	return 0; // if program exectued successfully 
  }	  
}
