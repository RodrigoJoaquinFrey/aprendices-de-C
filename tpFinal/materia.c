#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "materia.h"

// Funciones de Materias

NodoMateria* crearListaMaterias() {
    return NULL;
}

NodoMateria* agregarMateria(NodoMateria *lista, Materia materia) {
    NodoMateria *nuevoNodo = (NodoMateria *)malloc(sizeof(NodoMateria));
    nuevoNodo->materia = materia;
    nuevoNodo->proximo = lista;
    return nuevoNodo;
}

NodoMateria* modificarMateria(NodoMateria *lista, int id, Materia nuevaMateria) {
    NodoMateria *cursor = lista;
    while (cursor != NULL) {
        if (cursor->materia.id == id) {
            cursor->materia = nuevaMateria;
            return lista;
        }
        cursor = cursor->proximo;
    }
    return lista; // No se encontró la materia
}

NodoMateria* eliminarMateria(NodoMateria *lista, int id) {
    NodoMateria *cursor = lista;
    NodoMateria *anterior = NULL;
    while (cursor != NULL) {
        if (cursor->materia.id == id) {
            if (anterior == NULL) {
                lista = cursor->proximo;
            } else {
                anterior->proximo = cursor->proximo;
            }
            free(cursor);
            return lista;
        }
        anterior = cursor;
        cursor = cursor->proximo;
    }
    return lista; // No se encontró la materia
}

void listarMaterias(NodoMateria *lista) {
    NodoMateria *cursor = lista;
    while (cursor != NULL) {
        printf("ID: %d, Nombre: %s, Estado: %s\n",
               cursor->materia.id, cursor->materia.nombre, cursor->materia.estado);
        cursor = cursor->proximo;
    }
}