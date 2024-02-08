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

// void(main) will clean up an input by printing sentences in its own line, 
//    following the line number. It will also remove any non-letter characters
//    before or after a sentence & extra spaces will be ignored in the sentence.
//    Special characters in the sentence will be converted into spaces
// requires: the input must be a character
int main(void) {
  int n = 1; 
  int start = 1;
  int space = 1;
  char input = read_char(READ_WHITESPACE);
  
  while (input != READ_CHAR_FAIL) {
    if (start == 1 && input >= 'a' && input <= 'z') {
      if (n == 1) {
        printf("  %d: %c", n, input);
      } else if (n < 10) {
        printf("\n  %d: %c", n, input);
      } else if (n < 100) {
        printf("\n %d: %c", n, input);
      } else {
        printf("\n%d: %c", n, input);
      }
      
      start = 0;
      space = 1;
      input = read_char(READ_WHITESPACE);
    } else if (start == 1 && input >= 'A' && input <= 'Z') {
      if (n == 1) {
        printf("  %d: %c", n, input);
      } else if (n < 10) {
        printf("\n  %d: %c", n, input);
      } else if (n < 100) {
        printf("\n %d: %c", n, input);
      } else {
        printf("\n%d: %c", n, input);
      }
      
      start = 0;
      space = 1;
      input = read_char(READ_WHITESPACE);
    } else if (start == 0 && input >= 'a' && input <= 'z') { //generally if it is 
      printf("%c", input);
      space = 1;
      input = read_char(READ_WHITESPACE);
    } else if (start == 0 && input >= 'A' && input <= 'Z') {
      printf("%c", input);
      space = 1;
      input = read_char(READ_WHITESPACE);
    } else if (start == 0 && space == 1 && input == ' ') {
      space = 0;
      printf(" ");
      input = read_char(READ_WHITESPACE);
    } else if (start == 0 && input =='.') { 
      printf("%c", input);
      n += 1;
      start = 1;
      space = 1;
      input = read_char(READ_WHITESPACE);
    } else if (start == 0 && input =='!') { 
      printf("%c", input);
      n += 1;
      start = 1;
      space = 1;
      input = read_char(READ_WHITESPACE);
    } else if (start == 0 && input =='?') { 
      printf("%c", input);
      n += 1;
      start = 1;
      space = 1;
      input = read_char(READ_WHITESPACE);
    } else if (start == 0 && input != ' ' && input != '\n') { //special character
      printf(" ");
      input = read_char(READ_WHITESPACE);
    } else {
      input = read_char(IGNORE_WHITESPACE);
    }
  }
  
  printf("\n");
}