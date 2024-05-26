#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estudiante.h"
#include "materia.h"
#include "lista.h"
#include "utils.h"

int main() {
    Lista *listaEstudiantes = crearLista();
    Lista *listaMaterias = crearLista();

    // Ejemplo de agregar estudiantes
    Estudiante *est1 = crearEstudiante(1, "Juan Perez", "2000-01-01");
    Estudiante *est2 = crearEstudiante(2, "Maria Gomez", "1998-05-15");
    agregar(listaEstudiantes, est1);
    agregar(listaEstudiantes, est2);

    // Ejemplo de agregar materias
    Materia *mat1 = (Materia *)malloc(sizeof(Materia));
    inicializarMateria(mat1, 101, "Matematica", 5);
    Materia *mat2 = (Materia *)malloc(sizeof(Materia));
    inicializarMateria(mat2, 102, "Historia", 3);
    agregar(listaMaterias, mat1);
    agregar(listaMaterias, mat2);

    // Inscribir materias a estudiantes
    agregarMateriaEstudiante(est1, mat1);
    agregarMateriaEstudiante(est1, mat2);
    agregarMateriaEstudiante(est2, mat1);

    // Listar estudiantes
    listarEstudiantes(listaEstudiantes);

    // Rendir una materia
    printf("\nJuan Perez rinde Matematica:\n");
    rendirMateria(est1, 101, 8.5);
    printf("\nJuan Perez intenta rendir Historia dos veces:\n");
    rendirMateria(est1, 102, 7.0);
    rendirMateria(est1, 102, 9.0); // Ya rendida

    // Listar materias de Juan Perez
    printf("\nMaterias de Juan Perez:\n");
    Nodo *nodoMateria = est1->materias->cabeza;
    while (nodoMateria != NULL) {
        imprimirMateria((Materia *)nodoMateria->data);
        nodoMateria = nodoMateria->proximo;
    }

    // Liberar memoria
    // Aquí puedes implementar una función para liberar la lista de estudiantes y sus materias

    return 0;
}