#include <stdio.h>
#include <stdlib.h>

int main() {
    int Numbers[3][2] = {
        {1, 2},
        {3, 4},
        {5, 6},
    };

    printf("%d", Numbers[1][1]); /* will return 4 */
}