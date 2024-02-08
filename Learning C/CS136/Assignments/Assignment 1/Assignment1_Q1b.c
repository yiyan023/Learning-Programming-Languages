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

// gcd(int m, int n) returns the greatest common denominator of m and n.
// requires: m, n must be positive
int gcd_helper(int m, int n, int divisor) {
  if (divisor == 0) {
    return 1;
  } else if (m % divisor == 0 && n % divisor == 0) {
    return divisor;
  } else {
    return gcd_helper(m, n, divisor - 1);
  }
}

int gcd(int m, int n) {
  // your implementation goes here
  assert(m > 0);
  assert(n > 0);
  
  if (m < n) {
    return gcd_helper(m, n, m);
  } else {
    return gcd_helper(m, n, n);
  }
}

int main(void) {
  // public tests
  assert(gcd(18, 27) == 9);

  // your additional tests go here
  assert(gcd(7, 9) == 1);
  assert(gcd(8, 2) == 2);
  assert(gcd(9, 9) == 9);

  trace_msg("All assertion-based tests passed!");
  return EXIT_SUCCESS;
}
