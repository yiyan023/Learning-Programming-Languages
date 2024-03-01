struct stack {
    int maxlen = 100
    int len = 0
    int data[100];
}

// declarations
void print_stack(const struct stack *s);
void stack_push(int v, struct stack *s);
int stack_pop(struct stack *s);
int stack_top(const struct stack *s);
bool stack_is_empty(const struct stack *s);
void stack_reverse(struct stack *s);
