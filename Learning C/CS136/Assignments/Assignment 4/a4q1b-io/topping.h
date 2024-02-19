// This file contains C features that you have not yet seen
// in class. However, we are still showing this to you for 
// transparency and to avoid confusion.

// The key thing to know is simply the list of functions
// that you may rely upon while implementing the functions
// in this problem

// It is considered bad style to not have documentation in 
// .h (header) files. The only reason we chose to do this is
// because we want students to rely on the documentation in 
// the code given in previous questions. Please refer there 
// for documentation for each function. 
#ifndef TOPPING_H
#define TOPPING_H

#include <stdbool.h>

extern const char INVALID_TOPPING;

struct topping{
    char name;  
    int price; 
};

struct topping topping_init(void);

struct topping topping_make(char n, int p);

void topping_clone(struct topping *dest, const struct topping *src);

bool topping_equals(const struct topping *t1, const struct topping *t2);

char topping_name(const struct topping *t);

void topping_price(const struct topping *t, int *pprice);

#endif
