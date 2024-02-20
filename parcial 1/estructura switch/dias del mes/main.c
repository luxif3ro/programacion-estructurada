#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opcion;
    printf("SELECIONE EL MES A VER(escriba el numero segun el menu y de un enter)\n");
    printf("1.-ENERO\n");
    printf("2.-FEBRERO\n");
    printf("3.-MARZO\n");
    printf("4.-ABRIL\n");
    printf("5.-MAYO\n");
    printf("6.-JUNIO\n");
    printf("7.-JULIO\n");
    printf("8.-AGOSTO\n");
    printf("9.-SEPTIEMBRE\n");
    printf("10.-OCTUBRE\n");
    printf("11.-NOVIEMBRE\n");
    printf("12.-DICIEMBRE\n");
    printf(" > ");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
        printf("ENERO TIENE 31 DIAS");
        break;
    case 2:
        printf("FEBRERO TIENE 28 DIAS");
        break;
    case 3:
        printf("MARZO TIENE 31 DIAS");
        break;
    case 4:
        printf("ABRIL TIENE 30 DIAS");
        break;
    case 5:
        printf("MAYO TIENE 31 DIAS");
        break;
    case 6:
        printf("JUNIO TIENE 30 DIAS");
        break;
    case 7:
        printf("JULIO TIENE 31 DIAS");
        break;
    case 8:
        printf("AGOSTO TIENE 31 DIAS");
        break;
    case 9:
        printf("SEPTIEMBRE TIENE 30 DIAS");
        break;
    case 10:
        printf("OCTUBRE TIENE 31 DIAS");
        break;
    case 11:
        printf("NOBVIEMBRE TIENE 30 DIAS");
        break;
    case 12:
        printf("DICIEMBRE TIENE 31 DIAS");
        break;
    default:
        system("cls");
        printf("NO SE ME PROPORCIONO NINGUNA OPCION VALIDA");
        break;
    }
    return 0;
}