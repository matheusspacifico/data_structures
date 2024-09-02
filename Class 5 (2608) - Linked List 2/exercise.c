#include <stdio.h>
#include <stdlib.h>

typedef struct _no {
    int item;
    struct _no *proximo;
} t_no;

typedef struct {
    t_no *cabeca;
    t_no *cauda;
    int tamanho;
} t_lista;

t_lista *criarLista(){
    t_lista *lista = (t_lista *)malloc(sizeof(t_lista));
    if (lista == NULL)
    {
        printf("Erro na alocacao de memoria! Encerrando.\n");
        exit(1);
    }

    lista->cabeca = NULL;
    lista->cauda = NULL;
    lista->tamanho = 0;
    
    return lista;
}

int estaVazia(t_lista *lista){
    if (lista->tamanho == 0)
    {
        return 1;
    }
    return 0;
}

void adicionarElemento(t_lista *lista, int elemento){
    t_no *novoNo = (t_no *)malloc(sizeof(t_no));
    if (novoNo == NULL)
    {
        printf("Erro na alocacao de memoria! Encerrando.\n");
        exit(1);
    }

    novoNo->item = elemento;
    novoNo->proximo = NULL;

    if (estaVazia(lista))
    {
        lista->cabeca = novoNo;
    } else {
        lista->cauda->proximo = novoNo;
    }
    lista->cauda = novoNo;
    lista->tamanho++;
}

void printarLista(t_lista *lista){
    t_no *aux = lista->cabeca;
    while (aux != NULL)
    {
        printf("%d ", aux->item);
        aux = aux->proximo;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    t_lista *lista = criarLista();

    adicionarElemento(lista, 10);
    adicionarElemento(lista, 3);
    adicionarElemento(lista, 7);

    printarLista(lista);
    return 0;
}


