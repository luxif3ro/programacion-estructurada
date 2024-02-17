#include <stdio.h>

int main()
{
    int suma=0,cuadrado,digitos,numero;
    printf("Proporcioname el numero con el cual realizar la suma >");
    scanf("%d", &numero);
    while(numero!=0)
    {
        digitos=numero%10;
        cuadrado=digitos*digitos;
        suma+=cuadrado;
        numero/=10;
        cuadrado=0;
    }
    printf("La suma del numero proporcionado es  %d \n", suma);
    return 0;
}

