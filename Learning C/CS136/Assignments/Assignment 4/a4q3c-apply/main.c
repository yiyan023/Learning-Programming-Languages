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

// apply_double(n) returns n doubled.
int apply_double(int n) {
  return 2 * n;
}

// apply_shiftl(n) returns n shifted to the left.
int apply_shiftl(int n) {
  return n / 10;
}

// === Higher-order Functions =================================================

// apply(func, value, reps) applies the function func reps times to value.
// requires: reps must be positive
int apply(int (*func)(int), int value, int reps) {
  assert(func);
  assert(reps > 0);
  for (int i = 0; i < reps; ++i) {
    value = func(value);
  }
  return value;
}


// The program accepts the following commands:
// * APPLY [DOUBLE|SHIFTL] <reps:int> [<data:int> ...]
//   reads integers from the console and applies the function DOUBLE or SHIFTL
//   <reps:int> times to them.
int main(void) {
  // 1. Use lookup_symbol to register symbols
  // 2. Continue until done:
  //    A. Use read_symbol twice to read commands from input
  //    B. Use scanf to read reps from input
  //    C. Use a loop and scanf to read all remaining integers from input
  //       a. For each integer, call apply with the correct arguments
  
  const int CMD_APPLY = lookup_symbol("APPLY");
  const int CMD_DOUBLE = lookup_symbol("DOUBLE");
  const int CMD_SHIFTL = lookup_symbol("SHIFTL");
  
  int cmd_first = INVALID_SYMBOL;  // [MAP]
  int cmd_second = INVALID_SYMBOL; // [DOUBLE|SHIFTL]
  
  while ((cmd_first = read_symbol()) != INVALID_SYMBOL &&
         (cmd_second = read_symbol()) != INVALID_SYMBOL) {
    if (cmd_first == CMD_APPLY) {
      printf("APPLY");
      int (*apply_func)(int) = NULL; 
      
      if (cmd_second == CMD_DOUBLE) {      
        apply_func = apply_double;                    
        printf(" DOUBLE:");
        int reps = INT_MIN;
        
        if (scanf("%d", &reps) == 1) {
          int value;
          
          while (scanf("%d", &value) == 1) {
            printf(" %d", apply(apply_func, value, reps));
          }
        } else {
          assert(false);
        }
      } else if (cmd_second == CMD_SHIFTL) { // second command: ADD1
        apply_func = apply_shiftl;                    
        printf(" SHIFTL:");
        int reps = INT_MIN;
        
        if (scanf("%d", &reps) == 1) {
          int value;
          
          while (scanf("%d", &value) == 1) {
            printf(" %d", apply(apply_func, value, reps));
          }
        } else {
          assert(false);
        }
      } else {
        assert(false);
      }       
      printf("\n");
    } else {
      assert(false);
    }
  }
  
  return  EXIT_SUCCESS;
}