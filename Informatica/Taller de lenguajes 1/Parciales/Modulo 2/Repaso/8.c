/*
 * 8. (1 punto) Dada una lista enlazada de enteros y su definición de tipo:
 * typedef struct nodo {
 * int dato;
 * struct nodo * siguiente;
 * } lista;
 * a) Implemente una función con el código necesario para quitar y liberar un nodo de la lista.
 * b) Utilice la función definida en a) para liberar los nodos que componen la lista comenzando por el final y terminando con el que está ubicado al inicio de la lista.
 * * --- SOLUCION ---
 * La liberacion inversa (b) es O(n^2) en una lista simple, pero cumple el requisito funcional. 
 * La funcion quitar_y_liberar_nodo (a) maneja la re-conexión de los punteros.
 */

#include <stdio.h>
#include <stdlib.h>

// Definición de tipo de lista enlazada
typedef struct nodo {
    int dato;
    struct nodo *siguiente; 
} lista;

// --- IMPLEMENTACIÓN DEL PUNTO A) QUITAR Y LIBERAR UN NODO ---

/**
 * @brief Busca el nodo anterior al nodo_a_eliminar.
 */
lista* buscar_anterior(lista *cabeza, lista *nodo_a_eliminar) {
    if (cabeza == nodo_a_eliminar) {
        return NULL; // El nodo a eliminar es la cabeza.
    }
    lista *actual = cabeza;
    while (actual != NULL && actual->siguiente != nodo_a_eliminar) {
        actual = actual->siguiente;
    }
    return actual;
}

/**
 * @brief Quita y libera un nodo de la lista.
 * @param cabeza Puntero doble a la cabeza (para modificar la cabeza si es necesario).
 * @param nodo_a_eliminar Puntero al nodo que se desea eliminar.
 * @return int 1 si el nodo fue liberado, 0 si no fue encontrado.
 */
int quitar_y_liberar_nodo(lista **cabeza, lista *nodo_a_eliminar) {
    if (*cabeza == NULL || nodo_a_eliminar == NULL) return 0;
    
    lista *anterior = buscar_anterior(*cabeza, nodo_a_eliminar);
    
    if (anterior == NULL) {
        // Caso 1: El nodo a eliminar es la cabeza.
        if (*cabeza == nodo_a_eliminar) {
            *cabeza = nodo_a_eliminar->siguiente; 
            free(nodo_a_eliminar);
            return 1;
        } else {
            return 0;
        }
    } else {
        // Caso 2: El nodo a eliminar esta en el medio o al final.
        anterior->siguiente = nodo_a_eliminar->siguiente; 
        free(nodo_a_eliminar);
        return 1;
    }
}

// --- IMPLEMENTACIÓN DEL PUNTO B) LIBERACIÓN INVERSA ---

/**
 * @brief Libera los nodos comenzando por el final y terminando por el inicio.
 * @param cabeza Puntero doble a la cabeza.
 */
void liberar_inversamente(lista **cabeza) {
    printf("\n--- Liberacion Inversa (Final a Inicio) ---\n");
    
    while (*cabeza != NULL) {
        lista *actual = *cabeza;
        lista *ultimo = NULL;
        
        // 1. Encontrar el ULTIMO nodo (O(n) busqueda en cada iteracion)
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        ultimo = actual; 
        
        // 2. Quitar y liberar el ULTIMO nodo.
        printf("Liberando nodo: %d\n", ultimo->dato);
        quitar_y_liberar_nodo(cabeza, ultimo); 
    }
    printf("Lista completamente liberada.\n");
}

// --- FUNCIONES AUXILIARES DE PRUEBA ---
void insertar_al_final(lista **cabeza, int dato) {
    lista *nuevo = (lista*)malloc(sizeof(lista));
    if (nuevo == NULL) return;
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    
    if (*cabeza == NULL) {
        *cabeza = nuevo;
    } else {
        lista *actual = *cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
}

void imprimir_lista(lista *cabeza) {
    printf("Lista: ");
    lista *actual = cabeza;
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}


// --- FUNCIÓN PRINCIPAL ---
int main() {
    lista *mi_lista = NULL; 

    // Construir lista de ejemplo: 10 -> 20 -> 30 -> 40
    insertar_al_final(&mi_lista, 10); 
    insertar_al_final(&mi_lista, 20); 
    insertar_al_final(&mi_lista, 30); 
    insertar_al_final(&mi_lista, 40); 

    printf("Estado inicial de la lista:\n");
    imprimir_lista(mi_lista);
    
    // b) Liberar la lista comenzando por el final.
    liberar_inversamente(&mi_lista); 
    
    return 0;
}