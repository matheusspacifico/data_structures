#ifndef LINKED_DOUBLE_H
#define LINKED_DOUBLE_H

typedef struct _node {
    int data;
    struct _node *next;
    struct _node *prev;
} t_node;

typedef struct {
    t_node *head;
    t_node *tail;
    int size;
} t_list;

t_list *createList();
int isEmpty(t_list *list);
void printList(t_list *list);
void append(t_list *list, int value);
void del(t_list *list, int value);

#endif // !LINKED_DOUBLE_H