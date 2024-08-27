#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int max;
    int n;
    int *itens;
} t_list;
// not gonna check if(allocatedmemory == NULL) because of readability

t_list *create_list(int max){
    t_list *list = (t_list *)malloc(sizeof(t_list));
    list->max = max;
    list->n = 0;
    list->itens = (int *)malloc(sizeof(int) * max);
    return list;
}

void destroy_list(t_list *list){
    free(list->itens);
    free(list);
}

int len(t_list *list){
    return list->n;
}

int is_full(t_list *list){
    if (list->n == list->max)
    {
        return 1;
    }
    return 0;
}

void append(t_list *list, int elem){
    if (!is_full(list)){
        list->itens[list->n] = elem;
        list->n++;
    }
}

void print_list(t_list *list){
    for (int i = 0; i < list->n; i++)
    {
        printf("%d ", list->itens[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int x;
    t_list *list;

    list = create_list(10);
    append(list, 5);
    append(list, 10);
    append(list, 8);

    print_list(list);
    destroy_list(list);
    return 0;
}
