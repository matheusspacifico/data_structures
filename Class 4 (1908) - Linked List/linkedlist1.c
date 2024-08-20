#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

// Crie uma struct chamada No para representar um nó de uma lista encadeada, contendo um campo valor (int) e um ponteiro para o próximo nó. Implemente as funções para adicionar, remover e imprimir os elementos da lista.

No *cabeca = NULL;

void Adicionar() {
    No *novo_no = (No *)malloc(sizeof(No));
    if (novo_no == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    
    printf("Digite o valor do no a ser adicionado: ");
    scanf("%d%*c", &novo_no->valor);
    novo_no->proximo = NULL;

    if (cabeca == NULL)
    {
        cabeca = novo_no;
    } else {
        No *aux = cabeca;
        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        }
        aux->proximo = novo_no;
    }
    
    printf("Elemento adicionado!\n");
}

void Remover() {
    if (cabeca == NULL)
    {
        printf("A lista esta vazia! Adicione um elemento primeiro.\n");
        return;
    }

    int valor;
    printf("Digite qual valor deseja remover: ");
    scanf("%d%*c", &valor);

    No *aux = cabeca;
    No *anterior = NULL;

    while (aux != NULL && aux->valor != valor)
    {
        anterior = aux;
        aux = aux->proximo;
    }
    
    if (aux == NULL)
    {
        printf("Valor nao encontrado na lista!\n");
        return;
    }
    
    if (anterior == NULL)
    {
        cabeca = aux->proximo;
    } else {
        anterior->proximo = aux->proximo;
    }
    
    free(aux);
    printf("Elemento removido!\n");
}

void Imprimir() {
    if (cabeca == NULL)
    {
        printf("A lista esta vazia! Adicione um elemento primeiro.\n");
        return;
    }
    
    No *aux = cabeca;
    while (aux != NULL)
    {
        printf("%d ", aux->valor);
        aux = aux->proximo;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    while (1)
    {
        printf("=========================================\n");
        printf("Lista Encadeada:\n");
        int opcao;
        printf("\t[1] - Adicionar Elemento\n");
        printf("\t[2] - Remover Elemento\n");
        printf("\t[3] - Imprimir Lista\n");
        printf("\t[4] - Sair\n");
        printf("Digite a opcao: ");
        scanf("%d%*c", &opcao);
        printf("=========================================\n");
        switch (opcao) {
            case 1:
                printf("\n\n");
                Adicionar();
                printf("\n\n");
                break;
            case 2:
                printf("\n\n");
                Remover();
                printf("\n\n");
                break;
            case 3:
                printf("\n\n");
                Imprimir();
                printf("\n\n");
                break;
            case 4:
                printf("\n\n");
                printf("Fim.\n");
                return 0;
        }
    }

    return 0;
}
