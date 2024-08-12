#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ex1(){
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d%*c", &tamanho);

    int *vetor = (int *)malloc(tamanho * sizeof(int));
    for (int i = 0; i < tamanho; i++)
    {
        printf("Digite o elemento %d do vetor: ", i+1);
        scanf("%d%*c", &vetor[i]);
    }
    
    int soma = 0;
    for (int i = 0; i < tamanho; i++)
    {
        soma += vetor[i];
    }

    printf("A soma dos elementos totaliza: %d", soma);
    free(vetor);

    return 0;
}

int ex2(){
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d%*c", &tamanho);

    int *vetor = (int *)malloc(tamanho * sizeof(int));
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

int ex3(){
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d%*c", &tamanho);

    int *vetor = (int *)malloc(tamanho * sizeof(int));
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

int ex4(){
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d%*c", &tamanho);

    int *vetor = (int *)malloc(tamanho * sizeof(int));
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

int ex5(){
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d%*c", &tamanho);

    int *vetor = (int *)malloc(tamanho * sizeof(int));
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

int ex6(){
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d%*c", &tamanho);

    int *vetor = (int *)malloc(tamanho * sizeof(int));
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

int ex7(){
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

int main()
{
    while (1)
    {
        printf("=========================================\n");
        printf("Escolha o exercicio:\n");
        int opcao;
        printf("\t[1] - Exercicio 1\n");
        printf("\t[2] - Exercicio 2\n");
        printf("\t[3] - Exercicio 3\n");
        printf("\t[4] - Exercicio 4\n");
        printf("\t[5] - Exercicio 5\n");
        printf("\t[6] - Exercicio 6\n");
        printf("\t[7] - Exercicio 7\n");
        printf("\t[8] - Finalizar programa.\n");
        printf("Digite a opcao: ");
        scanf("%d%*c", &opcao);
        printf("=========================================\n");
        switch (opcao) {
            case 1:
                printf("\n\n");
                ex1();
                printf("\n\n");
                break;
            case 2:
                printf("\n\n");
                ex2();
                printf("\n\n");
                break;
            case 3:
                printf("\n\n");
                ex3();
                printf("\n\n");
                break;
            case 4:
                printf("\n\n");
                ex4();
                printf("\n\n");
                break;
            case 5:
                printf("\n\n");
                ex5();
                printf("\n\n");
                break;
            case 6:
                printf("\n\n");
                ex6();
                printf("\n\n");
                break;
            case 7:
                printf("\n\n");
                ex7();
                printf("\n\n");
                break;
            case 8:
                printf("\n\n");
                printf("Fim.\n");
                return 0;
        }
    }

    return 0;
}
