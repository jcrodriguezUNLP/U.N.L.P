// 10.  Escriba un programa que lea un número entero  n  y luego reserve memoria en forma dinámica para 
// un arreglo de n elementos double. Inicialice las posiciones del arreglo a partir de valores ingresados 
// por teclado y a continuación imprima el promedio de todos ellos. 
// a. Empleando notación de arreglos. 
// b. Empleando notación de punteros. 
 
// Por último, libere la memoria reservada. 
// Nota: modularice la reserva de  memoria, la inicialización, el cálculo del promedio y la liberación de 
// memoria.

#include <stdio.h>
#include <stdlib.h> // Para malloc y free

// =================================================================
// 1. MODULO DE RESERVA DE MEMORIA
// =================================================================

/**
 * @brief Reserva memoria dinamica para un arreglo de 'n' elementos double.
 * * @param n Cantidad de elementos a reservar.
 * @return double* Puntero al inicio del bloque de memoria reservado, o NULL si falla.
 */
double* reservar_memoria(int n) {
    // Calcula el tamaño total en bytes y reserva el bloque en el heap.
    double *arreglo = (double*)malloc(n * sizeof(double));
    
    if (arreglo == NULL) {
        perror("Error: Fallo la reserva de memoria (malloc)");
        // No retorna, simplemente imprime el error y la funcion continua
    }
    return arreglo;
}

// =================================================================
// 2. MODULO DE INICIALIZACIÓN (LECTURA DE DATOS)
// =================================================================

/**
 * @brief Lee los valores desde teclado e inicializa el arreglo.
 * * @param arreglo Puntero al arreglo de doubles.
 * @param n Cantidad de elementos del arreglo.
 */
void inicializar_arreglo(double *arreglo, int n) {
    printf("\n--- INGRESO DE DATOS ---\n");
    for (int i = 0; i < n; i++) {
        printf("Ingrese el valor para la posicion [%d]: ", i);
        // Usa notacion de arreglos (la más natural para la lectura)
        if (scanf("%lf", &arreglo[i]) != 1) { 
            printf("Error en la lectura del dato. Saliendo.\n");
            exit(1);
        }
    }
}

// =================================================================
// 3. MODULO DE CALCULO DEL PROMEDIO
// =================================================================

/**
 * @brief Calcula el promedio de los elementos del arreglo usando notacion de arreglos.
 * * @param arreglo Puntero al arreglo de doubles.
 * @param n Cantidad de elementos.
 * @return double El promedio calculado.
 */
double calcular_promedio_arreglo(double *arreglo, int n) {
    double suma = 0.0;
    
    // a. Empleando notación de arreglos (arreglo[i])
    for (int i = 0; i < n; i++) {
        suma += arreglo[i];
    }
    return (n > 0) ? (suma / n) : 0.0;
}

/**
 * @brief Calcula el promedio de los elementos del arreglo usando notacion de punteros.
 * * @param arreglo Puntero al arreglo de doubles.
 * @param n Cantidad de elementos.
 * @return double El promedio calculado.
 */
double calcular_promedio_punteros(double *arreglo, int n) {
    double suma = 0.0;
    
    // b. Empleando notación de punteros (*(arreglo + i))
    for (int i = 0; i < n; i++) {
        // *(arreglo + i) es el valor en la posicion i. 
        // Equivale a arreglo[i].
        suma += *(arreglo + i);
    }
    return (n > 0) ? (suma / n) : 0.0;
}


// =================================================================
// 4. MODULO DE LIBERACION DE MEMORIA
// =================================================================

/**
 * @brief Libera la memoria reservada dinamicamente.
 * * @param arreglo Puntero al inicio del bloque de memoria a liberar.
 */
void liberar_memoria(double *arreglo) {
    if (arreglo != NULL) {
        free(arreglo);
        printf("\nMemoria dinamica liberada correctamente.\n");
    }
}

// =================================================================
// FUNCION PRINCIPAL
// =================================================================

int main() {
    int n;
    double *datos = NULL;

    // 1. Lectura de n
    printf("Ingrese la cantidad de elementos (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Error: Ingrese un numero entero positivo valido.\n");
        return 1;
    }

    // 2. Reserva de memoria
    datos = reservar_memoria(n);
    if (datos == NULL) {
        return 1; // Termina si la reserva falla
    }
    
    // 3. Inicializacion
    inicializar_arreglo(datos, n);
    
    // 4. Calculo e impresion del promedio
    double promedio_arr = calcular_promedio_arreglo(datos, n);
    double promedio_ptr = calcular_promedio_punteros(datos, n);

    printf("\n--- RESULTADOS DEL PROMEDIO ---\n");
    printf("a. Promedio (Notacion de Arreglos): %.2f\n", promedio_arr);
    printf("b. Promedio (Notacion de Punteros): %.2f\n", promedio_ptr);

    // 5. Liberacion de memoria
    liberar_memoria(datos);
    
    return 0;
}