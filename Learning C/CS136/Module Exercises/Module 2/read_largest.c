#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

// Your function documentation goes here.
int read_largest(int current) {
  int input = read_int();
  
  if (input != READ_INT_FAIL) {
    if (input > current) {
      return read_largest(input);
    } else {
      return read_largest(current);
    }
  } else if (current == INT_MIN) {
    return -1;
  } else {
    return current;
  }
}

int main(void) {
  printf("%d\n", read_largest(INT_MIN));
}