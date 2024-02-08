#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Please fill in the following blanks:\n");

    char pluralNoun[30];
    char Occupation[50];
    printf("Hello, my fellow ______ in 2020, it's me, George Washington, the first _____. \n");
    printf("Now, enter a plural nown: \n");
    scanf("%s", &pluralNoun);
    printf("Now, enter an occupation: \n");
    scanf("%s", &Occupation);
    printf("Hello, my fellow %s in 2020, it's me, George Washington, the first %s. \n", pluralNoun, Occupation);

    char Place[50];
    int Num;
    printf("I am writing from (the) ______, where I have been secretly living for the past ___ years.\n");
    printf("Now, enter a place: \n");
    scanf("%s", &Place);
    printf("Now, enter a number: \n");
    scanf("%d", &Num);
    printf("I am writing from (the) %s, where I have been secretly living for the past %d years.\n", Place, Num);
}