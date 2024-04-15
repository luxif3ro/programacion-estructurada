/*
 * PROGRAMA ELABORADO POR JESUS SALADOR GARCIA LOPEZ
 */

#include <stdlib.h>
#include <stdio.h>

int main()
{
    char cadUno[50];
    char cadDos[50];
    int i = 0;

    printf("Dame la cadena a guardar > ");
    scanf("%s", cadUno);
    while (cadUno[i] != '\0')
    {
        cadDos[i] = cadUno[i];
        i++;
    }
    printf("La cadena original es : %s \n", cadUno);
    printf("La cedena copia es : %s \n ", cadDos);
    return 0;
}
