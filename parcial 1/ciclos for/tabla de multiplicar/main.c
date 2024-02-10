#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int numero,i;
	printf("Proporcioname un numero entero para mostrarte su tabla de multiplicar > ");
	scanf("%d",&numero);
	for ( i = 1; i <= 10; i++)
	{
		printf("%d x %d = %d \n",numero,i,(numero*i));
	}
	
	return 0;
}
