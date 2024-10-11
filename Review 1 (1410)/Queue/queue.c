#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

t_queue *createQueue(int limit){
    t_queue *queue = (t_queue*)malloc(sizeof(t_queue));
    queue->max = limit;
    queue->begin = 0;
    queue->end = 0;
    queue->size = 0;
    queue->arr = (t_elem*)malloc(sizeof(t_elem) * limit);
    return queue;
}

void destroy(t_queue *queue){
    clear(queue);
    free(queue->arr);
    free(queue);
}

int isEmpty(t_queue *queue){
    return queue->size == 0;
}

int isFull(t_queue *queue){
    return queue->size == queue->max;
}

void size(t_queue *queue){
    printf("Queue size: %d\n", queue->size);
}

int in(t_queue *queue, t_elem value){
    if (!isFull(queue))
    {
        queue->arr[queue->end] = value;
        queue->end = (queue->end + 1) % queue->max;
        queue->size++;
    }
    
}

int out(t_queue *queue){
    if (!isFull(queue))
    {
        queue->begin = (queue->begin + 1) % queue->max;
        queue->size--;
    }
}

void clear(t_queue *queue){
    queue->begin = 0;
    queue->end = 0;
    queue->size = 0;
}

void printQueue(t_queue *queue){
    if (!isEmpty(queue))
    {
        int i = queue->begin;
        int count = 0;
        while (count < queue->size)
        {
            printf("%d ", queue->arr[i]);

            count++;
            i = (i + 1) % queue->max;
        }
        
    } else {
        printf("Fila vazia chefe");
    }
    printf("\n");
}