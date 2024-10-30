#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int dado;
    struct _node *esq;
    struct _node *dir;
} t_node;

t_node *criaArvore(int dado){
    t_node *raiz = (t_node *)malloc(sizeof(t_node));
    raiz->dado = dado;
    raiz->esq = NULL;
    raiz->dir = NULL;
    return raiz;
}

t_node *inserirNo(t_node *raiz, int dado) {
    if (raiz == NULL) {
        return criaArvore(dado);
    }
    if (dado < raiz->dado) {
        raiz->esq = inserirNo(raiz->esq, dado);
    } else if (dado > raiz->dado) {
        raiz->dir = inserirNo(raiz->dir, dado);
    }
    return raiz;
}

void preOrdem(t_node *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dado);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

void emOrdem(t_node *raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esq);
        printf("%d ", raiz->dado);
        emOrdem(raiz->dir);
    }
}

void posOrdem(t_node *raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d ", raiz->dado);
    }
}

int main() {
    t_node *raiz = NULL;

    raiz = inserirNo(raiz, 10);
    raiz = inserirNo(raiz, 7);
    raiz = inserirNo(raiz, 3);
    raiz = inserirNo(raiz, 2);
    raiz = inserirNo(raiz, 15);
    raiz = inserirNo(raiz, 11);

    printf("Pre-Ordem: ");
    preOrdem(raiz);
    printf("\n");

    printf("Em-Ordem: ");
    emOrdem(raiz);
    printf("\n");

    printf("Pos-Ordem: ");
    posOrdem(raiz);
    printf("\n");

    return 0;
}