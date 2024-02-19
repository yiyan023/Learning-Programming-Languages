#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

// design recipe:
// sum_divisible(n, d0, d1) Calculate the sum of all numbers from 0 to n that are dividisble by one or more of d0, d1.
// requires: d0 != 0, d1 != 0, n >= 0
int sum_divisible(int n, int d0, int d1) {
    if (0 == n) {
        return 0;
    } else if ( n % d0 == 0 || n % d1 == 0) {
        return n + sum_divisible(n-1, d0, d1);
    } else {
        return sum_divisible(n-1, d0, d1);
    }
}

// has_divisor_below(n, d) Determines if any number between 2 and d divides n
// requires: n >= 0 and d >= 1

bool has_divisor_below(int n, int d) {
    assert(d >= 1);
    assert(n >= 0); //ensures these conditions are true
    
    if (d == 1) { //when d reaches 1, that means we have finally recursed through 2 and d
        return false;
    } else if (n % d == 0) {
        return true;
    } else {
        return has_divisor_below(n, d-1); //recursion
    }
}

// is_prime(n) Determines if n is prime
// no requirements
bool is_prime(int n) {
    if (n < 2) {
        return false;
    } else {
        return !has_divisor_below(n, n-1); //definitely more efficient way
    }
}

//fib(n) returns the nth term in the fibonacci sequence
//requires: n >= 0
int fib(int n) {
    assert(n >= 0);
    //trace_int(n);
    if (n < 2) {
        return n;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

// tail recursion/accumulative recursion in C:
int sum_to_acc(int n, int acc) {
    assert(n >= 0);
    if (n == 0) {
        return acc;
    } else {
        return sum_to_acc(n-1, n + acc);
    }
}

int fact_helper(int n, int acc) {
    if (n == 0) {
        return acc;
    } else {
        return fact_helper(n-1, acc * n);
    }
}

int fact(int n) {
    return fact_helper(n, 1);
}

int main(void) {
    // for testing
    assert(sum_divisible(0, 4, 7) == 0);
    assert(sum_divisible(10, 3, 5) == 33);

    assert(has_divisor_below(25, 6)); //true
    assert(!has_divisor_below(17, 1)); //false
    assert(!has_divisor_below(25, 4)); //false

    assert(fib(0) == 0);
    assert(fib(1) == 1);
    assert(fib(2) == 1);
    assert(fib(4) == 3);

    assert(sum_to_acc(3, 0) == 6);
    printf("all tests passed!");

    //printf can be used for debugging
    
}
