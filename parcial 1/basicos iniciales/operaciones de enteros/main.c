#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int suma,resta,multiplicacion,numero_1,numero_2;
	float division;
	printf("Proporcioname el primer numero entero con el realizar las operaciones > ");
	scanf("%d",&numero_1);
	printf("Proporcioname el segundo numero entero con el realizar las operaciones > ");
	scanf("%d",&numero_2);
	suma=numero_1+numero_2;
	resta=numero_1-numero_2;
	division=numero_1/numero_2;
	multiplicacion=numero_1*numero_2;
	printf("El resultado de la suma es: %d \n",suma);
	printf("El resultado de la resta es: %d \n",resta);
	printf("El resultado de la division es: %.2f \n",division);
	printf("El resultado de la multiplicacion es: %d \n",multiplicacion);
	return 0;
}
