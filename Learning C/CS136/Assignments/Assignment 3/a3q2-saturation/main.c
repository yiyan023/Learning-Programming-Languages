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

#include "cs136.h"

// Use these strings in your solutions:
// "Warning: positive overflow detected for a = %d, b = %d!\n"
// "Warning: negative overflow detected for a = %d, b = %d!\n"

// saturation_add(a, b) will add the numbers a and b together. If their sum is 
//   greater than INT_MAX, the function will return INT_MAX. Similarly, if the
//   sum is less than INT_MIN, the function will return INT_MIN.
// requires: a and b cannot be less than INT_MIN or greater than INT_MAX
int saturation_add(int a, int b) {
  // requirements
  assert(a <= INT_MAX && a >= INT_MIN);
  assert(b <= INT_MAX && b >= INT_MIN);
  
  if (a >= 0 && b >= 0 && a > INT_MAX - b) {
    printf("Warning: positive overflow detected for a = %d, b = %d!\n", a, b);
    return INT_MAX; 
  } else if (a <= 0 && b <= 0 && a < INT_MIN - b) {
    printf("Warning: negative overflow detected for a = %d, b = %d!\n", a, b);
    return INT_MIN;
  } else {
    return a + b;
  }
}

// saturation_sub(a, b) will subtract the numbers a and b together. If their  
//   difference is greater than INT_MAX, the function will return INT_MAX.  
//   Similarly, if the difference is less than INT_MIN, the function will 
//   return INT_MIN.
// requires: a and b cannot be less than INT_MIN or greater than INT_MAX
int saturation_sub(int a, int b) {
  assert(a <= INT_MAX && a >= INT_MIN);
  assert(b <= INT_MAX && b >= INT_MIN);
  
  if (a >= 0 && b <= 0 && a > INT_MAX + b) {
    printf("Warning: positive overflow detected for a = %d, b = %d!\n", a, b);
    return INT_MAX; 
  } else if (a <= 0 && b >= 0 && a < INT_MIN + b) {
    printf("Warning: negative overflow detected for a = %d, b = %d!\n", a, b);
    return INT_MIN;
  } else {
    return a - b;
  }
}

// saturation_mult(a, b) will multiply the numbers a and b together. If their  
//   product is greater than INT_MAX, the function will return INT_MAX.  
//   Similarly, if the product is less than INT_MIN, the function will 
//   return INT_MIN.
// requires: a and b cannot be less than INT_MIN or greater than INT_MAX
int saturation_mult(int a, int b) {
  assert(a <= INT_MAX && a >= INT_MIN);
  assert(b <= INT_MAX && b >= INT_MIN);
  
  if (a > 0 && b > 0 && a > INT_MAX / b) {
    printf("Warning: positive overflow detected for a = %d, b = %d!\n", a, b);
    return INT_MAX;
  } else if (a < 0 && b < 0 && a < INT_MAX / b) {
    printf("Warning: positive overflow detected for a = %d, b = %d!\n", a, b);
    return INT_MAX;
  } else if (b < 0 && a > 0 && a > INT_MIN / b) {
    printf("Warning: negative overflow detected for a = %d, b = %d!\n", a, b);
    return INT_MIN;
  } else if (b > 0 && a < 0 && a < INT_MIN / b) {
    printf("Warning: negative overflow detected for a = %d, b = %d!\n", a, b);
    return INT_MIN;
  } else {
    return a * b;
  }
}

int main(void) {
  assert(saturation_add(2, 2) == 4);
  assert(saturation_add(INT_MAX, 1) == INT_MAX);
  assert(saturation_add(INT_MAX, -1) == 2147483646);
  assert(saturation_add(INT_MAX, 0) == INT_MAX); // won't return error 
  assert(saturation_add(INT_MIN, -1) == INT_MIN);
  
  assert(saturation_sub(5, 1) == 4);
  assert(saturation_sub(-1, -4) == 3);
  assert(saturation_sub(INT_MAX, -1) == INT_MAX);
  assert(saturation_sub(INT_MIN, 1) == INT_MIN);
  assert(saturation_sub(INT_MAX, 0) == INT_MAX); // won't return error 
  assert(saturation_sub(-1, INT_MAX) == INT_MIN);
  
  assert(saturation_mult(2, 2) == 4);
  assert(saturation_mult(-2, -2) == 4);
  assert(saturation_mult(-2, 2) == -4);
  assert(saturation_mult(2, -2) == -4);
  assert(saturation_mult(-2, INT_MIN) == INT_MAX);
  assert(saturation_mult(2, INT_MIN) == INT_MIN);
  assert(saturation_mult(2, INT_MAX) == INT_MAX);
  assert(saturation_mult(-2, INT_MAX) == INT_MIN);
  printf("All tests are true");
}