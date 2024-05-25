#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estudiante.h"
#include "utils.h"

// Funciones de Estudiantes

NodoEstudiante* crearListaEstudiantes() {
    return NULL;
}

NodoEstudiante* agregarEstudiante(NodoEstudiante *lista, Estudiante estudiante) {
    NodoEstudiante *nuevoNodo = (NodoEstudiante *)malloc(sizeof(NodoEstudiante));
    nuevoNodo->estudiante = estudiante;
    nuevoNodo->proximo = lista;
    return nuevoNodo;
}

NodoEstudiante* modificarEstudiante(NodoEstudiante *lista, int id, Estudiante nuevoEstudiante) {
    NodoEstudiante *cursor = lista;
    while (cursor != NULL) {
        if (cursor->estudiante.id == id) {
            cursor->estudiante = nuevoEstudiante;
            return lista;
        }
        cursor = cursor->proximo;
    }
    return lista; // No se encontró el estudiante
}

NodoEstudiante* eliminarEstudiante(NodoEstudiante *lista, int id) {
    NodoEstudiante *cursor = lista;
    NodoEstudiante *anterior = NULL;
    while (cursor != NULL) {
        if (cursor->estudiante.id == id) {
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
    return lista; // No se encontró el estudiante
}

void listarEstudiantes(NodoEstudiante *lista) {
    NodoEstudiante *cursor = lista;
    while (cursor != NULL) {
        printf("ID: %d, Nombre: %s, Fecha de Nacimiento: %s\n",
               cursor->estudiante.id, cursor->estudiante.nombre, cursor->estudiante.fechaNacimiento);
        cursor = cursor->proximo;
    }
}

NodoEstudiante* buscarEstudiantesPorNombre(NodoEstudiante *lista, char *nombre) {
    NodoEstudiante *cursor = lista;
    NodoEstudiante *resultados = NULL;
    while (cursor != NULL) {
        if (strstr(cursor->estudiante.nombre, nombre) != NULL) {
            Estudiante estudiante = cursor->estudiante;
            resultados = agregarEstudiante(resultados, estudiante);
        }
        cursor = cursor->proximo;
    }
    return resultados;
}

NodoEstudiante* buscarEstudiantesPorRangoEdad(NodoEstudiante *lista, int edadMin, int edadMax) {
    NodoEstudiante *cursor = lista;
    NodoEstudiante *resultados = NULL;
    while (cursor != NULL) {
        int edad = calcularEdad(cursor->estudiante.fechaNacimiento);
        if (edad >= edadMin && edad <= edadMax) {
            Estudiante estudiante = cursor->estudiante;
            resultados = agregarEstudiante(resultados, estudiante);
        }
        cursor = cursor->proximo;
    }
    return resultados;
}

NodoEstudiante* anotarseEnMateria(NodoEstudiante *listaEstudiantes, int idEstudiante, Materia materia) {
    NodoEstudiante *cursor = listaEstudiantes;
    while (cursor != NULL) {
        if (cursor->estudiante.id == idEstudiante) {
            NodoMateria *nuevoNodo = (NodoMateria *)malloc(sizeof(NodoMateria));
            nuevoNodo->materia = materia;
            nuevoNodo->proximo = cursor->estudiante.materias;
            cursor->estudiante.materias = nuevoNodo;
            return listaEstudiantes;
        }
        cursor = cursor->proximo;
    }
    return listaEstudiantes; // No se encontró el estudiante
}

NodoEstudiante* rendirMateria(NodoEstudiante *listaEstudiantes, int idEstudiante, int idMateria, int nota) {
    NodoEstudiante *cursor = listaEstudiantes;
    while (cursor != NULL) {
        if (cursor->estudiante.id == idEstudiante) {
            NodoMateria *materiaCursor = cursor->estudiante.materias;
            while (materiaCursor != NULL) {
                if (materiaCursor->materia.id == idMateria) {
                    if (materiaCursor->materia.rendido == 1) {
                        printf("La materia ya se rindió y su nota es: %d\n", materiaCursor->materia.nota);
                    } else {
                        materiaCursor->materia.nota = nota;
                        materiaCursor->materia.rendido = 1;
                        printf("Materia rendida con éxito. Nota: %d\n", nota);
                    }
                    return listaEstudiantes;
                }
                materiaCursor = materiaCursor->proximo;
            }
            printf("El estudiante no está inscripto en esta materia.\n");
            return listaEstudiantes;
        }
        cursor = cursor->proximo;
    }
    printf("No se encontró el estudiante.\n");
    return listaEstudiantes;
}