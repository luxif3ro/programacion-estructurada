#include <stdlib.h>
// Declaracion del la funcion _longitud()
int _longitud(char *cadena)
{
    /*
    * @param
    *   char* cadena
    * 
    * @details
    *   funcion que retorna la longitud del arrelo de caracteres recibido en el parametro
    *   mediante un ciclo for 
    */
    int longitud = 0;
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        longitud++;
    }
    return longitud;
}
//Declaracion de la funcion _concatenarCadena()
char *_concatenarCadena(char *cadenaUno, char *cadenaDos)
{
    /*
    * @param
    *   char* cadenaUno
    *   char* cadenaDos
    * 
    * @details
    *   funcion que retorna una arreglo de caracteres declarado dentro de  esta funcion 
    *   la cual contiene el valor concatenado de los atributos:
    *        cadenaUno y cadenaDos 
    */
    int longitudUno = _longitud(cadenaUno);
    int longitudDos = _longitud(cadenaDos);
    char *cadenaNueva = (char *)malloc((longitudUno + longitudDos + 1) * sizeof(char));
    int i, j = 0;
    for (i = 0; i < longitudUno; i++)
    {
        cadenaNueva[i] = cadenaUno[i];
    }

    for (i = longitudUno; i < longitudUno + longitudDos; i++)
    {
        cadenaNueva[i] = cadenaDos[j];
        j++;
    }
    cadenaNueva[longitudUno + longitudDos] = '\0';

    return cadenaNueva;
}
//declaracion de la funcion _compararCadena()
int _compararCadena(char *canedaUno, char *cadenaDos)
{
    /*
    *
    * @param
    *   char *cadenaUno
    *   char *cadenaDos
    * 
    * @details
    *   funcion que retorna un valor entero que se usa como booleano(1 o 0) el cual
    *   se obtiene de comparar los valores de los atributos:
    *       cadenaUno y cadenaDos
    * 
    */
    int longitudUno = _longitud(canedaUno);
    int longitudDos = _longitud(cadenaDos);
    int igualdad = 1;

    if (longitudUno != longitudDos)
    {
        return igualdad = 0;
    }
    for (int i = 0; i < longitudUno; i++)
    {
        if (canedaUno[i] != cadenaDos[i])
        {
            return igualdad = 0;
        }
    }
    return igualdad;
}
//declaracion de la funcion _copiarCadena()
char *_copiarCadena(char *cadenaOriginal, char *cadenaCopia)
{
        /*
    *
    * @param
    *   char* cadena
    * 
    * @details
    *   - funcion que copia y pega los textos 
    *   - cadenaOriginal para agregar el texto que deseas copiar
    *   - cadenaCopia copia el texto anteriormente agregado de la funcion cadenaOriginal
    * 
    */
    int i;
    for (i = 0; cadenaOriginal[i] != '\0'; i++)
    {
        cadenaCopia[i] = cadenaOriginal[i];
    }
    cadenaCopia[i] = '\0';
    return cadenaCopia;
}
//declaracion de la funcion _invertirCadena
char *_invertirCadena(char *cadena)
{
    /*
    *
    * @param
    *   char* cadena
    * 
    * @details
    *   funcion que invirte lo que tienes dentro de la cadena
    * 
    */
    int longitud = _longitud(cadena);
    char *cadenaAuxiliar = (char *)malloc((longitud + 1) * sizeof(char)); // Asignar memoria para cadenaAuxiliar
    if (cadenaAuxiliar == NULL)
    {
        return NULL;
    }

    int i, j = longitud - 1;

    for (i = 0; i < longitud; i++)
    {
        cadenaAuxiliar[i] = cadena[j];
        j--;
    }
    cadenaAuxiliar[i] = '\0';

    for (i = 0; i < longitud; i++)
    {
        cadena[i] = cadenaAuxiliar[i];
    }
    cadena[i] = '\0';

    free(cadenaAuxiliar);//libera la memoria del arreglo de caracteres
    return cadena;
}
