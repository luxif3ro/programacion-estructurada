#include <stdio.h>

int main() {
    int original[] = {0,0,0,0,0};
    int copia[5];

    for (int i = 0; i < 5; i++)
    {
        printf("Dame el numero a guardar en el arreglo > ");
        scanf("%d",&original[i]);
    }
    
    for (int i = 0; i < 5; i++) {
        copia[i] = original[i];
    }

    printf("Vector original: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", original[i]);
    }
    printf("\n");

    printf("Vector copiado: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", copia[i]);
    }
    printf("\n");

    return 0;
}
