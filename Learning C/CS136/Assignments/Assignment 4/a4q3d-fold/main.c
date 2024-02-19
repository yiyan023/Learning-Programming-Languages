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

// === Fold Functions =========================================================

// fold_sum(base, value) returns the sum of value and base.
int fold_sum(int base, int value) {
  return value + base;
}

// fold_count_even(base, value) returns base incremented by 1 if value is
//   even, and base otherwise.
int fold_count_even(int base, int value) {
  // your implementation goes here
  if (value % 2 == 0) {
    return ++base;
  } else {
    return base;
  }
}

// === Higher-order Functions =================================================

// foldl(func, base) reads all numbers from input, folds them using func, and
//   finally returns the result. The fold is performed to the left, using base
//   in the base condition.
// effects: reads from input
int foldl(int (*func)(int, int), int base) {
  // your implementation goes here
  int value;
  
  while (scanf(" %d", &value) == 1) {
    base = func(base, value);
  }
  
  return base;
}

// === THERE IS NO NEED TO MODIFY THE MAIN FUNCTION ===========================

// The program accepts the following commands:
// * FOLDL [COUNT|SUM] [<data:int> ...]
//   reads integers from the console and prints either their count or their sum.
int main(void) {
  // registering all symbols (FOLDL, COUNT, and SUM) using lookup_symbol
  const int CMD_FOLDL = lookup_symbol("FOLDL");
  const int CMD_FOLD_COUNT = lookup_symbol("COUNT");
  const int CMD_FOLD_SUM = lookup_symbol("SUM");

  // setting up variables for storing both required commands
  int cmd_first = INVALID_SYMBOL;  // FOLDL
  int cmd_second = INVALID_SYMBOL; // [COUNT|SUM]

  while ((cmd_first = read_symbol()) != INVALID_SYMBOL &&
         (cmd_second = read_symbol()) != INVALID_SYMBOL) {
    
    int (*fold_direction)(int (*func)(int, int), int) = NULL;
    if (cmd_first == CMD_FOLDL) { // first command: FOLDL
      fold_direction = foldl;
      printf("FOLDL ");
    } else {                     // first command: unknown
      assert(false);                // assert-quit
    }
    
    int (*fold_func)(int, int) = NULL;
    if (cmd_second == CMD_FOLD_COUNT) {      // second command: COUNT
      fold_func = fold_count_even;
      printf("COUNT:");
    } else if (cmd_second == CMD_FOLD_SUM) { // second command: SUM
      fold_func = fold_sum;
      printf("SUM:");
    } else {                                 // second command: unknown
      assert(false);                            // assert-quit
    }
    printf(" %d\n", fold_direction(fold_func, 0));
    
  }

  return  EXIT_SUCCESS;
}