#include <stdio.h>

// Definición de la estructura Empleado
struct Empleado {
    int id;
    char nombre[50];
    float salario;
};

// Función para ingresar datos de empleados
void ingresarEmpleados(struct Empleado empleados[], int n) {
    printf("Ingrese los datos de los empleados:\n");
    for (int i = 0; i < n; i++) {
        printf("Empleado %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &empleados[i].id);
        printf("Nombre: ");
        scanf("%s", empleados[i].nombre);
        printf("Salario: ");
        scanf("%f", &empleados[i].salario);
    }
}

// Función para mostrar la información de los empleados
void mostrarEmpleados(struct Empleado empleados[], int n) {
    printf("\nInformación de empleados:\n");
    for (int i = 0; i < n; i++) {
        printf("Empleado %d:\n", i + 1);
        printf("ID: %d\n", empleados[i].id);
        printf("Nombre: %s\n", empleados[i].nombre);
        printf("Salario: %.2f\n", empleados[i].salario);
    }
}

int main() {
    int numEmpleados;

    printf("Ingrese el número de empleados: ");
    scanf("%d", &numEmpleados);

    // Declaración de un arreglo de estructuras Empleado
    struct Empleado empleados[numEmpleados];

    // Llamada a la función para ingresar empleados
    ingresarEmpleados(empleados, numEmpleados);

    // Llamada a la función para mostrar la información de los empleados
    mostrarEmpleados(empleados, numEmpleados);

    return 0;
}
