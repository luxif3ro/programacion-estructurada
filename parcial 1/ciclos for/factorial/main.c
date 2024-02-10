#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int numero,factorial=1,i;
	printf("Proporcioname el numero entero al cual realizar su factorial > ");
	scanf("%d",&numero);
	for ( i = numero; i >=1; i--)
	{
		factorial*=i;
	}
	printf("el factorial es: %d",factorial);
	return 0;
}
