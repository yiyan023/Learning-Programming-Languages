#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

void countdown(const int n) {
    if (n == 1) {
        printf("%d", 1);
    } else {
        printf("%d\n", n);
        return countdown(n - 1);
    }
}

int main() {
    // defining variables -- C also supports local variables
    // syntax -- <type> <name> = <value>
    int value = 17;
    int foo; // does not assign a value to this variable

    //mutation is possible in C, unlike Racket
    int x = 5;
    x = 6;
    x = x + 10;
    x += 10;
    x *= 2;

    int y = 5;
    //if you put y++ in a return statement, it will return y and then increment it 
    printf("%d\n", y++); // returns 5
    printf("%d\n", ++y); //returns 6, 7 in this case because we increment y twice

    ++y; //also returns 6

    //constants -- add the word const in front of it
    const int x1 = 5;
    countdown(3);

    int read1;
    read1 = read_int(); // only works in the cs homework
    //otherwise, use scanf
    printf("%d\n", read1);
}   
