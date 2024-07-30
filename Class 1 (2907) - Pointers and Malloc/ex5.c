#include <stdio.h>
#include <stdlib.h>

int *allocateArray(int size) {
    return (int *)malloc(size * sizeof(int));
}

int findValue(int x, int *arr, int size) {
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == x)
        {
            return i + 1;
        }   
    }

    return 0;
}

int main() {
    int n = 0;
    int x = 0;
    printf("Informe o tamanho do vetor: ");
    scanf("%d%*c", &n);
    
    int *arr = allocateArray(n);
    for (int i = 0; i < n; i++) {
        printf("Digite o valor do indice %d: ", i);
        scanf("%d%*c", &arr[i]);
    }
    
    printf("Informe o valor a ser buscado: ");
    scanf("%d%*c", &x);
    int resposta = findValue(x, arr, n);

    if(resposta){
        printf("Valor encontrado no indice: %d\n", resposta - 1);
        free(arr);
        return 0;
    }

    printf("Valor nao encontrado no array!\n");
    free(arr);
    return 0;
}