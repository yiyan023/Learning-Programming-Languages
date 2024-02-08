/////////////////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments > Assignment Information & Policies > Academic Integrity Policy)
/////////////////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

//
// Name: Yiyan Huang
// login ID: y84huang
//////////////////////////////////////////////////////////////////////////////////////////

#include "cs136.h"
// void(main) will convert all characters from an input into shout case.
// requires: the input must be a character
int main(void) {
  char string = read_char(READ_WHITESPACE);
  
  while (string != READ_CHAR_FAIL) {
    if (string >= 'a' && string <= 'z') {
      string = string - 'a' + 'A';
      printf("%c", string);
      string = read_char(READ_WHITESPACE);
    } else {
      printf("%c", string);
      string = read_char(READ_WHITESPACE);
    }
  } 
}