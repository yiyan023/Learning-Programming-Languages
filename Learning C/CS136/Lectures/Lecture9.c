#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

//returns an integer that it can read when possible, otherwise returns 
  // READ_INT_FAIL
int my_read_int(void) {
  int i = 0;
  int count = scanf("%d", &i);
  
  if (count != 1) {
    //return READ_INT_FAIL;
  } else {
    return i;
  }
}

void read_once_char(void) {
  char c = 'O';
  int count = scanf("%c", &c);
  printf("c is %c; count is %d\n", c, count);
}

void read_once(void) {
  int i = 12345;
  int count = scanf("%d", &i);
  printf("i is %d; count is %d\n", i, count);
}

// will turn all as to As
void a_to_A(void) {
  char c = '\0';
  int count = scanf("%c", &c);
  
  while (count == 1) {
    if (c == 'a') {
      printf("A");
    } else {
      printf("%c", c);
    }
    
    count = scanf("%c", &c);
  }
}

int add(int x, int y) { return x + y; }

int main(void) {
  // scanf can be used as read_int and read_char 
  read_once();
  read_once();
  
  // 42 will return a count of 1
  // 24601 will return a count of 1
  
  // if no number is inputted, it will return -1
  
  // returns 0 if it is not an integer (i.e. abc)
  // every proceeding input will also be returned as 0
  
  read_once_char();
  read_once_char();
  
  // similar logic applies
  a_to_A();
  
  // note -- pointers also works for structures 
  
  //const pointers -- prevents things (variables) being changed
  // you can change where the arrow (pointer) points at, but you cannot change 
      // the value
  //const int * p = 0; // can go before or after the data type
  //int const * i = 0; //constant pointer i points to an integer
  
  //int * const b = &i; // constant pointer b points to integer  
  
  //function pointers 
  int (*f)(int x, int y) = &add; //int, int are the parameters -- address of 
      // function add 
  
  assert(f(3, 4) == 7);
}
