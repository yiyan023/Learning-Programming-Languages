#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

// your function documentation goes here
int max_2(int a, int b) {
  // your implementation goes here
  if (a >= b) {
    return a;
  } else {
    return b;
  }
}

// your function documentation goes here
int max_3(int a, int b, int c) {
  // your implementation goes here
  if (a >= b && a >= c) {
    return a;
  } else if (b >= a && b >= c) {
    return b;
  } else {
    return c;
  }
}

int main(void) {
  assert(max_2(4, 4) == 4);
  assert(max_3(4, 4, 4) == 4);
  // Your additional tests go here
  assert(max_3(5, 4, 4) == 5);
  assert(max_3(5, 4, 6) == 6);
  assert(max_3(4, 4, 5) == 5);
  assert(max_3(4, 5, 4) == 5);
  
  trace_msg("All assertion-based tests passed!");
}