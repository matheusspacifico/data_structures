#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *nome;
    int idade;
    float altura;
} Pessoa;

void inicializaPessoa(Pessoa *p, char *n, int i, float a) {
    p->nome = (char *)malloc(41 * sizeof(char));

    if (p->nome == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    
    strcpy(p->nome, n);
    p->idade = i;
    p->altura = a;
}

int main(int argc, char const *argv[])
{
    Pessoa p;
    inicializaPessoa(&p, "Matheus", 20, 1.70);

    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
    printf("Altura: %.2f\n", p.altura);

    free(p.nome);
    return 0;
}
