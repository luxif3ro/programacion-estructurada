#include <stdio.h>
#define MAX_LENGTH 100

void MayorNumero(int numeros[], int longuitud);
void MenorrNumero(int numeros[], int longuitud);

int main()
{
    int numeros[MAX_LENGTH], i = 0;
    char respuesta = 'y';

    while (respuesta == 'y' && i < MAX_LENGTH)
    {
        printf("Dame el numero a guardar > ");
        scanf("%d", &numeros[i]);
        printf("¿Deseas seguir guardando numeros? (y/n) > ");
        scanf(" %c", &respuesta);
        i++;
    }

    MayorNumero(numeros, i);
    MenorrNumero(numeros, i);

    return 0;
}

void MayorNumero(int numeros[], int longuitud)
{
    int mayor = numeros[0], posicion = 0;
    for (int i = 1; i < longuitud; i++)
    {
        if (mayor < numeros[i])
        {
            mayor = numeros[i];
            posicion = i;
        }
    }
    printf("El dato mayor es %d y esta en la posicion %d\n", mayor, posicion);
}

void MenorrNumero(int numeros[], int longuitud)
{
    int menor = numeros[0], posicion = 0;
    for (int j = 1; j < longuitud; j++)
    {
        if (menor > numeros[j])
        {
            menor = numeros[j];
            posicion = j;
        }
    }
    printf("El dato menores %d y esta en la posicion %d\n", menor, posicion);
}
