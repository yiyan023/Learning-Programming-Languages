#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

// Your documentation goes here.
void factorial(int n, int *result) {
  // Your implementation goes here.
  *result = 1;
  
  for (int i = n; i > 0; i--) {
    * result *= i;
  }
}

int main() {
  int fact = 0;
  int num = 0;
  assert(scanf("%d", &num) == 1);
  // Your implementation goes here.
  // * Read fact and num1 from input .
  // * Call factorial.
  factorial(num, &input);
  printf("The factorial of %d is %d.\n", num, fact);
}