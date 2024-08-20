#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[41];
    int idade;
    float altura;
} Pessoa;

char* convertePessoaParaString(Pessoa *p) {
    char *final = (char *)malloc(100 * sizeof(char));
    
    if (final == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }

    sprintf(final, "Nome: %s\nIdade: %d\nAltura: %.2f", p->nome, p->idade, p->altura);
    return final;
}

int main(int argc, char const *argv[])
{
    Pessoa pessoa;
    strcpy(pessoa.nome, "Matheus");
    pessoa.idade = 20;
    pessoa.altura = 1.70;

    char *descricao = convertePessoaParaString(&pessoa);
    printf("%s\n", descricao);

    return 0;
}
