#include <stdio.h>

int main()
{
    int suma=0,digito ,numero;
    printf("Proporcioname el numero con el cual realizar la suma >");
    scanf("%d", &numero);
    while(numero!=0)
    {
        digito=numero%10;
        suma+=digito;
        numero/=10;
    }
    printf("La suma del numero proporcionado es  %d \n", suma);
    return 0;
}

