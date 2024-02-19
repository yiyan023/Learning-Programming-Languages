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

const char INVALID_TOPPING = '\0';


struct topping{
    char name;  // a single character to represent the name of the 
                // topping. The character must be an english 
                // alphabet: a-zA-Z e.g. g for Gummy Bears, 
                // h for Hot Fudge, c for Chocolate Chips
    int price; // price of topping in cents
};

// topping_init() returns an initialized struct topping 
//   with an INVALID_TOPPING name
struct topping topping_init(void) {
    struct topping new_topping = {INVALID_TOPPING, 0};
    return new_topping;
}


/////////////////////////////////////////////////////////
/////////// DO NOT MODIFY ANY CODE ABOVE THIS ///////////
/// YOU MUST OF COURSE UPDATE THE INTEGRITY STATEMENT ///
/////////////////////////////////////////////////////////


// topping_make(n, p) returns a struct topping with n as name and p as price.
// requires: n must be a valid topping name and p must be non-negative
struct topping topping_make(const char n, const int p) {
    // your implementation goes here
    // the following is an INCORRECT implementation and is here just so that 
    // the program compiles as written. Make sure to fix it.
    assert(p >= 0);
    assert((n >= 'a' && n <= 'z') || (n >= 'A' && n <= 'Z'));
    struct topping new_topping = {n, p};
    return new_topping;
}

// topping_clone(dest, src) clones the struct topping *src onto 
//   the struct topping *dest.
// effect: mutate *dest
// requires: dest and src are not NULL
void topping_clone(struct topping *dest, const struct topping *src) {
    // your implementation goes here
    assert(dest != NULL && src != NULL);
    dest->name = src->name;
    dest->price = src->price;
}

// topping_equals(t1, t2) returns true if t1 and t2 have identical names and prices,
//   and false otherwise.
// requires: t1 and t2 are not NULL
bool topping_equals(const struct topping *t1, const struct topping *t2) {
  // your implementation goes here
  assert(t1 != NULL && t2 != NULL);
  if (t1->name == t2->name && t1->price == t2->price) {
    return true;
  } else {
    return false;
  }
}

// topping_name(t) returns the name of *t.
// requires: t is not NULL
char topping_name(const struct topping *t) {
  // your implementation goes here
  assert(t != NULL);
  return t->name;
}

// topping_price(t, price) stores the price of *t in *price.
// effects: mutates *price.
// requires: t and price are not NULL
void topping_price(const struct topping *t, int *price) {
  // your implementation goes here
  assert(t != NULL && price != NULL);
  *price = t->price;
}


int main(void) {
  // public test
  int name = 'c';  //chocolate chips
  int price = 125; // cost 125 cents
  int name2 = 'h';
  int price2 = 120;
  
  struct topping my_topping = topping_make(name, price);
  struct topping clone_topping = topping_make(name, price);
  struct topping new_topping = topping_make(name2, price2);
  struct topping my_topping_clone = topping_init();
  assert(&my_topping != &my_topping_clone);
  
  // change my_topping_clone
  topping_clone(&my_topping_clone, &my_topping);
  
  assert(topping_equals(&my_topping, &clone_topping));
  assert(topping_equals(&my_topping, &new_topping) == false);
  assert(topping_equals(&my_topping, &my_topping_clone));
  assert(topping_name(&my_topping) == name);
  assert(topping_name(&my_topping_clone) == name);
  
  int my_topping_price = -1;
  topping_price(&my_topping, &my_topping_price);
  assert(my_topping_price == my_topping.price);

}