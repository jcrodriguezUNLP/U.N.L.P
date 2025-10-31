// Defina la estructura de una lista enlazada de enteros e implemente funciones para:
//   a. Inicializar la lista.
//   b. Eliminar todos los elementos de la lista.
//   c. Agregar un elemento al principio de la lista.
//   d. Agregar un elemento al final de la lista.
//   e. Calcular la cantidad de elementos de la lista.
//   f. Imprimir todos los elementos separados por coma.

#include <stdio.h>
#include <stdlib.h>

// Estructura de un nodo de la lista enlazada simple de enteros
typedef struct Nodo {
    int dato;                // Valor almacenado en el nodo
    struct Nodo* siguiente;  // Puntero al siguiente nodo
} Nodo;

// a. Inicializa la lista enlazada, dejando el puntero cabeza en NULL
void inicializarLista(Nodo** cabeza) {
    *cabeza = NULL;
}

// b. Elimina todos los nodos de la lista y libera la memoria utilizada
void eliminarLista(Nodo** cabeza) {
    Nodo* actual = *cabeza;
    Nodo* temp;
    while (actual != NULL) {
        temp = actual;
        actual = actual->siguiente;
        free(temp); // Libera el nodo actual
    }
    *cabeza = NULL; // Deja la lista vacía
}

// c. Agrega un nuevo nodo al principio de la lista con el valor dado
void agregarAlPrincipio(Nodo** cabeza, int valor) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevo == NULL) return; // Verifica si la memoria fue asignada correctamente
    nuevo->dato = valor;
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}

// d. Agrega un nuevo nodo al final de la lista con el valor dado
void agregarAlFinal(Nodo** cabeza, int valor) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevo == NULL) return; // Verifica si la memoria fue asignada correctamente
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    if (*cabeza == NULL) {
        *cabeza = nuevo; // Si la lista está vacía, el nuevo nodo es la cabeza
    } else {
        Nodo* actual = *cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente; // Avanza hasta el último nodo
        }
        actual->siguiente = nuevo; // Enlaza el nuevo nodo al final
    }
}

// e. Calcula y retorna la cantidad de nodos en la lista
int cantidadElementos(Nodo* cabeza) {
    int contador = 0;
    while (cabeza != NULL) {
        contador++;
        cabeza = cabeza->siguiente;
    }
    return contador;
}

// f. Imprime todos los elementos de la lista separados por coma
void imprimirLista(Nodo* cabeza) {
    while (cabeza != NULL) {
        printf("%d", cabeza->dato);
        if (cabeza->siguiente != NULL) {
            printf(", "); // Imprime coma solo si no es el último elemento
        }
        cabeza = cabeza->siguiente;
    }
    printf("\n");
}