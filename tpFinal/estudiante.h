#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "materia.h"
#include "lista.h"
#include <time.h>

typedef struct {
    int id;
    char nombre[100];
    char fechaNacimiento[11]; // Formato YYYY-MM-DD
    Lista *materias; // Lista de materias inscritas
} Estudiante;

Estudiante *crearEstudiante(int id, const char *nombre, const char *fechaNacimiento);
void modificarEstudiante(Estudiante *estudiante, const char *nuevoNombre, const char *nuevaFechaNacimiento);
void eliminarEstudiante(Lista *lista, int id);
Estudiante *buscarEstudiantePorNombre(Lista *lista, const char *nombre);
Lista *buscarEstudiantesPorRangoEdad(Lista *lista, int edadMin, int edadMax);
void listarEstudiantes(const Lista *lista);
void agregarMateriaEstudiante(Estudiante *estudiante, Materia *materia);
void rendirMateria(Estudiante *estudiante, int idMateria, float nota);
int calcularEdad(const char *fechaNacimiento);

#endif // ESTUDIANTE_H
