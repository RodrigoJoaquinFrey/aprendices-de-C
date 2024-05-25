#ifndef MATERIA_H
#define MATERIA_H

#include "lista.h"

typedef struct {
    int id;
    char nombre[100];
    char estado[20]; // "inscripto" o "rendido"
} Materia;

NodoMateria* crearListaMaterias();
NodoMateria* agregarMateria(NodoMateria *lista, Materia materia);
NodoMateria* modificarMateria(NodoMateria *lista, int id, Materia nuevaMateria);
NodoMateria* eliminarMateria(NodoMateria *lista, int id);
void listarMaterias(NodoMateria *lista);

#endif // MATERIA_H