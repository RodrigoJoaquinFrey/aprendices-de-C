#include <stdio.h>
#include <stdlib.h>
#include "estudiante.h"
#include "materia.h"

void mostrarMenu() {
    printf("1. Dar de alta estudiante\n");
    printf("2. Modificar estudiante\n");
    printf("3. Eliminar estudiante\n");
    printf("4. Listar estudiantes\n");
    printf("5. Buscar estudiante por nombre\n");
    printf("6. Buscar estudiante por rango de edad\n");
    printf("7. Dar de alta materia\n");
    printf("8. Modificar materia\n");
    printf("9. Eliminar materia\n");
    printf("10. Listar materias\n");
    printf("11. Anotarse en materia\n");
    printf("12. Rendir materia\n");
    printf("13. Salir\n");
}

int main() {
    NodoEstudiante *listaEstudiantes = crearListaEstudiantes();
    NodoMateria *listaMaterias = crearListaMaterias();
    int opcion;

    do {
        mostrarMenu();
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                Estudiante estudiante;
                printf("Ingrese ID: ");
                scanf("%d", &estudiante.id);
                printf("Ingrese nombre: ");
                scanf("%s", estudiante.nombre);
                printf("Ingrese fecha de nacimiento (YYYY-MM-DD): ");
                scanf("%s", estudiante.fechaNacimiento);
                estudiante.materias = NULL;
                listaEstudiantes = agregarEstudiante(listaEstudiantes, estudiante);
                break;
            }
            case 2: {
                int id;
                Estudiante nuevoEstudiante;
                printf("Ingrese ID del estudiante a modificar: ");
                scanf("%d", &id);
                printf("Ingrese nuevo nombre: ");
                scanf("%s", nuevoEstudiante.nombre);
                printf("Ingrese nueva fecha de nacimiento (YYYY-MM-DD): ");
                scanf("%s", nuevoEstudiante.fechaNacimiento);
                nuevoEstudiante.materias = NULL;
                listaEstudiantes = modificarEstudiante(listaEstudiantes, id, nuevoEstudiante);
                break;
            }
            case 3: {
                int id;
                printf("Ingrese ID del estudiante a eliminar: ");
                scanf("%d", &id);
                listaEstudiantes = eliminarEstudiante(listaEstudiantes, id);
                break;
            }
            case 4: {
                listarEstudiantes(listaEstudiantes);
                break;
            }
            case 5: {
                char nombre[100];
                printf("Ingrese el nombre del estudiante a buscar: ");
                scanf("%s", nombre);
                NodoEstudiante *resultados = buscarEstudiantesPorNombre(listaEstudiantes, nombre);
                listarEstudiantes(resultados);
                break;
            }
            case 6: {
                int edadMin, edadMax;
                printf("Ingrese la edad mínima: ");
                scanf("%d", &edadMin);
                printf("Ingrese la edad máxima: ");
                scanf("%d", &edadMax);
                NodoEstudiante *resultados = buscarEstudiantesPorRangoEdad(listaEstudiantes, edadMin, edadMax);
                listarEstudiantes(resultados);
                break;
            }
            case 7: {
                Materia materia;
                printf("Ingrese ID: ");
                scanf("%d", &materia.id);
                printf("Ingrese nombre: ");
                scanf("%s", materia.nombre);
                materia.nota = -1; // Nota no asignada
                materia.rendido = 0; // No rendido
                listaMaterias = agregarMateria(listaMaterias, materia);
                break;
            }
            case 8: {
                int id;
                Materia nuevaMateria;
                printf("Ingrese ID de la materia a modificar: ");
                scanf("%d", &id);
                printf("Ingrese nuevo nombre: ");
                scanf("%s", nuevaMateria.nombre);
                nuevaMateria.nota = -1; // Nota no asignada
                nuevaMateria.rendido = 0; // No rendido
                listaMaterias = modificarMateria(listaMaterias, id, nuevaMateria);
                break;
            }
            case 9: {
                int id;
                printf("Ingrese ID de la materia a eliminar: ");
                scanf("%d", &id);
                listaMaterias = eliminarMateria(listaMaterias, id);
                break;
            }
            case 10: {
                listarMaterias(listaMaterias);
                break;
            }
            case 11: {
                int idEstudiante, idMateria;
                printf("Ingrese ID del estudiante: ");
                scanf("%d", &idEstudiante);
                printf("Ingrese ID de la materia: ");
                scanf("%d", &idMateria);
                NodoMateria *materiaCursor = listaMaterias;
                while (materiaCursor != NULL) {
                    if (materiaCursor->materia.id == idMateria) {
                        listaEstudiantes = anotarseEnMateria(listaEstudiantes, idEstudiante, materiaCursor->materia);
                        break;
                    }
                    materiaCursor = materiaCursor->proximo;
                }
                break;
            }
            case 12: {
                int idEstudiante, idMateria, nota;
                printf("Ingrese ID del estudiante: ");
                scanf("%d", &idEstudiante);
                printf("Ingrese ID de la materia: ");
                scanf("%d", &idMateria);
                printf("Ingrese la nota: ");
                scanf("%d", &nota);
                listaEstudiantes = rendirMateria(listaEstudiantes, idEstudiante, idMateria, nota);
                break;
            }
            case 13: {
                printf("Saliendo del programa...\n");
                break;
            }
            default: {
                printf("Opción no válida. Intente nuevamente.\n");
                break;
            }
        }
    } while (opcion != 13);

    // Liberar memoria
    // ...

    return 0;
}