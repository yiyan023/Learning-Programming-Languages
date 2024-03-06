#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

int my_strlen(const char *s) {
    int len = 0;

    while (s[len] != '\0') {
        len += 1;
    }

    return len;
}

int main() {
     
}