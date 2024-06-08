#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "materia.h"
#include "lista.h"

typedef struct {
    int id;
    char nombre[50];
    char fechaNacimiento[11]; // formato: YYYY-MM-DD
    Lista *materias;
} Estudiante;

Estudiante* crearEstudiante(int id, const char *nombre, const char *fechaNacimiento);
void modificarEstudiante(Estudiante *estudiante, const char *nombre, const char *fechaNacimiento);
void eliminarEstudiante(Estudiante *estudiante);
void imprimirEstudiante(const Estudiante *estudiante);
int calcularEdad(const char *fechaNacimiento);
void agregarMateriaEstudiante(Estudiante *estudiante, Materia *materia);
void rendirMateria(Estudiante *estudiante, int idMateria, float nota);
void listarEstudiantes(const Lista *lista);
float promedioDelEstudiante(Estudiante *estudiante);
void generarEstudiantesYMaterias(Lista *listaEstudiantes, int cantidadEstudiantes, int cantidadMaterias);
int compararEstudiantesPorNombre(const void *a, const void *b);
int compararEstudiantesPorFechaNacimiento(const void *a, const void *b);
int compararEstudiantesPorID(const void *a, const void *b);

#endif // ESTUDIANTE_H