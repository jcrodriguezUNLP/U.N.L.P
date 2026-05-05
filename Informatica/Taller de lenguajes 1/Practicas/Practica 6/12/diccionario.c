#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "diccionario.h"

// a. Crear
Diccionario* dic_crear() {
    Diccionario* dic = (Diccionario*)malloc(sizeof(Diccionario));
    if (dic) {
        dic->cabeza = NULL;
        dic->cantidad = 0;
    }
    return dic;
}

// c. Existe (Lo ponemos antes porque 'agregar' lo necesita)
int dic_existe(Diccionario* dic, const char* texto) {
    if (!dic) return 0;
    
    NodoPalabra* actual = dic->cabeza;
    while (actual != NULL) {
        // strcmp retorna 0 si son iguales
        if (strcmp(actual->palabra, texto) == 0) {
            return 1; // Encontrado
        }
        actual = actual->sig;
    }
    return 0; // No encontrado
}

// b. Agregar (Insertamos al principio para ser O(1) tras verificar existencia)
int dic_agregar(Diccionario* dic, const char* texto) {
    if (!dic) return 0;

    // 1. Verificar si ya existe
    if (dic_existe(dic, texto)) {
        return 0; // Ya existe, no agregamos
    }

    // 2. Crear nodo
    NodoPalabra* nuevo = (NodoPalabra*)malloc(sizeof(NodoPalabra));
    if (!nuevo) return 0; // Error memoria

    // 3. Copiar la palabra (strdup no es C estándar estricto, usamos malloc+strcpy)
    nuevo->palabra = (char*)malloc(strlen(texto) + 1); // +1 para el \0
    if (!nuevo->palabra) {
        free(nuevo);
        return 0;
    }
    strcpy(nuevo->palabra, texto);

    // 4. Insertar al inicio de la lista (LIFO)
    nuevo->sig = dic->cabeza;
    dic->cabeza = nuevo;
    dic->cantidad++;

    return 1; // Éxito
}

// d. Eliminar
int dic_eliminar(Diccionario* dic, const char* texto) {
    if (!dic || !dic->cabeza) return 0;

    NodoPalabra* actual = dic->cabeza;
    NodoPalabra* anterior = NULL;

    while (actual != NULL) {
        if (strcmp(actual->palabra, texto) == 0) {
            // Encontrado. Desconectamos el nodo.
            
            if (anterior == NULL) {
                // Es el primer nodo (cabeza)
                dic->cabeza = actual->sig;
            } else {
                // Es un nodo intermedio o final
                anterior->sig = actual->sig;
            }

            // Liberamos memoria
            free(actual->palabra); // Primero el string
            free(actual);          // Luego el nodo
            dic->cantidad--;
            return 1; // Eliminado
        }
        
        // Avanzamos
        anterior = actual;
        actual = actual->sig;
    }

    return 0; // No existía
}

// f. Guardar a archivo
int dic_guardar(Diccionario* dic, const char* nombreArchivo) {
    FILE* fp = fopen(nombreArchivo, "w"); // "w" sobrescribe
    if (!fp) return 0;

    NodoPalabra* actual = dic->cabeza;
    while (actual != NULL) {
        fprintf(fp, "%s\n", actual->palabra);
        actual = actual->sig;
    }

    fclose(fp);
    return 1;
}

// e. Cargar desde archivo
int dic_cargar(Diccionario* dic, const char* nombreArchivo) {
    FILE* fp = fopen(nombreArchivo, "r");
    if (!fp) return 0;

    char buffer[256]; // Buffer temporal para leer
    int cargados = 0;

    // Leemos palabra por palabra hasta el fin del archivo
    while (fscanf(fp, "%s", buffer) != EOF) {
        if (dic_agregar(dic, buffer)) {
            cargados++;
        }
    }

    fclose(fp);
    return cargados;
}

// g. Destruir (Liberar todo)
void dic_destruir(Diccionario* dic) {
    if (!dic) return;

    NodoPalabra* actual = dic->cabeza;
    NodoPalabra* siguiente;

    while (actual != NULL) {
        siguiente = actual->sig;
        
        free(actual->palabra); // Liberar el string
        free(actual);          // Liberar el nodo
        
        actual = siguiente;
    }

    free(dic); // Liberar la estructura principal
}

// Auxiliar para ver qué pasa
void dic_imprimir(Diccionario* dic) {
    if (!dic) return;
    printf("\n--- Contenido Diccionario (%d palabras) ---\n", dic->cantidad);
    NodoPalabra* actual = dic->cabeza;
    while (actual != NULL) {
        printf(" - %s\n", actual->palabra);
        actual = actual->sig;
    }
    printf("----------------------------------------\n");
}