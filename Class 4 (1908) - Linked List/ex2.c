#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[41];
    float preco;
    int quantidade;
} Produto;

int main(int argc, char const *argv[]) 
{
    int N;

    printf("Informe a quantidade de produtos: ");
    scanf("%d%*c", &N);

    Produto *produtos = (Produto *)malloc(N * sizeof(Produto));
    
    if (produtos == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        printf("Produto %d:\n", i + 1);
        printf("\tNome: ");
        gets(produtos[i].nome);
        printf("\tPreco: ");
        scanf("%f%*c", &produtos[i].preco);
        printf("\tQuantidade: ");
        scanf("%d%*c", &produtos[i].quantidade);
    }

    printf("===========================\n");

    for (int i = 0; i < N; i++) {
        printf("Produto %d:\n", i + 1);
        printf("\tNome: %s\n", produtos[i].nome);
        printf("\tPreco: %.2f\n", produtos[i].preco);
        printf("\tQuantidade: %d\n", produtos[i].quantidade);
    }

    free(produtos);
    return 0;
}
