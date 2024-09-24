#include <stdio.h>
#include <stdlib.h>

typedef int t_elem;

typedef struct {
    t_elem *data;
    int top;
    int capacity;
} t_stack;

t_stack* create_stack(int n) {
    t_stack* stack = (t_stack*)malloc(sizeof(t_stack));
    if (!stack) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    stack->data = (t_elem*)malloc(n * sizeof(t_elem));
    if (!stack->data) {
        printf("Memory allocation failed.\n");
        free(stack);
        return NULL;
    }

    stack->top = -1;
    stack->capacity = n;
    return stack;
}

void destroy(t_stack *p) {
    if (p) {
        if (p->data) {
            free(p->data);
        }
        free(p);
    }
}

int is_full(t_stack *p) {
    return p->top == (p->capacity - 1);
}

int is_empty(t_stack *p) {
    return p->top == -1;
}

int push(t_stack *p, t_elem x) {
    if (is_full(p)) {
        printf("Stack overflow! Cannot push element.\n");
        return 0;
    }
    p->data[++(p->top)] = x;
    return 1;
}

int pop(t_stack *p, t_elem *x) {
    if (is_empty(p)) {
        printf("Stack underflow! Cannot pop element.\n");
        return 0;
    }
    *x = p->data[(p->top)--];
    return 1;
}

int top_index(t_stack *p, t_elem *x) {
    if (is_empty(p)) {
        printf("Stack is empty! No top element.\n");
        return 0;
    }
    *x = p->data[p->top];
    return 1;
}

void clear(t_stack *p) {
    p->top = -1;
}

void print(t_stack *p) {
    if (is_empty(p)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack contents (from top to bottom):\n");
    for (int i = p->top; i >= 0; i--) {
        printf("%d\n", p->data[i]);
    }
}

int main() {
    t_stack *stack = create_stack(5);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    print(stack);

    t_elem x;
    if (pop(stack, &x)) {
        printf("Popped: %d\n", x);
    }

    print(stack);

    destroy(stack);

    return 0;
}
