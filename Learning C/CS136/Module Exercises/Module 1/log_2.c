#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

// Your function documentation goes here

int expt(int b, int n) {
  // your implementation goes here
  if (n == 0) {
    return 1;
  } else {
    return b * expt(b, n - 1);
  }
}

int log_2_helper(int n, int count) {
  if (expt(2, count) >= n) {
    return count;
  } else {
    return log_2_helper(n, count + 1);
  }
}

int log_2(int n) {
  // Your implementation goes here
  return log_2_helper(n, 0);
}

int main(void) {
  assert(log_2(18) == 5);
  // Your additional tests go here
  
  trace_msg("All assertion-based tests passed!");
}