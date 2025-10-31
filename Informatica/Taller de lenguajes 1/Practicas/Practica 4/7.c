// Programa que lee números enteros positivos desde teclado hasta ingresar 0.
// Los números se almacenan en una lista enlazada en el orden de ingreso.
// Luego, se genera una nueva lista con el orden invertido.
// Se imprimen ambas listas y la cantidad de elementos de cada una.
// Finalmente, se libera la memoria reservada dinámicamente.

#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura Nodo para la lista enlazada
typedef struct Nodo {
    int dato;
    struct Nodo* sig;
} Nodo;

// Inserta un nuevo nodo con el valor dado al final de la lista
Nodo* insertarFinal(Nodo* lista, int valor) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = valor;
    nuevo->sig = NULL;
    if (lista == NULL) {
        return nuevo; // Si la lista está vacía, el nuevo nodo es el primero
    }
    Nodo* aux = lista;
    while (aux->sig != NULL) {
        aux = aux->sig; // Avanza hasta el último nodo
    }
    aux->sig = nuevo; // Enlaza el nuevo nodo al final
    return lista;
}

// Crea una nueva lista enlazada con el orden invertido de la lista original
Nodo* invertirLista(Nodo* lista) {
    Nodo* invertida = NULL;
    Nodo* aux = lista;
    while (aux != NULL) {
        Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
        nuevo->dato = aux->dato;
        nuevo->sig = invertida; // Inserta al principio de la nueva lista
        invertida = nuevo;
        aux = aux->sig;
    }
    return invertida;
}

// Imprime los elementos de la lista y la cantidad de nodos
void imprimirLista(Nodo* lista) {
    int count = 0;
    Nodo* aux = lista;
    while (aux != NULL) {
        printf("%d ", aux->dato);
        count++;
        aux = aux->sig;
    }
    printf("\nCantidad de elementos: %d\n", count);
}

// Libera la memoria ocupada por todos los nodos de la lista
void liberarLista(Nodo* lista) {
    Nodo* aux;
    while (lista != NULL) {
        aux = lista;
        lista = lista->sig;
        free(aux);
    }
}

int main() {
    Nodo* lista = NULL; // Puntero a la lista original
    int num;

    // Solicita al usuario ingresar números enteros positivos
    printf("Ingrese numeros enteros positivos (0 para terminar):\n");
    do {
        scanf("%d", &num);
        // Si el número es positivo, lo agrega al final de la lista
        if (num > 0) {
            lista = insertarFinal(lista, num);
        }
    } while (num != 0); // Termina cuando se ingresa 0

    // Imprime la lista original y la cantidad de elementos
    printf("Lista original:\n");
    imprimirLista(lista);

    // Genera una nueva lista con el orden invertido
    Nodo* invertida = invertirLista(lista);
    printf("Lista invertida:\n");
    imprimirLista(invertida);

    // Libera la memoria de ambas listas
    liberarLista(lista);
    liberarLista(invertida);

    return 0;
}