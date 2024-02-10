#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	char cadena_1[]="negro",cadena_2[]="blanco";
	printf("La primera cadena es %s \n",cadena_1);
	printf("La segunda cadena es %s \n",cadena_2);
	strcat(cadena_1 , cadena_2);
	printf("La cadena concatenada es %s \n",cadena_1);
	return 0;
}
