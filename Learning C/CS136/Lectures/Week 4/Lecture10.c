#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

//returns an integer that it can read when possible, otherwise returns 
  // READ_INT_FAIL
  
int int_sum(int a[], int len) {
  int acc = 0;
  
  for (int i = 0; i < len; i++) {
    acc += a[i];
  }
  
  return acc;
}

int sqr(int x) { return x * x; }

// maps to int sqr(int x)
void array_map(int (*f)(int), int a[], int len) {
  for (int i = 0; i < len; i++) {
    a[i] = f(a[i]);
  }
}

int char_sum(char *p, int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += *p;
    p += 1;
  }
  
  return sum;
}

int main(void) {
  // arrays -- once you create an array, you cannot change its length 
  // every item in the array must be the same type 
  // in c, an array does not store its length so we need another parameter for
      // that 

  int a[6] = {1, 2, 2, 5, 14, 42};
  int array[5] = {2, 4, 6, 0, 1};
  printf("%d\n", int_sum(array, 5)); //should print 13
  
  //int j = a[3]; // sets j to 5
  //int *p = &a[j - 1]; //points to a[4]
  a[2] = 5; //sets a[2] equal to 5
  ++ a[3]; //a[3] becomes 6 
  
  for (int i = 0; i < 5; i++) printf(" %d", array[i]);
  printf("\n");
  array_map(&sqr, array, 5);
  for (int i = 0; i < 5; ++i) printf(" %d", array[i]);
  printf("\n");
  
  // if you create an array with not enough values, it will automatically 
     // initialize the other terms in the array as 0
  
  // note that you can only mutate specific elements in an array, not the 
     // whole array
  
  int thousand[1000] = {0};
  
  for (int i = 0; i < 1000; i++) {
    thousand[i] = i;
  }
  
  assert(int_sum(thousand, 1000) == 499500);
  printf("true.\n");
  
  // each char in an array is held in memory increments by 1 for a succeeding
     // element 
  char plato[5] = {4, 6, 8, 12, 20};
  char *p = &plato[0];
  for (int i = 0; i < 5; i++) {
    printf("p+%d = %p, *(p + %d) = %d\n", i, p + i, i, *(p + i));
    
    //result:
       // p+0 = 0x7f3ae78010c0, *(p + 0) = 4
       // p+1 = 0x7f3ae78010c1, *(p + 1) = 6
       // p+2 = 0x7f3ae78010c2, *(p + 2) = 8
       // p+3 = 0x7f3ae78010c3, *(p + 3) = 12
       // p+4 = 0x7f3ae78010c4, *(p + 4) = 20
  }
  
  printf("%d\n", char_sum(&plato[0], 5)); //returns 50
  printf("%d\n", char_sum(&plato[0], 3)); //adds up 3 values, returns 18 
  printf("%d\n", char_sum(&plato[2], 3)); //adds up 3 values, returns 40
  
  // assert that pointers are NOT NULL!!
  
  //sizeof operator -- produces number of bytes required to store a type or 
     // variable
}
