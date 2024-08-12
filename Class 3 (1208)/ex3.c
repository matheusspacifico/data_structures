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
    
    printf("Vetor antes do bobblesort: [ ");
    for (int i = 0; i < tamanho; i++)
    {
        if (i != tamanho - 1)
        {
            printf("%d, ", vetor[i]);
            continue;
        }
        printf("%d ]\n", vetor[i]);
    }

    int aux = 0;
    for (int i = 0; i < tamanho - 1; i++)
    {
        for (int j = 0; j < (tamanho - i - 1); j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }

    printf("Vetor organizado por bobblesort: [ ");
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
