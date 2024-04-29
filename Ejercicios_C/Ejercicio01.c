#include <stdio.h>

//EntradaSalida
int main() {
    char nombre[10];
    int edad;
    printf("Ingrese su nombre: \n");
    scanf("%s", nombre);
    printf("Ingrese su edad: \n");
    scanf("%d", &edad);

    printf("Su nombre es : %s \n", nombre);
    printf("Su edad es : %d \n", edad);

    return 0;
}