#include <stdio.h>
#include <stdlib.h>

int _longitudCadena(char cadena[50]);
int main()
{
    char cadUno[50], cadDos[50];
    int i, j = 0, longitudCadena;
    printf("Dame la cadena a invertir >");
    scanf("%s", cadUno);
    longitudCadena = _longitudCadena(cadUno);
    printf("%d \n", longitudCadena);
    i=longitudCadena-1;
    while (j<=longitudCadena)
    {
        cadDos[j]=cadUno[i];
        j++;
        i--;
    }
    
    printf("La cadena original es : %s \n", cadUno);
    i=0;
    while (cadDos[i]!='\0')
    {
        cadUno[i]=cadDos[i];
        i++;
    }
    cadUno[i]='\0';
    printf("La cadena invertida es : %s \n", cadUno);
    return 0;
}
int _longitudCadena(char cadena[50])
{
    int i = 0;
    while (cadena[i] != '\0')
    {
        i++;
    }
    return i;
}