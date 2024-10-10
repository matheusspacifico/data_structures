#include <stdio.h>
#include <stdlib.h>
#include "linkeddouble.h"

t_list *createList(){
    t_list *list = (t_list*)malloc(sizeof(t_list));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

int isEmpty(t_list *list){
    return list->size == 0;
}

void printList(t_list *list){
    if (!isEmpty(list))
    {
        t_node *aux = list->head;
        while (aux != NULL)
        {
            printf("%d ", aux->data);
            aux = aux->next;
        }
    } else {
        printf("The list is empty!");
    }
    printf("\n");
}

void append(t_list *list, int value){
    t_node *new = (t_node*)malloc(sizeof(t_node));
    new->data = value;
    new->next = NULL;
    new->prev = NULL;

    if (isEmpty(list))
    {
        list->head = new;
        list->tail = new;
    }
    
    else {
        list->tail->next = new;
        new->prev = list->tail;
        list->tail = new;
    }

    list->size++;
}

void del(t_list *list, int value){
    if (!isEmpty(list))
    {
        if (list->head->data == value)
        {
            t_node *memoryClear = list->head;

            if (list->size == 1)
            {
                list->head = NULL;
                list->tail = NULL;
            } else {
                list->head = list->head->next;
                list->head->prev = NULL;
            }
            free(memoryClear);
            list->size--;
        }
        
        else if (list->tail->data == value)
        {
            t_node *memoryClear = list->tail;
            list->tail = list->tail->prev;
            list->tail->next = NULL;
            free(memoryClear);
            list->size--;
        }

        else 
        {
            t_node *aux = list->head;
            while (aux != NULL)
            {
                if (aux->data == value)
                {
                    aux->prev->next = aux->next;
                    aux->next->prev = aux->prev;
                    free(aux);
                    list->size--;
                    break;
                }
                aux = aux->next;
            }
        }
    }
}