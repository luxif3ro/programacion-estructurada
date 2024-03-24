#include <stdio.h>
#include <stdlib.h>

struct Libro
{
    char titulo[100];
    char autor[100];
    int añoPublicacion;
};

int main()
{
    int cantidadLimite = 0, i;
    printf("Dame la cantidad de libros a guardar > ");
    scanf("%d", &cantidadLimite);
    if (cantidadLimite <= 0)
    {
        perror("Debe ser un numero positivo");
        return 1;
    }
    struct Libro libros[cantidadLimite];
    for (i = 0; i < cantidadLimite; i++)
    {
        printf("Dame el titulo del libro numero %d > ", (i + 1));
        scanf("%s", &libros[i].titulo);
        printf("Dame el autor del libro numero %d > ", (i + 1));
        scanf("%s", &libros[i].autor);
        printf("Dame el año de publicacion del libro numero %d > ", (i + 1));
        scanf("%d", &libros[i].añoPublicacion);
    }
    for (i = 0; i < cantidadLimite; i++)
    {
        printf("%s %s %d \n", libros[i].titulo, libros[i].autor, libros[i].añoPublicacion);
    }

    return 0;
}
