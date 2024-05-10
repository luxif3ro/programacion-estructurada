/**
 * Escribir un programa en C que copie el contenido de un archivo de texto de origen a un archivo de texto de
 * destino.El programa debe solicitar al usuario los nombres de los archivos de origen y destino.
 * Pasos de solución:
 *      El programa debe solicitar al usuario los nombres de los archivos de origen y destino.
 *      Se abren los archivos de origen y destino utilizando fopen en modo lectura ("r") y escritura ("w") respectivamente.
 *      Se verifica si la apertura de los archivos fue exitosa. En caso contrario, se muestra un mensaje de error y se sale del programa.
 *      Se utiliza un ciclo while para leer caracteres del archivo de origen con fgetc() y escribirlos en el archivo de destino con fputc(), hasta que se alcance el final del archivo (EOF).
 *      Después de copiar el contenido, se cierran ambos archivos utilizando fclose().
 *      Mostrar un mensaje indicando que los archivos se copiaron correctamente.
*/

#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100

int main()
{
    FILE *origen,*destino;
    char caracter;
    char archivoOrigen[MAX_LENGTH], archivoDestino[MAX_LENGTH];

    printf("ingrese el nombre del archivo origen > ");
    scanf("%s",archivoOrigen);

    printf("ingrese el nombre del archivo destino > ");
    scanf("%s",archivoDestino);

    origen=fopen(archivoOrigen,"r");
    if (origen==NULL)
    {
        perror("Error con el archivo origen");
        return 1;
    }
    destino=fopen(archivoDestino,"w");
    if (destino==NULL)
    {
        perror("Error con el archivo destino");
        fclose(origen);
        return 1;
    }

    while ((caracter=fgetc(origen)) != EOF)
    {
        fputc(caracter,destino);
    }
    
    fclose(origen);
    fclose(destino);
    printf("Se copio correctamente");
    return 0;
}
