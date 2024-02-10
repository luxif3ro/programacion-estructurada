#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	float radio,area;
	printf("Proporcioname al radio del circulo a calcular > ");
	scanf("%f",&radio);
	area=3.1416*(radio*radio);
	printf("El area del circulo calculado es %.2f unidades cubicas",area);
	return 0;
}
