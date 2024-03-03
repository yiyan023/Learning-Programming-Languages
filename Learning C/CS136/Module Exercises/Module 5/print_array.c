#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

void print_arr(int arr[], int len) {
  printf("[");
  
  for (int i = 0; i < len; i++) {
    if (i == 0) {
      printf("%d", arr[i]);
    } else {
      printf(", %d", arr[i]);
    }
  }
  
  printf("]");
}

int main(void) {
  int arr1[4] = {1, 2, 3, 4};
  print_arr(arr1, 4);
}