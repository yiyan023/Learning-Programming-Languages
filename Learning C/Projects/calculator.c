#include <stdio.h>
#include <stdlib.h>

int main() {
    double Num1;
    double Num2;
    double Result;
    char Operation;

    printf("Enter a number:");
    scanf("%lf", &Num1);

    printf("Enter an operation:");
    scanf("%s", &Operation);

    printf("Enter another number:");
    scanf("%lf", &Num2);

    if (Operation == '+') {
        Result = Num1 + Num2;
    } else if (Operation == '-') {
        Result = Num1 - Num2;
    } else if (Operation == '*') {
        Result = Num1 * Num2;
    } else if (Operation == '/') {
        Result = Num1 / Num2;
    } else {
        printf("Invalid Operator");
    }
    printf("The answer is: %f", Result);
}