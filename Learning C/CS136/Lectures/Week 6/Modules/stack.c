#include <stack.h>

void print_stack (const struct stack *s) {
    printf("[");
    for (int i = 0; i < s->len; i++) {
        if (i == 0) {
            printf("%d", s[i]);
        } else {
            printf(", %d", s[i]);
        }
    }
    printf("]");
}

void stack_push(int v, struct stack *s) {
    assert(s->len <= s->maxlen) 
    s[s->len] = v;
    s->len += 1;
}

int stack_pop(struct stack *s) {
    assert(s->len > 0);
    int temp = s[s->len - 1];
    s->len -= 1;
    return temp;
}

int stack_top(const struct stack *s) {
    return s[s->len-1];
}

bool stack_is_empty(const struct stack *s) {
    if (s->len == 0) {
        return true;
    } else {
        return false;
    }
}

void stack_reverse(struct stack *s) {
    struct stack temp = {100, 0, {0}};
    struct stack temp2 = {100, 0, {0}};

    while (!stack_is_empty(s)) {
        stack_push(stack_pop(s), &temp);
    }

    while (!stack_is_empty(&temp)) {
        stack_push(stack_pop(&temp), &temp2);
    }

     while (!stack_is_empty(&temp2)) {
        stack_push(stack_pop(&temp2), s);
    }
}