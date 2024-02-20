#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opcion, numero_1, numero_2;
    float resultado;
    printf("SELECIONE LA OPERACION A REALIZAR(escriba el numero segun el menu y de un enter)\n");
    printf("1.-Suma\n");
    printf("2.-Resta\n");
    printf("3.-Division\n");
    printf("4.-Multiplicacion\n");
    printf(" > ");
    scanf("%d", &opcion);
    printf("Proporcioname el primer numero para la operacion > ");
    scanf("%d", &numero_1);
    printf("Proporcioname el segundo numero para la operacion > ");
    scanf("%d", &numero_2);

    switch (opcion)
    {
    case 1:
        resultado = numero_1 + numero_2;
        printf("EL RESULTADO DE LA OPERACION ES > %.2f", resultado);
        break;
    case 2:
        resultado = numero_1 - numero_2;
        printf("EL RESULTADO DE LA OPERACION ES > %.2f", resultado);
        break;
    case 3:
        resultado = numero_1 / numero_2;
        printf("EL RESULTADO DE LA OPERACION ES > %.2f", resultado);
        break;
    case 4:
        resultado = numero_1 * numero_2;
        printf("EL RESULTADO DE LA OPERACION ES > %.2f", resultado);
        break;
    default:
        system("cls");
        printf("NO SE ME PROPORCIONO NINGUNA OPCION VALIDA");
        break;
    }
    return 0;
}
