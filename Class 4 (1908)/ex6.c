#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[41];
    int idade;
    float altura;
} Pessoa;

void liberaPessoa(Pessoa *p) {
    free(p);
    printf("Memoria liberada.\n");
}

int main(int argc, char const *argv[])
{
    Pessoa *pessoa = (Pessoa *)malloc(sizeof(Pessoa));
    if (pessoa == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }
    
    strcpy(pessoa->nome, "Matheus");
    pessoa->idade = 20;
    pessoa->altura = 1.70;

    liberaPessoa(pessoa);

    return 0;
}
