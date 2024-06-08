#include "estudiante.h"

Estudiante* crearEstudiante(int id, const char *nombre, const char *fechaNacimiento) {
    int edad = calcularEdad(fechaNacimiento);
    if (edad < 6 || edad > 100) {
        printf("Error: La edad del estudiante debe estar entre 6 y 100 años. Edad calculada: %d\n", edad);
        return NULL;
    }

    Estudiante* buscarEstudiantePorID(int id) {
    Nodo *nodo = lista_de_estudiantes->cabeza; // Suponiendo que lista_de_estudiantes es una variable global que almacena la lista de estudiantes
    while (nodo != NULL) {
        Estudiante *estudiante = (Estudiante*)nodo->data;
        if (estudiante->id == id) {
            return estudiante;
        }
        nodo = nodo->proximo;
    }
    return NULL; // Retorna NULL si no se encuentra ningún estudiante con el ID especificado
}
Estudiante* crearEstudiante(int id, const char *nombre, const char *apellido, const char *fechaNacimiento) {
    if (buscarEstudiantePorID(id) != NULL) {
        printf("Error: Ya existe un estudiante con el ID %d.\n", id);
        return NULL;
    }

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
    if (estudiante == NULL) {
        printf("Error: El estudiante no existe.\n");
        return;
    }
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
     int dia, mes, anio;
    sscanf(fechaNacimiento, "%d/%d/%d", &dia, &mes, &anio); // Cambiado el formato de entrada a "DD/MM/YYYY"
    
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
    if (nota < 1.0 || nota > 10.0) {
        printf("Error: La nota debe estar entre 1 y 10.\n");
        return;
    }
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
