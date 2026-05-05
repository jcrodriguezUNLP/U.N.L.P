// 16.  Escriba  un  programa  que  permita  conocer  todos  los  divisores  de  un  número  entero  n  leído  desde 
// teclado. Los números deben almacenarse en un arreglo unidimensional. Como se desea optimizar el 
// espacio  a  ocupar,  la  memoria  debe  reservarse  a  medida  que  se  la  va  necesitando.  Una  vez  que  se 
// almacenaron  todos  los  divisores,  imprímalos  junto  al  número  n.  Por  último,  libere  la  memoria 
// reservada.

#include <stdio.h>
#include <stdlib.h> // Para malloc, realloc, free

// =================================================================
// 1. MODULO DE GESTIÓN DINÁMICA
// =================================================================

/**
 * @brief Expande dinamicamente la memoria del arreglo usando realloc.
 * * @param arreglo Puntero doble a la direccion actual del arreglo (int**),
 * ya que la direccion puede cambiar despues de realloc.
 * @param nuevo_tam Nuevo tamaño total del arreglo.
 * @return int 0 si la reasignacion es exitosa, -1 si falla.
 */
int expandir_memoria(int **arreglo, int nuevo_tam) {
    // Intentamos reasignar el bloque. El puntero original debe pasarse por referencia.
    int *temp = (int*)realloc(*arreglo, nuevo_tam * sizeof(int));
    
    if (temp == NULL) {
        perror("Error: Fallo la reasignacion de memoria (realloc)");
        return -1;
    }
    
    // Si realloc fue exitoso, actualizamos el puntero original.
    // Usamos *arreglo (doble puntero) para modificar la variable del llamador.
    *arreglo = temp;
    return 0;
}

// =================================================================
// 2. MODULO PRINCIPAL: ENCONTRAR DIVISORES
// =================================================================

/**
 * @brief Encuentra todos los divisores de 'n' y los almacena dinamicamente.
 * * @param n Numero entero del cual se buscan los divisores.
 * @param divisores Puntero doble que contendra la direccion del arreglo final.
 * @param contador Puntero al entero que almacenara la cantidad de divisores encontrados.
 * @return int 0 si es exitoso, -1 si falla la memoria.
 */
int encontrar_divisores(int n, int **divisores, int *contador) {
    *divisores = NULL; // Inicializamos el puntero a NULL (importante para el primer realloc)
    *contador = 0;
    
    // Solo iteramos hasta n/2, ya que el divisor mas grande (excluyendo n) es n/2.
    // Luego agregaremos 'n' al final.
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            // El contador es el NUEVO tamaño del arreglo (crece de 1 en 1).
            (*contador)++;
            
            // Reasignamos memoria para el nuevo elemento
            if (expandir_memoria(divisores, *contador) == -1) {
                return -1; // Falla de realloc
            }
            
            // Almacenamos el nuevo divisor en la ultima posicion
            (*divisores)[(*contador) - 1] = i;
        }
    }
    
    // Si n > 0, agregamos el propio 'n' como divisor
    if (n > 0) {
        (*contador)++;
        if (expandir_memoria(divisores, *contador) == -1) {
            return -1;
        }
        (*divisores)[(*contador) - 1] = n;
    }

    return 0;
}

// =================================================================
// 3. MODULO DE IMPRESIÓN
// =================================================================

/**
 * @brief Imprime el numero original y todos sus divisores almacenados.
 */
void imprimir_resultados(int n, int *divisores, int contador) {
    if (divisores == NULL || contador == 0) {
        printf("El numero %d no tiene divisores (o es 0/negativo).\n", n);
        return;
    }
    
    printf("\n--- RESULTADOS ---\n");
    printf("Numero original (n): %d\n", n);
    printf("Total de divisores encontrados: %d\n", contador);
    printf("Divisores: ");
    
    for (int i = 0; i < contador; i++) {
        printf("%d", divisores[i]);
        if (i < contador - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

// =================================================================
// 4. MODULO DE LIBERACIÓN DE MEMORIA
// =================================================================

/**
 * @brief Libera la memoria reservada dinamicamente.
 */
void liberar_memoria(int *divisores) {
    if (divisores != NULL) {
        free(divisores);
        printf("\nMemoria dinamica liberada correctamente.\n");
    }
}

// =================================================================
// FUNCIÓN PRINCIPAL
// =================================================================

int main() {
    int n;
    int *divisores = NULL; // Puntero al arreglo de divisores
    int contador = 0;       // Contador de divisores (tamaño actual del arreglo)

    // 1. Lectura de n
    printf("Ingrese un numero entero positivo (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Error: Ingrese un numero entero positivo valido.\n");
        return 1;
    }

    // 2. Encontrar y almacenar divisores (con realloc)
    if (encontrar_divisores(n, &divisores, &contador) == -1) {
        // Si encontrar_divisores falla, libera lo que pudo reservar antes de salir.
        liberar_memoria(divisores);
        return 1;
    }
    
    // 3. Imprimir resultados
    imprimir_resultados(n, divisores, contador);

    // 4. Liberar memoria
    liberar_memoria(divisores);
    
    return 0;
}