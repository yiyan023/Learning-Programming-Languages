#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <Modules/rational.h>
#include <Modules/stack.h>

int main() {
    // dictionaries -- can do a lookup & insert & remove new elements 
    // have keys & associated values

    // stack -- elements atr pushed onto the top & popped off the top 
    // push - adds an item to the top 
    // pop -- removes top item from the stack 
    // top - returns top item from the stack 
    // is_empty - determines whether it is empty

    // check stack.h and stack.c
    struct stack mystack = {100, 0, {0}};

    stack_push(4, &mystack);
    stack_push(10, &mystack);
    print_stack(&mystack);
    printf("Top is: %d\n", stack_top(&mystack));
    printf("Popping: %d\n", stack_pop(&mystack));
    print_stack(&mystack);
    printf("Top is: %d\n", stack_top(&mystack));
    printf("Popping: %d\n", stack_pop(&mystack));
    print_stack(&mystack);
    printf("Is stack empty? %d\n", stack_is_empty(&mystack));
}