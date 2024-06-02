#include "lista.h"
#include <stdlib.h>

Lista* crearLista() {
    Lista *lista = (Lista*)malloc(sizeof(Lista));
    lista->cabeza = NULL;
    lista->longitud = 0;
    return lista;
}

void agregar(Lista *lista, void *data) {
    Nodo *nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
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
    lista->longitud++;
}

void eliminarNodo(Lista *lista, int index) {
    if (index < 0 || index >= lista->longitud) return;
    Nodo *temp;
    if (index == 0) {
        temp = lista->cabeza;
        lista->cabeza = lista->cabeza->proximo;
    } else {
        Nodo *cursor = lista->cabeza;
        for (int i = 0; i < index - 1; i++) {
            cursor = cursor->proximo;
        }
        temp = cursor->proximo;
        cursor->proximo = temp->proximo;
    }
    free(temp);
    lista->longitud--;
}

void* obtener(Lista *lista, int index) {
    if (index < 0 || index >= lista->longitud) return NULL;
    Nodo *cursor = lista->cabeza;
    for (int i = 0; i < index; i++) {
        cursor = cursor->proximo;
    }
    return cursor->data;
}

int obtenerLongitud(Lista *lista) {
    return lista->longitud;
}
