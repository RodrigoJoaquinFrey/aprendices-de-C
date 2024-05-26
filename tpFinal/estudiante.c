#include "estudiante.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Estudiante *crearEstudiante(int id, const char *nombre, const char *fechaNacimiento) {
    Estudiante *nuevoEstudiante = (Estudiante *)malloc(sizeof(Estudiante));
    nuevoEstudiante->id = id;
    strncpy(nuevoEstudiante->nombre, nombre, sizeof(nuevoEstudiante->nombre) - 1);
    nuevoEstudiante->nombre[sizeof(nuevoEstudiante->nombre) - 1] = '\0';
    strncpy(nuevoEstudiante->fechaNacimiento, fechaNacimiento, sizeof(nuevoEstudiante->fechaNacimiento) - 1);
    nuevoEstudiante->fechaNacimiento[sizeof(nuevoEstudiante->fechaNacimiento) - 1] = '\0';
    nuevoEstudiante->materias = crearLista();
    return nuevoEstudiante;
}

void modificarEstudiante(Estudiante *estudiante, const char *nuevoNombre, const char *nuevaFechaNacimiento) {
    strncpy(estudiante->nombre, nuevoNombre, sizeof(estudiante->nombre) - 1);
    estudiante->nombre[sizeof(estudiante->nombre) - 1] = '\0';
    strncpy(estudiante->fechaNacimiento, nuevaFechaNacimiento, sizeof(estudiante->fechaNacimiento) - 1);
    estudiante->fechaNacimiento[sizeof(estudiante->fechaNacimiento) - 1] = '\0';
}

void eliminarEstudiante(Lista *lista, int id) {
    Nodo *anterior = NULL;
    Nodo *actual = lista->cabeza;

    while (actual != NULL && ((Estudiante *)actual->data)->id != id) {
        anterior = actual;
        actual = actual->proximo;
    }

    if (actual == NULL) return;

    if (anterior == NULL) {
        lista->cabeza = actual->proximo;
    } else {
        anterior->proximo = actual->proximo;
    }

    free(actual->data);
    free(actual);
    lista->largo--;
}

Estudiante *buscarEstudiantePorNombre(Lista *lista, const char *nombre) {
    Nodo *actual = lista->cabeza;

    while (actual != NULL) {
        Estudiante *estudiante = (Estudiante *)actual->data;
        if (strcmp(estudiante->nombre, nombre) == 0) {
            return estudiante;
        }
        actual = actual->proximo;
    }
    return NULL;
}

Lista *buscarEstudiantesPorRangoEdad(Lista *lista, int edadMin, int edadMax) {
    Lista *resultado = crearLista();
    Nodo *actual = lista->cabeza;

    while (actual != NULL) {
        Estudiante *estudiante = (Estudiante *)actual->data;
        int edad = calcularEdad(estudiante->fechaNacimiento);
        if (edad >= edadMin && edad <= edadMax) {
            agregar(resultado, estudiante);
        }
        actual = actual->proximo;
    }

    return resultado;
}

void listarEstudiantes(const Lista *lista) {
    Nodo *actual = lista->cabeza;

    while (actual != NULL) {
        Estudiante *estudiante = (Estudiante *)actual->data;
        printf("ID: %d, Nombre: %s, Fecha de Nacimiento: %s\n", estudiante->id, estudiante->nombre, estudiante->fechaNacimiento);
        actual = actual->proximo;
    }
}

void agregarMateriaEstudiante(Estudiante *estudiante, Materia *materia) {
    agregar(estudiante->materias, materia);
}

void rendirMateria(Estudiante *estudiante, int idMateria, float nota) {
    Nodo *actual = estudiante->materias->cabeza;

    while (actual != NULL) {
        Materia *materia = (Materia *)actual->data;
        if (materia->id == idMateria) {
            if (materia->nota >= 0) {
                printf("Ya ha rendido esta materia. Nota: %.2f\n", materia->nota);
                return;
            }
            materia->nota = nota;
            printf("Materia rendida. Nota: %.2f\n", nota);
            return;
        }
        actual = actual->proximo;
    }
    printf("No está inscrito en esta materia.\n");
}

int calcularEdad(const char *fechaNacimiento) {
    int anio, mes, dia;
    sscanf(fechaNacimiento, "%d-%d-%d", &anio, &mes, &dia);

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    int anioActual = tm->tm_year + 1900;
    int mesActual = tm->tm_mon + 1;
    int diaActual = tm->tm_mday;

    int edad = anioActual - anio;

    if (mesActual < mes || (mesActual == mes && diaActual < dia)) {
        edad--;
    }

    return edad;
}
