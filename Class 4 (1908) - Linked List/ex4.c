#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *nome;
    float preco;
    int quantidade;
} Produto;

void copiaProduto(Produto *copiado, Produto *principal) {
    copiado->nome = (char *)malloc(41 * sizeof(char));
    
    if (copiado->nome == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    strcpy(copiado->nome, principal->nome);
    copiado->preco = principal->preco;
    copiado->quantidade = principal->quantidade;
}

int main(int argc, char const *argv[])
{
    Produto produto1, produto2;
    produto1.nome = (char *)malloc(41 * sizeof(char));
    strcpy(produto1.nome, "Produto A");
    produto1.preco = 10.0;
    produto1.quantidade = 5;

    copiaProduto(&produto2, &produto1);

    printf("Produto Copiado:\n");
    printf("\tNome: %s\n", produto2.nome);
    printf("\tPreco: %.2f\n", produto2.preco);
    printf("\tQuantidade: %d\n", produto2.quantidade);

    free(produto1.nome);
    free(produto2.nome);
    return 0;
}