#include <stdio.h>
#include <math.h>

void _calcularCuadradoCubo(int numero);

int main()
{
    int numero;
    printf("Dame el numero a usar > ");
    scanf("%d", &numero);
    _calcularCuadradoCubo(numero);
    return 0;
}

void _calcularCuadradoCubo(int numero)
{
    double cuadrado, cubo;
    cuadrado =numero*numero;
    cubo = numero *cuadrado;
    printf("%d al cuadrado es > %.0f \n", numero, cuadrado);
    printf("%d al cubo es > %.0f", numero, cubo);
}