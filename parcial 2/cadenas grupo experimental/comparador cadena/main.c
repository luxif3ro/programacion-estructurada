#include <stdio.h>
#include <stdlib.h>

int _longitud(char cadena[50]);
int main()
{
    char cadUno[50],cadDos[50];
    int longitudCadenaUno,longitudCadenaDos,i;
    printf("Dame la primer cadena > ");
    scanf("%s",cadUno);
    printf("Dame la segunda cadena cadena > ");
    scanf("%s",cadDos);
    longitudCadenaUno=_longitud(cadUno);
    longitudCadenaDos=_longitud(cadDos);
    if (longitudCadenaUno!=longitudCadenaDos)
    {
        printf("Las cadenas no son iguales");
        return 1;
    }

    for (i = 0; cadUno[i]!='\0'; i++)
    {
        if (cadDos[i]!=cadUno[i])
        {
          printf("Las cadenas no son iguales");
          return 1;
        }
    }
    
    if (i==longitudCadenaUno)
    {
        printf("Las cadenas son iguales");
    }
    

    
    return 0;
}

int _longitud(char cadena[50]){
    int longitud=0;
    for (int i = 0; cadena[i]!='\0'; i++){longitud++;}
    return longitud;
};