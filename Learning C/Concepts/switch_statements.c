#include <stdio.h>
#include <stdlib.h>

int main () {
    char Grade;
    printf("Enter your grade average:");
    scanf("%s", &Grade);

    switch (Grade) {
        case 'A':
            printf("You did great!");
            break;
        
        case 'B':
            printf("You did alright.");
            break;
        
        case 'C':
            printf("You did poorly.");
            break;
        
        case 'D':
            printf("Try harder next time.");
            break;
    }
}