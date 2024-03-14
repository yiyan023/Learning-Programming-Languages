///////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments >  Information & Policies > Academic Integrity Policy)
///////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

//
//
// Name: Yiyan Huang
// login ID: y84huang
///////////////////////////////////////////////////////////////////////////////

#include "cs136-trace.h"
#include "rational.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// Your additional includes go here.

// === HELPER FUNCTIONS =======================================================

// Your helper functions includes go here.

// === MODULE FUNCTIONS =======================================================

// See rational.h for documentation.
struct rational rational_init(int num, int denom) {
    // Your implementation goes here.
    assert(denom != 0);

    int div = 1;
    int maxDiv = 1;

    while (div <= num && div <= denom) {
        if (num % div == 0 && denom % div == 0) {
            maxDiv = div;
        }

        div += 1;
    }

    struct rational simpleRational = {num / maxDiv, denom / maxDiv};
    return simpleRational;
    
}

// See rational.h for documentation.
bool rational_eq(struct rational a, struct rational b) {
    // Your implementation goes here.
    return a.num  * b.denom == a.denom % b.num;
}

// See rational.h for documentation.
void rational_print(const struct rational *r) {
    assert(r);
    if (r->num == 0 || r->denom == 1) {
        printf("%d\n", r->num);
    } else if (abs(r->num) < r->denom) { // r->denom cannot be non-positive
        printf("%d/%d\n", r->num, r->denom);
    } else { // r->num cannot be 0
        if (r->num > 0) {
            printf("%d %d/%d\n", r->num / r->denom, r->num % r->denom, r->denom);
        } else { // if (r->num < 0)
            printf("%d %d/%d\n", r->num / r->denom, abs(r->num) % r->denom, r->denom);
        }
    }
}

// See rational.h for documentation.
struct rational rational_add(struct rational a, struct rational b) {
    // Your implementation goes here.

    int num = a.num * b.denom + b.num * a.denom;
    int denom = a.denom * b.denom;

    return rational_init(num, denom);
}

// See rational.h for documentation.
struct rational rational_mul(struct rational a, struct rational b) {
    // Your implementation goes here.
    return rational_init(a.num * b.num, a.denom * b.denom);
}

// See rational.h for documentation.
struct rational rational_div(struct rational a, struct rational b) {
    // Your implementation goes here.
    assert(b.num != 0);
    return rational_init(a.num * b.denom, a.denom * b.num);
}

// See rational.h for documentation.
struct rational rational_reciprocal(struct rational r) {
    // Your implementation goes here.
    assert(r.num != 0);
    return rational_init(r.denom, r.num);
}