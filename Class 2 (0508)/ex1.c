#include <stdio.h>
#include <string.h>
#define QTDE_MAX_ALUNOS 45

typedef struct{
    int id;
    char nome[100];
    int idade;
    char endereco[100];
} aluno;

aluno t3A[45];
int idx_disponivel = 0;

int verificar_id(int id_analisado){
    for (int i = 0; i < idx_disponivel; i++)
    {
        if (t3A[i].id == id_analisado)
        {
            return 1;
        }
    }
    return 0;
}

int cadastraAluno(){
    int id_read;
    char nome_read[100];
    int idade_read;
    char endereco_read[100];

    if (idx_disponivel < QTDE_MAX_ALUNOS)
    {
        printf("Digite o id do aluno %d: ", idx_disponivel);
        scanf("%d%*c", &id_read);
        printf("Digite o nome do aluno %d: ", idx_disponivel);
        gets(nome_read);
        printf("Digite a idade do aluno %d: ", idx_disponivel);
        scanf("%d%*c", &idade_read);
        printf("Digite o endereco do aluno %d: ", idx_disponivel);
        gets(endereco_read);

        if (!verificar_id(id_read))
        {
            t3A[idx_disponivel].id = id_read;
            strcpy(t3A[idx_disponivel].nome, nome_read);
            t3A[idx_disponivel].idade = idade_read;
            strcpy(t3A[idx_disponivel].endereco, endereco_read);
            idx_disponivel++;
            return 1;
        } else {
            printf("id ja existe, aluno digitado nao foi salvo.\n");
            return 0;
        }
    }
}

int removeAluno(){
    int id_read;
    printf("Digite o id do aluno a ser removido: ");
    scanf("%d%*c", &id_read);

    if (!verificar_id(id_read))
    {
        printf("O aluno nao existe! Cadastre-o primeiro.\n");
        return 0;
    }

    int index_aluno = verificar_index(id_read);

    for (int i = index_aluno; i < idx_disponivel; i++)
    {
        t3A[i] = t3A[i + 1];
    }
    idx_disponivel--;

    printf("Aluno removido com sucesso.\n");
    return 1;
}

int verificar_index(int id_analisado){
    for (int i = 0; i < idx_disponivel; i++)
    {
        if (t3A[i].id == id_analisado)
        {
            return i;
        }
    }
    return 0;
}

int atualizaAluno(){
    int id_read;
    printf("Digite o id do aluno a ser atualizado: ");
    scanf("%d%*c", &id_read);

    if (!verificar_id(id_read))
    {
        printf("O aluno nao existe! Cadastre-o primeiro.\n");
        return 0;
    }

    char nome_read[100];
    int idade_read;
    char endereco_read[100];
    
    int index_aluno = verificar_index(id_read);

    printf("Digite o nome atualizado do aluno %d: ", index_aluno);
    gets(nome_read);
    printf("Digite a idade atualizada do aluno %d: ", index_aluno);
    scanf("%d%*c", &idade_read);
    printf("Digite o endereco atualizado do aluno %d: ", index_aluno);
    gets(endereco_read);
    
    strcpy(t3A[index_aluno].nome, nome_read);
    t3A[index_aluno].idade = idade_read;
    strcpy(t3A[index_aluno].endereco, endereco_read);

    printf("Aluno atualizado com sucesso.\n");
    return 1;
}

int printarArray(){
    if (idx_disponivel == 0)
    {
        printf("Nenhum aluno cadastrado!");
        return 0;
    }

    for (int i = 0; i < idx_disponivel; i++)
    {
        printf("Aluno indice %d:\n", i);
        printf("\tId: %d\n", t3A[i].id);
        printf("\tNome: %s\n", t3A[i].nome);
        printf("\tIdade: %d\n", t3A[i].idade);
        printf("\tEndereco: %s\n", t3A[i].endereco);
        printf("\n");
    }

    return 1;
}

int main(int argc, char const *argv[])
{
    while (1)
    {
        printf("=========================================\n");
        printf("Crud Menu:\n");
        int opcao;
        printf("\t[1] - Cadastrar Aluno\n");
        printf("\t[2] - Remover Aluno\n");
        printf("\t[3] - Atualizar Aluno\n");
        printf("\t[4] - Printar Array de Alunos\n");
        printf("\t[5] - Sair\n");
        printf("Digite a opcao: ");
        scanf("%d%*c", &opcao);
        printf("=========================================\n");
        switch (opcao) {
            case 1:
                printf("\n\n");
                cadastraAluno();
                printf("\n\n");
                break;
            case 2:
                printf("\n\n");
                removeAluno();
                printf("\n\n");
                break;
            case 3:
                printf("\n\n");
                atualizaAluno();
                printf("\n\n");
                break;
            case 4:
                printf("\n\n");
                printarArray();
                printf("\n\n");
                break;
            case 5:
                printf("\n\n");
                printf("Fim.\n");
                return 0;
        }
    }

    return 0;
}
