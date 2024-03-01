// add program documentation

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

// ELEVATOR CONFIGURATION - DO NOT EDIT THESE CONSTANTS
const int max_capacity = 15;
const int max_floor = 10;
const int min_floor = 0;


int elevator_occ = 0;
int elevator_floor = 0;


// Your function documentation goes here.
void set_floor(const int n) {
  // Error message:
  // "WARNING! Invalid Floor!\n"
  // Success message:
  // "You have reached floor XX.\n"
  
  // Your implementation goes here.
  if (n >= min_floor && n <= max_floor) {
    elevator_floor = n;
    printf("You have reached floor %d.\n", n);
  } else {
    printf("WARNING! Invalid Floor!\n");
  }
}

// Your function documentation goes here.
void enter(const int n) {
  // Error message:
  // "WARNING! Over Capacity!\n"
  // Success message:
  // "The number of passengers is XX.\n"
  
  // Your implementation goes here.
  assert(n > 0);
  if (n + elevator_occ <= max_capacity) {
    elevator_occ += n;
    printf("The number of passengers is %d.\n", elevator_occ);
  } else {
    printf("WARNING! Over Capacity!");
  }
}

// Your function documentation goes here.
void leave(const int n) {
  // Error message:
  // "WARNING! Invalid Leave!\n"
  // Success message:
  // "The number of passengers is XX.\n"
  
  // Your implementation goes here.
  assert(n > 0);
  assert(elevator_occ <= max_capacity);
  if (elevator_occ - n < 0) {
    printf("WARNING! Invalid Leave!\n");
  } else {
    elevator_occ -= n;
     printf("The number of passengers is %d.\n", elevator_occ);
  }
}

int main(void) {
  // Your assertion-based testing goes here.
  set_floor(-1);                // Invalid: floor too low  
  assert(elevator_floor == 0);
  set_floor(11);                // Invalid: floor too high
  assert(elevator_floor == 0);
  set_floor(5);                 // Valid
  assert(elevator_floor == 5);
  set_floor(min_floor);         // Valid: Min floor
  assert(elevator_floor == 0);  
  set_floor(max_floor);         // Valid: Max floor
  assert(elevator_floor == 10); 
  // enter tests
  enter(6);                     // Valid
  assert(elevator_occ == 6);
  enter(3);                     // Valid
  assert(elevator_occ == 9);
  enter(7);                     // Invalid: too many people
  assert(elevator_occ == 9);
  // leave tests
  leave(4);                     // Valid
  assert(elevator_occ == 5);
  leave(2);                     // Valid
  assert(elevator_occ == 3);
  leave(4);                     // Invalid: too many people
  assert(elevator_occ == 3);
  
  trace_msg("All tests have successfully passed!");
}