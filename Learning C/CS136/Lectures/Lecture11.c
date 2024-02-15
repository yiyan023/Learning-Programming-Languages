#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <Modules/rational.h>

// function declarations -- allows you to do mutual recursion
int F(int n);
int M(int n);

// following functions allows you to return alternating 0s and 1s
int F(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n - M(F(n-1));
    }
}

int M(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n - F(M(n-1));
    }
}

int main(void) {
    printf("F:");
    for (int i = 0; i < 24; i++) {
        printf("%d, ", F(i));
    }
    printf("\nM:");
    for (int i = 0; i < 24; i++ ) {
        printf(" %d", M(i));
    }

    //  rational part -- h file is the header, which makes the function declarations, c file is the functionality
    struct rational half = {1, 2};
    print_rational(&half);
    print_rational(&PI);
} 

// prime.h is a module that allows us to check whether an integer is a prime number