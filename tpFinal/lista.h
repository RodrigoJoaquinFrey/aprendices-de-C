#ifndef LISTA_H
#define LISTA_H

typedef struct Nodo {
    void *data;
    struct Nodo *proximo;
} Nodo;

typedef struct {
    Nodo *cabeza;
    int longitud;
} Lista;

Lista* crearLista();
void agregar(Lista *lista, void *data);
void eliminarNodo(Lista *lista, int index);
void* obtener(Lista *lista, int index);
int obtenerLongitud(Lista *lista);

#endif // LISTA_H
