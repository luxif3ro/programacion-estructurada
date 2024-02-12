#include <stdio.h>

int main()
{
    int anterior=1,posicion,suma=0,i,valores=0;

    printf("Proporcioname la posicion hasta la que tengo que llegar de la serie fibonacci >");
    scanf("%d",&posicion);
    for ( i = 1; i <= posicion; i++)
    {
        printf("%d \n",valores);
        suma=valores+anterior;
        valores=anterior;
        anterior=suma;
    }
    
    return 0;
}
