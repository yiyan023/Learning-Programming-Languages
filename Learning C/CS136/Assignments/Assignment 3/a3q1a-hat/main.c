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

const int colourNum = 5;

// hat_helper(n, c0, c1, c2, c3, c4) prints a specific character depending on 
//   the value of n (the input).
// requires: n cannot be negative
void hat_helper(int n, char c0, char c1, char c2, char c3, char c4) {
  assert (n >= 0);
  
  if (n % colourNum == 0) {
    printf("%c", c0);
  } else if (n % colourNum == 1) {
    printf("%c", c1);
  } else if (n % colourNum == 2) {
    printf("%c", c2);
  } else if (n % colourNum == 3) {
    printf("%c", c3);
  } else {
    printf("%c", c4);
  }
}

// print_hat(n, c0, c1, c2, c3, c4) prints a "hat" or pyramid with at most 5 
//   colours, which follow a pattern depending on the value of n
// requires: n cannot be negative.
void print_hat(int n, char c0, char c1, char c2, char c3, char c4) {
  assert(n >= 0);
  
  for (int index = 0; index <= n; index ++) {
    int space = 1;
    
    while (space <= n - index) {
      printf(" ");
      space += 1;
    }
    
    int start = (n - 1) % colourNum;
    
    int column = 0;
    
    while (column < (index * 2) + 1) {
      if (index == n) {
        if (column == 0 || column == (index * 2)) {
          printf("%c", c0);
          column += 1;
        } else {
          printf("%c", c1);
          column += 1;
        }
      } else {
        if (column < index) {
          hat_helper(start % colourNum, c0, c1, c2, c3, c4);
          column += 1;
          if (start == 0) {
            start = 4;
          } else {
            start -= 1;
          }
        } else {
          hat_helper(start % colourNum, c0, c1, c2, c3, c4);
          start += 1;
          column += 1;
        }
      }
    }
    printf("\n");
  }
}

// There is no need to modify this main function
// You can simply add new .in (and .expect) files
int main(void) {
  int n = read_int();
  char c0 = read_char(true);
  char c1 = read_char(true);
  char c2 = read_char(true);
  char c3 = read_char(true);
  char c4 = read_char(true);
  print_hat(n, c0, c1, c2, c3, c4);
}