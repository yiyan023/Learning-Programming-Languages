#include <stdio.h>
#include <stdlib.h>

int main () {
    int Age = 30;
    int * pAge = &Age;

    printf("%p", pAge); /* Pointer Address */
    printf("%d", *pAge); /* Deference Pointer */
}