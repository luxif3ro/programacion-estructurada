#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	char numero[100]; 
    int longitud = 0;
    printf("Proporcioneme un numero entero para contar sus digitos > ");
    scanf("%[^\n]", numero);
    for (int i = 0; numero[i] != '\0'; i++) {
        longitud++;
    }
    printf("El numero proporcionado tiene %d digitos.\n", longitud);
	return 0;
}
