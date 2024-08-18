#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[41];
    float nota;
} Aluno;

int main(int argc, char const *argv[]) 
{
    int M, N;
    printf("Informe o numero de linhas: ");
    scanf("%d%*c", &M);
    printf("Informe o numero de colunas: ");
    scanf("%d%*c", &N);

    Aluno **matriz = (Aluno **)malloc(M * sizeof(Aluno *));

    if (matriz == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }
    
    
    for (int i = 0; i < M; i++) {
        matriz[i] = (Aluno *)malloc(N * sizeof(Aluno));

        if (matriz[i] == NULL)
        {
            printf("Erro ao alocar memoria!\n");
            return 1;
        }

        for (int j = 0; j < N; j++) {
            printf("Aluno [%d][%d]:\n", i, j);
            printf("\tNome: ");
            gets(matriz[i][j].nome);
            printf("\tNota: ");
            scanf("%f%*c", &matriz[i][j].nota);
        }
    }

    printf("===========================================\n");

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("Aluno [%d][%d]:\n", i, j);
            printf("\tNome: %s\n", matriz[i][j].nome);
            printf("\tNota: %.2f\n", matriz[i][j].nota);
        }
    }

    for (int i = 0; i < M; i++) {
        free(matriz[i]);
    }
    free(matriz);
    return 0;
}
