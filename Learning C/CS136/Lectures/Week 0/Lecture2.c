#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
// for assignments, you can use #include "cs136.h to include all these dependencies"

int last_digit(int Num) {
    return Num % 10;   
}

int rest_digits(int Num) {
    return Num / 10;
}

// can also do this recursively
int sum_to(int Num) {
    int Sum = 0;
    while (Num > 0) {
        Sum = Sum + Num;
        printf("%d ", Sum);
        Num = Num - 1;
    }
    return Sum;
    // return n + sum_to(n-1)
}

// design recipes  -- assert your requirements 

// my_div(x, y) returns the fraction of x/y
// requires: y is not 0
int my_div(int x, int y) {
    assert(y != 0); // ensures the y is NOT equal to zero
    return x / y;
}

// functions can be tested using assert

int sum_divisible(int n, int d0, int d1) {
    int Sum = 0;
    int i = 1;

    while (i <= n) {
        if (i % d0 == 0 || i % d1 == 0) {
            Sum = Sum + i;
        }
        i = i + 1;
    }

    return Sum;
}

int main() {
    int Num;
    printf("%d", sum_divisible(10, 3, 5));
    printf("Enter a number:");
    scanf("%d", &Num);
    printf("The last digit is %d\n", last_digit(Num));
    printf("The other digits are %d\n", rest_digits(Num));
    printf("The sum of 1 to %d is %d.\n", Num, sum_to(Num));

    // booleans -- use 0 and 1 instead of true & false
    // false is 0, true is 1
    bool One = 3 > 5;
    printf("%d\n", One);

    assert(my_div(10, 2) == 5);
    assert(my_div(22, 7) == 3);
    printf("All Tests passed!");
}
