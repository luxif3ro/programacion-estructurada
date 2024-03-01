#include <stdio.h>

void _sumaNumeroPromedio(int *numero_1, int *numero_2, int *numero_3);

int main()
{
    int numero_1, numero_2, numero_3;
    printf("Dame el primer numero >");
    scanf("%d",&numero_1);
    printf("Dame el segundo numero >");
    scanf("%d",&numero_2);
    printf("Dame el tercer numero >");
    scanf("%d",&numero_3);

    _sumaNumeroPromedio(&numero_1,&numero_2,&numero_3);

     return 0;
}

void _sumaNumeroPromedio(int *numero_1, int *numero_2, int *numero_3){
    int suma,promedio;
    suma=*numero_1+*numero_2+*numero_3;
    promedio=suma/3;
    printf("La suma es > %d \n",suma);
    printf("El promedio es > %d \n",promedio);
}