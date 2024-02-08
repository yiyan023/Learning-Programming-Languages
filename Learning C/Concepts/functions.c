#include <stdio.h>
#include <stdlib.h>

void sayHi () {
    printf("Hello User!"); /* will NOT return anything unless you call it in main */
}

/* You can call parameters in a function */

void sayHi2 (char Name[]) {
    printf("Hello, %s!", Name);
}

double cube (double Num) {
    double Result = Num * Num * Num;
    return Result;
}

int main() {
    sayHi();
    sayHi2("Mike");
    printf("%f", cube(3));
}