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
    
    int numero;
    printf("Digite qual numero deseja contar no vetor: ");
    scanf("%d%*c", &numero);

    int vezes = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i] == numero)
        {
            vezes++;
        }
    }
    
    printf("O numero %d foi encontrado %d vezes no vetor.", numero, vezes);

    
    free(vetor);
    return 0;
}
