#include <stdio.h>
#include <stdlib.h>

struct Estudiante
{
    char nombre[100];
    int edad;
    float promedioCalificaciones;
};

int main()
{
    int cantidadLimite=0,i;
    printf("Dame la cantidad de estudiantes a guardar > ");
    scanf("%d",&cantidadLimite);
    if (cantidadLimite<=0)
    {
        perror("Debe ser un numero positivo");
        return 1;
    }
    struct Estudiante estudiantes[cantidadLimite];
    for (i = 0; i < cantidadLimite; i++)
    {
        printf("Dame el nombre del alumno numero %d > ",(i+1));
        scanf("%s",&estudiantes[i].nombre);
        printf("Dame la edad del alumno numero %d > ",(i+1));
        scanf("%d",&estudiantes[i].edad);
        printf("Dame el nombre del alumno numero %d > ",(i+1));
        scanf("%f",&estudiantes[i].promedioCalificaciones);
    }
    for ( i = 0; i < cantidadLimite; i++)
    {
        printf("%s %d %.2f \n",estudiantes[i].nombre,estudiantes[i].edad,estudiantes[i].promedioCalificaciones);
    }
    
    return 0;
}
