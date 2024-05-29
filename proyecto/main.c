#include "libreriaAlumnos.h"
#define MAX_SIZE 100

typedef struct usuario
{
    char nombre[MAX_SIZE];
    char contraseña[MAX_SIZE];
} usuario;

Estudiante *alumnos;
int cantidadUsuarios;
char nombreArchivo[MAX_SIZE];
FILE *archivoAlumnos;

void _menu();
usuario *_obtenerUsuarios();

int main()
{
    char user[MAX_SIZE];
    char contra[MAX_SIZE];
    char archivo[MAX_SIZE];
    int aceptado = 0, encontrado = 0, intentos = 0;
    usuario *usuarios = _obtenerUsuarios();
    if (usuarios == NULL)
    {
        perror("No se pudo obtener los usuarios");
        return 1;
    }
    while (aceptado != 1)
    {
        printf("Dame el nombre del usuario > ");
        scanf("%s", user);
        printf("Dame la contrasena del usuario > ");
        scanf("%s", contra);
        for (int i = 0; i < cantidadUsuarios; i++)
        {
            if ((_compararCadena(user, usuarios[i].nombre) == 1) && (_compararCadena(contra, usuarios[i].contraseña) == 1))
            {
                aceptado = 1;
                printf("Dame el nombre de el archivo a usar (recuerda agregar la extensin) > ");
                scanf("%s", nombreArchivo);
                archivoAlumnos = fopen(nombreArchivo, "r");
                if (archivoAlumnos == NULL)
                {
                    perror("No se pudo abrir el archivo");
                    return 1;
                }
                alumnos = _creacionDeEstructura(archivoAlumnos);
                _llenadoDeEstructura(archivoAlumnos, alumnos);
                _menu();
                break;
            }
            else if ((_compararCadena(user, usuarios[i].nombre) != 1))
            {
                printf("Usuario incorrecto");
            }
            else if (_compararCadena(contra, usuarios[i].contraseña) != 1)
            {
                printf("Contraseña incorrecta");
            }
            else
            {
                intentos++;
            }
        }
        if (intentos == 2)
        {
            printf("Se agotaron los intentos");
            aceptado = 1;
        }
    }

    return 0;
}

void _menu()
{
    int op;
    while (op != 9)
    {
        printf("\n\n|RECUERDA ENTRAR PRIMERO A LA OPCION 1|\n\n");
        printf("1.- Calcular calificacion final\n");
        printf("2.- Reporte general de calificaciones\n");
        printf("3.- Promedio general del grupo sin redondear\n");
        printf("4.- Mostrar el alumno con menor calificacion\n");
        printf("5.- Mostrar el alumno con mayor calificacion\n");
        printf("6.- Reporte de calificaciones ordenadas de menor a mayor\n");
        printf("7.- Busqueda por ID de la calificacion final del alumno\n");
        printf("8.- Generar los porcentajes de aprobacion y reprobacion del grupo\n");
        printf("9.- Salir\n");
        printf("\nElige una opcion > ");
        scanf("%i", &op);

        switch (op)
        {
        case 1:
            _calcularCalificacionFinal(alumnos, archivoAlumnos);
            printf("Promedios finales calculados calculado");
            Sleep(3000);
            break;
        case 2:
            printf("%d \n", alumnos[0].parcialFinal);
            if (alumnos[0].parcialFinal == 11)
            {
                printf("Entra primero a la opcion no.1\n");
                Sleep(3000);
            }
            else
            {
                _impresionDeCalificaciones(alumnos);
                Sleep(3000);
            }

            break;
        case 3:
            if (alumnos[0].parcialFinal == 11)
            {
                printf("Entra primero a la opcion no.1\n");
                Sleep(3000);
            }
            else
            {
                _promedioGeneralSinRedondear(alumnos,tamañoEstudiantes);
                Sleep(3000);
            }
            break;
        case 4:
            if (alumnos[0].parcialFinal == 11)
            {
                printf("Entra primero a la opcion no.1\n");
                Sleep(3000);
            }
            else
            {
                _menorCalificacion(alumnos,tamañoEstudiantes);
                Sleep(3000);
            }
            break;
        case 5:
            if (alumnos[0].parcialFinal == 11)
            {
                printf("Entra primero a la opcion no.1\n");
                Sleep(3000);
            }
            else
            {
                _mayorCalificacion(alumnos,tamañoEstudiantes);
                Sleep(3000);
            }
            break;
        case 6:
            if (alumnos[0].parcialFinal == 11)
            {
                printf("Entra primero a la opcion no.1\n");
                Sleep(3000);
            }
            else
            {
                _ordenarMenorMayor(alumnos,tamañoEstudiantes);
                Sleep(3000);
            }
            break;
        case 7:
            if (alumnos[0].parcialFinal == 11)
            {
                printf("Entra primero a la opcion no.1\n");
                Sleep(3000);
            }
            else
            {
                _buscarID(alumnos,tamañoEstudiantes);
                Sleep(3000);
            }
            break;
        case 8:
            if (alumnos[0].parcialFinal == 11)
            {
                printf("Entra primero a la opcion no.1\n");
                Sleep(3000);
            }
            else
            {
                _porcentajeAprobadoReprobado(alumnos,tamañoEstudiantes);
                Sleep(3000);
            }
            break;
        case 9:
            printf("\n \b Vuelva pronto\n");
            break;
        default:
            break;
        }
    }
}

usuario *_obtenerUsuarios()
{
    FILE *archivoUsuarios = fopen("usuario.txt", "r");
    if (archivoUsuarios == NULL)
    {
        return NULL;
    }
    int i = 0;
    usuario *usuarios = (usuario *)malloc(_obtenerTamanoArchivo(archivoUsuarios) / sizeof(usuario) * sizeof(usuario));
    if (usuarios == NULL)
    {
        fclose(archivoUsuarios);
        return NULL;
    }

    while ((fscanf(archivoUsuarios, "%s %s", usuarios[i].nombre, usuarios[i].contraseña)) == 2)
    {
        i++;
    }
    cantidadUsuarios = i;
    fclose(archivoUsuarios);
    return usuarios;
}