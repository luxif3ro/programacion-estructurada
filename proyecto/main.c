/*
 * Jesus Salvador Garcia Lopez
 * 466239
 * Licenciatura en Informatica y Tecnologias Computacionales
 * Programacion Estructurada
 * Dr. Carlos Arevalo
 */

//----LIBRERIAS----//
// las primeras 2 son basicas en c
#include <stdio.h>
#include <stdlib.h>  // se usa para el limpiar pantalla
#include <string.h>  //se usa para las cadenas
#include <windows.h> // se usa para el Sleep
//------------------//

struct Estudiante
{
    char id[7];
    char nombre[50];
    char apellido[50];
    float parcial_1;
    float parcial_2;
    float parcial_3;
    float parcial_4;
    float parcialFinal;
};
void llenadoDeEStructura(struct Estudiante alumnos[13], FILE *archivo);
void preguntaDeControl(struct Estudiante Alumno[13]);
void menu(struct Estudiante Alumno[13]);
void impresionDeCalificaciones(struct Estudiante Alumno[13]);
void promedioGeneralSinRedondear(struct Estudiante Alumno[13]);
void menorCalificacion(struct Estudiante Alumno[13]);
void mayorCalificacion(struct Estudiante Alumno[13]);
void ordenarMenorMayor(struct Estudiante Alumno[13]);
void intercambio(struct Estudiante AlumnoOrdenado[13], int i, int j);
void buscarID(struct Estudiante Alumno[13]);
void porcentajeAprobadoReprobado(struct Estudiante Alumno[13]);

int main()
{
    struct Estudiante alumno[13];
    FILE *archivo = fopen("diccionario.txt", "rb");
    if (archivo == NULL)
    {
        perror("Error en abrir el archivo");
        return 1;
    }
    int ID, password, IDvalido, paswordValido, intentos = 0, valido = 1; // se declaran las variaables
    IDvalido = 1234;                                                     // se asigna que el usario es 1234
    paswordValido = 1234;                                                // se asigna que la contraseña es 1234
    printf("|BIENVENIDO PROFESOR|\n");                                   // se le da la vienvenida al usuario
    printf("Para acceder a los datos registra lo siguiente\n");          // se le comunica que va a tener que iniciar secion
    do                                                                   // sirve para validar los intentos
    {
        printf("ID >");                                  // le pedimos su ID
        scanf("%d", &ID);                                // leemos su ID
        printf("Contrasena >");                          // le pedimos su contraseña
        scanf("%d", &password);                          // leemos su contraseña
        if (ID == IDvalido && password == paswordValido) // verificamos que esten correctos sus valores
        {
            valido = 0;                // le decimos al sistema que deje de repetir
            system("cls");             // limpiamos pantalla
            printf("ACCESO CORRECTO"); // le comunicamos que su acceso fue correcto
            llenadoDeEStructura(alumno, archivo);
            menu(alumno);
        }
        else // si no estan correctos los valores
        {
            if (ID != IDvalido) // verificamos que el ID sea el erroneo
            {
                printf("ID ERRONEO\n"); // le comunicamos que su ID es erroneo
            }
            if (password != paswordValido) // verificamos que la contraseña es erronea
            {
                printf("CONTRASEÑA ERROENEA\n"); // le comunicamos que contraseña es erronea
            }
            intentos++;                                               // le aumentamos 1 al contador de intentos
            printf("quedan %d intentos restantes\n", (3 - intentos)); // le comunicamos al usuario cuantos intentos le quedan
            printf("Vuelva a intentarlo\n");                          // le avisamos al usuario que vuelva a colocar los datos
            if (intentos == 3)                                        // verificamos que aun le queden intentos al usuario
            {
                valido = 0;                               // le decimos al sistema que deje de repetir
                system("cls");                            // limpiamos pantallla
                printf("INTENTOS AGOTADOS VUELVA LUEGO"); // le decimos que agoto sus intentos, que vuelva despues
            }
        }
    } while (valido == 1);
    return 0;
}
void llenadoDeEStructura(struct Estudiante alumnos[13], FILE *archivo)
{
    int i = 0;
    while (feof(archivo) == 0)
    {
        fscanf(archivo, "%s%s%s%f%f%f%f%f", alumnos[i].id, alumnos[i].nombre, alumnos[i].apellido, &alumnos[i].parcial_1, &alumnos[i].parcial_2, &alumnos[i].parcial_3, &alumnos[i].parcial_4, &alumnos[i].parcialFinal);
        i++;
    }
}
void preguntaDeControl(struct Estudiante Alumno[13]) // definimos los procesos de la funcion preguguntaDeControl()
{
    int respuesta, valido = 0; // declaramos las variables a usar y las inicializamos
    do                         // se asegura que la respuesta sea valida
    {
        printf("Desea seguir revisando reportes?(1=si,0=no) >"); // le pregunta al usuario si desea seguir viendo el sistema
        scanf("%d", &respuesta);                                 // lee la respuesta del usuario
        if (respuesta == 1)                                      // valida que haya dicho que si
        {
            // llama a carga
            menu(Alumno); // llama al menu del sistema
            valido = 1;   // le dice al sistema que la respuesta fue valida
        }
        else if (respuesta == 0) // valida que la respuesta sea no
        {
            system("cls");           // limpia pantalla
            printf("VUELVA PRONTO"); // se despide del usuario
            valido = 1;              // le dice al sistema que la respuesta fue valida
        }
        else
        {
            printf("Favor de darme una respuesta valida \n"); // le comunica al usuario que su respuesta no es valida
        }

    } while (valido == 0);
}
void menu(struct Estudiante Alumno[13])
{
    int op, valido = 1; // definimos e inicializamos las variables a usar
    do
    {
        system("cls");        // limpia la pantalla
        printf("|MENU|\n\n"); // se declara el titulo de la informacion que esta viendo el usuario
        // a continuacion se muestra las opciones que tiene el usuario para seleccionar
        printf("1)Un reporte general con la calificación final de todos los alumnos, mostrando los parciales y la calificacion final.\n");
        printf("   Cada parcial vale el 25 porciento de la calificacion final. La calificacion final debe redondearse.\n");
        printf("2) El promedio general del grupo, sin redondear.\n");
        printf("3) Mostrar el alumno con la menor calificacion.\n");
        printf("4) Mostrar el alumno con la mayor calificacion.\n");
        printf("5) Reporte de calificaciones del grupo ordenados de mayor a menor.\n");
        printf("6) Búsqueda por ID de la calificacion final de un alumno.\n");
        printf("7) Generar los porcentajes de aprobacion y reprobacion del grupo.\n\n");
        printf("Dame la opcion a escoger >"); // se le pide una opcion a escoger al usuario
        scanf("%d", &op);                     // lee la opcion
        switch (op)                           // realizamos procesos segun la opcion del usuario
        {
        case 1:                                // este proceso correspnde a la opcion 1 del menu
            valido = 0;                        // le decimos al usuario que la opcion es valida
                                               // llamamos a la funcion carga()
            impresionDeCalificaciones(Alumno); // llamamos a la funcion que realiza la opcion 1 del menu
            break;
        case 2:
            valido = 0;                          // le decimos al usuario que la opcion es valida
                                                 // llamamos a la funcion carga()
            promedioGeneralSinRedondear(Alumno); // llamamos a la funcion que realiza la opcion 2 del menu
            break;
        case 3:
            valido = 0;                // le decimos al usuario que la opcion es valida
                                       // llamamos a la funcion carga()
            menorCalificacion(Alumno); // llamamos a la funcion que realiza la opcion 3 del menu
            break;
        case 4:
            valido = 0;                // le decimos al usuario que la opcion es valida
                                       // llamamos a la funcion carga()
            mayorCalificacion(Alumno); // llamamos a la funcion que realiza la opcion 4 del menu
            break;
        case 5:
            valido = 0;                // le decimos al usuario que la opcion es valida
                                       // llamamos a la funcion carga()
            ordenarMenorMayor(Alumno); // llamamos a la funcion que realiza la opcion 5 del menu
            break;
        case 6:
            valido = 0; // le decimos al usuario que la opcion es valida
                        // llamamos a la funcion carga()
            buscarID(Alumno); // llamamos a la funcion que realiza la opcion 6 del menu
            break;
        case 7:
            valido = 0;                          // le decimos al usuario que la opcion es valida
                                                 // llamamos a la funcion carga()
            porcentajeAprobadoReprobado(Alumno); // llamamos a la funcion que realiza la opcion 7 del menu
            break;

        default:
            printf("No diste una opcion valida vuelve a intentarlo");
            Sleep(2000);
            break;
        }
    } while (valido == 1);
}
void impresionDeCalificaciones(struct Estudiante Alumno[13]) // declaramos los procesos de la funcion impresionDeCalificaciones()
{
    system("cls");                                     // limpiamos pantalla
    int i;                                          // declaramoslas variables a usar
    printf("|REPORTE GENERAL DE CALIFICACIONES|\n\n"); // se muestra el titulo de el reporte
    for (i = 0; i <= 12; i++)
    {
        printf("%s %s %s %.2f %.2f %.2f %.2f %.0f \n", Alumno[i].id, Alumno[i].nombre, Alumno[i].apellido, Alumno[i].parcial_1, Alumno[i].parcial_2, Alumno[i].parcial_3, Alumno[i].parcial_4, Alumno[i].parcialFinal); // imprimimos los alumnos segun el ciclo for
    }
    preguntaDeControl(Alumno); // llamamos a la funcion pregunta de control
}
void promedioGeneralSinRedondear(struct Estudiante Alumno[13]) // declaramoslos procesos de la funcion promedioGeneralSinRedondear()
{
    system("cls");                     // limpiamos la pantalla
    int i;                          // declaramos las variables que van a controlar a los ciclos for
    float sumaGeneral; // declaramos las variables para el proceso

    for (i = 0; i <= 12; i++)
    {
        sumaGeneral += Alumno[i].parcialFinal; // sumamos cada calificacion a la variable sumaGeneral
    }
    printf("|PROMEDIO GENERAL DEL GRUPO|\n\n");                             // mostramos el titulo de el reporte
    printf("El promedio general del grupo es %.2f \n", (sumaGeneral / 13)); // le mostramos el promedio general de el grupo
    preguntaDeControl(Alumno);                                              // llamamos a la funcion preguntaDeControl
}
void menorCalificacion(struct Estudiante Alumno[13]) // declaramos los procesos de la funcion menorCalificacion()
{
    system("cls");            // limpiamos la pantalla
    int i, posicion;          // declaramos las variables a usar
    float minima = 10;        // declaramos la variable minima y la inicializamos en el maximo valor que hay de las calificaciones
    for (i = 0; i <= 12; i++) // recorremos todo el arreglo
    {
        if (Alumno[i].parcialFinal < minima) // validamos la calificacion final
        {
            minima = Alumno[i].parcialFinal; // guardamos la nueva menor calificacion
            posicion = i;                    // guardamos la posicion en donde la encontramos
        }
    }
    printf("|ALUMNO CON MENOR CALIFICACION|\n\n");                                                                                                                                                                                                                // imprimimos el titulo de el reporte
    printf("El alumno con la menor calificacion es;\n");                                                                                                                                                                                                          // le comunicamos al usuario que si hay alumno con menor calificacion
    printf("%s %s %s %.2f %.2f %.2f %.2f %.2f \n", Alumno[posicion].id, Alumno[posicion].nombre, Alumno[posicion].apellido, Alumno[posicion].parcial_1, Alumno[posicion].parcial_2, Alumno[posicion].parcial_3, Alumno[posicion].parcial_4, Alumno[posicion].parcialFinal); // imprimimos los alumnos segun el ciclo for
    preguntaDeControl(Alumno);                                                                                                                                                                                                                                    // llamamos a la funcion pregunta de control
}
void mayorCalificacion(struct Estudiante Alumno[13]) // declaramos los procesos de la funcion mayorCalificacion
{
    system("cls");            // limpiamos la pantalla
    int i, posicion;          // declaramoslass variables que apoyaran el recorrido de el arreglo
    float mayor = 0;          // definimos la variable mayor y la inicializamos con la menor calificacion
    for (i = 0; i <= 12; i++) // recorremos todo el arreglo
    {
        if (Alumno[i].parcialFinal > mayor) // validamos la calificacion final
        {
            mayor = Alumno[i].parcialFinal; // guardamos la nueva menor calificacion
            posicion = i;                   // guardamos la posicion en donde la encontramos
        }
    }
    printf("|ALUMNO CON MENOR CALIFICACION|\n\n");                                                                                                                                                                                                                // imprimimos el titulo de el reporte
    printf("El alumno con la menor calificacion es;\n");                                                                                                                                                                                                          // le comunicamos al usuario que si hay alumno con menor calificacion
    printf("%s %s %s %.2f %.2f %.2f %.2f %.2f \n", Alumno[posicion].id, Alumno[posicion].nombre, Alumno[posicion].apellido, Alumno[posicion].parcial_1, Alumno[posicion].parcial_2, Alumno[posicion].parcial_3, Alumno[posicion].parcial_4, Alumno[posicion].parcialFinal); // imprimimos los alumnos segun el ciclo for
    preguntaDeControl(Alumno);                                                                                                                                                                                                                                    // llamamos a la funcion pregunta de control
}
void ordenarMenorMayor(struct Estudiante Alumno[13]) // declaramos los procesos de la funcion ordenarMenorMayor()
{
    system("cls");                        // limpiamos la pantalla
    struct Estudiante AlumnoOrdenado[13]; // definimos una copia de nuestro arreglo
    int minimo, i, j;                     // definimos las variables que nos ayudaran al recorrido

    for (i = 0; i <= 12; i++)
    {
        AlumnoOrdenado[i] = Alumno[i]; // llenamos la copia del arreglo con los datos de nuestro arreglo
    }
    // de la linea 476 a 487 realiza un ordenamiento por seleccion
    for (i = 0; i <= 11; i++)
    {
        minimo = i;
        for (j = i + 1; j <= 12; j++)
        {
            if (AlumnoOrdenado[j].parcialFinal < AlumnoOrdenado[minimo].parcialFinal)
            {
                minimo = j;
            }
            intercambio(AlumnoOrdenado, i, minimo); // llamamos a la funcion intercambi()
        }
    }
    // de la linea 489 a 498 imprimimos la copia del arreglo
    printf("|REPORTE DE CALIFICACIONES DEL GRUPO ORDENADOS DE MAYOR A MENOR|\n\n"); // mostramos el titulo del reporte
    for (i = 0; i <= 12; i++)
    {
        printf("%s %s %s %.2f %.2f %.2f %.2f %.2f \n", Alumno[i].id, Alumno[i].nombre, Alumno[i].apellido, Alumno[i].parcial_1, Alumno[i].parcial_2, Alumno[i].parcial_3, Alumno[i].parcial_4, Alumno[i].parcialFinal); // imprimimos los alumnos segun el ciclo for
    }
    preguntaDeControl(Alumno); // llamamos a la funcion preguntaDeControl()
}
void intercambio(struct Estudiante AlumnoOrdenado[13], int i, int j)
{
    // esta funcion hace el camnbio de valores del metodo de seleccion
    struct Estudiante temporal;

    temporal = AlumnoOrdenado[i];
    AlumnoOrdenado[i] = AlumnoOrdenado[j];
    AlumnoOrdenado[j] = temporal;
}
void buscarID(struct Estudiante Alumno[13]) // declaramos los procesos de la funcion buscarID()
{
    system("cls");                   // limpiamos pantalla
    int i, posicion, aceptable = 1;  // declaramoslas variables que apoyan a los ciclos
    char IDbuscar[7];                // declaramos la variable con la que compararemos el ID del arreglo
    printf("|BUSQUEDA POR ID|\n\n"); // mostramos el titulo del reporte
    printf("Dame el id a buscar >"); // le pedimos al usuario el ID a buscar
    do                               // sirve para asegurar un respuesta valida
    {
        scanf("%s", IDbuscar);    // leemos el ID a buscar
        for (i = 0; i <= 12; i++) // recorremos el arreglo
        {
            if (strcmp(Alumno[i].id, IDbuscar) == 0) // verificamos que se encuentre el id
            {
                printf("Alumno encontrado, es:\n"); // le comunicamos al usuario que se encontro al alumno
                posicion = i;                       // guardamos la posicion donde encontramos el ID
                aceptable = 1;                      // le decimos al sitema que la respuesta es valida
            }
        }
    } while (aceptable);

    // de la linea 531 a 538 imprimimos el alumno encontrado
    printf("%s %s %s %.2f %.2f %.2f %.2f %.2f \n", Alumno[posicion].id, Alumno[posicion].nombre, Alumno[posicion].apellido, Alumno[posicion].parcial_1, Alumno[posicion].parcial_2, Alumno[posicion].parcial_3, Alumno[posicion].parcial_4, Alumno[posicion].parcialFinal); // imprimimos los alumnos segun el ciclo for
    preguntaDeControl(Alumno);                                                                                                                                                                                                                                    // llamamos a la funcion preguntaDeControl()
}
void porcentajeAprobadoReprobado(struct Estudiante Alumno[13]) // declaramos los procesos de la funcion porcentajeAprobadosReprobados()
{
    system("cls"); // limpiamos la pantalla
    // definimos las variables a urilizar
    int i, aprobados = 0;
    float porcentaje;

    for (i = 0; i <= 12; i++) // recorremos el arreglo
    {
        if (Alumno[i].parcialFinal >= 7) // verificamos que el alumno haya pasado la materia segun las normas de la UAA
        {
            aprobados++; // le sumamos 1 al contador de alumnos aprobados
        }
    }
    porcentaje = (aprobados * 100) / 13; // sacamos el porcentaje de alumnos aprobados
    // de la linea 561 a 562 imprimimos los porcentajes de aprobado y reprobado
    printf("El porcentaje de alumnos aprobados es de el %.2f porciento\n", porcentaje);
    printf("El porcentaje de alumnos reprobados es de el %.2f porciento\n\n", (100 - porcentaje));
    preguntaDeControl(Alumno); // llamamos a la funcion preguntaDeControl()
}
