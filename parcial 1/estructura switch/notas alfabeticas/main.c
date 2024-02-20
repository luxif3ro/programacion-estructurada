#include <stdio.h>

int main()
{
    int calificacion;
    printf("Proporcioname la calificacion del alumno(solo numero entero y mayor que 5) >");
    scanf("%d",&calificacion);
    switch (calificacion)
    {
    case 10:
        printf("la calificacion en letra es A");
        break;
    case 9:
        printf("la calificacion en letra es B");
        break;
    case 8:
        printf("la calificacion en letra es C");
        break;
    case 7:
        printf("la calificacion en letra es D");
        break;
    case 6:
        printf("la calificacion en letra es E");
        break;
   
    default:
        printf("LA CALIFICACION QUE PROPORCIONASTE NO ENTRA EN EL RANGO VALIDO (10->5)");
        break;
    }
    return 0;
}
