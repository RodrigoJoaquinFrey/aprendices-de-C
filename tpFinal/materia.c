#include "materia.h"
#include <stdio.h>
#include <string.h>

void inicializarMateria(Materia *materia, int id, const char *nombre, int creditos) {
    materia->id = id;
    strncpy(materia->nombre, nombre, sizeof(materia->nombre) - 1);
    materia->nombre[sizeof(materia->nombre) - 1] = '\0'; // Asegurar la terminación nula
    materia->creditos = creditos;
    materia->nota = -1.0; // Inicializar con una nota inválida indicando que no ha rendido
}

void imprimirMateria(const Materia *materia) {
    printf("ID: %d\n", materia->id);
    printf("Nombre: %s\n", materia->nombre);
    printf("Créditos: %d\n", materia->creditos);
    if (materia->nota >= 0) {
        printf("Nota: %.2f\n", materia->nota);
    } else {
        printf("No ha rendido esta materia.\n");
    }
}
