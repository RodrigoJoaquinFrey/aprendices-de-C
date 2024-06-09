#include "estudiante.h"

const char *nombres[] = {"Luciana", "Benjamin", "Paula", "Esteban","Zoe","Luciano","Emilia", "Diego", "Narella", "Mateo", "Catalina", "Chano", "Antonella", "Mariel",
                            "Daniel", "Camila", "Miguel", "Belen", "Agustin", "Giuliana", "Bruno", "Delfina", "Mariano", "Florencia", "Joaquin", "Melina",
                            "Leonel", "Olivia", "Martin", "Evelin", "Leonardo", "Agustina", "Jonathan", "Milagros", "Micaela", "Federico", "Carolina", "Facundo",
                            "Romina", "Franco", "Brenda", "Thiago", "Celeste", "Lucio", "Sofia", "Matias","Florencia", "Nicolas", "Santino", "Cristian" , "Rodrigo"};
const char *apellidos[] = {"Garcia", "Rodriguez", "Martinez", "Fernandez", "Lopez", "Gonzalez", "Perez", "Sanchez", "Ramirez", "Torres", "Acosta", "Almada", "Ayala", 
                            "Barrios", "Benitez", "Blanco", "Bustos", "Caceres", "Cardozo", "Carrizo", "Castillo", "Diaz", "Dominguez", "Gutierrez", "Herrera", "Ledesma",
                            "Leiva", "Peralta", "Pereyra", "Quiroga"};
const char *materias[] = {"Matematicas", "Fisica", "Quimica", "Biologia", "Historia", "Geografia", "Lengua", "Literatura", "Filosofia", "Economia", "Algoritmos y Programacion I",
                            "Algebra", "Matematica Discreta", "Disenio Logico", "Programacion de bajo nivel", "Analisis Matematico", "Arquitecturas de Computadoras",
                            "Ingles", "Sistemas Operativos", "Comunicacion de Datos"};

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
                printf("Ya se rindio esta materia y su nota es: %.2f\n", materia->nota);
            } else {
                materia->nota = nota;
                printf("Materia rendida con exito. Nota: %.2f\n", materia->nota);
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

float promedioDelEstudiante(Estudiante *estudiante) {
    float suma = 0.0;
    int count = 0;
    Nodo *nodo = estudiante->materias->cabeza;
    while (nodo != NULL) {
        Materia *materia = (Materia *)nodo->data;
        if (materia->nota >= 0) {
            suma += materia->nota;
            count++;
        }
        nodo = nodo->proximo;
    }
    if (count == 0) {
        return 0.0;
    }
    return suma / count;
}

// Función para ordenar la lista de estudiantes
void ordenarEstudiantes(Lista *lista, int (*comparar)(const void *, const void *)) {
    int longitud = obtenerLongitud(lista);
    Estudiante **arreglo = (Estudiante **)malloc(longitud * sizeof(Estudiante *));
    Nodo *nodo = lista->cabeza;
    int i = 0;
    while (nodo != NULL) {
        arreglo[i++] = (Estudiante *)nodo->data;
        nodo = nodo->proximo;
    }
    qsort(arreglo, longitud, sizeof(Estudiante *), comparar);
    nodo = lista->cabeza;
    for (i = 0; i < longitud; i++) {
        nodo->data = arreglo[i];
        nodo = nodo->proximo;
    }
    free(arreglo);
}

// Función de comparación para ordenar estudiantes por nombre
int compararEstudiantesPorNombre(const void *a, const void *b) {
    Estudiante *estudianteA = (Estudiante *)a;
    Estudiante *estudianteB = (Estudiante *)b;
    return strcmp(estudianteA->nombre, estudianteB->nombre);
}

// Función de comparación para ordenar estudiantes por fecha de nacimiento
int compararEstudiantesPorFechaNacimiento(const void *a, const void *b) {
    Estudiante *estudianteA = (Estudiante *)a;
    Estudiante *estudianteB = (Estudiante *)b;
    return strcmp(estudianteA->fechaNacimiento, estudianteB->fechaNacimiento);
}

// Función de comparación para ordenar estudiantes por ID
int compararEstudiantesPorID(const void *a, const void *b) {
    Estudiante *estudianteA = (Estudiante *)a;
    Estudiante *estudianteB = (Estudiante *)b;
    return estudianteA->id - estudianteB->id;
}

void generarEstudiantesYMaterias(Lista *listaEstudiantes, int cantidadEstudiantes, int cantidadMaterias) {
    srand(time(NULL));

    for (int i = 0; i < cantidadEstudiantes; i++) {
        char nombre[50];
        sprintf(nombre, "%s %s", nombres[rand() % 50], apellidos[rand() % 30]);

        int dia = rand() % 28 + 1;
        int mes = rand() % 12 + 1;
        int anio = rand() % 20 + 2000;
        char fechaNacimiento[15];
        sprintf(fechaNacimiento, "%d-%02d-%02d", anio, mes, dia);

        Estudiante *estudiante = crearEstudiante(i + 1, nombre, fechaNacimiento);

        for (int j = 0; j < cantidadMaterias; j++) {
            Materia *materia = (Materia *)malloc(sizeof(Materia));
            inicializarMateria(materia, j + 1, materias[rand() % 20]);
            agregarMateriaEstudiante(estudiante, materia);
            rendirMateria(estudiante, materia->id, (float)(rand() % 101) / 10); // Asignar nota aleatoria entre 0 y 10
        }

        agregar(listaEstudiantes, estudiante);
    }
}