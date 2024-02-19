#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

void show_int_ptr(int i, int *p) {
  printf("%p\n", p);
  printf("%p\n", &i);
}

int main() {
  int x = 5;
  int y = 6;
  int *q = &y; //stores the memory address of y in q
  
  show_int_ptr(x, q);
  show_int_ptr(x, &x); //different -- *p points to &x, and returns &i
  
  // this also applies to global variables too
  // *p points  to the contents of the box inside p 
  // &p gets the address of box p
  
  int i = 42;
  
  // * can be used for pointer definitions & pointer types 
  int *m = &i;
  
  // * can be used as the indireciton operator for pointers 
  //int j = *m;
  *m = 5;
  
  int a = 9;
  int b = 9;
  int *c = &b;
  
  printf("%d\n", a * *c); //multiply a * (*c)
  
  int **p = &c; //point to the pointer 
  printf("%d\n", (**p) * (**p));
  
  // remember how to draw stack chain
}
