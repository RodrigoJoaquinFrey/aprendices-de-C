#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estudiante.h"
#include "materia.h"
#include "lista.h"
#include "utils.h"

void mostrarMenu() {
    printf("\nMenu de opciones:\n");
    printf("1. Dar de alta un estudiante\n");
    printf("2. Modificar un estudiante\n");
    printf("3. Eliminar un estudiante\n");
    printf("4. Listar estudiantes\n");
    printf("5. Buscar estudiante por nombre\n");
    printf("6. Buscar estudiante por rango de edad\n");
    printf("7. Dar de alta una materia\n");
    printf("8. Anotarse en una materia\n");
    printf("9. Rendir una materia\n");
    printf("0. Salir\n");
    printf("Seleccione una opcion: ");
}

int main() {
    Lista *listaEstudiantes = crearLista();
    Lista *listaMaterias = crearLista();
    int opcion, id, idMateria;
    char nombre[50], fechaNacimiento[11];
    float nota;

    do {
        mostrarMenu();
        scanf("%d", &opcion);
        limpiarBuffer();

        switch (opcion) {
            case 1:
                printf("Ingrese ID del estudiante: ");
                scanf("%d", &id);
                limpiarBuffer();
                printf("Ingrese nombre del estudiante: ");
                fgets(nombre, sizeof(nombre), stdin);
                nombre[strcspn(nombre, "\n")] = '\0';
                printf("Ingrese fecha de nacimiento (YYYY-MM-DD): ");
                fgets(fechaNacimiento, sizeof(fechaNacimiento), stdin);
                fechaNacimiento[strcspn(fechaNacimiento, "\n")] = '\0';
                agregar(listaEstudiantes, crearEstudiante(id, nombre, fechaNacimiento));
                break;
            case 2:
                printf("Ingrese ID del estudiante a modificar: ");
                scanf("%d", &id);
                limpiarBuffer();
                for (int i = 0; i < obtenerLongitud(listaEstudiantes); i++) {
                    Estudiante *est = obtener(listaEstudiantes, i);
                    if (est->id == id) {
                        printf("Ingrese nuevo nombre: ");
                        fgets(nombre, sizeof(nombre), stdin);
                        nombre[strcspn(nombre, "\n")] = '\0';
                        printf("Ingrese nueva fecha de nacimiento (YYYY-MM-DD): ");
                        fgets(fechaNacimiento, sizeof(fechaNacimiento), stdin);
                        fechaNacimiento[strcspn(fechaNacimiento, "\n")] = '\0';
                        modificarEstudiante(est, nombre, fechaNacimiento);
                        break;
                    }
                }
                break;
            case 3:
                printf("Ingrese ID del estudiante a eliminar: ");
                scanf("%d", &id);
                limpiarBuffer();
                for (int i = 0; i < obtenerLongitud(listaEstudiantes); i++) {
                    Estudiante *est = obtener(listaEstudiantes, i);
                    if (est->id == id) {
                        eliminarEstudiante(est);
                        eliminarNodo(listaEstudiantes, i);
                        break;
                    }
                }
                break;
            case 4:
                listarEstudiantes(listaEstudiantes);
                break;
            case 5:
                printf("Ingrese nombre del estudiante a buscar: ");
                fgets(nombre, sizeof(nombre), stdin);
                nombre[strcspn(nombre, "\n")] = '\0';
                for (int i = 0; i < obtenerLongitud(listaEstudiantes); i++) {
                    Estudiante *est = obtener(listaEstudiantes, i);
                    if (strcmp(est->nombre, nombre) == 0) {
                        imprimirEstudiante(est);
                        break;
                    }
                }
                break;
            case 6:
                printf("Ingrese edad minima: ");
                int edadMin;
                scanf("%d", &edadMin);
                limpiarBuffer();
                printf("Ingrese edad maxima: ");
                int edadMax;
                scanf("%d", &edadMax);
                limpiarBuffer();
                int encontrado = 0;
                for (int i = 0; i < obtenerLongitud(listaEstudiantes); i++) {
                    Estudiante *est = obtener(listaEstudiantes, i);
                    int edad = calcularEdad(est->fechaNacimiento);
                    if (edad >= edadMin && edad <= edadMax) {
                        imprimirEstudiante(est);
                        encontrado = 1;
                    }
                }
                if (!encontrado) {
                    printf("No se encontraron estudiantes en ese rango de edad.\n");
                }
                break;
            case 7:
                printf("Ingrese ID de la materia: ");
                scanf("%d", &id);
                limpiarBuffer();
                printf("Ingrese nombre de la materia: ");
                fgets(nombre, sizeof(nombre), stdin);
                nombre[strcspn(nombre, "\n")] = '\0';
                Materia *materia = (Materia*)malloc(sizeof(Materia));
                inicializarMateria(materia, id, nombre);
                agregar(listaMaterias, materia);
                break;
            case 8:
                printf("Ingrese ID del estudiante: ");
                scanf("%d", &id);
                limpiarBuffer();
                printf("Ingrese ID de la materia a agregar: ");
                scanf("%d", &idMateria);
                limpiarBuffer();
                for (int i = 0; i < obtenerLongitud(listaEstudiantes); i++) {
                    Estudiante *est = obtener(listaEstudiantes, i);
                    if (est->id == id) {
                        for (int j = 0; j < obtenerLongitud(listaMaterias); j++) {
                            Materia *mat = obtener(listaMaterias, j);
                            if (mat->id == idMateria) {
                                agregarMateriaEstudiante(est, mat);
                                break;
                            }
                        }
                        break;
                    }
                }
                break;
            case 9:
                printf("Ingrese ID del estudiante: ");
                scanf("%d", &id);
                limpiarBuffer();
                printf("Ingrese ID de la materia a rendir: ");
                scanf("%d", &idMateria);
                limpiarBuffer();
                printf("Ingrese la nota: ");
                scanf("%f", &nota);
                limpiarBuffer();
                for (int i = 0; i < obtenerLongitud(listaEstudiantes); i++) {
                    Estudiante *est = obtener(listaEstudiantes, i);
                    if (est->id == id) {
                        rendirMateria(est, idMateria, nota);
                        break;
                    }
                }
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida. Intente nuevamente.\n");
        }
    } while (opcion != 0);

    // Liberar memoria
    while (obtenerLongitud(listaEstudiantes) > 0) {
        Estudiante *est = obtener(listaEstudiantes, 0);
        eliminarEstudiante(est);
        eliminarNodo(listaEstudiantes, 0);
    }
    free(listaEstudiantes);

    while (obtenerLongitud(listaMaterias) > 0) {
        Materia *mat = obtener(listaMaterias, 0);
        free(mat);
        eliminarNodo(listaMaterias, 0);
    }
    free(listaMaterias);

    return 0;
}
