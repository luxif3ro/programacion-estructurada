#include <stdio.h>
#define MAX_LENGTH 100

void _eliminacionDuplicado(int vec[MAX_LENGTH], int tam);

int main()
{
    int arrayDuplicate[MAX_LENGTH], i, longuitud;
    char respuesta = 'y';
    while (respuesta == 'y' && i < MAX_LENGTH)
    {
        printf("Dame el numero a guardar > ");
        scanf("%d", &arrayDuplicate[i]);
        printf("¿Deseas seguir guardando numeros? (y/n) > ");
        scanf(" %c", &respuesta);
        i++;
    }
    longuitud = i;
    printf("Vector inicial: ");
    for (i = 0; i < longuitud; i++)
    {
        printf("%i, ", arrayDuplicate[i]);
    }

    _eliminacionDuplicado(arrayDuplicate, longuitud);
    return 0;
}

void _eliminacionDuplicado(int vec[MAX_LENGTH], int tam)
{
    int i, j, k;
    for (i = 0; i < tam; i++)
    {
        for (j = i + 1; j < tam; j++)
        {
            if (vec[i] == vec[j])
            {

                k = j;

                while (k < tam) // Mientras k sea menor que la cantidad de elementos
                {
                    vec[k] = vec[k + 1]; // Copiará el elemento siguiente,

                    // Ejemplo en posición 1 copiará el valor de la posición la dos, y en la dos la tres y así sucesivamente.

                    ++k; // Aumentamos el contador k en 1
                }

                --tam; // Disminuimos el tamaño del vector ya que se eliminaron elementos repetidos.
                --j;

                /* --j
                 *
                 * Disminuimos  el valor de j para verificar si el elemento que se copió ahí es igual al anterior.
                 *
                 * Ejemplo: vec[] ={1,2,2,3,4}
                 *
                 * Cuando llegue a la  comparación 2==2 moverá el 3 a la posición del 2 repetido, si no disminuimos
                 * el contador en la próxima comparación comparará 2 == 4, y no con el 3, porque si 3 hubiese
                 * sido otro 2 lo saltaría y no lo eliminaría.
                 * */

            } // Fin del if

        } // Fin del bucle for con j

    } // Fin del bucle for con i
    printf("\nVector final: ");
    for (i = 0; i < tam; i++)
    {
        printf("%i, ", vec[i]);
    }
}