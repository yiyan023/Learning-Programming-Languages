#include <stdio.h>
#include <stdlib.h>

int main () {
    int secretNumber = 5;
    int Guess;
    int Attempts = 0;

    printf("Guess a number:");
    scanf("%d", &Guess);
    Attempts ++;

    while ((Guess != secretNumber)) {
        printf("Your guess is incorrect. Try again:");
        scanf("%d", &Guess);
        Attempts ++;
    }

    printf("Your guess is correct! You guessed in %d tries.", Attempts);
}