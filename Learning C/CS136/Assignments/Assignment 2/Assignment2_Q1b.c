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

// Consider defining global constants to make your code more readable.

// print_island(width, height, T_col, T_row) prints 'height' rows of 'width' stars ('*').
// At (T_col, T_row), the star is replaced with the letter "T"
// example:  print_island(5, 4, 2, 3)
//           *****
//           *****
//           *****
//           **T**
//
// requires: width, height, must be positive, T_col and T_row must be non-negative
// effects:  writes to the console

int width_finder(int n) {
  if (n == 0) {
    return 0;
  } else {
    printf("*");
    return width_finder(n - 1);
  }
}

int tcol_finder(int width, int col) {
  if (width == 0) {
    return 0;
  } if (width - 1 == col) {
    printf("T");
    return tcol_finder(width - 1, col);
  } else {
    printf("*");
    return tcol_finder(width - 1, col);
  }
}

int island_helper(int width, int height, int col, int row) {
  if (height == 0) {
    return 0;
  } else if (height - 1 == row) { //when height = 1, row == 3
    tcol_finder(width, col);
    printf("\n");
    return island_helper(width, height - 1, col, row);
  } else {
    width_finder(width);
    printf("\n");
    return island_helper(width, height - 1, col, row);
  }
}

void print_island(int width, int height, int T_col, int T_row) {
  // your implementation goes here
  island_helper(width, height, width - T_col - 1, height - T_row - 1);
}

// turtle_run() should read in two positive integers corresponding to the
// width and height of an island. It should then continuously read integers
// from input corresponding to movement commands. The current state consists
// of a grid of 'height' rows and 'width' stars. A character "T" begins at position
// (0,0) and can be moved to a new row or column via movement commands. After each
// movement, the updated position is printed out.
// example:  turtle_run()  Input: 8 4 4 2 
//           T*******
//           ********
//           ********
//           ********
//           The turtle is at (0, 0).
//           *T******
//           ********
//           ********
//           ********
//           The turtle is at (1, 0).
//           ********
//           *T******
//           ********
//           ********
//           The turtle is at (1, 1).
// requires: input height, width must be positive
// effects:  writes to the console
int up_down (int dir, int col, int row) {
  if (dir == 1) {
    return row - 1;
  } else if (dir == 2) {
    return row + 1;
  } else {
    return 0;
  }
}

int left_right (int dir, int col, int row) {
  if (dir == 3) {
    return col - 1;
  } else if (dir == 4) {
    return col + 1;
  } else {
    return 0;
  }
}

void moving_turtle(int dir, int width, int height, int col, int row) {
  if (dir == 1) {
    print_island(width, height, col, row - 1);
    printf("The turtle is at (%d, %d).\n", col, row - 1);
  } else if (dir == 2) {
    print_island(width, height, col, row + 1);
    printf("The turtle is at (%d, %d).\n", col, row + 1);
  } else if (dir == 3) {
    print_island(width, height, col - 1, row);
    printf("The turtle is at (%d, %d).\n", col - 1, row);
  } else if (dir == 4) {
    print_island(width, height, col + 1, row);
    printf("The turtle is at (%d, %d).\n", col + 1, row);
  } else {
    printf("Invalid input.");
  }
}

int directions(int width, int height, int col, int row) {
  int dir = read_int();
  /* if (READ_INT_FAIL != dir) {
    if (dir == 1) {
      print_island(width, height, col, row - 1);
      printf("The turtle is at (%d, %d).\n", col, row - 1);
      return directions(width, height, col, row - 1);
    } else if (dir == 2) {
      print_island(width, height, col, row + 1);
      printf("The turtle is at (%d, %d).\n", col, row + 1);
      return directions(width, height, col, row + 1);
    } else if (dir == 3) {
      print_island(width, height, col - 1, row);
      printf("The turtle is at (%d, %d).\n", col - 1, row);
      return directions(width, height, col - 1, row);
    } else if (dir == 4) {
      print_island(width, height, col + 1, row);
      printf("The turtle is at (%d, %d).\n", col + 1, row);
      return directions(width, height, col + 1, row);
    } else {
      printf("Invalid input.");
      return directions(width, height, 0, 0);
    } */
}


void turtle_run(void) {
  // your implementation goes here
  int width = read_int();
  int height = read_int();
  
  /* if (READ_INT_FAIL != width) {
    if (READ_INT_FAIL != height) {
      print_island(width, height, 0, 0);
      printf("The turtle is at (0, 0).\n");
    }
  } */
  
  directions(width, height, 0, 0);
}

int main(void) {
  //print_island(5, 4, 2, 3); 
  //print_island(2, 8, 0, 0); 
  turtle_run();
  return EXIT_SUCCESS;
}