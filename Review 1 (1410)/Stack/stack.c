#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

t_stack *createStack(int limit){
    t_stack *stack = (t_stack*)malloc(sizeof(t_stack));
    stack->max = limit;
    stack->top_index = 0;
    stack->arr = (t_elem*)malloc(sizeof(t_elem) * limit);
    return stack;
}

int isFull(t_stack *stack){
    return stack->top_index == stack->max;
}

int isEmpty(t_stack *stack){
    return stack->top_index == 0;
}

void push(t_stack *stack, t_elem value){
    if (!isFull(stack))
    {
        stack->arr[stack->top_index] = value;
        stack->top_index++;
    }
}

void pop(t_stack *stack){
    if (!isEmpty(stack))
    {
        // sem free() porque é um int simples,
        // se fosse uma struct ou array
        // free(stack->arr[stack->top_index - 1]);
        stack->top_index--;
    }
}

void top(t_stack *stack){
    if (!isEmpty(stack))
    {
        printf("%d", stack->arr[stack->top_index - 1]);   
    } else {
        printf("Pilha vazia chefe");
    }
    printf("\n");
}

void destroy(t_stack *stack){
    free(stack->arr);
    free(stack);
}

void clear(t_stack *stack){
    stack->top_index = 0;
}

void printStack(t_stack *stack){
    if (!isEmpty(stack))
    {
        for (int i = 0; i < stack->top_index; i++)
        {
            printf("%d ", stack->arr[i]);
        }
    } else {
        printf("Pilha vazia chefe");
    }
    printf("\n");
}