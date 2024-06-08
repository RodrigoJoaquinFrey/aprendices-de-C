#include "materia.h"

void inicializarMateria(Materia *materia, int id, const char *nombre) {
    materia->id = id;
    strncpy(materia->nombre, nombre, sizeof(materia->nombre) - 1);
    materia->nombre[sizeof(materia->nombre) - 1] = '\0';
    materia->nota = -1.0; // Inicializar con una nota inválida indicando que no ha rendido
}

void rendirMateria(int id_estudiante, int id_materia) {
    // Verificar si el estudiante está registrado
    int encontrado = 0;
    for (int i = 0; i < num_estudiantes; i++) {
        if (estudiantes[i].id == id_estudiante) {
            encontrado = 1;
            // Verificar si el estudiante está anotado en la materia
            int encontrada_materia = 0;
            for (int j = 0; j < estudiantes[i].num_materias; j++) {
                if (estudiantes[i].materias[j] == id_materia) {
                    encontrada_materia = 1;
                    // Rendir la materia (en ests sección se puede pedir la nota y asignarla)
                    printf("El estudiante con ID %d ha rendido la materia con ID %d.\n", id_estudiante, id_materia);
                    break;
                }
            }
            if (!encontrada_materia) {
                printf("La materia no está asignada al estudiante o no existe.\n");
            }
            break;
        }
    }
    if (!encontrado) {
        printf("El estudiante no tiene materias para rendir o no está registrado.\n");
    }
}

void imprimirMateria(const Materia *materia) {
    printf("ID: %d\n", materia->id);
    printf("Nombre: %s\n", materia->nombre);
    if (materia->nota >= 0) {
        printf("Nota: %.2f\n", materia->nota);
    } else {
        printf("No ha rendido esta materia.\n");
    }
}
