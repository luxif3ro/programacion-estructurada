#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opcion;
    float cantidad, resultado;
    printf("SELECIONE LA CONVERSION A REALIZAR(escriba el numero segun el menu y de un enter)\n");
    printf("1.-KILOGRAMOS A LIBRAS\n");
    printf("2.-LIBRAS A KILOGRAMOS\n");
    printf("3.-METROS A PIES\n");
    printf("4.-PIES A METROS\n");
    printf(" > ");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
        resultado = cantidad * 2.20462;
        printf("EL RESULTADO DE LA CONVERSION ES > %.2f", resultado);
        break;
    case 2:
        resultado = cantidad / 2.20462;
        printf("EL RESULTADO DE LA CONVERSION ES > %.2f", resultado);
        break;
    case 3:
        resultado = cantidad * 3.28084;
        printf("EL RESULTADO DE LA CONVERSION ES > %.2f", resultado);
        break;
    case 4:
        resultado = cantidad *0.3048;
        printf("EL RESULTADO DE LA CONVERSION ES > %.2f", resultado);
        break;
    default:
        system("cls");
        printf("NO SE ME PROPORCIONO NINGUNA OPCION VALIDA");
        break;
    }
    return 0;
}