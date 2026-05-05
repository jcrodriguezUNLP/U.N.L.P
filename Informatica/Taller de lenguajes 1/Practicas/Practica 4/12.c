// 12.  Rehaga el ejercicio anterior utilizando un arreglo unidimensional en lugar de uno bidimensional.

#include <stdio.h>
#include <stdlib.h> // Para malloc y free

// =================================================================
// 1. MODULO DE RESERVA DE MEMORIA
// =================================================================

/**
 * @brief Reserva memoria dinamica para una matriz logica de n x m, usando
 * un arreglo unidimensional contiguo de n*m elementos.
 * @param n Numero de filas.
 * @param m Numero de columnas.
 * @return int* Puntero al inicio del bloque de memoria contiguo, o NULL si falla.
 */
int* reservar_matriz_lineal(int n, int m) {
    // n * m es el numero total de elementos.
    int total_elementos = n * m;
    int *matriz_lineal = (int*)malloc(total_elementos * sizeof(int));
    
    if (matriz_lineal == NULL) {
        perror("Error: Fallo al reservar memoria para el bloque contiguo");
    }
    return matriz_lineal;
}

// =================================================================
// 2. MODULO DE INICIALIZACIÓN (LECTURA DE DATOS)
// =================================================================

/**
 * @brief Lee valores desde teclado e inicializa el arreglo unidimensional.
 * Utiliza la formula de mapeo de indices.
 * @param matriz Puntero al arreglo lineal.
 * @param n Numero de filas.
 * @param m Numero de columnas.
 */
void inicializar_matriz_lineal(int *matriz, int n, int m) {
    printf("\n--- INGRESO DE DATOS ---\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Mapeo de indices: i * m + j
            int indice_lineal = i * m + j;
            
            printf("Ingrese valor para la posicion [%d][%d]: ", i, j);
            if (scanf("%d", &matriz[indice_lineal]) != 1) {
                printf("Error en la lectura del dato. Saliendo.\n");
                exit(1);
            }
        }
    }
}

// =================================================================
// 3. MODULO DE IMPRESIÓN (MÚLTIPLOS DE 3)
// =================================================================

/**
 * @brief Imprime las posiciones (i, j) donde el valor es multiplo de 3,
 * accediendo al arreglo con notacion lineal.
 * @param matriz Puntero al arreglo lineal.
 * @param n Numero de filas.
 * @param m Numero de columnas.
 */
void imprimir_multiplos_de_tres_lineal(int *matriz, int n, int m) {
    printf("\n--- POSICIONES DE VALORES MULTIPLOS DE 3 ---\n");
    int encontrado = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Mapeo de indices: i * m + j
            int indice_lineal = i * m + j; 
            
            // Acceso: matriz[indice_lineal]
            if (matriz[indice_lineal] % 3 == 0) {
                printf("Valor %d encontrado en posicion [%d][%d]\n", matriz[indice_lineal], i, j);
                encontrado = 1;
            }
        }
    }
    
    if (!encontrado) {
        printf("No se encontraron multiplos de 3 en la matriz.\n");
    }
}

// =================================================================
// 4. MODULO DE LIBERACION DE MEMORIA
// =================================================================

/**
 * @brief Libera la memoria reservada para el unico bloque dinamico.
 * @param matriz Puntero al bloque de memoria a liberar.
 */
void liberar_memoria_lineal(int *matriz) {
    if (matriz != NULL) {
        free(matriz);
        printf("\nMemoria dinamica del bloque contiguo liberada correctamente.\n");
    }
}

// =================================================================
// FUNCION PRINCIPAL
// =================================================================

int main() {
    int n, m;
    int *matriz_lineal = NULL;

    // 1. Lectura de n y m
    printf("Ingrese el numero de filas (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Error: Ingrese un numero de fila valido.\n");
        return 1;
    }
    
    printf("Ingrese el numero de columnas (m): ");
    if (scanf("%d", &m) != 1 || m <= 0) {
        printf("Error: Ingrese un numero de columna valido.\n");
        return 1;
    }

    // 2. Reserva de memoria (un solo malloc)
    matriz_lineal = reservar_matriz_lineal(n, m);
    if (matriz_lineal == NULL) {
        return 1;
    }
    
    // 3. Inicializacion
    inicializar_matriz_lineal(matriz_lineal, n, m);
    
    // 4. Impresion de resultados
    imprimir_multiplos_de_tres_lineal(matriz_lineal, n, m);

    // 5. Liberacion de memoria (un solo free)
    liberar_memoria_lineal(matriz_lineal);
    
    return 0;
}