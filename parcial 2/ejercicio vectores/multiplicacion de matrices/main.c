#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void multiplicacionMatrices(int **primerMatriz, int **segundaMatriz, int ancho, int altura);

int main()
{
    srand(time(NULL));
    int anchoPrimeraMatriz, alturaPrimeraMatriz, anchoSegundaMatriz, alturaSegundaMatriz;
    int ancho, altura;

    printf("Ingresa el ancho de la primera matriz: ");
    scanf("%d", &anchoPrimeraMatriz);
    printf("Ingresa la altura de la primera matriz: ");
    scanf("%d", &alturaPrimeraMatriz);
    printf("Ingresa el ancho de la segunda matriz: ");
    scanf("%d", &anchoSegundaMatriz);
    printf("Ingresa la altura de la segunda matriz: ");
    scanf("%d", &alturaSegundaMatriz);

    if (anchoPrimeraMatriz <= 0 || alturaPrimeraMatriz <= 0 || anchoSegundaMatriz <= 0 || alturaSegundaMatriz <= 0)
    {
        printf("Las dimensiones de la matriz deben ser positivas.\n");
        return 1;
    }

    if (anchoPrimeraMatriz != anchoSegundaMatriz || alturaPrimeraMatriz != alturaSegundaMatriz)
    {
        printf("Las dimensiones de las matrices deben coincidir para su suma.\n");
        return 1;
    }

    ancho = anchoPrimeraMatriz;
    altura = alturaPrimeraMatriz;

    int **primerMatriz = (int **)malloc(ancho * sizeof(int *));
    int **segundaMatriz = (int **)malloc(ancho * sizeof(int *));
    for (int i = 0; i < ancho; i++)
    {
        primerMatriz[i] = (int *)malloc(altura * sizeof(int));
        segundaMatriz[i] = (int *)malloc(altura * sizeof(int));
    }

    for (int i = 0; i < ancho; i++)
    {
        for (int j = 0; j < altura; j++)
        {
            primerMatriz[i][j] = rand() % 101;
            segundaMatriz[i][j] = rand() % 101;
        }
    }

    multiplicacionMatrices(primerMatriz, segundaMatriz, ancho, altura);

    // Liberar la memoria asignada
    for (int i = 0; i < ancho; i++)
    {
        free(primerMatriz[i]);
        free(segundaMatriz[i]);
    }
    free(primerMatriz);
    free(segundaMatriz);

    return 0;
}

void multiplicacionMatrices(int **primerMatriz, int **segundaMatriz, int ancho, int altura)
{
    int **matrizResultado = (int **)malloc(ancho * sizeof(int *));
    for (int i = 0; i < ancho; i++)
    {
        matrizResultado[i] = (int *)malloc(altura * sizeof(int));
    }

    for (int i = 0; i < ancho; i++)
    {
        for (int j = 0; j < altura; j++)
        {
            matrizResultado[i][j] = primerMatriz[i][j] * segundaMatriz[i][j];
        }
    }

    printf("Primera matriz:\n");
    for (int i = 0; i < ancho; i++)
    {
        for (int j = 0; j < altura; j++)
        {
            printf("%d ", primerMatriz[i][j]);
        }
        printf("\n");
    }

    printf("\nSegunda matriz:\n");
    for (int i = 0; i < ancho; i++)
    {
        for (int j = 0; j < altura; j++)
        {
            printf("%d ", segundaMatriz[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz resultado:\n");
    for (int i = 0; i < ancho; i++)
    {
        for (int j = 0; j < altura; j++)
        {
            printf("%d ", matrizResultado[i][j]);
        }
        printf("\n");
    }

    // Liberar la memoria asignada
    for (int i = 0; i < ancho; i++)
    {
        free(matrizResultado[i]);
    }
    free(matrizResultado);
}
