#include <stdio.h>

int main()
{
    int numeros[5] = {0, 0, 0, 0, 0};
    int n = 5;
    int temp;

    for (int i = 0; i < 5; i++)
    {
        printf("Dame el numero a guardar en el arreglo > ");
        scanf("%d", &numeros[i]);
    }

    // Algoritmo de ordenamiento de burbuja
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (numeros[j] > numeros[j + 1])
            {
                // Intercambio de elementos
                temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }

    printf("Vector ordenado: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
}