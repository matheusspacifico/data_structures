#include <stdio.h>
#include <stdlib.h>

int binarySearch(int vet[], int tamanho, int procurado){
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;

        if (vet[meio] == procurado)
        {
            return 1;
        }

        else if (vet[meio] < procurado) {
            inicio = meio + 1;
        }
        
        else {
            fim = meio - 1;
        }
    }
    
    return -1;
}

int main()
{
    int tamanho = 10;
    int vet[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    
    int achar = binarySearch(vet, tamanho, 20);
    printf("%d\n", achar);
    


    return 0;
}
