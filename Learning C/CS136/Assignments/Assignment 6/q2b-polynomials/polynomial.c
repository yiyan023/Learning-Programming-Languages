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
#include "polynomial.h"
#include <stdio.h>

// Your additional includes go here.

const int POLYNOMIAL_MAXDEG = 100;

// max(a, b) returns the greater value between the two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

// See polynomial.h for documentation.
struct polynomial polynomial_init(void) {
    struct rational data[101];
    
    for (int i = 0; i < POLYNOMIAL_MAXDEG; i++) {
        data[i].num = 0;
        data[i].denom = 1;
    }

    // Assigning each element of the array individually
    struct polynomial init;
    init.deg = POLYNOMIAL_MAXDEG;
    for (int i = 0; i < POLYNOMIAL_MAXDEG; i++) {
        init.data[i] = data[i];
    }

    return init;
}

// See polynomial.h for documentation.
struct polynomial polynomial_read(void) {
    // Your implementation includes goes here.
    int deg = 0;
    scanf("%d", &deg);

    int num = 0;
    int denom = 1;

    struct polynomial newPoly = polynomial_init();
    newPoly.deg = deg;

    while (scanf("%d", &num) == 1 && scanf("%d", &denom) == 1) {
        if (deg < 0) {
            break;
        }

        newPoly.data[deg].num = num;
        newPoly.data[deg].denom = denom;
        deg -= 1;
    }

    return newPoly;
}

// See polynomial.h for documentation.
void polynomial_print(const struct polynomial *p) {
    // Your implementation includes goes here.

    int deg = p->deg;

    while (deg > 0) {
        rational_print(&p->data[deg]);
        
        if (deg > 1) {
            printf(" x^%d + ", deg);
        } else {
            printf(" x + ");
        }

        deg -= 1;
    }

    rational_print(&p->data[deg]);
    printf("\n");
}

// See polynomial.h for documentation.
void polynomial_add(struct polynomial *dest, const struct polynomial *src) {
    // Your implementation includes goes here.
    int deg = max(dest->deg, src->deg);

    while (deg >= 0) {
        dest->data[deg] = rational_add(src->data[deg], dest->data[deg]);
        deg -= 1;
    }
}

// See polynomial.h for documentation.
void polynomial_copy(struct polynomial *dest, const struct polynomial *src) {
    // Your implementation includes goes here.
    int deg = POLYNOMIAL_MAXDEG;

    while (deg >= 0) {
        dest->data[deg] = src->data[deg];
        deg -= 1;
    }

    dest->deg = src->deg;
}

// See polynomial.h for documentation.
void polynomial_mul(struct polynomial *dest, const struct polynomial *src) {
    // Your implementation includes goes here.

    struct polynomial product = polynomial_init();
    product.deg = dest->deg + src->deg;

    for (int i = 0; i <= dest->deg; i++) {
        for (int j = 0; j <= src->deg; j++) {
            product.data[i + j] = rational_add(rational_mul(dest->data[i], src->data[j]), product.data[i + j]);
        }
    }

    dest->deg = product.deg;

    for (int i = 0; i <= product.deg; i++) {
        dest->data[i] = product.data[i];
    }
}