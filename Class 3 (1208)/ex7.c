#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int tamanho = 5;
    char **vetor = (char **)malloc(tamanho * sizeof(char *));
    for (int i = 0; i < tamanho; i++)
    {
        char *string = (char *)malloc(21 * sizeof(char));
        printf("Digite a string %d: ", i + 1);
        gets(string);
        vetor[i] = string;
    }
    
    printf("Vetor depois da inversao das strings: [ ");
    for (int i = 0; i < tamanho; i++)
    {
        if (i != tamanho - 1)
        {
            printf("%s, ", vetor[i]);
            continue;
        }
        printf("%s ]\n", vetor[i]);
    }

    char aux;
    for (int i = 0; i < tamanho; i++)
    {
        int tamanhoJ = strlen(vetor[i]);
        for (int j = 0; j < tamanhoJ / 2; j++)
        {
            aux = vetor[i][j];
            vetor[i][j] = vetor[i][tamanho - j - 1];
            vetor[i][tamanho - j - 1] = aux;
        }
        
    }

    printf("Vetor depois da inversao das strings: [ ");
    for (int i = 0; i < tamanho; i++)
    {
        if (i != tamanho - 1)
        {
            printf("%s, ", vetor[i]);
            continue;
        }
        printf("%s ]\n", vetor[i]);
    }

    for (int i = 0; i < tamanho; i++)
    {
        free(vetor[i]);
    }
    free(vetor);

    return 0;
}
