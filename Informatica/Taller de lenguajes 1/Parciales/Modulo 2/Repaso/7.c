/*
 * 7. (1.5 puntos) En álgebra lineal, una matriz triangular es un tipo especial de matriz cuadrada cuyos elementos por encima o por debajo de su diagonal principal son cero. Una matriz cuadrada de orden n se dice que es triangular inferior si es de la forma:
 * [Se muestra la forma de la matriz triangular inferior L]
 * Escriba un programa que lea desde teclado un valor entero n y reserve memoria para una matriz triangular inferior de orden n de enteros. 
 * Como se desea ahorrar espacio de almacenamiento, no se deben almacenar los elementos cuyo valor es 0, es decir, sólo se reservará memoria para los valores del triángulo inferior de la matriz. 
 * Luego, inicialice la estructura con valores aleatorios entre 0 y 20 e imprímala en pantalla. Por último, libere la memoria reservada. 
 * Nota: modularice la reserva de memoria, la inicialización, la impresión y la liberación de memoria.
 * * --- SOLUCION ---
 * Se utiliza un arreglo unidimensional contiguo para ahorrar espacio. La clave es la formula 
 * de mapeo para el indice (i, j) donde i >= j: indice = i * (i + 1) / 2 + j
 */

#include <stdio.h>
#include <stdlib.h> // Para malloc, free, rand, srand
#include <time.h>   // Para inicializar la semilla de rand

// --- MODULO DE UTILIDADES ---

/**
 * @brief Obtiene el indice lineal (1D) para la posicion (i, j) de la matriz triangular.
 * Formula: i * (i + 1) / 2 + j (solo valido si i >= j)
 */
int obtener_indice_lineal(int i, int j) {
    // La suma de los elementos en las filas completas anteriores + j
    return (i * (i + 1) / 2) + j; 
}

// --- MODULO DE RESERVA DE MEMORIA ---

/**
 * @brief Reserva memoria dinamica para el arreglo lineal que almacena el triangulo inferior.
 * @param n Orden de la matriz.
 * @return int* Puntero al bloque de memoria contiguo.
 */
int* reservar_memoria(int n) {
    // Calculo del tamano optimizado: n * (n + 1) / 2
    int tamanio = n * (n + 1) / 2;
    int *arreglo = (int*)malloc(tamanio * sizeof(int));
    
    if (arreglo == NULL) {
        perror("Error: Fallo la reserva de memoria");
    }
    return arreglo;
}

// --- MODULO DE INICIALIZACIÓN ---

/**
 * @brief Inicializa el arreglo lineal con valores aleatorios entre 0 y 20.
 */
void inicializar_matriz_aleatoria(int *matriz, int n) {
    srand(time(NULL)); 
    
    for (int i = 0; i < n; i++) {       
        for (int j = 0; j <= i; j++) {  
            int indice = obtener_indice_lineal(i, j);
            matriz[indice] = rand() % 21; // Aleatorio entre 0 y 20
        }
    }
    printf("\nInicializacion con valores aleatorios completa.\n");
}

// --- MODULO DE IMPRESIÓN ---

/**
 * @brief Imprime la matriz completa n x n, mostrando los elementos almacenados
 * y un 0 en las posiciones no almacenadas.
 */
void imprimir_matriz(int *matriz, int n) {
    printf("\n--- Matriz Triangular Inferior (%d x %d) ---\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) {
                // Elemento almacenado
                int indice = obtener_indice_lineal(i, j);
                printf("%5d", matriz[indice]);
            } else {
                // Elemento no almacenado (Triangulo superior)
                printf("%5d", 0);
            }
        }
        printf("\n");
    }
}

// --- MODULO DE LIBERACIÓN DE MEMORIA ---

/**
 * @brief Libera el unico bloque de memoria reservada.
 */
void liberar_memoria(int *matriz) {
    if (matriz != NULL) {
        free(matriz);
        printf("\nMemoria dinamica liberada correctamente.\n");
    }
}

// --- FUNCION PRINCIPAL ---

int main() {
    int n;
    int *matriz_lineal = NULL;

    printf("Ingrese el orden de la matriz cuadrada (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Error: Ingrese un numero entero positivo valido.\n");
        return 1;
    }

    // 1. Reserva de memoria
    matriz_lineal = reservar_memoria(n);
    if (matriz_lineal == NULL) {
        return 1;
    }
    
    // 2. Inicializacion
    inicializar_matriz_aleatoria(matriz_lineal, n);
    
    // 3. Impresion
    imprimir_matriz(matriz_lineal, n);

    // 4. Liberacion de memoria
    liberar_memoria(matriz_lineal);
    
    return 0;
}