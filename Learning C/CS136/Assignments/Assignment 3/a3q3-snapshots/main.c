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

// This code doesn't do anything special.
// We just wanted some fun names (identifiers)

const int bb = 3;
int rogue = 2;

int poe(int c, int d) {
  printf("printing within poe(%d, %d)\n", c, d);    // snapshot here (first and third time)
  rogue--;
  int e = c - d;
  if (e >= 0) {
    return c / 2;
  } else {
    return d / 2;
  }
}

int rey(int b) {
  int a = poe(b * -5, b * 3);
  printf("printing within rey(%d)\n", b);    // snapshot here
  return a;
}

int finn(int a) {
  const int y = poe(rey(a - 1), a + 1);
  int z = poe(y, 2 * y);
  z += y;
  printf("printing within finn(%d)\n", a);   // snapshot here
  return y + z + rogue + bb;
}

int main(void) {
  int x = finn(6);
  printf("x = %d\n", x);
}