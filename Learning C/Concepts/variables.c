#include <stdio.h>
#include <stdlib.h>

int main ()
{
    /* Different Data Types for Variables */
    char characterName[] = "John";
    char Grade = "A";
    double GPA = 3.0;
    int Age = 40;

    /* They can also be turned into constants */
    const char characterName[] = "John";
    char const Grade = "A";
    const double GPA = 3.0;
    int const Age = 40;

    printf("The man's name is %s\n", characterName);
    return 0;
}