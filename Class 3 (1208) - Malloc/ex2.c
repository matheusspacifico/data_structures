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
    
    int maior = vetor[0];
    int menor = vetor[0];
    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i] > maior)
        {
            maior = vetor[i];
        }

        if (vetor[i] < menor)
        {
            menor = vetor[i];
        }
    }
    
    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);

    free(vetor);
    return 0;
}
