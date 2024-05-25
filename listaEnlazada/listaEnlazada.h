// lista.h
#ifndef LISTA_H
#define LISTA_H

typedef struct structNodo {
    int valor;
    struct structNodo *proximo;
} Nodo;

Nodo* crearLista();
Nodo* agregar(Nodo *lista, int valor);
int obtenerLargo(Nodo *lista);
Nodo* obtenerElemento(Nodo *lista, int indice);
Nodo* eliminarElemento(Nodo *lista, int indice);
Nodo* insertarOrdenado(Nodo *lista, int valor);
void imprimirLista(Nodo *lista);

#endif // LISTA_H