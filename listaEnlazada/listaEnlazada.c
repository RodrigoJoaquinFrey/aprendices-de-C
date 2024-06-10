#include <stdio.h>
#include <malloc.h>

typedef struct structNodo {
    int valor;
    struct structNodo *proximo;
} Nodo;

// Función para crear e inicializar la lista
Nodo* crearLista() {
    return NULL;
}

// Función para agregar un elemento a la lista
Nodo* agregar(Nodo *lista, int valor) {
    Nodo *nuevoNodo = malloc(sizeof(Nodo));
    if (!nuevoNodo) {
        printf("Error al asignar memoria\n");
        exit(1);
    }
    nuevoNodo->valor = valor;
    nuevoNodo->proximo = NULL;

    if (lista == NULL) {
        return nuevoNodo;
    } else {
        Nodo *cursor = lista;
        while (cursor->proximo != NULL) {
            cursor = cursor->proximo;
        }
        cursor->proximo = nuevoNodo;
    }
    return lista;
}

// Función para agregar un elemento en orden
Nodo* agregarOrdenado(Nodo *lista, int valor) {
    Nodo *nuevoNodo = malloc(sizeof(Nodo));
    if (!nuevoNodo) {
        printf("Error al asignar memoria\n");
        exit(1);
    }
    nuevoNodo->valor = valor;
    nuevoNodo->proximo = NULL;

    if (lista == NULL || lista->valor >= valor) {
        nuevoNodo->proximo = lista;
        lista = nuevoNodo;
    } else {
        Nodo *cursor = lista;
        while (cursor->proximo != NULL && cursor->proximo->valor < valor) {
            cursor = cursor->proximo;
        }
        nuevoNodo->proximo = cursor->proximo;
        cursor->proximo = nuevoNodo;
    }

    return lista;
}

// Función para obtener el largo de la lista
int obtenerLargo(Nodo *lista) {
    int largo = 0;
    Nodo *cursor = lista;
    while (cursor != NULL) {
        largo++;
        cursor = cursor->proximo;
    }
    return largo;
}

// Función para obtener el elemento en la posición N
Nodo* obtenerElemento(Nodo *lista, int posicion) {
    int contador = 0;
    Nodo *cursor = lista;
    while (cursor != NULL) {
        if (contador == posicion) {
            return cursor;
        }
        contador++;
        cursor = cursor->proximo;
    }
    return NULL;  // Si la posición es mayor que el largo de la lista
}

// Función para eliminar el elemento en la posición N
Nodo* eliminar(Nodo *lista, int posicion) {
    if (lista == NULL) {
        return NULL;  // La lista está vacía
    }

    if (posicion == 0) {
        Nodo *temp = lista;
        lista = lista->proximo;
        free(temp);
        return lista;
    }

    Nodo *cursor = lista;
    for (int i = 0; cursor != NULL && i < posicion - 1; i++) {
        cursor = cursor->proximo;
    }

    if (cursor == NULL || cursor->proximo == NULL) {
        return lista;  // La posición está fuera de los límites de la lista
    }

    Nodo *nodoAEliminar = cursor->proximo;
    cursor->proximo = nodoAEliminar->proximo;
    free(nodoAEliminar);

    return lista;
}

// Función para imprimir la lista
void imprimirLista(Nodo *lista) {
    Nodo *cursor = lista;
    while (cursor != NULL) {
        printf("%d\n", cursor->valor);
        cursor = cursor->proximo;
    }
}

int main(void) {
    Nodo *lista = crearLista();

    lista = agregar(lista, 1);
    lista = agregar(lista, 2);
    lista = agregar(lista, 3);
    lista = agregar(lista, 4);
    lista = agregar(lista, 5);

    printf("Lista original:\n");
    imprimirLista(lista);

    int largo = obtenerLargo(lista);
    printf("Largo de la lista: %d\n", largo);

    int posicion = 2;
    Nodo *elemento = obtenerElemento(lista, posicion);
    if (elemento != NULL) {
        printf("Elemento en la posición %d: %d\n", posicion, elemento->valor);
    } else {
        printf("No se encontró el elemento en la posición %d\n", posicion);
    }

    lista = eliminar(lista, posicion);
    printf("Lista después de eliminar el elemento en la posición %d:\n", posicion);
    imprimirLista(lista);
    
    /////////////////////// TEST DE LISTA ORDENADA ////////////////////////////////

    Nodo *lista2 = crearLista();

    //Agrego elementos en distinto orden
    lista2 = agregarOrdenado(lista2, 5);
    lista2 = agregarOrdenado(lista2, 1);
    lista2 = agregarOrdenado(lista2, 3);
    lista2 = agregarOrdenado(lista2, 2);
    lista2 = agregarOrdenado(lista2, 4);

    printf("Lista 2 ordenada:\n");
    imprimirLista(lista2); //La lista ordenada me los agrega de menor a mayor

    return 0;
}