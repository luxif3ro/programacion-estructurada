#include <stdio.h>

int numero;

void _duplicarNumero(int *numeroDuplicado);

int main()
{
    printf("Dame el numero que quieras que duplique >");
    scanf("%d",&numero);
    _duplicarNumero(&numero);
    return 0;
}

void _duplicarNumero(int *numeroDuplicado){
    printf("este es el numero que me diste > %d \n",numero);
    printf("este es el numero duplicaado > %d \n",*numeroDuplicado);
}
