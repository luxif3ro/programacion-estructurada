#include <stdio.h>

int main() {
    int numeros[5] = {0,0,0,0,0};
    int buscar;
    int encontrado = 0;

    for (int i = 0; i <5; i++)
    {
        printf("Dame un numero a guardar en el arreglo > ");
        scanf("%d",&numeros[i]);
    }
    
    printf("dame el numero a buscar > ");
    scanf("%d",&buscar);

    for (int i = 0; i < 5; i++) {
        if (numeros[i] == buscar) {
            encontrado = 1;
            break;
        }
    }

    if (encontrado) {
        printf("El elemento %d fue encontrado en el vector.\n", buscar);
    } else {
        printf("El elemento %d no fue encontrado en el vector.\n", buscar);
    }

    return 0;
}