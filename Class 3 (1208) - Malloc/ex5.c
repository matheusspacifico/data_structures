#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d%*c", &tamanho);

    int *vetor = (int *)malloc(tamanho * sizeof(int*));
    for (int i = 0; i < tamanho; i++)
    {
        printf("Digite o elemento %d do vetor: ", i+1);
        scanf("%d%*c", &vetor[i]);
    }
    
    printf("Vetor antes da inversao: [ ");
    for (int i = 0; i < tamanho; i++)
    {
        if (i != tamanho - 1)
        {
            printf("%d, ", vetor[i]);
            continue;
        }
        printf("%d ]\n", vetor[i]);
    }

    int aux;
    for (int i = 0; i < tamanho / 2; i++)
    {
        aux = vetor[i];
        vetor[i] = vetor[tamanho - i - 1];
        vetor[tamanho - i - 1] = aux;
    }
    
    printf("Vetor depois da inversao: [ ");
    for (int i = 0; i < tamanho; i++)
    {
        if (i != tamanho - 1)
        {
            printf("%d, ", vetor[i]);
            continue;
        }
        printf("%d ]\n", vetor[i]);
    }

    
    free(vetor);
    return 0;
}
