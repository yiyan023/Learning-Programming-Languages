#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

// your function documentation goes here
int expt(int b, int n) {
  // your implementation goes here
  if (n == 1) {
    return b;
  } else {
    return expt(b * b, n - 1);
  }
}

int main(void) {
  assert(expt(2, 2) == 4);
  // your additional tests go here
  
  trace_msg("All assertion-based tests passed!");
}