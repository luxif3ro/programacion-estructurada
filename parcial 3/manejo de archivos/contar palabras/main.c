/**
 * @details
 *      Crea un nuevo archivo de código fuente con las bibliotecas : <stdio.h> y <string.h>.
 *      Crear una función:
 *          int contar_palabras(char *archivo): Esta función recibe el nombre del archivo como argumento y debe devolver el número total de palabras en el archivo.
 *      Implementar la función contar_palabras(char *archivo)para que realice lo siguiente
 *          Abrir el archivo en modo lectura utilizando fopen(archivo, "r").
 *          Verificar si la apertura fue exitosa; en caso contrario, manejar el error y retornar -1.
 *          Crear un buffer (un arreglo de caracteres) para leer líneas del archivo.
 *          Inicializar un contador de palabras en 0.
 *          Leer líneas del archivo utilizando la función fgets(buffer, tamaño_buffer, archivo_apuntador).
 *          Para cada línea leída, utilizar la función strtok(linea, " ") para separar las palabras y actualizar el contador de palabras.
 *          Cerrar el archivo utilizando fclose(archivo_apuntador).
 *          Devolver el contador de palabras.
 *      Crear la función main() que haga lo siguiente
 *          Solicitar al usuario que ingrese el nombre del archivo a procesar.
 *          Llamar a la función contar_palabras(nombre_archivo).
 *          Mostrar el número de palabras contadas en el archivo.
 * @author 
 *      jesus salvador garcia lopez
*/

#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 1000

int contar_palabras(char *archivo);

int main()
{
    char archivo[MAX_LENGTH];
    int palabras;

    printf("Ingrese el nombre del archivo. > ");
    scanf("%s",archivo);
    
    palabras=contar_palabras(archivo);
    if (palabras==-1)
    {
        perror("ERROR AL PROCESAR EL ARCHIVO");
    }
    else
    {
        printf("El archivo tiene %i palabras.",palabras);
    }
    
    
    return 0;
}

int contar_palabras(char *archivo){
    char *token;
    FILE *documento=fopen(archivo,"r");
    if (documento==NULL)
    {
        printf("No se pudo abrir el archivo\n");
        return -1;
    }
    char palabras[MAX_LENGTH];
    int contador=0;
    while (fgets(palabras,MAX_LENGTH,documento)!=NULL)
    {
        token = strtok(palabras," ");
        while (token!=NULL)
        {
            contador++;
            token=strtok(NULL," ");
        }   
    }
    fclose(documento);
    return contador;
    
}
