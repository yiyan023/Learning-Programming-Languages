#include <stdio.h>
#include <stdlib.h>

int max(int num1, int num2) {
    int result;
    if (num1 < num2) {
        result = num2;
    } else {
        result = num1;
    }
    return result;
}

int main() {
    printf("%d", max(3, 6));
}