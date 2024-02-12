#include <stdio.h>

int main()
{
    int suma=0,digito ,numero;
    printf("Proporcioname el numero con el cual realizar la suma >");
    scanf("%d", &numero);
    for ( ; numero!=0; numero/=10)
    {
        digito=numero%10;
        suma+=digito;
    }
    printf("La suma del numero proporcionado es  %d \n", suma);
    return 0;
}

