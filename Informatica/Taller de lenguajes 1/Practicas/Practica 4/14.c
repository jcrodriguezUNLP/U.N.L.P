// 14.  En álgebra lineal, una matriz triangular es un tipo especial de matriz cuadrada cuyos elementos por 
// encima o por debajo de su diagonal principal son cero. Una matriz cuadrada de orden n se dice que es 
// triangular inferior si es de la forma: 
 
// Escriba  un  programa  que  lea  desde  teclado  un  valor  entero  n  y  reserve  memoria  para  una  matriz 
// triangular inferior de orden  n de enteros. Como se desea ahorrar espacio de almacenamiento, no se 
// deben almacenar los elementos cuyo valor es 0, es decir, sólo se reservará memoria para los valores 
// del triángulo inferior de la matriz. Luego, inicialice la estructura con valores aleatorios entre 0 y 20 
// e imprímala en pantalla. Por último, libere la memoria reservada. 
// Nota: modularice la reserva de memoria, la inicialización, la impresión y la liberación de memoria

#include <stdio.h>
#include <stdlib.h> // Para malloc, free, rand, srand
#include <time.h>   // Para inicializar la semilla de rand

// =================================================================
// 1. MODULO DE UTILIDADES
// =================================================================

/**
 * @brief Calcula el numero total de elementos a almacenar en una matriz
 * triangular inferior de orden n.
 * Formula: n * (n + 1) / 2
 * @param n Orden de la matriz (numero de filas/columnas).
 * @return int El tamano total del arreglo lineal.
 */
int calcular_tamanio_almacenamiento(int n) {
    return n * (n + 1) / 2;
}

/**
 * @brief Obtiene el indice lineal (1D) para la posicion (i, j) de la matriz triangular.
 * Solo se llama si i >= j.
 * Formula: i * (i + 1) / 2 + j
 * @param i Fila (0-indexada).
 * @param j Columna (0-indexada).
 * @param n Orden de la matriz (no se usa directamente, pero se incluye para consistencia).
 * @return int El indice en el arreglo unidimensional.
 */
int obtener_indice_lineal(int i, int j) {
    // La suma de los elementos en las filas completas anteriores (0 hasta i-1) es i*(i+1)/2.
    // El elemento j en la fila i es el j-esimo elemento (j+1)-esimo contado desde 0.
    return (i * (i + 1) / 2) + j;
}

// =================================================================
// 2. MODULO DE RESERVA DE MEMORIA
// =================================================================

/**
 * @brief Reserva memoria dinamica para el arreglo lineal que almacena el triangulo inferior.
 * @param n Orden de la matriz.
 * @return int* Puntero al inicio del bloque de memoria contiguo, o NULL si falla.
 */
int* reservar_memoria(int n) {
    int tamanio = calcular_tamanio_almacenamiento(n);
    // Reserva un unico bloque contiguo en el Heap.
    int *arreglo = (int*)malloc(tamanio * sizeof(int));
    
    if (arreglo == NULL) {
        perror("Error: Fallo la reserva de memoria (malloc)");
    }
    return arreglo;
}

// =================================================================
// 3. MODULO DE INICIALIZACIÓN
// =================================================================

/**
 * @brief Inicializa el arreglo lineal con valores aleatorios entre 0 y 20.
 * @param matriz Puntero al arreglo lineal.
 * @param n Orden de la matriz.
 */
void inicializar_matriz_aleatoria(int *matriz, int n) {
    // Inicializar la semilla de rand una sola vez.
    srand(time(NULL)); 
    
    printf("\n--- Inicializando con valores aleatorios (0-20) ---\n");
    
    // Solo iteramos sobre las posiciones que realmente almacenamos (i >= j)
    for (int i = 0; i < n; i++) {       // Recorre filas
        for (int j = 0; j <= i; j++) {  // Recorre columnas hasta la diagonal
            int indice = obtener_indice_lineal(i, j);
            // Asigna un valor aleatorio entre 0 y 20
            matriz[indice] = rand() % 21; 
        }
    }
}

// =================================================================
// 4. MODULO DE IMPRESIÓN
// =================================================================

/**
 * @brief Imprime la matriz completa n x n, mostrando los elementos almacenados
 * y un 0 en las posiciones del triangulo superior (no almacenadas).
 * @param matriz Puntero al arreglo lineal.
 * @param n Orden de la matriz.
 */
void imprimir_matriz(int *matriz, int n) {
    printf("\n--- Matriz Triangular Inferior (%d x %d) ---\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) {
                // Si i >= j, es un elemento almacenado. Calculamos su indice y lo imprimimos.
                int indice = obtener_indice_lineal(i, j);
                printf("%5d", matriz[indice]);
            } else {
                // Si i < j, es un elemento del triangulo superior (debe ser 0).
                printf("%5d", 0);
            }
        }
        printf("\n");
    }
    printf("--------------------------------------------------\n");
}

// =================================================================
// 5. MODULO DE LIBERACION DE MEMORIA
// =================================================================

/**
 * @brief Libera el unico bloque de memoria reservada.
 * @param matriz Puntero al bloque de memoria a liberar.
 */
void liberar_memoria(int *matriz) {
    if (matriz != NULL) {
        free(matriz);
        printf("\nMemoria dinamica liberada correctamente.\n");
    }
}

// =================================================================
// FUNCION PRINCIPAL
// =================================================================

int main() {
    int n;
    int *matriz_lineal = NULL;

    // 1. Lectura de n
    printf("Ingrese el orden de la matriz cuadrada (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Error: Ingrese un numero entero positivo valido.\n");
        return 1;
    }

    // 2. Reserva de memoria
    matriz_lineal = reservar_memoria(n);
    if (matriz_lineal == NULL) {
        return 1;
    }
    
    // 3. Inicializacion
    inicializar_matriz_aleatoria(matriz_lineal, n);
    
    // 4. Impresion
    imprimir_matriz(matriz_lineal, n);

    // 5. Liberacion de memoria
    liberar_memoria(matriz_lineal);
    
    return 0;
}