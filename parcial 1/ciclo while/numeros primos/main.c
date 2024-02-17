#include <stdio.h>

int main()
{
    int numero, j, i, divisores = 0;
    printf("Proporcioname el numero de cual empezar a revisar > ");
    scanf("%d", &numero);
    while (numero > 0)
    {
        j=numero;
        for (i = 1; i <= j; i++)
        {
            if ((numero % i) == 0)
            {
                divisores++;
            }
        }
        if (divisores <= 2)
        {
            printf("%d es primo \n", numero);
        }
        divisores = 0;
        numero = numero - 1;
    }

    return 0;
}
