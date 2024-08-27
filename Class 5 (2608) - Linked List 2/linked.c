#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int item;
    struct _node *next;
} t_node;

typedef struct {
    t_node *head;
    t_node *tail;
    int size;
} t_list;
// not gonna check if(allocatedmemory == NULL) because of readability

t_list *create_list(){
    t_list *list = (t_list *)malloc(sizeof(t_list));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

int is_empty(t_list* list){
    return list->size == 0;
}

void append(t_list *list, int item){
    t_node *node = (t_node *)malloc(sizeof(t_node));
    node->item = item;
    node->next = NULL;

    if (is_empty(list))
    {
        list->head = node;
    } else {
        list->tail->next = node;
    }
    list->tail = node;
    list->size++;
}

void print_list(t_list *list){
    t_node *node_aux = list->head;
    while (node_aux != NULL)
    {
        printf("%d ", node_aux->item);
        node_aux = node_aux->next;
    }
    printf("\n");
}



int main(int argc, char const *argv[])
{
    t_list *list;

    list = create_list();
    append(list, 2);
    append(list, 4);
    append(list, 6);
    append(list, 7);

    print_list(list);
    //destroy_list(list);
    return 0;
}
