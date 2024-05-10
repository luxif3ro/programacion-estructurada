#include <stdio.h>

int main()
{

    int longitud=1,pocision=0,mayor;
    printf("Cuantos numeros vas a meter en el arreglo > ");
    scanf("%d",&longitud);
    int arreglo[longitud];
    for (int i = 0; i < longitud; i++)
    {
        printf("Dame el numero a guardar en la posicion %d > ",i+1);
        scanf("%d",&arreglo[i]);
    }
    mayor=arreglo[0];
    for (int i = 0; i < longitud; i++)
    {
        if (arreglo[i]>mayor)
        {
            mayor=arreglo[i];
            pocision=1;
        }
        
    }
    printf("el mayor es %i que se encuentra en la pocision %i",arreglo[pocision],pocision+1);
    return 0;
}
