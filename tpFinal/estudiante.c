#include "estudiante.h"

Estudiante* crearEstudiante(int id, const char *nombre, const char *fechaNacimiento) {
    Estudiante *estudiante = (Estudiante*)malloc(sizeof(Estudiante));
    estudiante->id = id;
    strncpy(estudiante->nombre, nombre, sizeof(estudiante->nombre) - 1);
    estudiante->nombre[sizeof(estudiante->nombre) - 1] = '\0';
    strncpy(estudiante->fechaNacimiento, fechaNacimiento, sizeof(estudiante->fechaNacimiento) - 1);
    estudiante->fechaNacimiento[sizeof(estudiante->fechaNacimiento) - 1] = '\0';
    estudiante->materias = crearLista();
    return estudiante;
}

void modificarEstudiante(Estudiante *estudiante, const char *nombre, const char *fechaNacimiento) {
    strncpy(estudiante->nombre, nombre, sizeof(estudiante->nombre) - 1);
    estudiante->nombre[sizeof(estudiante->nombre) - 1] = '\0';
    strncpy(estudiante->fechaNacimiento, fechaNacimiento, sizeof(estudiante->fechaNacimiento) - 1);
    estudiante->fechaNacimiento[sizeof(estudiante->fechaNacimiento) - 1] = '\0';
}

void eliminarEstudiante(Estudiante *estudiante) {
    Nodo *nodo = estudiante->materias->cabeza;
    while (nodo != NULL) {
        Nodo *temp = nodo;
        nodo = nodo->proximo;
        free(temp->data);
        free(temp);
    }
    free(estudiante->materias);
    free(estudiante);
}

void imprimirEstudiante(const Estudiante *estudiante) {
    printf("ID: %d\n", estudiante->id);
    printf("Nombre: %s\n", estudiante->nombre);
    printf("Fecha de Nacimiento: %s\n", estudiante->fechaNacimiento);
    printf("Edad: %d\n", calcularEdad(estudiante->fechaNacimiento));
    printf("Materias:\n");
    Nodo *nodo = estudiante->materias->cabeza;
    while (nodo != NULL) {
        imprimirMateria((Materia*)nodo->data);
        nodo = nodo->proximo;
    }
}

int calcularEdad(const char *fechaNacimiento) {
    int anio, mes, dia;
    sscanf(fechaNacimiento, "%d-%d-%d", &anio, &mes, &dia);
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int anioActual = tm.tm_year + 1900;
    int mesActual = tm.tm_mon + 1;
    int diaActual = tm.tm_mday;
    int edad = anioActual - anio;
    if (mes > mesActual || (mes == mesActual && dia > diaActual)) {
        edad--;
    }
    return edad;
}

void agregarMateriaEstudiante(Estudiante *estudiante, Materia *materia) {
    agregar(estudiante->materias, materia);
}

void rendirMateria(Estudiante *estudiante, int idMateria, float nota) {
    Nodo *nodo = estudiante->materias->cabeza;
    while (nodo != NULL) {
        Materia *materia = (Materia*)nodo->data;
        if (materia->id == idMateria) {
            if (materia->nota >= 0) {
                printf("Ya se rindió esta materia y su nota es: %.2f\n", materia->nota);
            } else {
                materia->nota = nota;
                printf("Materia rendida con éxito. Nota: %.2f\n", materia->nota);
            }
            return;
        }
        nodo = nodo->proximo;
    }
    printf("Materia no encontrada.\n");
}

void listarEstudiantes(const Lista *lista) {
    Nodo *nodo = lista->cabeza;
    while (nodo != NULL) {
        imprimirEstudiante((Estudiante*)nodo->data);
        nodo = nodo->proximo;
    }
}