#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int valor;
    struct Nodo* siguiente;
} Nodo;

// Función para crear e inicializar la lista
Nodo* crearLista() {
    return NULL;
}

// Función para agregar un elemento al final de la lista
Nodo* agregarNodo(Nodo* head, int valor) {
    Nodo* nodoNuevo = (Nodo*)malloc(sizeof(Nodo));
    nodoNuevo->valor = valor;
    nodoNuevo->siguiente = NULL;

    if (head == NULL) {
        return nodoNuevo;
    }

    Nodo* actual = head;
    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }

    actual->siguiente = nodoNuevo;
    return head;
}

// Función para obtener el largo de la lista
int largoDeLista(Nodo* head) {
    int largo = 0;
    Nodo* actual = head;

    while (actual != NULL) {
        largo++;
        actual = actual->siguiente;
    }

    return largo;
}

// Función para obtener un elemento igual a N de la lista
Nodo* obtenerElemento(Nodo* head, int n) {
    int contador = 1;
    Nodo* actual = head;

    while (actual != NULL && contador < n) {
        actual = actual->siguiente;
        contador++;
    }

    if (contador == n) {
        return actual;
    }

    return NULL;
}

// Función para eliminar un elemento igual a N de la lista
Nodo* borrarElemento(Nodo* head, int n) {
    if (n == 1) {
        Nodo* temp = head;
        head = head->siguiente;
        free(temp);                    //libera memoria
        return head;
    }

    Nodo* actual = head;
    int contador = 1;

    while (actual->siguiente != NULL && contador < n - 1) {
        actual = actual->siguiente;
        contador++;
    }

    if (contador == n - 1 && actual->siguiente != NULL) {
        Nodo* temp = actual->siguiente;
        actual->siguiente = temp->siguiente;
        free(temp);                    //libera memoria
    }

    return head;
}

// Función para imprimir la lista
void printList(Nodo* head) {
    Nodo* actual = head;
    while (actual != NULL) {
        printf("%d ", actual->valor);
        actual = actual->siguiente;
    }
    printf("\n");
}

// Parte 2: Implementar una lista de enteros ordenada
Nodo* agregarNodoOrdenado(Nodo* head, int valor) {
    Nodo* nodoNuevo = (Nodo*)malloc(sizeof(Nodo));
    nodoNuevo->valor = valor;
    nodoNuevo->siguiente = NULL;

    if (head == NULL || valor < head->valor) {
        nodoNuevo->siguiente = head;
        return nodoNuevo;
    }

    Nodo* actual = head;
    while (actual->siguiente != NULL && actual->siguiente->valor < valor) {
        actual = actual->siguiente;
    }

    nodoNuevo->siguiente = actual->siguiente;
    actual->siguiente = nodoNuevo;

    return head;
}

int main() {
    Nodo* lista = crearLista();

    // Agregar elementos a la lista
    lista = agregarNodo(lista, 10);
    lista = agregarNodo(lista, 20);
    lista = agregarNodo(lista, 30);
    lista = agregarNodo(lista, 40);

    printf("Lista original: ");
    printList(lista);

    // Obtener el largo de la lista
    int largo = largoDeLista(lista);
    printf("Largo de la lista: %d\n", largo);

    // Obtener el segundo elemento de la lista
    Nodo* segundoElemento = obtenerElemento(lista, 2);
    if (segundoElemento != NULL) {
        printf("Segundo elemento: %d\n", segundoElemento->valor);
    } else {
        printf("No existe el segundo elemento en la lista.\n");
    }

    // Eliminar el segundo elemento de la lista
    lista = borrarElemento(lista, 2);
    printf("Lista después de eliminar el segundo elemento: ");
    printList(lista);

    // Parte 2: Lista ordenada
    Nodo* listaOrdenada = crearLista();

    listaOrdenada = agregarNodoOrdenado(listaOrdenada, 25);
    listaOrdenada = agregarNodoOrdenado(listaOrdenada, 10);
    listaOrdenada = agregarNodoOrdenado(listaOrdenada, 35);
    listaOrdenada = agregarNodoOrdenado(listaOrdenada, 5);

    printf("Lista ordenada: ");
    printList(listaOrdenada);

    return 0;
}