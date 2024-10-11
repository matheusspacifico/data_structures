#include "queue.c"

int main() 
{
    t_queue *queue = createQueue(5);

    size(queue);

    in(queue, 10);
    in(queue, 20);
    in(queue, 30);

    size(queue);

    printQueue(queue);

    out(queue);

    size(queue);

    printQueue(queue);

    destroy(queue);

    printQueue(queue);
    return 0;
}