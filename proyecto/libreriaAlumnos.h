#ifndef FUNCIONES_ESTUDIANTE_H
#define FUNCIONES_ESTUDIANTE_H

#include <stdio.h>
#include "libreriaAlumnos.c"

/**
 * Obtiene el tamaño de un archivo en bytes.
 * 
 * @param archivo Puntero al archivo del cual se desea obtener el tamaño.
 * 
 * @return El tamaño del archivo en bytes.
 *         Si ocurre algún error, devuelve un valor negativo.
 */
int _obtenerTamanoArchivo(FILE *archivo);

/**
 * Crea una estructura de estudiantes a partir de un archivo.
 * 
 * @param archivo Puntero al archivo del cual se leerán los datos para crear la estructura de estudiantes.
 * 
 * @return Un puntero a la estructura de estudiantes creada.
 *         Si ocurre algún error, devuelve NULL.
 */
Estudiante *_creacionDeEstructura(FILE *archivo);

/**
 * Llena una estructura de estudiantes a partir de un archivo.
 * 
 * @param archivo Puntero al archivo del cual se leerán los datos para llenar la estructura de estudiantes.
 * @param alumnos Puntero a la estructura de estudiantes que se desea llenar.
 * @param tamaño Tamaño del arreglo de estudiantes.
 * 
 * @return Un puntero a la estructura de estudiantes llena.
 *         Si ocurre algún error, devuelve NULL.
 */
void _llenadoDeEstructura(FILE *archivo, Estudiante *alumnos);

/**
 * Imprime las calificaciones de los estudiantes en formato tabular.
 * 
 * @param alumnos Puntero al arreglo de estudiantes.
 * @param tamaño Tamaño del arreglo de estudiantes.
 */
void _impresionDeCalificaciones(Estudiante *alumnos);

void _calcularCalificacionFinal(Estudiante *alumnos,FILE *archivo);

/**
 * Calcula y muestra el promedio general del grupo sin redondear.
 * 
 * @param alumnos Puntero al arreglo de estudiantes.
 * @param tamaño Tamaño del arreglo de estudiantes.
 */
void _promedioGeneralSinRedondear(Estudiante *alumnos, int tamaño);

/**
 * Encuentra al alumno con la menor calificación y la imprime.
 * 
 * @param alumnos Puntero al arreglo de estudiantes.
 * @param tamaño Tamaño del arreglo de estudiantes.
 */
void _menorCalificacion(Estudiante *alumnos, int tamaño);

/**
 * Encuentra al alumno con la mayor calificación y la imprime.
 * 
 * @param alumnos Puntero al arreglo de estudiantes.
 * @param tamaño Tamaño del arreglo de estudiantes.
 */
void _mayorCalificacion(Estudiante *alumnos, int tamaño);

/**
 * Ordena las calificaciones de los estudiantes de menor a mayor y las imprime.
 * 
 * @param alumnos Puntero al arreglo de estudiantes.
 * @param tamaño Tamaño del arreglo de estudiantes.
 */
void _ordenarMenorMayor(Estudiante *alumnos, int tamaño);

/**
 * Busca a un estudiante por su ID y muestra sus datos si se encuentra.
 * 
 * @param alumnos Puntero al arreglo de estudiantes.
 * @param tamaño Tamaño del arreglo de estudiantes.
 */
void _buscarID(Estudiante *alumnos, int tamaño);

/**
 * Calcula y muestra el porcentaje de alumnos aprobados y reprobados.
 * 
 * @param alumnos Puntero al arreglo de estudiantes.
 * @param tamaño Tamaño del arreglo de estudiantes.
 */
void _porcentajeAprobadoReprobado(Estudiante *alumnos, int tamaño);

#endif /* FUNCIONES_ESTUDIANTE_H */
