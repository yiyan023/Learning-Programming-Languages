//TODO: move to school environment to include this
//#include "cs136.h"
#include "assert.h"
#include "stdbool.h"
#include "stdio.h"
#include "topping.h"

// THIS FILE IS INTENTIONALLY UNDOCUMENTED AS IT IS NOT MEANT TO BE STUDENT FACING
const char INVALID_TOPPING = '\0';


struct topping topping_init(void) {
    struct topping new_topping = {INVALID_TOPPING,0};
    return new_topping;
}

struct topping topping_make(char n, int p) {
    assert((n >= 'a' && n <= 'z') || (n >= 'A' && n <= 'Z'));
    assert(p >= 0);
    struct topping new_topping;
    new_topping.name = n;
    new_topping.price = p;
    return new_topping;
}

void topping_clone(struct topping *dest, const struct topping *src) {
    dest->name = src->name;
    dest->price = src->price;
}

bool topping_equals(const struct topping *t1, const struct topping *t2) {
  if (t1->name == t2->name && t1->price == t2->price) {
    return true;
  }
  return false;
}

char topping_name(const struct topping *t) {
  return t->name;
}

void topping_price(const struct topping *t, int *pprice) {
  *pprice = t->price;
}

