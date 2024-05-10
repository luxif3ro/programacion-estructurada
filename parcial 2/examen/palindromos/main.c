#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

int main()
{
    char cadenaOringinal[MAX_SIZE],cadenaRevez[MAX_SIZE];
    printf("Dame la cadena a verificar que sea un palindromo > ");
    scanf("%s",cadenaOringinal);
    strcpy(cadenaRevez,cadenaOringinal);
    strrev(cadenaRevez);
    for (int i = 0; cadenaOringinal[i]!='\0'; i++)
    {
        if (cadenaOringinal[i] != cadenaRevez[i])
        {
            printf("no son palindromos");
            return 0;
        }
    }
    
    printf("Es un palindromo");
    return 0;
}
