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

t_node *search(t_list *list, int item){
    t_node *node_aux = list->head;
    while (node_aux != NULL)
    {
        if (node_aux->item == item)
        {
            return node_aux;
        }
        node_aux = node_aux->next;
    }
    printf("Item not found!\n");
}

void delete(t_list *list, t_node *node_to_be_removed){
    if (node_to_be_removed == list->head) // CASO 1: PRIMEIRO ELEMENTO
    {
        list->head = node_to_be_removed->next;
        if (list->tail == node_to_be_removed) // CASO 1.1 APENAS 1 ELEMENTO NA LISTA
        {
            list->tail == NULL;
        }
        
        free(node_to_be_removed);
        list->size--;
        return;
    }

    t_node *node_predecessor = list->head; // TO BE REMOVED PREDECESSOR
    while (node_predecessor->next != node_to_be_removed) // ACHAR ANTERIOR AO NODE_TO_BE_REMOVED
    {
        node_predecessor = node_predecessor->next;
    }

    if (node_to_be_removed == list->tail) // CASO 2: ULTIMO ELEMENTO
    {
        list->tail = node_predecessor;
        node_predecessor->next = NULL;
        free(node_to_be_removed);
        list->size--;
    } else { // CASO 3: MEIO DA LISTA
        node_predecessor->next = node_to_be_removed->next;
        free(node_to_be_removed);
        list->size--;
    }    
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

    t_node *node;
    node = search(list, 2);
    if (node != NULL)
    {
        delete(list, node);
    }
    print_list(list);
    
    append(list, 49);
    append(list, 8);
    print_list(list);

    node = search(list, 6);
    if (node != NULL)
    {
        delete(list, node);
    }
    print_list(list);
    
    node = search(list, 8);
    if (node != NULL)
    {
        delete(list, node);
    }
    print_list(list);

    //destroy_list(list);
    return 0;
}
