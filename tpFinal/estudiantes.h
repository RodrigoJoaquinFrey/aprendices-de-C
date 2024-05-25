#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "lista.h"

typedef struct {
    int id;
    char nombre[50];
    char fechaNacimiento[11]; // Formato: "YYYY-MM-DD"
    NodoMateria *materias;
} Estudiante;

NodoEstudiante* crearListaEstudiantes();
NodoEstudiante* agregarEstudiante(NodoEstudiante *lista, Estudiante estudiante);
NodoEstudiante* modificarEstudiante(NodoEstudiante *lista, int id, Estudiante nuevoEstudiante);
NodoEstudiante* eliminarEstudiante(NodoEstudiante *lista, int id);
void listarEstudiantes(NodoEstudiante *lista);
NodoEstudiante* buscarEstudiantesPorNombre(NodoEstudiante *lista, char *nombre);
NodoEstudiante* buscarEstudiantesPorRangoEdad(NodoEstudiante *lista, int edadMin, int edadMax);
NodoEstudiante* anotarseEnMateria(NodoEstudiante *listaEstudiantes, int idEstudiante, Materia materia);
NodoEstudiante* rendirMateria(NodoEstudiante *listaEstudiantes, int idEstudiante, int idMateria, int nota);

#endif // ESTUDIANTE_H