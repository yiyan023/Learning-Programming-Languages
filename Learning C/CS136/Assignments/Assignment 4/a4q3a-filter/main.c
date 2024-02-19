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

// === Filter Functions =======================================================

// filter_odd(n) returns true if n is odd and false otherwise.
bool filter_odd(int n) {
  if (n % 2 == 1) {
    return true;
  } else if (n % 2 == -1) {
    return true;
  } else {
    return false;
  }
}

// filter_lt(n, param) returns true if n is less than param, and false
//   otherwise.
bool filter_lt(int n, int param) {
  // your implementation goes here
  if (n < param) {
    return true;
  } else {
    return false;
  }
}

// filter_div(n, param) returns true if n is divisible by param, and false
//   otherwise.
// requires: param must be positive
bool filter_div(int n, int param) {
  // your implementation goes here
  assert(param > 0);
  if (n % param == 0) {
    return true;
  } else {
    return false;
  }
}

// === Higher-order Functions =================================================

// filter(pred) reads all numbers from input and prints them if they satisfy
//   the predicate pred.
// effects: reads from input
//          writes to output
void filter(bool (*pred)(int)) {
  // use the following printf format to print numbers: " %d"
  // your implementation goes here
  int num;
  while (scanf("%d", &num) == 1) {
    if (pred(num)) {
      printf(" %d", num);
    }
  }
}

// filter_param(pred, param) reads all numbers from input and prints them if
//   they satisfy the predicate pred given a parameter param.
// effects: reads from input
//          writes to output
void filter_param(bool (*pred)(int, int), int param) {
  // use the following printf format to print numbers: " %d"
  // your implementation goes here
  int num;
  scanf(" %d", &num);
  
  while (scanf("%d", &num) == 1) {
    if ( pred(num, param) ) {
      printf(" %d", num);
    }
  }
}

// === THERE IS NO NEED TO MODIFY THE MAIN FUNCTION ===========================

// The program accepts the following commands:
// * FILTER ODD [<data:int> ...]
//   reads integers from the console and applies the filter ODD to them
// * FILTER [DIV|LT] <param:int> [<data:int> ...]
//   reads integers from the console and applies the filter DIV or LT to them
//   with the first <param:int> being the parameter to the filter
int main(void) {
  // registering all symbols (FILTER, ODD, LT, and DIV) using lookup_symbol
  const int CMD_FILTER = lookup_symbol("FILTER");
  const int CMD_FILTER_ODD = lookup_symbol("ODD");
  const int CMD_FILTER_LT = lookup_symbol("LT");
  const int CMD_FILTER_DIV = lookup_symbol("DIV");

  // setting up variables for storing both required commands
  int cmd_first = INVALID_SYMBOL;  // [FILTER]
  int cmd_second = INVALID_SYMBOL; // [ODD|LT|DIV]

  while ((cmd_first = read_symbol()) != INVALID_SYMBOL &&
         (cmd_second = read_symbol()) != INVALID_SYMBOL) {
    if (cmd_first == CMD_FILTER) { // first command: FILTER
      printf("FILTER ");
      if (cmd_second == CMD_FILTER_ODD) {        // second command: ODD
        printf("ODD:");
        filter(filter_odd);                         // call filter
      } else if (cmd_second == CMD_FILTER_LT) {  // second command: LT
        printf("LT:");
        int param = INT_MIN;                        // LT requires parameter
        if (scanf("%d", &param) == 1) {             // read parameter
          filter_param(filter_lt, param);              // call filter
        } else {                                    // cannot read parameter
          assert(false);                               // assert-quit
        }
      } else if (cmd_second == CMD_FILTER_DIV) { // second command: DIV
        printf("DIV:");
        int param = INT_MIN;                        // DIV requires parameter
        if (scanf("%d", &param) == 1) {             // read parameter
          filter_param(filter_div, param);             // call filter
        } else {                                    // cannot read parameter
          assert(false);                               // assert-quit
        }
      } else {                                   // second command: unknown
        assert(false);                              // assert-quit
      }
      printf("\n");
    } else {                       // first command: unknown
      assert(false);                  // assert-quit
    }
  }

  return  EXIT_SUCCESS;
}