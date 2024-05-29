#ifndef CADENAS_H
#define CADENAS_H

#include "libreriaCadenas.c"
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
int _longitud(char *cadena);


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
int _compararCadena(char *cadenaUno, char *cadenaDos);

#endif /* CADENAS_H */
