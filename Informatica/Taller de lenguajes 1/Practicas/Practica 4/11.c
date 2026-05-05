// 11.  Escriba  un  programa  que  lea  desde  teclado  dos  valores  enteros  n  y  m,  y  luego  reserve  memoria  en 
// forma dinámica para una matriz de enteros de n filas por m columnas. Inicialice la matriz creada con 
// valores ingresados por teclado. Una vez inicializada, imprima las posiciones de todos aquellos valores 
// múltiplos de 3. Por último, libere la memoria reservada. 
// Nota: modularice la reserva de memoria, la inicialización, la impresión de las posiciones con valores 
// múltiplo de 3 y la liberación de memoria.

#include <stdio.h>
#include <stdlib.h> // Para malloc y free

// =================================================================
// 1. MODULO DE RESERVA DE MEMORIA
// =================================================================

/**
 * @brief Reserva memoria dinamica para una matriz de n filas por m columnas.
 * Utiliza un arreglo de punteros (int**) para la matriz.
 * @param n Numero de filas.
 * @param m Numero de columnas.
 * @return int** Puntero al arreglo de punteros (la matriz), o NULL si falla.
 */
int** reservar_matriz(int n, int m) {
    // 1. Reserva memoria para el arreglo de punteros (las 'n' filas)
    int **matriz = (int**)malloc(n * sizeof(int*));
    if (matriz == NULL) {
        perror("Error: Fallo al reservar las filas");
        return NULL;
    }

    // 2. Reserva memoria para cada columna (m)
    for (int i = 0; i < n; i++) {
        matriz[i] = (int*)malloc(m * sizeof(int));
        if (matriz[i] == NULL) {
            perror("Error: Fallo al reservar una columna");
            // Si falla una columna, liberamos todo lo reservado hasta ahora
            for (int j = 0; j < i; j++) {
                free(matriz[j]);
            }
            free(matriz);
            return NULL;
        }
    }
    return matriz;
}

// =================================================================
// 2. MODULO DE INICIALIZACIÓN (LECTURA DE DATOS)
// =================================================================

/**
 * @brief Lee valores desde teclado e inicializa la matriz dinamica.
 * @param matriz Puntero a la matriz.
 * @param n Numero de filas.
 * @param m Numero de columnas.
 */
void inicializar_matriz(int **matriz, int n, int m) {
    printf("\n--- INGRESO DE DATOS ---\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Ingrese valor para la posicion [%d][%d]: ", i, j);
            if (scanf("%d", &matriz[i][j]) != 1) {
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
 * @brief Imprime las posiciones (i, j) donde el valor es multiplo de 3.
 * @param matriz Puntero a la matriz.
 * @param n Numero de filas.
 * @param m Numero de columnas.
 */
void imprimir_multiplos_de_tres(int **matriz, int n, int m) {
    printf("\n--- POSICIONES DE VALORES MULTIPLOS DE 3 ---\n");
    int encontrado = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matriz[i][j] % 3 == 0) {
                printf("Valor %d encontrado en posicion [%d][%d]\n", matriz[i][j], i, j);
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
 * @brief Libera la memoria reservada para la matriz dinamica.
 * @param matriz Puntero a la matriz.
 * @param n Numero de filas (necesario para iterar y liberar columnas).
 */
void liberar_matriz(int **matriz, int n) {
    if (matriz != NULL) {
        // 1. Liberar cada columna (los bloques de int*)
        for (int i = 0; i < n; i++) {
            if (matriz[i] != NULL) {
                free(matriz[i]);
            }
        }
        // 2. Liberar el arreglo de punteros (el bloque principal int**)
        free(matriz);
        printf("\nMemoria dinamica de la matriz liberada correctamente.\n");
    }
}

// =================================================================
// FUNCION PRINCIPAL
// =================================================================

int main() {
    int n, m;
    int **matriz = NULL;

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

    // 2. Reserva de memoria
    matriz = reservar_matriz(n, m);
    if (matriz == NULL) {
        return 1; // Termina si la reserva falla
    }
    
    // 3. Inicializacion
    inicializar_matriz(matriz, n, m);
    
    // 4. Impresion de resultados
    imprimir_multiplos_de_tres(matriz, n, m);

    // 5. Liberacion de memoria
    liberar_matriz(matriz, n);
    
    return 0;
}