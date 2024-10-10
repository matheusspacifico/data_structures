#include <stdio.h>
#include <stdlib.h>
#include "linkedsingle.h"

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
        printf("\n");
    } else {
        printf("The list is empty!\n");
    }
}

void append(t_list *list, int value){
    t_node *new = (t_node*)malloc(sizeof(t_node));
    new->data = value;
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

void del(t_list *list, int value){
    if (!isEmpty(list))
    {
        // Caso 1: Valor está no head.
        if (list->head->data == value)
        {
            // Variável apenas para dar free() na memória.
            t_node *memoryClear = list->head;

            // Se tiver 1 Node só.
            if (list->size == 1)
            {
                list->head = NULL;
                list->tail = NULL;
            } else { // Caso tenha mais de 1.
                list->head = list->head->next;
                
            }

            free(memoryClear);
            list->size--;
        } else {
            // Caso 2: Valor não está no head.
            t_node *aux = list->head;

            while (aux->next != NULL)
            {
                if (aux->next->data == value)
                {
                    t_node *memoryClear = aux->next;

                    // Caso for o estiver no Tail.
                    if (aux->next == list->tail)
                    {
                        list->tail = aux;
                        aux->next = NULL;
                    } else { // Caso não estiver no Tail.
                        aux->next = aux->next->next;
                    }
                    free(memoryClear);
                    list->size--;
                    break;
                }
                aux = aux->next;
            }   
        }
    }
}