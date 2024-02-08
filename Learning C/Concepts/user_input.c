#include <stdio.h>
#include <stdlib.h>

int main ()
{
    /* Input Age */
    int Age;
    printf("Enter your age:\n");
    scanf("%d", &Age);
    printf("Your age is %d.\n", Age);

    /* Input Name */
    char Name[25];
    printf("Enter your name:\n");
    fgets(Name, 25, stdin);
    printf("Your Name is: %s\n", Name);
}