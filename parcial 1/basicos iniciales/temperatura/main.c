#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	float fharenheit,celcius;
	printf("Proporcioname la temperatura en celcius a convertir a fharenheits > ");
	scanf("%f",&celcius);
	fharenheit=(celcius*1.8)+32;
	printf("La temperatura en fharenheits seria: %.2f grados",fharenheit);
	return 0;
}
