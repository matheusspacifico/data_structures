#include <stdio.h>
#include <stdlib.h>

int *allocateArray(int size) {
    return (int *)malloc(size * sizeof(int));
}

int main() {
    int n = 5;
    int *arr = allocateArray(n);

    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
        printf("%d ", arr[i]);
    }
    
    free(arr);

    return 0;
}