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

// === Map Functions ==========================================================

// map_add1(n) returns the increment of n.
int map_add1(int n) {
  return n + 1;
}

// map_double(n) returns n doubled.
int map_double(int n) {
  // your implementation goes here
  return n * 2;
}

// === Higher-order Functions =================================================

// map(func) reads all numbers from input, applies func to it, and prints
//   out the result.
// effects: reads from input
//          writes to output
void map(int (*func)(int)) {
  // use the following printf format to print numbers: " %d"
  // your implementation goes here
  int num;
  
  while (scanf( "%d", &num) == 1) {
    printf(" %d", func(num));
  }
}

// === THERE IS NO NEED TO MODIFY THE MAIN FUNCTION ===========================

// The program accepts the following commands:
// * MAP [DOUBLE|ADD1] [<data:int> ...]
//   reads integers from the console and applies the function DOUBLE or ADD1
//   to them
int main(void) {
  // registering all symbols (MAP, DOUBLE, and ADD1) using lookup_symbol
  const int CMD_MAP = lookup_symbol("MAP");
  const int CMD_MAP_DOUBLE = lookup_symbol("DOUBLE");
  const int CMD_MAP_ADD1 = lookup_symbol("ADD1");

  int cmd_first = INVALID_SYMBOL;  // [MAP]
  int cmd_second = INVALID_SYMBOL; // [DOUBLE|ADD1]

  while ((cmd_first = read_symbol()) != INVALID_SYMBOL &&
         (cmd_second = read_symbol()) != INVALID_SYMBOL) {
    if (cmd_first == CMD_MAP) { // first command: MAP
      printf("MAP ");
      int (*map_func)(int) = NULL; // function pointer to map function
      if (cmd_second == CMD_MAP_DOUBLE) {      // second command: DOUBLE
        map_func = map_double;                    // set fp to map function
        printf("DOUBLE:");
      } else if (cmd_second == CMD_MAP_ADD1) { // second command: ADD1
        map_func = map_add1;                          // set fp to map function
        printf("ADD1:");
      } else {                                 // second command: unknown
        assert(false);                            // assert-quit
      }
      map(map_func);               // call map function
      printf("\n");
    } else {                    // first command: unknown
      assert(false);               // assert-quit
    }
  }

  return  EXIT_SUCCESS;
}