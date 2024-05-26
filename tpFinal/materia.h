#ifndef MATERIA_H
#define MATERIA_H

typedef struct Materia {
    int id;
    char nombre[100];
    int creditos;
    float nota; // Nota de la materia
} Materia;

void inicializarMateria(Materia *materia, int id, const char *nombre, int creditos);
void imprimirMateria(const Materia *materia);

#endif // MATERIA_H
