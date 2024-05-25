#ifndef LISTA_H
#define LISTA_H

typedef struct structMateria {
    int id;
    char nombre[100];
    int nota;          // Nota obtenida al rendir la materia
    int rendido;       // 0 si no se ha rendido, 1 si ya se rindió
    struct structMateria *proximo;
} Materia;

typedef struct NodoMateria {
    Materia materia;
    struct NodoMateria *proximo;
} NodoMateria;

typedef struct structEstudiante {
    int id;
    char nombre[100];
    char fechaNacimiento[11]; // Formato: "YYYY-MM-DD"
    NodoMateria *materias;
} Estudiante;

typedef struct NodoEstudiante {
    Estudiante estudiante;
    struct NodoEstudiante *proximo;
} NodoEstudiante;

#endif // LISTA_H
