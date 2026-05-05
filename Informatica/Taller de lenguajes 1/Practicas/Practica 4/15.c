// 15.  Escriba  un  programa  que,  dado  un  número  entero  n  ingresado  por 
// teclado,  construya  una  pirámide  de  pascal  de  n  filas.  Un  triángulo  de 
// pascal  es  una  serie  de  filas  apiladas  que  comienza  con  un  elemento  y 
// agrega  un  elemento  más  en  cada  fila.  El  primer  y último  elemento  de 
// cada  fila  es  un  1.  Los  demás  elementos  se  calculan  sumando  los  2 
// números  superiores  de  la  fila  anterior.  Por  ejemplo,  para  obtener  el 
// segundo  elemento  de  la  cuarta  fila  (4)  deben  sumarse  el  primer  (1)  y 
// segundo (3) elemento de la tercera fila de forma que 1+3 = 4. Tenga en 
// cuenta las siguientes condiciones: 
// a) Utilizar una estructura de datos eficiente. Contemple la información necesaria para recorrer 
// la pirámide y liberar la memoria de forma correcta. 
// b) Implemente una función que dado un entero n retorne una pirámide de pascal de n filas. 
// c) Implemente una función para imprimir la pirámide. 
// d) Implemente una función para destruir la pirámide.

#include <stdio.h>
#include <stdlib.h> // Para malloc, free

// =================================================================
// 1. MODULO DE CONSTRUCCIÓN (RESERVA Y CÁLCULO)
// =================================================================

/**
 * @brief Construye y calcula una piramide de Pascal de 'n' filas.
 * * Utiliza una matriz irregular (int**) donde cada fila se reserva individualmente.
 * * @param n Numero de filas de la piramide.
 * @return int** Puntero a la piramide de Pascal, o NULL si falla la memoria.
 */
int** construir_pascal(int n) {
    if (n <= 0) {
        return NULL;
    }

    // 1. Reserva el arreglo de punteros (las 'n' filas).
    int **piramide = (int**)malloc(n * sizeof(int*));
    if (piramide == NULL) {
        perror("Error al reservar el arreglo de filas");
        return NULL;
    }

    // 2. Itera sobre cada fila para calcular y reservar memoria.
    for (int i = 0; i < n; i++) {
        // La fila 'i' tiene 'i + 1' elementos.
        int num_elementos = i + 1;
        
        // Reserva memoria para los elementos de la fila actual.
        piramide[i] = (int*)malloc(num_elementos * sizeof(int));
        
        if (piramide[i] == NULL) {
            perror("Error al reservar memoria para una fila");
            // Si falla, liberamos lo que se haya reservado hasta ahora.
            for (int j = 0; j < i; j++) {
                free(piramide[j]);
            }
            free(piramide);
            return NULL;
        }

        // CÁLCULO DE LA FILA:
        for (int j = 0; j < num_elementos; j++) {
            if (j == 0 || j == num_elementos - 1) {
                // El primer y ultimo elemento de cada fila es 1.
                piramide[i][j] = 1;
            } else {
                // Los demas elementos son la suma de los dos superiores de la fila anterior.
                // Elemento superior izquierdo: piramide[i-1][j-1]
                // Elemento superior derecho: piramide[i-1][j]
                piramide[i][j] = piramide[i-1][j-1] + piramide[i-1][j];
            }
        }
    }
    return piramide;
}

// =================================================================
// 2. MODULO DE IMPRESIÓN
// =================================================================

/**
 * @brief Imprime la piramide de Pascal en pantalla.
 * * @param piramide Puntero a la piramide.
 * @param n Numero de filas.
 */
void imprimir_piramide(int **piramide, int n) {
    if (piramide == NULL || n <= 0) {
        printf("Piramide vacia o invalida.\n");
        return;
    }

    printf("\n--- Triangulo de Pascal de %d filas ---\n", n);

    for (int i = 0; i < n; i++) {
        // Imprimir espacios para centrar la piramide (opcional)
        for (int k = 0; k < n - 1 - i; k++) {
            printf("  ");
        }

        // Imprimir los elementos de la fila
        int num_elementos = i + 1;
        for (int j = 0; j < num_elementos; j++) {
            printf("%4d", piramide[i][j]);
        }
        printf("\n");
    }
}

// =================================================================
// 3. MODULO DE DESTRUCCIÓN (LIBERACIÓN DE MEMORIA)
// =================================================================

/**
 * @brief Libera la memoria reservada para la piramide de Pascal.
 * * Debe liberar primero cada fila individual y luego el arreglo de punteros.
 * * @param piramide Puntero a la piramide.
 * @param n Numero de filas.
 */
void destruir_piramide(int **piramide, int n) {
    if (piramide != NULL) {
        // 1. Liberar cada bloque de fila (memoria reservada en el bucle interno)
        for (int i = 0; i < n; i++) {
            if (piramide[i] != NULL) {
                free(piramide[i]);
            }
        }
        // 2. Liberar el arreglo principal de punteros (memoria reservada primero)
        free(piramide);
        printf("\nMemoria dinamica de la piramide liberada correctamente.\n");
    }
}

// =================================================================
// FUNCION PRINCIPAL
// =================================================================

int main() {
    int n;
    int **piramide = NULL;

    // 1. Lectura de n
    printf("Ingrese el numero de filas (n) para el Triangulo de Pascal: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Error: Ingrese un numero entero positivo valido.\n");
        return 1;
    }

    // 2. Construccion de la piramide (Punto b)
    piramide = construir_pascal(n);
    if (piramide == NULL) {
        return 1; // Error ya reportado por la funcion
    }
    
    // 3. Impresion (Punto c)
    imprimir_piramide(piramide, n);

    // 4. Destruccion (Punto d)
    destruir_piramide(piramide, n);
    
    return 0;
}