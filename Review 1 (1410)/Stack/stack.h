#ifndef STACK_H
#define STACK_H

typedef int t_elem;

typedef struct {
    int max;
    int top_index;
    t_elem *arr;
} t_stack;

t_stack *createStack(int limit);
int isFull(t_stack *stack);
int isEmpty(t_stack *stack);
void push(t_stack *stack, t_elem value);
void pop(t_stack *stack);
void top(t_stack *stack);
void destroy(t_stack *stack);
void clear(t_stack *stack);
void printStack(t_stack *stack);

#endif // !STACK_H