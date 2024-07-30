#include <stdio.h>
#include <string.h>

int isPalindrome(char str1[21], char str2[21]) {
    int tamanho1 = strlen(str1);
    int tamanho2 = strlen(str2);

    if (tamanho1 != tamanho2)
    {
        return 0;
    }
    
    char aux[21];

    for (int i = 0; i < tamanho1; i++)
    {
        aux[i] = str1[tamanho1 - 1  - i];
    }
    aux[tamanho1] = '\0';
    
    if (strcmp(aux, str2) == 0)
    {
        return 1;
    }
    
    return 0;
}

int main() {
    
    char str1[21] = "roma";
    char str2[21] = "amor";

    int resposta = isPalindrome(str1, str2);

    if(resposta){
        printf("Eh palindromo!\n");
        return 0;
    }

    printf("Nao eh palindromo!\n");
    return 0;
}