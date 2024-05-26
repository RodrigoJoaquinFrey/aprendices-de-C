#ifndef LISTA_H
#define LISTA_H

typedef struct Nodo {
    void *data;
    struct Nodo *proximo;
} Nodo;

typedef struct {
    Nodo *cabeza;
    int largo;
} Lista;

Lista *crearLista();
void agregar(Lista *lista, void *data);
int obtenerLargoLista(const Lista *lista);
void *obtenerElementoLista(const Lista *lista, int indice);
void eliminarElementoLista(Lista *lista, int indice);

#endif // LISTA_H
