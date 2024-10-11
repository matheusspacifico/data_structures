#ifndef QUEUE_H
#define QUEUE_H

typedef int t_elem;

typedef struct {
    int max;
    int begin;
    int end;
    int size;
    t_elem *arr;
} t_queue;

t_queue *createQueue(int limit);
void destroy(t_queue *queue);
int isEmpty(t_queue *queue);
int isFull(t_queue *queue);
void size(t_queue *queue);
int in(t_queue *queue, t_elem value);
int out(t_queue *queue);
void clear(t_queue *queue);
void printQueue(t_queue *queue);

#endif // !QUEUE_H