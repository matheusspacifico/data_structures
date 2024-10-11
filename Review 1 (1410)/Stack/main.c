#include "stack.c"

int main()
{
    t_stack *stack = createStack(5);

    printStack(stack);
    top(stack);
    push(stack, 2);
    push(stack, 4);
    top(stack);
    printStack(stack);
    push(stack, 54);
    push(stack, 299);
    push(stack, 9);
    push(stack, 9);
    push(stack, 9);
    printStack(stack);
    pop(stack);
    printStack(stack);
    top(stack);
    clear(stack);
    printStack(stack);
    destroy(stack);
    printStack(stack);

    return 0;
}
