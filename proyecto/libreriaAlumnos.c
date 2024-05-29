#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "libreriaCadenas.h"

/**
 * Estructura que representa a un estudiante.
 *
 * Esta estructura contiene los datos de un estudiante, incluyendo su identificador, nombre, apellido
 * y las calificaciones de cuatro parciales y la calificación final.
 *
 * @field id             El identificador único del estudiante.
 * @field nombre         El nombre del estudiante.
 * @field apellido       El apellido del estudiante.
 * @field parcial_1      La calificación del primer parcial.
 * @field parcial_2      La calificación del segundo parcial.
 * @field parcial_3      La calificación del tercer parcial.
 * @field parcialFinal   La calificación final del estudiante.
 *
 * @details Esta estructura representa a un estudiante y almacena sus datos personales y calificaciones.
 *          Cada estudiante tiene un identificador único, un nombre, un apellido y calificaciones para
 *          cuatro parciales, así como una calificación final.
 *
 * @author Jesús Salvador García López
 */
typedef struct Estudiante
{
    char id[7];
    char nombre[50];
    char apellido[50];
    float parcial_1;
    float parcial_2;
    float parcial_3;
    float parcialFinal;
} Estudiante;
int tamañoEstudiantes =0;

/**
 * Obtiene el tamaño de un archivo en bytes.
 *
 * @param archivo Puntero al archivo del cual se desea obtener el tamaño.
 *
 * @return El tamaño del archivo en bytes.
 *         Si ocurre algún error, devuelve un valor negativo.
 *
 * @details Esta función obtiene el tamaño de un archivo en bytes.
 *          Si ocurre algún error durante la obtención del tamaño, devuelve un valor negativo.
 *
 * @author Jesús Salvador García López
 *
 */
int _obtenerTamanoArchivo(FILE *archivo)
{
    int tamano;
    fseek(archivo, 0, SEEK_END);
    tamano = ftell(archivo);
    fseek(archivo, 0, SEEK_SET);
    return tamano;
}

/**
 * Crea una estructura de estudiantes a partir de un archivo.
 *
 * @param archivo Puntero al archivo del cual se leerán los datos para crear la estructura de estudiantes.
 *
 * @return Un puntero a la estructura de estudiantes creada.
 *         Si ocurre algún error, devuelve NULL.
 *
 * @details Esta función crea una estructura de estudiantes a partir de un archivo.
 *          Si ocurre algún error durante la creación de la estructura, devuelve NULL.
 *          Es responsabilidad del llamador liberar la memoria asignada para esta estructura.
 *
 * @author Jesús Salvador García López
 */
Estudiante *_creacionDeEstructura(FILE *archivo)
{
    Estudiante alumnes;
    while (fscanf(archivo, "%s %s %s %f %f %f",
                  alumnes.id,
                  alumnes.nombre,
                  alumnes.apellido,
                  &alumnes.parcial_1,
                  &alumnes.parcial_2,
                  &alumnes.parcial_3) == 6)
    {
        tamañoEstudiantes++;
    }
    int num_estudiantes=tamañoEstudiantes;
    Estudiante *alumnos = (Estudiante *)malloc(num_estudiantes * sizeof(Estudiante));
    fseek(archivo,0,SEEK_SET);
    if (alumnos == NULL)
    {
        perror("Error: No se pudo asignar memoria para el arreglo de estudiantes.\n");
        return NULL;
    }
    return alumnos;
}

/**
 * Llena una estructura de estudiantes a partir de un archivo.
 *
 * @param archivo Puntero al archivo del cual se leerán los datos para llenar la estructura de estudiantes.
 * @param alumnos Puntero a la estructura de estudiantes que se desea llenar.
 *
 * @return Un puntero a la estructura de estudiantes llena.
 *         Si ocurre algún error, devuelve NULL.
 *
 * @details Esta función llena una estructura de estudiantes a partir de un archivo.
 *          Si ocurre algún error durante el llenado de la estructura, devuelve NULL.
 *          Es responsabilidad del llamador liberar la memoria asignada para esta estructura.
 *
 * @author Jesús Salvador García López
 */
void _llenadoDeEstructura(FILE *archivo, Estudiante *alumnos)
{
    int i = 0;
    printf("hola puta\n");
    for ( i = 0; i < tamañoEstudiantes; i++)
    {
        fscanf(archivo, "%s %s %s %f %f %f",
                  alumnos[i].id,
                  alumnos[i].nombre,
                  alumnos[i].apellido,
                  &alumnos[i].parcial_1,
                  &alumnos[i].parcial_2,
                  &alumnos[i].parcial_3);
        alumnos[i].parcialFinal=11;
    } 
}

void _calcularCalificacionFinal(Estudiante *alumnos, FILE *archivo)
{
    int i = 0;
    float calificacionFinal = 0;
    while (i < tamañoEstudiantes)
    {
        calificacionFinal = (alumnos[i].parcial_1 + alumnos[i].parcial_2 + alumnos[i].parcial_3) / 3;
        if (calificacionFinal < 6.5)
        {
            alumnos[i].parcialFinal = calificacionFinal;
        }
        else if (calificacionFinal < 7.5)
        {
            alumnos[i].parcialFinal = 7;
        }
        else if (calificacionFinal < 8.5)
        {
            alumnos[i].parcialFinal = 8;
        }
        else if (calificacionFinal < 9.5)
        {
            alumnos[i].parcialFinal = 9;
        }
        else
        {
            alumnos[i].parcialFinal = 10;
        }
        i++;
    }
}

/**
 * Imprime las calificaciones de los estudiantes.
 *
 * @param Alumno Puntero a la estructura de estudiantes.
 * @param tamaño Tamaño de la estructura de estudiantes.
 *
 * @details Esta función imprime las calificaciones de los estudiantes en un formato específico.
 *          Antes de imprimir las calificaciones, muestra un encabezado con los nombres de las columnas.
 *          Llama a la función _preguntaDeControl al finalizar la impresión.
 *
 * @author Jesús Salvador García López
 */
void _impresionDeCalificaciones(Estudiante *Alumno)
{
    printf("si entra a la funcion\n");
    //system("cls");
    printf("| REPORTE GENERAL DE CALIFICACIONES |\n\n");
    printf("______________________________________________________________________________________________________\n");
    printf("|%-7s | %-15s | %-15s | %-10s | %-10s | %-10s | %-14s |\n", "ID", "Nombre", "Apellido", "Parcial 1", "Parcial 2", "Parcial 3", "Parcial Final");
    printf("______________________________________________________________________________________________________\n");
    for (int i = 0; i < tamañoEstudiantes; i++)
    {
        printf("|%-7s | %-15s | %-15s | %-10.2f | %-10.2f | %-10.2f | %-14.0f |\n",
               Alumno[i].id,
               Alumno[i].nombre,
               Alumno[i].apellido,
               Alumno[i].parcial_1,
               Alumno[i].parcial_2,
               Alumno[i].parcial_3,
               Alumno[i].parcialFinal);
    }
    printf("______________________________________________________________________________________________________\n");
}

/**
 * Calcula y muestra el promedio general del grupo sin redondear.
 *
 * @param Alumno Puntero a la estructura de estudiantes.
 * @param tamaño Tamaño de la estructura de estudiantes.
 *
 * @details Esta función calcula el promedio general del grupo sin redondear y lo muestra en pantalla.
 *          Llama a la función _preguntaDeControl al finalizar el cálculo.
 *
 * @author Jesús Salvador García López
 */
void _promedioGeneralSinRedondear(Estudiante *alumnos, int tamaño)
{
    int i;
    float sumaGeneral = 0;

    for (i = 0; i < tamaño; i++)
    {
        sumaGeneral += (alumnos[i].parcial_1 + alumnos[i].parcial_2 + alumnos[i].parcial_3) / 3;
    }
    printf("| PROMEDIO GENERAL DEL GRUPO |\n\n");
    printf("El promedio general del grupo es %.2f \n", (sumaGeneral / tamaño));
}

/**
 * Encuentra al estudiante con la menor calificación final.
 *
 * @param Alumno Puntero a la estructura de estudiantes.
 * @param tamaño Tamaño de la estructura de estudiantes.
 *
 * @details Esta función encuentra al estudiante con la menor calificación final y muestra sus datos en pantalla.
 *          Llama a la función _preguntaDeControl al finalizar la búsqueda.
 *
 * @author Jesús Salvador García López
 */
void _menorCalificacion(Estudiante *Alumno, int tamaño)
{
    int posicion = 0;
    float minima = Alumno[0].parcialFinal;

    for (int i = 1; i < tamaño; i++)
    {
        if (Alumno[i].parcialFinal < minima)
        {
            minima = Alumno[i].parcialFinal;
            posicion = i;
        }
    }

    printf("| ALUMNO CON MENOR CALIFICACION |\n\n");
    printf("El alumno con la menor calificación es:\n");
    printf("______________________________________________________________________________________________________\n");
    printf("|%-7s | %-15s | %-15s | %-10s | %-10s | %-10s | %-14s |\n", "ID", "Nombre", "Apellido", "Parcial 1", "Parcial 2", "Parcial 3", "Parcial 4", "Parcial Final");
    printf("______________________________________________________________________________________________________\n");

    printf("|%-7s | %-15s | %-15s | %-10.2f | %-10.2f | %-10.2f | %-14.0f |\n",
           Alumno[posicion].id,
           Alumno[posicion].nombre,
           Alumno[posicion].apellido,
           Alumno[posicion].parcial_1,
           Alumno[posicion].parcial_2,
           Alumno[posicion].parcial_3,
           Alumno[posicion].parcialFinal);

    printf("______________________________________________________________________________________________________\n");
}

/**
 * Encuentra al estudiante con la mayor calificación final.
 *
 * @param Alumno Puntero a la estructura de estudiantes.
 * @param tamaño Tamaño de la estructura de estudiantes.
 *
 * @details Esta función encuentra al estudiante con la mayor calificación final y muestra sus datos en pantalla.
 *          Llama a la función _preguntaDeControl al finalizar la búsqueda.
 *
 * @author Jesús Salvador García López
 */
void _mayorCalificacion(Estudiante *Alumno, int tamaño)
{
    int posicion = 0;
    float maxima = Alumno[0].parcialFinal;

    for (int i = 1; i < tamaño; i++)
    {
        if (Alumno[i].parcialFinal > maxima)
        {
            maxima = Alumno[i].parcialFinal;
            posicion = i;
        }
    }

    printf("| ALUMNO CON MAYOR CALIFICACION |\n\n");
    printf("El alumno con la mayor calificación es:\n");
    printf("______________________________________________________________________________________________________\n");
    printf("|%-7s | %-15s | %-15s | %-10s | %-10s | %-10s | %-14s |\n", "ID", "Nombre", "Apellido", "Parcial 1", "Parcial 2", "Parcial 3", "Parcial 4", "Parcial Final");
    printf("______________________________________________________________________________________________________\n");

    printf("|%-7s | %-15s | %-15s | %-10.2f | %-10.2f | %-10.2f | %-14.0f |\n",
           Alumno[posicion].id,
           Alumno[posicion].nombre,
           Alumno[posicion].apellido,
           Alumno[posicion].parcial_1,
           Alumno[posicion].parcial_2,
           Alumno[posicion].parcial_3,
           Alumno[posicion].parcialFinal);

    printf("______________________________________________________________________________________________________\n");
}

/**
 * Intercambia dos estudiantes en un arreglo.
 *
 * @param a Puntero al primer estudiante.
 * @param b Puntero al segundo estudiante.
 *
 * @details Esta función intercambia dos estudiantes en un arreglo.
 *          Se utiliza en el proceso de ordenar los estudiantes.
 *
 * @author Jesús Salvador García López
 */
void _intercambiar(Estudiante *a, Estudiante *b)
{
    Estudiante temporal = *a;
    *a = *b;
    *b = temporal;
}

/**
 * Ordena los estudiantes de menor a mayor según su calificación final y muestra el resultado.
 *
 * @param alumno Puntero a la estructura de estudiantes.
 * @param tamaño Tamaño de la estructura de estudiantes.
 *
 * @details Esta función ordena los estudiantes de menor a mayor según su calificación final y muestra el resultado en pantalla.
 *          Llama a la función _preguntaDeControl al finalizar la ordenación.
 *
 * @author Jesús Salvador García López
 */
void _ordenarMenorMayor(Estudiante *alumno, int tamaño)
{
    Estudiante *alumnoOrdenado = (Estudiante *)malloc(tamaño * sizeof(Estudiante));
    if (alumnoOrdenado == NULL)
    {
        perror("Error al asignar memoria para el arreglo ordenado");
        return;
    }

    memcpy(alumnoOrdenado, alumno, tamaño * sizeof(Estudiante));

    for (int i = 0; i < tamaño - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < tamaño; j++)
        {
            if (alumnoOrdenado[j].parcialFinal < alumnoOrdenado[min_idx].parcialFinal)
            {
                min_idx = j;
            }
        }
        _intercambiar(&alumnoOrdenado[min_idx], &alumnoOrdenado[i]);
    }

    printf("______________________________________________________________________________________________________\n");
    printf("|%-7s | %-15s | %-15s | %-10s | %-10s | %-10s | %-14s |\n", "ID", "Nombre", "Apellido", "Parcial 1", "Parcial 2", "Parcial 3", "Parcial 4", "Parcial Final");
    printf("______________________________________________________________________________________________________\n");
    for (int i = 0; i < tamaño; i++)
    {
        printf("|%-7s | %-15s | %-15s | %-10.2f | %-10.2f | %-10.2f | %-14.0f |\n",
               alumnoOrdenado[i].id,
               alumnoOrdenado[i].nombre,
               alumnoOrdenado[i].apellido,
               alumnoOrdenado[i].parcial_1,
               alumnoOrdenado[i].parcial_2,
               alumnoOrdenado[i].parcial_3,
               alumnoOrdenado[i].parcialFinal);
    }
    printf("______________________________________________________________________________________________________\n");

    free(alumnoOrdenado);
}

/**
 * Busca un estudiante por su ID y muestra sus datos.
 *
 * @param alumnos Puntero a la estructura de estudiantes.
 * @param tamaño Tamaño de la estructura de estudiantes.
 *
 * @details Esta función busca un estudiante por su ID y muestra sus datos si se encuentra.
 *          Si no se encuentra ningún estudiante con el ID especificado, muestra un mensaje de error.
 *          Llama a la función _preguntaDeControl al finalizar la búsqueda.
 *
 * @author Jesús Salvador García López
 */
void _buscarID(Estudiante *alumnos, int tamaño)
{
    int posicion = -1;
    char IDbuscar[7];

    printf("| BUSQUEDA POR ID |\n\n");
    printf("Dame el ID a buscar > ");
    scanf("%s", IDbuscar);

    // Buscamos el ID en el arreglo de estudiantes
    for (int i = 0; i < tamaño; i++)
    {
        if (_compararCadena(alumnos[i].id, IDbuscar))
        {
            posicion = i;
            break;
        }
    }

    if (posicion != -1)
    {
        printf("Alumno encontrado, es:\n");
        printf("______________________________________________________________________________________________________\n");
        printf("|%-7s | %-15s | %-15s | %-10s | %-10s | %-10s | %-14s |\n", "ID", "Nombre", "Apellido", "Parcial 1", "Parcial 2", "Parcial 3", "Parcial 4", "Parcial Final");
        printf("______________________________________________________________________________________________________\n");
        printf("|%-7s | %-15s | %-15s | %-10.2f | %-10.2f | %-10.2f | %-14.0f |\n",
               alumnos[posicion].id,
               alumnos[posicion].nombre,
               alumnos[posicion].apellido,
               alumnos[posicion].parcial_1,
               alumnos[posicion].parcial_2,
               alumnos[posicion].parcial_3,
               alumnos[posicion].parcialFinal);
        printf("______________________________________________________________________________________________________\n");
    }
    else
    {
        perror("No se encontró ningún alumno con ese ID");
    }
}

/**
 * Calcula y muestra el porcentaje de alumnos aprobados y reprobados.
 *
 * @param alumnos Puntero a la estructura de estudiantes.
 * @param tamaño Tamaño de la estructura de estudiantes.
 *
 * @details Esta función calcula y muestra el porcentaje de alumnos aprobados y reprobados en el grupo.
 *          Llama a la función _preguntaDeControl al finalizar los cálculos.
 *
 * @author Jesús Salvador García López
 */
void _porcentajeAprobadoReprobado(Estudiante *alumnos, int tamaño)
{
    int aprobados = 0;
    float porcentaje;

    if (tamaño <= 0)
    {
        perror("Error: Tamaño inválido de estudiantes");
        return;
    }

    for (int i = 0; i < tamaño; i++)
    {
        if (alumnos[i].parcialFinal >= 7)
        {
            aprobados++;
        }
    }

    porcentaje = (aprobados * 100.0) / tamaño;
    float porcentaje_reprobados = 100.0 - porcentaje;

    printf("El porcentaje de alumnos aprobados es del %.2f%%\n", porcentaje);
    printf("El porcentaje de alumnos reprobados es del %.2f%%\n\n", porcentaje_reprobados);
}
