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

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

// nth_hailstone(int x, int n) returns the n-th Hailstone number of a given
//   number x.
// requires: x and n must both be non-negative
int nth_hailstone(int x, int n) {
  // your implementation goes here
  assert (x >= 0 && n >= 0);
  
  if (n == 0) {
    return x;
  } else if (x % 2 == 0) {
    return nth_hailstone (x / 2, n - 1);
  } else {
    return nth_hailstone (3 * x + 1, n - 1);
  }
}

int main(void) {
  // public tests
  assert(nth_hailstone(5, 2) == 8);   //              5 ->
                                      // 5 * 3 + 1 = 16 ->
                                      // 16 / 2 =     8

  assert(nth_hailstone(11, 5) == 13); //              11 ->
                                      // 11 * 3 + 1 = 34 ->
                                      // 34 / 2 =     17 ->
                                      // 17 * 3 + 1 = 52 ->
                                      // 52 / 2 =     26 ->
                                      // 26 / 2 =     13

  // your additional tests go here
  assert(nth_hailstone(6, 2) == 10);  //             6  ->
                                      // 6 / 2     = 3  ->
                                      // 3 * 3 + 1 = 10
                                      
  assert(nth_hailstone(6, 3) == 5);   //             6  ->
                                      // 6 / 2     = 3  ->
                                      // 3 * 3 + 1 = 10
                                      // 10 / 2    = 5

  trace_msg("All assertion-based tests passed!");
  return EXIT_SUCCESS;
}
