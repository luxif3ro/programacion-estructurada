#include <stdlib.h>

/**
 * Obtiene la longitud de una cadena de caracteres.
 * 
 * @param cadena Puntero a la cadena de caracteres de la cual se quiere conocer la longitud.
 * 
 * @return La longitud de la cadena de caracteres.
 * 
 * @details Esta función calcula la longitud de la cadena de caracteres pasada como argumento.
 * 
 * @author Jesús Salvador García López
 */
int _longitud(char *cadena)
{
    int longitud = 0;
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        longitud++;
    }
    return longitud;
}

/**
 * Concatena dos cadenas de caracteres y devuelve una nueva cadena que contiene la concatenación.
 * 
 * @param cadenaUno Puntero a la primera cadena de caracteres.
 * @param cadenaDos Puntero a la segunda cadena de caracteres.
 * 
 * @return Un puntero a la nueva cadena que contiene la concatenación de cadenaUno y cadenaDos.
 *         Es responsabilidad del llamador liberar la memoria asignada para esta cadena.
 * 
 * @details Esta función concatena dos cadenas de caracteres y devuelve una nueva cadena que contiene la concatenación.
 * 
 * @author Jesús Salvador García López
 */
char *_concatenarCadena(char *cadenaUno, char *cadenaDos)
{
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

/**
 * Compara dos cadenas de caracteres y determina si son iguales.
 * 
 * @param cadenaUno Puntero a la primera cadena de caracteres.
 * @param cadenaDos Puntero a la segunda cadena de caracteres.
 * 
 * @return 1 si las cadenas son iguales, 0 si son diferentes.
 * 
 * @details Esta función compara dos cadenas de caracteres y determina si son iguales.
 * 
 * @author Jesús Salvador García López
 */
int _compararCadena(char *cadenaUno, char *cadenaDos)
{
    int longitudUno = _longitud(cadenaUno);
    int longitudDos = _longitud(cadenaDos);
    int igualdad = 1;

    if (longitudUno != longitudDos)
    {
        return igualdad = 0;
    }
    for (int i = 0; i < longitudUno; i++)
    {
        if (cadenaUno[i] != cadenaDos[i])
        {
            return igualdad = 0;
        }
    }
    return igualdad;
}

/**
 * Copia una cadena de caracteres a otra.
 * 
 * @param cadenaOriginal Puntero a la cadena original que se desea copiar.
 * @param cadenaCopia Puntero a la cadena donde se copiará la cadena original.
 * 
 * @return Puntero a la cadena copiada.
 * 
 * @details Esta función copia una cadena de caracteres a otra.
 * 
 * @author Jesús Salvador García López
 */
char *_copiarCadena(char *cadenaOriginal, char *cadenaCopia)
{
    int i;
    for (i = 0; cadenaOriginal[i] != '\0'; i++)
    {
        cadenaCopia[i] = cadenaOriginal[i];
    }
    cadenaCopia[i] = '\0';
    return cadenaCopia;
}

/**
 * Invierte el orden de los caracteres en una cadena.
 * 
 * @param cadena Puntero a la cadena que se desea invertir.
 * 
 * @return Puntero a la cadena invertida.
 * 
 * @details Esta función invierte el orden de los caracteres en una cadena.
 *          Es responsabilidad del llamador liberar la memoria asignada para la cadena invertida.
 * 
 * @author Jesús Salvador García López
 */
char *_invertirCadena(char *cadena)
{
    int longitud = _longitud(cadena);
    char *cadenaAuxiliar = (char *)malloc((longitud + 1) * sizeof(char));
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

    // Liberar memoria asignada a la cadena original antes de reasignarla.
    free(cadena);

    // Reasignar la cadena original con la cadena invertida.
    cadena = cadenaAuxiliar;

    return cadena;
}
