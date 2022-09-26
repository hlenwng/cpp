# include <iostream>
# include <cstring> 
using namespace std;

int main() {
  char str[81];
  char revstr[81];
  char nopun[81];
  int len = strlen(str);
  int newlen = strlen(nopun);
  int count = 0;
  int x = 0;

  cout << "Enter a word: " << endl;
  
  cin.getline(str, 81, '\n');
  len = strlen(str);

  // turns all upercase to lowercase
  for (int i = 0; i < len; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      str[i] += 32;
      //cout << "all lowercase: " << str[i] << endl;
    }  
  }

  cout << "all lowercase: " << str << endl;
 
  // removes punctuation and spaces
  // copies only alpha to new char
  int puncounter = 0;
  for (int i = 0; i < len; i++) {
    if (isalpha(str[i])) {
      if (!isspace(str[i])) {
	  nopun[puncounter] = str[i];
	  // i.e. nopun[0] = str[1] 
	  puncounter++;
	  //cout << "is a letter: " << nopun[i] << endl;
      }
    }
    // ends the word with null (one more after the counter)
    nopun[puncounter + 1] = '\0';
  }
  
  cout << "only letters: " << nopun << endl;
    
  // compares first and last letter
  newlen = strlen(nopun);
  for (int i = 0; i <= newlen; i++) {
    if(nopun[i] != '\0') {
      if(nopun[i] == nopun[newlen-i-1]) {
	count++;
      }
      cout << nopun[newlen-i-1] << endl;
    }
    //cout << count << endl;
  }
  
  cout << count << endl;

  // if count (# of matching characters all the way across/*2) is equal to length of word
  if (count == newlen) {
    cout << "Palindrome" << endl;
  } else {
    cout << "Not a palindrome" << endl;
  }
  
  return 0;
}
 




  
