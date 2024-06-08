#ifndef MATERIA_H
#define MATERIA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nombre[50];
    float nota; // Inicialmente -1 para indicar que no fue rendida
} Materia;

void inicializarMateria(Materia *materia, int id, const char *nombre);
void imprimirMateria(const Materia *materia);

#endif // MATERIA_H
