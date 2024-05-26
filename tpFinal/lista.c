#include "lista.h"
#include <stdlib.h>

Lista *crearLista() {
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    lista->cabeza = NULL;
    lista->largo = 0;
    return lista;
}

void agregar(Lista *lista, void *data) {
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    nuevoNodo->data = data;
    nuevoNodo->proximo = NULL;

    if (lista->cabeza == NULL) {
        lista->cabeza = nuevoNodo;
    } else {
        Nodo *cursor = lista->cabeza;
        while (cursor->proximo != NULL) {
            cursor = cursor->proximo;
        }
        cursor->proximo = nuevoNodo;
    }
    lista->largo++;
}

int obtenerLargoLista(const Lista *lista) {
    return lista->largo;
}

void *obtenerElementoLista(const Lista *lista, int indice) {
    Nodo *cursor = lista->cabeza;
    int contador = 0;

    while (cursor != NULL) {
        if (contador == indice) {
            return cursor->data;
        }
        cursor = cursor->proximo;
        contador++;
    }

    return NULL;
}

void eliminarElementoLista(Lista *lista, int indice) {
    if (indice < 0 || indice >= lista->largo) {
        return;
    }

    Nodo *anterior = NULL;
    Nodo *actual = lista->cabeza;

    for (int i = 0; i < indice; i++) {
        anterior = actual;
        actual = actual->proximo;
    }

    if (anterior == NULL) {
        lista->cabeza = actual->proximo;
    } else {
        anterior->proximo = actual->proximo;
    }

    free(actual->data);
    free(actual);
    lista->largo--;
}
