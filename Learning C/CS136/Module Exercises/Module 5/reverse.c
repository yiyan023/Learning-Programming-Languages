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
  
  printf("]\n");
}

void swap(int * a, int * b) {
  int temp = * b;
  * b = * a;
  * a = temp;
}

void reverse_array_idx(int arr[], int len) {
  int l = 0;
  int r = len - 1;
  
  while (l <= r) {
    swap(&arr[l], &arr[r]);
    l += 1;
    r -= 1;
  }
  
  print_arr(arr, len);
}

void reverse_array_ptr(int arr[], int len) {
  int l = 0;
  int r = len - 1;
  
  while (l <= r) {
    swap(& *(arr + l), & *(arr + r));
    l += 1;
    r -= 1;
  }
  
  print_arr(arr, len);
}

int main(void) {
  int arr1[4] = {1, 2, 3, 4};
  print_arr(arr1, 4);
  reverse_array_idx(arr1, 4);
  reverse_array_ptr(arr1, 4);
}