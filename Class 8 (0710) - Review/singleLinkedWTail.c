#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *next;
} t_node;

typedef struct {
    t_node *head;
    t_node *tail;
    int size;
} t_list;

t_list *create(){
    t_list *list = (t_list*)malloc(sizeof(t_list));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

int isEmpty(t_list *list){
    return list->head == NULL;
}

void append(t_list *list, int data){
    t_node *new = (t_node*)malloc(sizeof(t_node));
    new->data = data;
    new->next = NULL;

    if (isEmpty(list))
    {
        list->head = new;
        list->tail = new;
    } else {
        list->tail->next = new;
        list->tail = new;
    }
    
    list->size++;
}

void printl(t_list *list){
    if (isEmpty(list))
    {
        printf("NULL\n");
    } else {
        t_node *aux = list->head;
        while (aux != NULL)
        {
            printf("%d ", aux->data);
            aux = aux->next;
        }
    }
    printf("\n");
}

void del(t_list *list, int data){
    if (isEmpty(list))
    {
        return;
    } else if (list->head->data == data)
    {
        list->head = list->head->next;
    } else {
        t_node *aux = list->head;

        while (aux->next->data != data)
        {
            aux = aux->next;
        }
        
        aux->next = aux->next->next;
    }

   list->size--; 
}

int main(int argc, char const *argv[])
{
    t_list *list = create();

    printl(list);
    append(list, 6);
    printl(list);
    
    del(list, 6);
    printl(list);
    append(list, 3953);
    printl(list);
    

    return 0;
}
