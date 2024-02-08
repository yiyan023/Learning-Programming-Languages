#include <stdio.h>
#include <stdlib.h>

int main () {
    int Num1;
    int Num2;
    printf("Enter the two numbers you want to add:\n");
    scanf("%d", &Num1);
    scanf("%d", &Num2);

    const int Sum = Num1 + Num2;
    printf("The sum of these numbers is %d.\n", Sum);
}