#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

// Your documentation goes here.
void print_forward_reversed(void) {
  // Your implementation goes here.
  int input = read_int();
  
  if (input != READ_INT_FAIL) {
    printf("%d\n", input);
    print_forward_reversed();
    printf("%d\n", input);
  }
}

int main(void) {
  print_forward_reversed();
}