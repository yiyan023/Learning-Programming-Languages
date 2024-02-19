#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

//structures in c -- does not have to be in int main
struct posn {
  int x;
  int y;
};

// function that allows us to add the x and y values of struct posn  
struct posn add_posn(struct posn a, struct posn b) {
  struct posn new_posn = {a.x + b.x, a.y + b.y};
  return new_posn;
}

// we cannot use == to compare struct values -- it will return a 
  // compiler error
bool posn_eq(struct posn a, struct posn b) {
  if (a.x == b.x && a.y == b.y) {
    return true;
  } else {
    return false;
  }
}

int main(void) {
  //overflow 
  // int value is stored using 32 bits -- smallest number is -2^31, largest is 
  // 2^31-1
  //i.e. if you try to add 1 to 2147483647, it will return -2147483648
  
  //char values -- very small integer, constrained between -128,  127
  char mychar = 42;
  printf("%d\n", mychar);
  
  //in cs136, we have defined a function that reads a single character from
  // stdin & returns READ_CHAR_FAIL if it does not work
  
  //IGNORE_WHITESPACE in cs136 ignores a whitespace 
  //READ_WHITESPACE reads the whitespace
  
  int i = 0;
  /* while (read_char(READ_WHITESPACE) != READ_CHAR_FAIL) {
    i++;
  } */
  
  printf("%d", i);
  
  //for printf, char uses %c, integer uses %d
  //char c = read_char(IGNORE_WHITESPACE);
  
  /* while (c != READ_CHAR_FAIL) {
    printf("%d (%c)\n", c, c);
    c = read_char(IGNORE_WHITESPACE);
  } */
  
  //symbols can be determined using global constants (check hamburgers 
  //assignment)
  
  //defining a variable:
  struct posn p = {3, 5};
  struct posn q = {10, 20};
  struct posn r = {3, 5};
  printf("(%d, %d)\n", p.x, p.y); //prints (3, 5)
  
  struct posn p0 = add_posn(p, q);
  printf("(%d, %d)\n", p0.x, p0.y); //prints (13, 25)
  printf("%d\n", posn_eq(p, q)); //returns 0 because they are not equal;
  printf("%d\n", posn_eq(p, r)); //returns 1 because they are equal
  
  //POINTERS!! 
  // C was designed to give programmers "low-level" access to memory & expose 
  // underlying memory model 
  // address operator -- &, address of an identifier can be found using this 
  
  // in C, a pointer is used for storing an address 
  // done by adding * after some type T, making T * a pointer to T 
  
  int i = 42; //a variable named i that stores 42
  int *p = &i; //a variable named p that stores the address of i
  
  // type of p is "int *", which points to the int of i, it is the arrow 
  // pointing to a value 
  
  int x = 5;
  int *p = &x;
  int **q = &p; // points to a pointer
}