#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

// your function documentation goes here
int sqr_int_helper(int n, int count) {
  if (n < count * count) {
    return count - 1;
  } else {
    return sqr_int_helper(n, count + 1);
  }
}
int sqrt_int(int n) {
  // your implementation goes here
  return sqr_int_helper(n, 0);
}

int main(void) {
  assert(sqrt_int(16) == 4);
  // your additional tests go here
  
  trace_msg("All assertion-based tests passed!");
}