/////////////////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments > Assignment Information & Policies > Academic Integrity Policy)
/////////////////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// Nobody
//
// Name: Yiyan Huang
// login ID: y84huang
//////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

int width_finder(int n) {
  if (n == 0) {
    return 0;
  } else {
    printf("*");
    return width_finder(n - 1);
  }
}

int rectangle_finder(int width, int height) {
  if (height == 0) {
    return 0;
  } else {
    width_finder(width);
    printf("\n");
    return rectangle_finder(width, height-1);
  }
}

void print_rectangles(void) {
// Your implementation goes here
  int width = read_int();
  int height = read_int();
  /* if (READ_INT_FAIL != width) {
    if (READ_INT_FAIL != height) {
      rectangle_finder(width, height);
      print_rectangles();
    }
  } */
}

int main(void) {
  print_rectangles();
}