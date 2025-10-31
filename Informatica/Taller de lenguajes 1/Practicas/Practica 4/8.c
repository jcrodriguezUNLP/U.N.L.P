// Utilizando la estructura y funciones de los ejercicios anteriores escriba un programa que lea números 
// enteros desde teclado hasta ingresar el número 0. Luego, vuelva a leer otro número entero desde 
// teclado y elimine de la lista a todos aquellos que sean múltiplos del mismo.

#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de nodo
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

// Inicializa la lista
void inicializarLista(Nodo** cabeza) {
    *cabeza = NULL;
}

// Agrega un elemento al final de la lista
void agregarAlFinal(Nodo** cabeza, int valor) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevo == NULL) return;
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    if (*cabeza == NULL) {
        *cabeza = nuevo;
    } else {
        Nodo* actual = *cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
}

// Imprime todos los elementos de la lista separados por coma
void imprimirLista(Nodo* cabeza) {
    while (cabeza != NULL) {
        printf("%d", cabeza->dato);
        if (cabeza->siguiente != NULL) {
            printf(", ");
        }
        cabeza = cabeza->siguiente;
    }
    printf("\n");
}

// Elimina todos los nodos cuyos datos sean múltiplos de 'multiplo'
void eliminarMultiplos(Nodo** cabeza, int multiplo) {
    Nodo* actual = *cabeza;
    Nodo* anterior = NULL;
    while (actual != NULL) {
        if (multiplo != 0 && actual->dato % multiplo == 0) {
            Nodo* temp = actual;
            if (anterior == NULL) {
                *cabeza = actual->siguiente;
                actual = *cabeza;
            } else {
                anterior->siguiente = actual->siguiente;
                actual = actual->siguiente;
            }
            free(temp);
        } else {
            anterior = actual;
            actual = actual->siguiente;
        }
    }
}

// Libera la memoria de la lista
void eliminarLista(Nodo** cabeza) {
    Nodo* actual = *cabeza;
    Nodo* temp;
    while (actual != NULL) {
        temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    *cabeza = NULL;
}

int main() {
    Nodo* lista;
    inicializarLista(&lista);

    int num;
    printf("Ingrese numeros enteros (0 para terminar):\n");
    do {
        scanf("%d", &num);
        if (num != 0) {
            agregarAlFinal(&lista, num);
        }
    } while (num != 0);

    printf("Lista original:\n");
    imprimirLista(lista);

    printf("Ingrese un numero para eliminar sus multiplos de la lista: ");
    scanf("%d", &num);

    eliminarMultiplos(&lista, num);

    printf("Lista luego de eliminar los multiplos de %d:\n", num);
    imprimirLista(lista);

    eliminarLista(&lista);
    return 0;
}

