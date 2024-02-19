#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

void twice_all(void) {
    const int val = read_int();
    //if (READ_INT_FAIL != val) {
        //printf("%d", 2 * val);
        //twice_all();
    //} 
}

void countdown_all_helper(int val) {
  if (val > 0) {
    printf("%d\n", val);
    countdown_all_helper(val-1);
  }
}

void countdown_all(void) {
  int val = read_int();
  //if (READ_INT_FAIL != val) {
    //countdown_all_helper(val);
    //countdown_all();
  //}
}

int fact2(int n) {
  assert(n>=0);
  return n ? n * fact2(n - 1) : 1; //if n is non-zero, it will take condition 
  // before :, otherwise it will take the condition after : (1)
}

// test harnessing
void fact_all(void) {
  const int val = read_int();
  //if (READ_INT_FAIL != val) {
    //printf("%d\n", fact2(val));
    //fact_all();
  //}
}

void downup(int n) {
  if (n > 0) {
    printf("%d\n", n);
    downup(n - 1);
    printf("%d\n", n);
  } else if (n == 0) {
    printf("0\n");
  }
}

int partial_sum_helper(int acc) {
  int n = read_int();
  //if (READ_INT_FAIL != n) {
    //printf("%d\n", n + acc);
    //return partial_sum_helper(n + acc);
  //} else {
    //return 0;
  //}
}

int partial_sum(void) {
  return partial_sum_helper(0);
}

int print_sums(int acc) {
  const int val = read_int();
  //if (READ_INT_FAIL != val) {
    //acc += val;
    //printf("%d\n", acc);
    //return print_sums(acc);
  //} else {
    //return acc;
  //}
}

int main(void) {
    //twice_all();
    //countdown_all();
    //downup(2);
    //partial_sum();
    print_sums(0);
}
