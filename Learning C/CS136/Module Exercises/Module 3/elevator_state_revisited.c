#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

// ELEVATOR CONFIGURATION - DO NOT EDIT THESE CONSTANTS
const int OCCUPANCY_MAX = 15;
const int FLOOR_MAX = 10;
const int FLOOR_MIN = 0;

int elevator_occ = 0;
int elevator_floor = 0;

// set_floor(n) sets the elevator floor or outputs an error if there is no
//   floor n.
// effects: produces output
//          may mutate global variable elevator_floor
void set_floor(const int n) {
  if (n >= FLOOR_MIN && n <= FLOOR_MAX) {
    elevator_floor = n;
    printf("You have reached floor %d.\n", elevator_floor);
  } else {
    printf("WARNING! Invalid Floor!\n");
  }
}

// enter(n) increases the number of passengers by n or outputs an error
//   message if the number of passengers exceeds the maximum occupancy.
// requires: n >= 0
// effects: produces output
//          may mutate global variable elevator_occ
void enter(const int n) {
  assert(n >= 0);
  if (elevator_occ + n > OCCUPANCY_MAX) {
    printf("WARNING! Over Capacity!\n");
  } else {
    elevator_occ += n;
    printf("The number of passengers is %d.\n", elevator_occ);
  }
}

// leave(n) decreases the number of passengers by n or outputs an error
//   message if the number of passengers would become negative.
// requires: n >= 0
// effects: produces output
//          may mutate global variable elevator_occ
void leave(const int n) {
  assert(n >= 0);
  if(n > elevator_occ) {
    printf("WARNING! Invalid Leave!\n");
  } else {
    elevator_occ -= n;
    printf("The number of passengers is %d.\n", elevator_occ);
  }
}

int main(void) {
  // Add the implementation for testing "enter" and "leave".
  
  const int FLOOR = lookup_symbol("floor");
  const int ENTER = lookup_symbol("enter");
  const int LEAVE = lookup_symbol("leave");

  while (true) {
    int cmd = read_symbol();
    if (cmd == FLOOR) {
      int flr = read_int();
      if (flr == READ_INT_FAIL) {
        break;
      }
      set_floor(flr);
    } else if (cmd == ENTER) {
      int ent = read_int();
      
      if (ent == READ_INT_FAIL) {
        break;
      }
      enter(ent);
    } else if (cmd == LEAVE) {
      int left = read_int();
      
      if (left == READ_INT_FAIL) {
        break;
      }
      
      leave(left);
    } else {
      break;
    }
  }
}