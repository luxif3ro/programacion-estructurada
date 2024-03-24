#include <stdio.h>
#include <stdlib.h>

enum colorSemaforo{
    Rojo,
    Verde,
    Amarillo
};

int main()
{
    enum colorSemaforo colorActual=Rojo;
    switch (colorActual)
    {
    case Rojo:
        printf("El color actua es el Rojo\n");
        printf("el que sigue es el color Verde");
        break;
    case Verde:
        printf("El color actua es el Rojo\n");
        printf("el que sigue es el color Verde");
        break;
    case Amarillo:
        printf("El color actua es el Rojo\n");
        printf("el que sigue es el color Verde");
        break;
    default:
        printf("El color que me diste no es valido");
        break;
    }
    return 0;
}
