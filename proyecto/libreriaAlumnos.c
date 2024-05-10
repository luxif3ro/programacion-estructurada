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
 * @field parcial_4      La calificación del cuarto parcial.
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
    float parcial_4;
    float parcialFinal;
} Estudiante;


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
int _obtenerTamanoArchivo(FILE *archivo) {
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
Estudiante *_creacionDeEstructura(FILE *archivo) {
    int tamaño = _obtenerTamanoArchivo(archivo);
    if (tamaño <= 0) {
        perror("Error: El tamaño del archivo es inválido.\n");
        return NULL;
    }
    int num_estudiantes = tamaño / sizeof(Estudiante);
    Estudiante *alumnos = (Estudiante *)malloc(num_estudiantes * sizeof(Estudiante));
    if (alumnos == NULL) {
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
Estudiante *_llenadoDeEstructura(FILE *archivo, Estudiante *alumnos) {
    int i = 0;
    while (fscanf(archivo, "%6s %49s %49s %f %f %f %f %f",
                  alumnos[i].id,
                  alumnos[i].nombre,
                  alumnos[i].apellido,
                  &alumnos[i].parcial_1,
                  &alumnos[i].parcial_2,
                  &alumnos[i].parcial_3,
                  &alumnos[i].parcial_4,
                  &alumnos[i].parcialFinal) == 8)
    {
        i++;
    }
    if (i == 0 && feof(archivo)) {
        perror("Error: El archivo está vacío");
        return NULL;
    } else if (!feof(archivo)) {
        perror("Error durante la lectura del archivo");
        return NULL;
    }

    return alumnos;
}

/**
 * Realiza una pregunta de control y espera una respuesta válida.
 * 
 * @param Alumno Puntero a la estructura de estudiantes.
 * 
 * @details Esta función realiza una pregunta de control y espera una respuesta válida (1 para sí, 0 para no).
 *          Si la respuesta es 1, llama a la función menu con la estructura de estudiantes como argumento.
 *          Si la respuesta es 0, muestra un mensaje de despedida.
 *          Si la respuesta no es válida, muestra un mensaje de error y vuelve a solicitar la respuesta.
 * 
 * @author Jesús Salvador García López
 */
void _preguntaDeControl(Estudiante *Alumno) {
    int respuesta, valido = 0;
    do {
        printf("Desea seguir revisando reportes? (1 = sí, 0 = no) > ");
        scanf("%d", &respuesta);
        if (respuesta == 1) {
            menu(Alumno);
            valido = 1;
        } else if (respuesta == 0) {
            system("cls");
            printf("VUELVA PRONTO");
            valido = 1;
        } else {
            printf("Favor de dar una respuesta válida.\n");
        }
    } while (valido == 0);
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
void _impresionDeCalificaciones(Estudiante *Alumno, int tamaño) {
    system("cls");
    printf("| REPORTE GENERAL DE CALIFICACIONES |\n\n");
    printf("___________________________________________________________________________________________________________________\n");
    printf("|%-7s | %-15s | %-15s | %-10s | %-10s | %-10s | %-10s | %-14s |\n", "ID", "Nombre", "Apellido", "Parcial 1", "Parcial 2", "Parcial 3", "Parcial 4", "Parcial Final");
    printf("-------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < tamaño; i++) {
        printf("|%-7s | %-15s | %-15s | %-10.2f | %-10.2f | %-10.2f | %-10.2f | %-14.0f |\n",
               Alumno[i].id,
               Alumno[i].nombre,
               Alumno[i].apellido,
               Alumno[i].parcial_1,
               Alumno[i].parcial_2,
               Alumno[i].parcial_3,
               Alumno[i].parcial_4,
               Alumno[i].parcialFinal);
    }
    printf("-------------------------------------------------------------------------------------------------------------------\n");
    _preguntaDeControl(Alumno);
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
void _promedioGeneralSinRedondear(Estudiante *Alumno, int tamaño) {
    system("cls");
    int i;
    float sumaGeneral = 0;

    for (i = 0; i < tamaño; i++) {
        sumaGeneral += Alumno[i].parcialFinal;
    }
    printf("| PROMEDIO GENERAL DEL GRUPO |\n\n");
    printf("El promedio general del grupo es %.2f \n", (sumaGeneral / tamaño));
    _preguntaDeControl(Alumno);
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
void _menorCalificacion(Estudiante *Alumno, int tamaño) {
    system("cls");
    int posicion = 0;
    float minima = Alumno[0].parcialFinal;

    for (int i = 1; i < tamaño; i++) {
        if (Alumno[i].parcialFinal < minima) {
            minima = Alumno[i].parcialFinal;
            posicion = i;
        }
    }

    printf("| ALUMNO CON MENOR CALIFICACION |\n\n");
    printf("El alumno con la menor calificación es:\n");
    printf("___________________________________________________________________________________________________________________\n");
    printf("|%-7s | %-15s | %-15s | %-10s | %-10s | %-10s | %-10s | %-14s |\n", "ID", "Nombre", "Apellido", "Parcial 1", "Parcial 2", "Parcial 3", "Parcial 4", "Parcial Final");
    printf("-------------------------------------------------------------------------------------------------------------------\n");

    printf("|%-7s | %-15s | %-15s | %-10.2f | %-10.2f | %-10.2f | %-10.2f | %-14.0f |\n",
           Alumno[posicion].id,
           Alumno[posicion].nombre,
           Alumno[posicion].apellido,
           Alumno[posicion].parcial_1,
           Alumno[posicion].parcial_2,
           Alumno[posicion].parcial_3,
           Alumno[posicion].parcial_4,
           Alumno[posicion].parcialFinal);

    printf("-------------------------------------------------------------------------------------------------------------------\n");

    _preguntaDeControl(Alumno);
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
void _mayorCalificacion(Estudiante *Alumno, int tamaño) {
    system("cls");
    int posicion = 0;
    float maxima = Alumno[0].parcialFinal;

    for (int i = 1; i < tamaño; i++) {
        if (Alumno[i].parcialFinal > maxima) {
            maxima = Alumno[i].parcialFinal;
            posicion = i;
        }
    }

    printf("| ALUMNO CON MAYOR CALIFICACION |\n\n");
    printf("El alumno con la mayor calificación es:\n");
    printf("___________________________________________________________________________________________________________________\n");
    printf("|%-7s | %-15s | %-15s | %-10s | %-10s | %-10s | %-10s | %-14s |\n", "ID", "Nombre", "Apellido", "Parcial 1", "Parcial 2", "Parcial 3", "Parcial 4", "Parcial Final");
    printf("-------------------------------------------------------------------------------------------------------------------\n");

    printf("|%-7s | %-15s | %-15s | %-10.2f | %-10.2f | %-10.2f | %-10.2f | %-14.0f |\n",
           Alumno[posicion].id,
           Alumno[posicion].nombre,
           Alumno[posicion].apellido,
           Alumno[posicion].parcial_1,
           Alumno[posicion].parcial_2,
           Alumno[posicion].parcial_3,
           Alumno[posicion].parcial_4,
           Alumno[posicion].parcialFinal);

    printf("-------------------------------------------------------------------------------------------------------------------\n");

    _preguntaDeControl(Alumno);
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
void _ordenarMenorMayor(Estudiante *alumno, int tamaño) {
    system("cls");

    Estudiante *alumnoOrdenado = (Estudiante *)malloc(tamaño * sizeof(Estudiante));
    if (alumnoOrdenado == NULL) {
        perror("Error al asignar memoria para el arreglo ordenado");
        return;
    }

    memcpy(alumnoOrdenado, alumno, tamaño * sizeof(Estudiante));

    for (int i = 0; i < tamaño - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < tamaño; j++) {
            if (alumnoOrdenado[j].parcialFinal < alumnoOrdenado[min_idx].parcialFinal) {
                min_idx = j;
            }
        }
        _intercambiar(&alumnoOrdenado[min_idx], &alumnoOrdenado[i]);
    }

    printf("___________________________________________________________________________________________________________________\n");
    printf("|%-7s | %-15s | %-15s | %-10s | %-10s | %-10s | %-10s | %-14s |\n", "ID", "Nombre", "Apellido", "Parcial 1", "Parcial 2", "Parcial 3", "Parcial 4", "Parcial Final");
    printf("-------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < tamaño; i++) {
        printf("|%-7s | %-15s | %-15s | %-10.2f | %-10.2f | %-10.2f | %-10.2f | %-14.0f |\n", 
            alumnoOrdenado[i].id, 
            alumnoOrdenado[i].nombre, 
            alumnoOrdenado[i].apellido, 
            alumnoOrdenado[i].parcial_1, 
            alumnoOrdenado[i].parcial_2, 
            alumnoOrdenado[i].parcial_3, 
            alumnoOrdenado[i].parcial_4, 
            alumnoOrdenado[i].parcialFinal);
    }
    printf("-------------------------------------------------------------------------------------------------------------------\n");

    free(alumnoOrdenado);
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
void _intercambiar(Estudiante *a, Estudiante *b) {
    Estudiante temporal = *a;
    *a = *b;
    *b = temporal;
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
void _buscarID(Estudiante *alumnos, int tamaño) {
    system("cls");
    int posicion = -1;
    char IDbuscar[7];
    
    printf("| BUSQUEDA POR ID |\n\n");
    printf("Dame el ID a buscar > ");
    scanf("%s", IDbuscar);
    
    // Buscamos el ID en el arreglo de estudiantes
    for (int i = 0; i < tamaño; i++) {
        if (_compararCadena(alumnos[i].id, IDbuscar)) {
            posicion = i;
            break;
        }
    }

    if (posicion != -1) {
        printf("Alumno encontrado, es:\n");
        printf("___________________________________________________________________________________________________________________\n");
        printf("|%-7s | %-15s | %-15s | %-10s | %-10s | %-10s | %-10s | %-14s |\n", "ID", "Nombre", "Apellido", "Parcial 1", "Parcial 2", "Parcial 3", "Parcial 4", "Parcial Final");
        printf("-------------------------------------------------------------------------------------------------------------------\n");
        printf("|%-7s | %-15s | %-15s | %-10.2f | %-10.2f | %-10.2f | %-10.2f | %-14.0f |\n",
               alumnos[posicion].id,
               alumnos[posicion].nombre,
               alumnos[posicion].apellido,
               alumnos[posicion].parcial_1,
               alumnos[posicion].parcial_2,
               alumnos[posicion].parcial_3,
               alumnos[posicion].parcial_4,
               alumnos[posicion].parcialFinal);
        printf("-------------------------------------------------------------------------------------------------------------------\n");
    } else {
        perror("No se encontró ningún alumno con ese ID");
    }
    
    _preguntaDeControl(alumnos);
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
void _porcentajeAprobadoReprobado(Estudiante *alumnos, int tamaño) {
    system("cls");

    int aprobados = 0;
    float porcentaje;

    if (tamaño <= 0) {
        perror("Error: Tamaño inválido de estudiantes");
        return;
    }

    for (int i = 0; i < tamaño; i++) {
        if (alumnos[i].parcialFinal >= 7) {
            aprobados++;
        }
    }

    porcentaje = (aprobados * 100.0) / tamaño;
    float porcentaje_reprobados = 100.0 - porcentaje;

    printf("El porcentaje de alumnos aprobados es del %.2f%%\n", porcentaje);
    printf("El porcentaje de alumnos reprobados es del %.2f%%\n\n", porcentaje_reprobados);

    _preguntaDeControl(alumnos);
}
