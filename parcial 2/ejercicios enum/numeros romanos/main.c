#include <stdio.h>
#include <stdlib.h>

enum numeroRomanos
{
    I,
    II,
    III,
    IV,
    V,
    VI,
    VII,
    VIII,
    IX,
    X
};
int _convertirANumero(enum numeroRomanos romano);
int main()
{
    enum numeroRomanos romano=X;
    printf("El numero en arabico es %d",_convertirANumero(romano));
    return 0;
}

int _convertirANumero(enum numeroRomanos romano){
    return (romano+1);
}