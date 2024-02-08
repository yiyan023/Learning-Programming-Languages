#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

int factorial_helper(int n, int acc) {
  while (n > 0) {
    return factorial_helper(n-1, acc * n);
  }
  return acc;
}

int factorial(int n) {
  return factorial_helper(n, 1);
}

int sum_helper(int n, int acc) {
  while (n > 0) {
    return sum_helper(n-1, acc + n * n);
  }
  
  return acc;
}

int sum_squares(int n) {
  return sum_helper(n, 0);
}

int main(void) {
  // if and while loops
  int n = 5;
  while (n > 0) {
    printf("%d\n", n);
    n = n - 1;
  }
  
  // do while loops also exist but they are not that common -- do something 
  // while looping 
  
  //break -- jumps out of the innermost loop 
  int number = 10;
  while (true) {
    --n;
    printf("I see %d\n", n);
    if (5 == n) {
      break;
    }
    printf("n must be 5: %d\n", n);
  }
  
  //continue -- jumps to the top of the innermost loop
  int integer = 10;
  while (n>0) {
    --n;
    if (!(n % 3)) { //checks if n is divisible by 3
      printf("Skipping %d\n", n);
      continue;
    }
    printf("Including %d\n", n);
  }
  
  //how can we make this function without continue?
  while (n>0) {
    --n;
    if (!(n % 3)) { //checks if n is divisible by 3
      printf("Skipping %d\n", n);
    } else {
      printf("Including %d\n", n);
    }
  }
  
  //for loops -- can also be rewritten into while loops 
  for (int i = 10; i > 0; --i) { //initial condition, continue condition (while)
                                 // next condition
    printf("%d\n", i); 
  }
  
  // rewritten into a while loop:
  int i = 10;
  while (i > 0) {
    printf("%d\n", i);
    --i;
  }
  
  // different types of memory -- code, read-only data, global data, heap, stack
}
