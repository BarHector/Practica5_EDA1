#include <stdlib.h>
#include <stdio.h>

typedef struct nodo{
    int valor;
    struct nodo *siguiente;
}tipoNodo;

typedef tipoNodo *pNodo;

void Insertar(pNodo *primero, pNodo *ultimo, int v);
int Eliminar(pNodo *primero, pNodo *ultimo);

int main() {
    pNodo primero = NULL, ultimo = NULL;
    Insertar(&primero, &ultimo, 20);
    printf("Añadir(20)\n");
    Insertar(&primero, &ultimo, 10);
    printf("Añadir(10)\n");
    printf("Eliminar: %d\n", Eliminar(&primero, &ultimo));
    Insertar(&primero, &ultimo, 40);
    printf("Añadir(40)\n");
    Insertar(&primero, &ultimo, 30);
    printf("Añadir(30)\n");
    printf("Eliminar: %d\n", Eliminar(&primero, &ultimo));
    printf("Eliminar: %d\n", Eliminar(&primero, &ultimo));
    Insertar(&primero, &ultimo, 90);
    printf("Añadir(90)\n");
    printf("Eliminar: %d\n", Eliminar(&primero, &ultimo));
    printf("Eliminar: %d\n", Eliminar(&primero, &ultimo));

    return 0;
}

void Insertar(pNodo *primero, pNodo *ultimo, int v) {
    pNodo nuevo;

    nuevo = (pNodo)malloc(sizeof(tipoNodo));
    nuevo->valor = v;
    nuevo->siguiente = NULL;

    if(*ultimo) 
        (*ultimo)->siguiente = nuevo;
    *ultimo = nuevo; 
   
    if(!*primero) 
        *primero = nuevo; 
}

int Eliminar(pNodo *primero, pNodo *ultimo) {
    pNodo nodo;
    int v;

    nodo = *primero;
    if(!nodo) 
        return 0; 

    *primero = nodo->siguiente;  
    v = nodo->valor;
    free(nodo);

    if(!*primero) 
        *ultimo = NULL;

    return v;
}