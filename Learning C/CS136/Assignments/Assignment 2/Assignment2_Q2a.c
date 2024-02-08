/////////////////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments > Assignment Information & Policies > Academic Integrity Policy)
/////////////////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

//  nobody
//
// Name: ERROR_NO_NAME
// login ID: ERROR_NO_LOGIN
//////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

// print_mean() reads in all numbers from the console and prints out their
//   mean.
// effects: reads from the console
//          writes to the console

void print_mean(int acc, int n) {
  // use the following printf format string:
  //   "The mean is %d.\n"
  // your implementation goes here
  int num = read_int(); 
  /* if (READ_INT_FAIL != num) {
    print_mean(num + acc, n + 1);
  } else {
    int mean = acc / n;
    printf("The mean is %d.\n", mean);
  } */
}

int main(void) {
  print_mean(0, 1);
  return EXIT_SUCCESS;
}