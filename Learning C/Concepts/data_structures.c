#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
    char name[50];
    char major[50];
    int age;
    double GPA;
};

int main () {
    struct Student Jim;
    strcpy(Jim.name, "Jim");
    strcpy(Jim.major, "Computer Science");
    Jim.age = 22;
    Jim.GPA = 3.2;

    printf("%f", Jim.GPA);
}