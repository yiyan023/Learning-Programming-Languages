/////////////////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments > Assignment Information & Policies > Academic Integrity Policy)
/////////////////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

//
// Name: Yiyan Huang
// login ID: y84huang
//////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

// print_mean_detail() reads in all numbers from the console and prints out 
//   their mean as well as the relation between each value and the mean
//   (above, below, equal).
// effects: reads from the console
//          writes to the console
int print_mean(int acc, int n) {
  // use the following printf format string:
  //   "The mean is %d.\n"
  // your implementation goes here
  int num = read_int(); 
  /* if (READ_INT_FAIL != num) {
    int mean = print_mean(acc + num, n + 1); // set a variable to the recursive call so the mean does not update
    
    if (num > mean) {
      printf("Value (%d) is above the mean.\n", num);
    } else if (num == mean) {
      printf("Value (%d) is equal to the mean.\n", num);
    } else {
      printf("Value (%d) is below the mean.\n", num);
    }
    
    return mean;
    
  } else {
    int mean = acc / n;
    printf("The mean is %d.\n", mean);
    return mean;
  } */
}

void print_mean_detail(void) {
  // use the following printf format strings:
  //   "The mean is %d.\n"
  //   "Value (%d) is above the mean.\n"
  //   "Value (%d) is below the mean.\n"
  //   "Value (%d) is equal to the mean.\n"
  // your implementation goes here
  //int mean = print_mean(0, 0);
  print_mean(0, 1);
}

int main(void) {
  print_mean_detail();
  return EXIT_SUCCESS;
}