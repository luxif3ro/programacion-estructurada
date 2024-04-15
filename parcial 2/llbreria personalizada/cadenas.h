#ifndef Cadenas_h
#define Cadenas_h
#include "cadenas.c"
// cabecera de la funcion _longitud
int _longitud(char *cadena);
// cabecera de la funcion _concatenarCadena
char *_concatenarCadena(char *cadenaReceptora, char *cadenaDonadora);
// cabecera de la funcion _compararCadena
int _compararCadena(char *canedaUno, char *cadenaDos);
// cabecera de la funcion _copiarCadena
char *_copiarCadena(char *cadenaOriginal, char *cadenaCopia);
// cabecera de la funcion _invertirCadena
char *_invertirCadena(char *cadena);
#endif