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

// void(main) will convert all characters from an input into sarcasm case, or 
//    alternating caps.
// requires: the input must be a character
int main(void) {
  char string = read_char(READ_WHITESPACE);
  int index = 0;
  
  while (string != READ_CHAR_FAIL) {
    if (index % 2 == 0) {
      if (string >= 'A' && string <= 'Z') {
        string = string - 'A' + 'a';
        index += 1;
        printf("%c", string);
        string = read_char(READ_WHITESPACE);
      } else if (string >= 'a' && string <= 'z') {
        index += 1;
        printf("%c", string);
        string = read_char(READ_WHITESPACE);
      } else {
        printf("%c", string);
        string = read_char(READ_WHITESPACE);
      }
    } else if (index % 2 == 1) {
      if (string >= 'a' && string <= 'z') {
        string = string - 'a' + 'A';
        index += 1;
        printf("%c", string);
        string = read_char(READ_WHITESPACE);
      } else if (string >= 'A' && string <= 'Z') {
        index += 1;
        printf("%c", string);
        string = read_char(READ_WHITESPACE);
      } else {
        printf("%c", string);
        string = read_char(READ_WHITESPACE);
      }
    }
  }
}