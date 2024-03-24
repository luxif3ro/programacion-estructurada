#include <stdio.h>
#include <stdlib.h>

enum diasSemana
{
    Lunes,
    Martes,
    Miercoles,
    Jueves,
    Viernes,
    Sabado,
    Domingo
};
int _diasRestantes(enum diasSemana diaActual);
int main()
{
    enum diasSemana diaActual = Lunes;

    printf("Quedan %d hasta el domingo", _diasRestantes(diaActual));
    return 0;
}

int _diasRestantes(enum diasSemana diaActual)
{
    int diasRestantes;
    enum diasSemana diaFinal = Domingo;
    diasRestantes = diaFinal - diaActual;
    return diasRestantes;
}