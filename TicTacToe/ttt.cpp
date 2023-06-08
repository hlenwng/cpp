# include <iostream>
# include <cstring>
using namespace std;

/*
  Name: Helen Wang
  Date: Oct 10, 2022
  Program: Two users can play tic tac toe in the console.
*/


// Declare constant variables
const int BLANK = 0;
const int X_MOVE = 1;
const int O_MOVE = 2;
const int X_TURN = 0;
const int O_TURN = 1;

// Declare functions
void printBoard(int board[3][3]);
void resetGame(int board[3][3]);
bool checkWin(int board[3][3], int player);
bool checkTie(int board[3][3]);

int main() {

  // Declare variables
  int board[3][3];
  int turn = X_TURN;
  int numXWins = 0;
  int numOWins = 0;
  int numTies = 0;
  bool stillPlaying = true;
  char input[3];
  char yon = 'y';

  // While player is still playing
  while (stillPlaying == true) {
    resetGame(board);
    
    // While no player has won, lost or tied yet
    while ((checkWin(board, X_MOVE) == false) && (checkWin(board, O_MOVE) == false) && (checkTie(board) == false)) {
      printBoard(board);
      cin.getline(input, 3);

      // If the user input is invalid
      if (!((input[0] >= 'a' && input[0] <= 'c') && (input[1] >= '1' && input[1] <= '3'))) {
	cout << "Enter a valid coordinate input (eg. a1)" << endl;
      }
      else { // Record down user's turn
	int row = input[0] - 'a';
	int column = input[1] - '1';

	if (board[row][column] == BLANK) {
	  if (turn == X_TURN) {
	    board[row][column] = X_MOVE;
	    turn = O_TURN;	  
	  }
	  else {
	    board[row][column] = O_MOVE;
	    turn = X_TURN;
	  }
	}
	else {
	  cout << "There's a piece there!" << endl;
	}
      }
    }

    // Check for wins
    if (checkWin(board, X_MOVE) == true) {
      cout << "X Wins!" << endl;
      numXWins++;
    }
    else if (checkWin(board, O_MOVE) == true) {
      cout << "O Wins!" << endl;
      numOWins++;
    }
    else if (checkTie(board) == true) {
      cout << "It's a tie!" << endl;
      numTies++;
    }

    cout << '\n' << "Scoreboard: " << '\n' << "X wins = " << numXWins << " , O wins = " << numOWins << " , Ties = " << numTies << '\n' << endl;


    // Ask if user wants to play again
    cout << "Play again? (Y or N?)" << endl;
    
    cin >> yon;
    if (yon == 'y' || yon == 'Y') {
      turn = X_TURN;
      resetGame(board);
      stillPlaying = true;
      
    } else {
      stillPlaying = false;
    }
  }
}

// Check board for wins
bool checkWin(int board[3][3], int player) {
  //row 1
  if (board[0][0] == player && board[0][1] == player && board [0][2] == player) {
    return true;
  }
  //row 2
  if (board[1][0] == player && board[1][1] == player && board [1][2] == player) {
    return true;
  }
  //row 3
  if (board[2][0] == player && board[2][1] == player && board [2][2] == player) {
    return true;
  }
  

  //column 1
  if (board[0][0] == player && board[1][0] == player && board [2][0] == player) {
    return true;
  }
  //column 2
  if (board[0][1] == player && board[1][1] == player && board [2][1] == player) {
    return true;
  }
  //column 3
  if (board[0][2] == player && board[1][2] == player && board [2][2] == player) {
    return true;
  }

  // diagonal top left - bottom right
  if (board[0][0] == player && board[1][1] == player && board [2][2] == player) {
    return true;
  }
  // diagonal bottom left - top right
  if (board[2][0] == player && board[1][1] == player && board [0][2] == player) {
    return true;
  }

  return false;
}

// Check board for ties
bool checkTie(int board[3][3]) {
  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++) {
      if (board[row][column] == BLANK) {
	return false;
      }
    }
  }
  return true;
}

// Print out the board & user inputs
void printBoard(int board[3][3]) {
  cout << "\t1\t2\t3" << endl;
  for (int row = 0; row < 3; row++) {
    char output[9];
    char abc = 'a' + row;
    output[0] = abc;
    output[1] = '\t';
    int x=2;
    for (int column = 0; column < 3; column++) {
      if (board[row][column] == BLANK) {
	output[x] = ' ';
      }
      else if (board[row][column] == X_MOVE) {
	output[x] = 'X';
      }
      else if (board[row][column] == O_MOVE) {
	output[x] = 'O';
      }
      x++;
      output[x] = '\t';
      x++;
      output[8] = '\0';
    }
    cout << output << endl;
  }
}

// Reset the board
void resetGame(int board[3][3]) {
  int turn;
  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++) {
      board[row][column] = 0;
    }
  }
  turn = X_TURN;
}  
