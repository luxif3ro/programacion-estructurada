/*
* Programa que comprueba que se este realizando la buena importacion de
* librerias personalizadas
*
* @authors
*   Dante Ivan Serrano Leyva
*   Luis Pablo Mendoza Saucedo
*   Ana Gabriela Padilla Garcia
*   Daniela Tirado faraci
*   Jesus Salvador Garcia Lopez
*/
#include <stdio.h>
#include <string.h>
#include "cadenas.h"

int main()
{
    char cadena[]="hola";
    char cadenaDos[]="holas";
    printf("Primera cadena: %s \n",cadena);
    printf("Segunda cadena: %s \n",cadenaDos);
    printf("Longitud primera cadena: %d\n",_longitud(cadena));
    char *concatenada=_concatenarCadena(cadena,cadenaDos);
    printf("Cadenas concatenadas: %s\n",concatenada);
    if ((_compararCadena(cadena,cadenaDos))==0)
    {
        printf("las cadenas no son iguales\n");
    } 
    _copiarCadena(cadena,cadenaDos);
    printf("Copiar la primera cadena en la segunda: %s\n",cadenaDos);
    if ((_compararCadena(cadena,cadenaDos))==1)
    {
        printf("las cadenas si son iguales\n");
    }
    printf("Primera cadena invertida: %s\n",_invertirCadena(cadena));

    free(concatenada);
    return 0;
}
