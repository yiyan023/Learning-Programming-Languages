#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

struct business {
  int id;
  int profit;
  char bracket;
};

// Document and implement update_bracket
void update_bracket(struct business *bus) {
  assert(bus);
  if (bus->profit >= 100000) {
    bus->bracket = 'A';
  } else {
    bus->bracket = 'B';
  }
}

// Document and implement calculate_tax
int calculate_tax(struct business *bus) {
  assert(bus);
  assert(bus->bracket == 'A' || bus->bracket == 'B');
  
  int tax = 0;
  
  if (bus->bracket == 'A') {
    tax = bus->profit * 4 / 5;
    return tax;
  } else if (bus->bracket == 'B' && bus->profit >= 0) {
    tax = bus->profit * 17 / 20;
    return tax;
  } else {
    return 0;
  }
}

int main(void) {
  // Your assertion-based tests go here.
  struct business one = {1, 100100, CHAR_MIN};
  struct business two = {2, 8231, CHAR_MIN};
  struct business three = {3, -5, CHAR_MIN};
  
  update_bracket(&one);
  calculate_tax(&one);
  update_bracket(&two);
  calculate_tax(&two);
  update_bracket(&three);
  
  assert(calculate_tax(&one) == 80080);
  assert(calculate_tax(&two) == 6996);
  assert(calculate_tax(&three) == 0);
  printf("yay");
}