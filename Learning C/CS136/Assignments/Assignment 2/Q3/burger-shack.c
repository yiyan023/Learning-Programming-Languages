
///////////////////////////////////////////////////////////////////////////// 
// INTEGRITY STATEMENT (v3)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement:
// https://student.cs.uwaterloo.ca/~cs136/current/assignments/integrity.shtml
/////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with: 
 
// No one
//  
// Name: Avery Lin 
// login ID: x254lin 
///////////////////////////////////////////////////////////////////////////// 

#include "cs136-trace.h"
#include "burger-shack.h"
#include <stdio.h>

// This initial "empty" shack depends on your burger_shack structure.
// Because we don't know what your fields are, we can't do this for you.
// If your fields simply need to be all initialized to zero, then
//   you do not have to change this constant:
const struct burger_shack empty_shack = {0};

// you must complete this implementation

void add_pickles(struct burger_shack *shack, int jars) {
  int pickles_per_jar = 250;
  if (jars < 1){
    printf("invalid: add_pickles\n");
  } else {
    shack->pickles += jars * pickles_per_jar;
  }
}

void add_buns(struct burger_shack *shack, int crates) {
  int buns_per_crate = 144;
  if (crates < 1){
    printf("invalid: add_buns\n");
  } else {
    shack->buns += crates * buns_per_crate;
  }
}

void add_cheese(struct burger_shack *shack, int blocks) {
  int cheese_per_block = 36;
  if (blocks < 1){
    printf("invalid: add_cheese\n");
  } else {
    shack->cheese += blocks * cheese_per_block;
  }
}

void add_patties(struct burger_shack *shack, int boxes) {
  int patties_per_box = 48;
  if (boxes < 1){
    printf("invalid: add_patties\n");
  } else {
    shack->patties += boxes * patties_per_box;
  }
}

void order(struct burger_shack *shack, int burgers) {  
  
  int pickles_per_burger = 3;
  int buns_per_burger = 1;
  int cheese_per_burger = 2;
  int patties_per_burger = 2;
  
  if (burgers < 1){
    printf("invalid: order\n");
  } else {
    int capacity_buns = shack->buns / buns_per_burger;
    int capacity_cheese = shack->cheese / cheese_per_burger;
    int capacity_patties = shack->patties / patties_per_burger;
    int capacity_pickles = shack->pickles / pickles_per_burger;
    if (capacity_buns < burgers || capacity_cheese < burgers || 
        capacity_patties < burgers || capacity_pickles < burgers){
      printf("order cancelled:\n");
      if (capacity_buns < burgers){
        printf("  not enough buns\n");
      }
      if (capacity_cheese < burgers){
        printf("  not enough cheese\n");
      }
      if (capacity_patties < burgers){
        printf("  not enough patties\n");
      }
      if (capacity_pickles < burgers){
        printf("  not enough pickles\n");
      }
    } else {
      int pickles_per_burger = 3;
      int buns_per_burger = 1;
      int cheese_per_burger = 2;
      int patties_per_burger = 2;
      shack->buns -= buns_per_burger * burgers;
      shack->cheese -= cheese_per_burger * burgers;
      shack->patties -= patties_per_burger * burgers;
      shack->pickles -= pickles_per_burger * burgers;
      printf("order complete: %d burgers\n", burgers);
    }
  }
}

void print_warning(int qty, int qty_per_burger){
  int capacity = qty / qty_per_burger;
  int inventory_low = 10;
  int inventory_hi = 100;
  if (capacity < inventory_low){
    printf("WARNING\n");
  } else if (capacity < inventory_hi){
    printf("LOW\n");
  } else {
    printf("OK\n");
  }
}

void check_inventory(const struct burger_shack *shack) {
  int pickles_per_burger = 3;
  int buns_per_burger = 1;
  int cheese_per_burger = 2;
  int patties_per_burger = 2;
  printf("inventory:\n");
  printf("  buns: [%d] ", shack->buns);
  print_warning(shack->buns, buns_per_burger);
  printf("  cheese: [%d] ", shack->cheese);
  print_warning(shack->cheese, cheese_per_burger);
  printf("  patties: [%d] ", shack->patties);
  print_warning(shack->patties, patties_per_burger);
  printf("  pickles: [%d] ", shack->pickles);
  print_warning(shack->pickles, pickles_per_burger);
}
