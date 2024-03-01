#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

// digit(i, nth) returns the nth digit in i.
//   685413
//   ^      5th digit (6)
//        ^ 0th digit (3)
// requires: i must be positive and have exactly six digits
//           nth must be between 0 and 5
int digit(int i, int nth) {
  if (nth == 0) {
    return i % 10;
  } else {
    return digit(i / 10, nth - 1);
  }
}

int main(void) {
  assert(digit(685413, 5) == 6);
  assert(digit(685413, 0) == 3);
  // Your additional tests go here
  
  trace_msg("All assertion-based tests passed!");
}