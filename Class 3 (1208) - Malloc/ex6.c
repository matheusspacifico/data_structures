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
    
    int soma = 0;
    float media = 0;
    for (int i = 0; i < tamanho; i++)
    {
        soma += vetor[i];
    }

    media = (float)soma / tamanho;
    printf("Media do vetor: %.2f", media);
    
    free(vetor);
    return 0;
}
