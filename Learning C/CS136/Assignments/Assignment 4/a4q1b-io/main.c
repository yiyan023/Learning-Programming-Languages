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
#include "topping.h" // we have not yet discussed include statements. 
              // This is needed here if we are to provide you with a 
              // correct implementation of the functions discussed in 
              // the previous subproblem. 
              

// read_topping(t) reads from standard input a character and an integer. 
//   Whitespace is ignored. 
//   The character and integer must satisfy the requirements for the 
//   name and price of a topping as specified by the definition for 
//   struct topping in the previous problem.
//   The function uses valid inputs to update *t and returns true.
//   If valid inputs are not provided or an error occurs while 
//   attempting to read either of these inputs, *t is not updated 
//   and the function returns false. 
// effects: reads from standard input and may mutate *t
// requires: t is not NULL
bool read_topping(struct topping *t){
  // your implementation comes here
  assert(t != NULL);
  
  char topping;
  int price;
  
  scanf("%c", &topping);
  scanf("%d", &price);
  
  if (topping >= 'a' && topping <= 'z' && price >= 0) {
    t->name = topping;
    t->price = price;
    return true;
  } else if (topping >= 'A' && topping <= 'Z' && price >= 0) {
    t->name = topping;
    t->price = price;
    return true;
  } else {
    return false;
  }
}

// print_topping(t) will print the name and price of the topping 
//   if the topping name and price satisfy the requirements specified
//   in the struct topping's type definition from the previous problem
//   Format string "Name: %c Price: %d\n"
// effects: may produce output
// requires: t is not NULL
void print_topping(const struct topping *t){
  // your implementation comes here
  assert(t != NULL);
  
  if (t->name >= 'a' && t->name <= 'z' && t->price >= 0) {
    printf("Name: %c Price: %d\n", t->name, t->price);
  } else if (t->name >= 'A' && t->name <= 'Z' && t->price >= 0) {
    printf("Name: %c Price: %d\n", t->name, t->price);
  } else {
    printf("Failed to read topping. \n");
  }
}


int main(void) {
  // public test
  struct topping my_topping = topping_init();
  if ( read_topping(&my_topping) ) {
      print_topping(&my_topping);
  } else {
    printf("Failed to read topping.\n");
  }

}