#include <stdio.h>
#include <stdlib.h>

int main () {
    char Line[255];
    FILE * fpointer = fopen("name.text", "w");
    fprintf(fpointer, "Hello, my name is Yiyan!");
    fclose(fpointer);

    fgets(Line, 255, fpointer);
    printf("%s", Line);
}