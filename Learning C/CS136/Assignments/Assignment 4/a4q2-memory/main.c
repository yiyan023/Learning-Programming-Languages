/////////////////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments > Assignment Information & Policies > Academic Integrity Policy)
/////////////////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:


//
// Name: Yiyan
// login ID: y84huang
//////////////////////////////////////////////////////////////////////////////////////////

#include "cs136.h"

struct arthur {
  int truth;
  int lies;
};

void mordred(struct arthur *a1, struct arthur *a2) {
  a1->truth *= 10;
  a2->truth += 30;
  a2->lies = a1->truth / 20;
  a1->lies = a2->lies - 4; 
  // <--- TRACE C
}

int magic(int *status, int power, int **wealth) {
  *status = *status + 1;
  // <--- TRACE B
  return *status + **wealth / power;
}

void merlin(int *good, int *evil) {
  *good = 30;
  // <--- TRACE A
  int *wealth = good;
  good = evil;
  *evil = *good / 10;
  *good = magic(evil, *good, &wealth);
}

int main(void) {
  int good = 10;
  int evil = 20;
  merlin(&good, &evil);

  struct arthur a1 = {50, 20};
  struct arthur a2 = {30, 40};
  mordred(&a1, &a2);
}