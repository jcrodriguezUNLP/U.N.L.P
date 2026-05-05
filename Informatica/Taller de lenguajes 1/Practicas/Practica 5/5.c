/*
 * 5) Escriba un programa que permita a un usuario consultar si un conjunto de palabras existe o no en
 * un diccionario.
 * El usuario ingresa de a una palabra y la consulta finaliza cuando ingresa la palabra
 * "ZZZ".
 * Para cada palabra ingresada se debe informar si la misma pertenece o no al diccionario.
 * El diccionario consiste en un archivo de texto y las palabras se encuentran ordenadas en forma
 * ascendente (una por línea).
 * Se desea generar una estructura de datos dinámica (memoria RAM) en
 * la cual se almacenen las palabras de todo el diccionario.
 * Luego, verifique la pertenencia de las
 * palabras ingresadas por el usuario utilizando dicha estructura en lugar del archivo.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para strcmp
#include <stdbool.h> // Para tipo bool

#define FILENAME "diccionario.txt"
#define MAX_WORD_LEN 50
#define TOKEN_FIN "ZZZ"

// Estructura para almacenar el diccionario en memoria
typedef struct {
    char **palabras; // Array de punteros a cadenas (las palabras)
    int count;       // Cantidad de palabras
} Diccionario;

// --- MODULO DE GESTION DE MEMORIA ---

/**
 * @brief Carga todas las palabras del archivo en una estructura dinamica en RAM.
 * @return Diccionario La estructura Diccionario con las palabras cargadas.
 */
Diccionario cargar_diccionario() {
    FILE *f = fopen(FILENAME, "r");
    Diccionario dic = {NULL, 0};
    
    if (f == NULL) {
        perror("Error al abrir el diccionario");
        return dic;
    }

    // Paso 1: Contar las palabras para reservar memoria una sola vez.
    char temp_line[MAX_WORD_LEN];
    int num_palabras = 0;
    while (fgets(temp_line, MAX_WORD_LEN, f) != NULL) {
        num_palabras++;
    }
    
    // Volver al inicio del archivo para la lectura real.
    rewind(f); 
    
    if (num_palabras == 0) {
        fclose(f);
        return dic;
    }

    // Paso 2: Reservar el array de punteros (char**)
    dic.palabras = (char**)malloc(num_palabras * sizeof(char*));
    if (dic.palabras == NULL) {
        perror("Error de memoria (array de punteros)");
        fclose(f);
        return dic;
    }

    // Paso 3: Leer las palabras y reservar memoria para cada una.
    while (fgets(temp_line, MAX_WORD_LEN, f) != NULL && dic.count < num_palabras) {
        // Eliminar el salto de linea ('\n') si existe
        size_t len = strlen(temp_line);
        if (len > 0 && temp_line[len-1] == '\n') {
            temp_line[len-1] = '\0';
            len--;
        }
        
        // Reservar memoria para la palabra actual
        dic.palabras[dic.count] = (char*)malloc((len + 1) * sizeof(char));
        if (dic.palabras[dic.count] == NULL) {
            perror("Error de memoria (palabra)");
            // Si falla, se debe liberar todo lo anterior (omitido por simplicidad de ejemplo).
            break; 
        }
        
        // Copiar la palabra
        strcpy(dic.palabras[dic.count], temp_line);
        dic.count++;
    }

    fclose(f);
    printf("Diccionario cargado: %d palabras.\n", dic.count);
    return dic;
}

/**
 * @brief Libera toda la memoria reservada para el diccionario dinamico.
 */
void destruir_diccionario(Diccionario dic) {
    if (dic.palabras != NULL) {
        // 1. Liberar cada palabra individualmente
        for (int i = 0; i < dic.count; i++) {
            free(dic.palabras[i]);
        }
        // 2. Liberar el array principal de punteros
        free(dic.palabras);
        printf("Memoria del diccionario liberada.\n");
    }
}

// --- MODULO DE BUSQUEDA ---

/**
 * @brief Realiza una busqueda dicotomica (binaria) en el diccionario ordenado en RAM.
 * @return bool True si la palabra es encontrada, False en caso contrario.
 */
bool buscar_dicotomica(Diccionario dic, const char *palabra) {
    int bajo = 0;
    int alto = dic.count - 1;

    while (bajo <= alto) {
        int medio = bajo + (alto - bajo) / 2;
        int comparacion = strcmp(palabra, dic.palabras[medio]);

        if (comparacion == 0) {
            return true; // Encontrado
        } else if (comparacion > 0) {
            bajo = medio + 1; // Buscar en la mitad superior
        } else {
            alto = medio - 1; // Buscar en la mitad inferior
        }
    }
    return false; // No encontrado
}


// --- FUNCION PRINCIPAL ---

int main() {
    Diccionario diccionario;
    char palabra_consulta[MAX_WORD_LEN];
    
    // NOTA: Para probar, cree un archivo 'diccionario.txt' con palabras ordenadas (una por linea).
    // Ejemplo:
    // agua
    // casa
    // perro
    // zorro
    
    diccionario = cargar_diccionario();
    if (diccionario.count == 0) return 1;

    printf("\n--- Consulta de Palabras ---\n");
    printf("Ingrese 'ZZZ' para finalizar.\n");
    
    while (1) {
        printf("Palabra a buscar: ");
        if (fgets(palabra_consulta, MAX_WORD_LEN, stdin) == NULL) break;

        // Eliminar el salto de linea y obtener el string limpio
        size_t len = strlen(palabra_consulta);
        if (len > 0 && palabra_consulta[len-1] == '\n') {
            palabra_consulta[len-1] = '\0';
        }
        
        // Condicion de salida
        if (strcmp(palabra_consulta, TOKEN_FIN) == 0) {
            break;
        }

        // Busqueda y resultado
        if (buscar_dicotomica(diccionario, palabra_consulta)) {
            printf("-> La palabra '%s' SI pertenece al diccionario.\n", palabra_consulta);
        } else {
            printf("-> La palabra '%s' NO pertenece al diccionario.\n", palabra_consulta);
        }
    }

    destruir_diccionario(diccionario);
    return 0;
}