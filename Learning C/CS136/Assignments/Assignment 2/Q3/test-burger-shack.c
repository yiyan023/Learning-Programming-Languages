// This program is an I/O Driver for the CS 136 Burger Shack Module
// See burger-io.txt for instructions

#include "burger-shack.h"
#include "cs136-trace.h"
#include <stdio.h>

// complete your I/O Driver here
// (it can all be in your main function)
// you do NOT need to worry about invalid input
// (e.g., input that does not match what is in burger-io.txt)

// You may use our code from A2 as the starting point for your solution

// you must NOT access any of the fields of shack directly in this file
// (i.e., you must not use shack.???)

int main(void) {
  struct burger_shack shack = empty_shack;
  int cmd = read_symbol();
  while (1){
    if (cmd == lookup_symbol("quit")){
      break;
    }
    if (cmd == lookup_symbol("add")) {
      int type = read_symbol();
      int qty = 0;
      int returnvalue = (scanf("%d", &qty));
      if (returnvalue != 1) {
        printf("UNEXPECTED: INVALID INPUT FILE [add]\n");
        return 0;
      }
      if (type == lookup_symbol("buns")) {
        add_buns(&shack, qty);
      } else if (type == lookup_symbol("cheese")) {
        add_cheese(&shack, qty);
      } else if (type == lookup_symbol("patties")) {
        add_patties(&shack, qty);
      } else if (type == lookup_symbol("pickles")) {
        add_pickles(&shack, qty);
      } else {
        printf("UNEXPECTED: INVALID INPUT FILE [add]\n");
        return 0;
      }
    } else if (cmd == lookup_symbol("order")) {
      int qty = 0;
      int returnvalue = (scanf("%d", &qty));
      if (returnvalue != 1) {
        printf("UNEXPECTED: INVALID INPUT FILE [order]\n");
        return 0;
      }
      order(&shack, qty);
    } else if (cmd == lookup_symbol("inventory")) {
      check_inventory(&shack);
    } else if (cmd == lookup_symbol("quit")) {
      return 0;
    } else {
      printf("UNEXPECTED: INVALID INPUT FILE [bad/missing command]\n");
      return 0;
    }
    cmd = read_symbol();
  }
}
