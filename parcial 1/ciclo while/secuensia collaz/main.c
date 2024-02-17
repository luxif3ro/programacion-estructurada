#include <stdio.h>

int main()
{
    int numero;
    printf("Proporcioname el numero desde el cual empezar la serie collaz > ");
    scanf("%d", &numero);

    while (numero != 1)
    {
        if ((numero % 2) == 0)
        {
            printf("%d es par entonces se divide por 2 para obtener ", numero);
            numero /= 2;
            printf("%d.\n", numero);
        }
        else
        {
            printf("%d es inpar entonces se multiplica por 3 y se suma 1 para obtener ", numero);
            numero = (numero * 3) + 1;
            printf("%d.\n", numero);
        }
    }

    return 0;
}
