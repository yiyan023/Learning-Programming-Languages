// Part 1

///////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments > Information & Policies > Academic Integrity Policy)
///////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// Nobody
//
// Name: Yiyan Huang
// login ID: y84huang
///////////////////////////////////////////////////////////////////////////////

#include "cs136.h"

// divide(num, denom) returns the quotient of numerator num and denominator
//   denom.
// requires: denom cannot be 0
int divide_helper(int num, int denom, int acc) {
  assert(denom != 0);
  
  if (num < denom) {
    return acc;
  } else {
    return divide_helper(num - denom, denom, acc + 1);
  }
}

int divide(int num, int denom) {
  // Remember: You may NOT use the multiplication, division, or module operator
  //   (*, /, or %). You MUST use a recursive approach!
  // your implementation goes here
  
  return divide_helper(num, denom, 0);
}

int main(void) {
  // public tests
  assert(divide(10, 5) == 2);
  assert(divide(1205, 2) == 602);

  // your additional tests go here
  assert(divide(9, 4) == 2);
  assert(divide(10, 3) == 3);
  
  trace_msg("All assertion-based tests passed!");
  return EXIT_SUCCESS;
}
