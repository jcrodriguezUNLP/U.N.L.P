// 13.  Dado el siguiente código: 
 
// int x=2, y=3; 
// int * m= (int*) malloc(x*y*sizeof(int)); 
 
// a. ¿Qué estructura/s se puede/n modelar con la variable m? 
// b. ¿Se puede utilizar a m como si fuera una matriz, simulando el acceso por filas y columnas? En ese 
// caso, ¿cómo se podría acceder a sus elementos? 
// c. Escriba un programa que trabaje con una matriz de enteros utilizando las declaraciones 
// anteriores  sin  importar  el  orden  de  acceso  a  cada  dimensión  (fila  y  columna  o  columna  y  fila). 
// Cargue  a  m  con  valores  leídos  desde  teclado  y  luego  imprima  sus  valores  en  pantalla  para 
// verificar que se cargó correctamente. Por último, libere la memoria reservada

#include <stdio.h>
#include <stdlib.h> // Necesario para malloc y free

int main() {
    int x = 2; // Número de filas (Fila)
    int y = 3; // Número de columnas (Columna)
    
    // Declaración anterior: Reserva un bloque contiguo para 2 * 3 = 6 enteros
    int *m = (int *)malloc( (x * y) * sizeof(int));

    if (m == NULL) {
        printf("Error: Fallo la reserva de memoria.\n");
        return 1;
    }

    printf("--- Carga de Matriz 2x3 (Acceso [Fila][Columna]) ---\n");
    // La fórmula de mapeo es: indice = Fila * Num_Columnas + Columna (i * y + j)
    for (int i = 0; i < x; i++) {       // i: Filas (0 a 1)
        for (int j = 0; j < y; j++) {   // j: Columnas (0 a 2)
            int indice = i * y + j;
            printf("Ingrese valor para m[%d][%d]: ", i, j);
            if (scanf("%d", &m[indice]) != 1) {
                printf("Error de lectura.\n");
                free(m);
                return 1;
            }
        }
    }
    
    // --- Verificación 1: Imprimir en orden FILA-COLUMNA (i, j) ---
    printf("\n--- Impresion (Orden Fila-Columna) ---\n");
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            int indice = i * y + j;
            printf("m[%d][%d] = %d\t", i, j, m[indice]);
        }
        printf("\n");
    }

    // --- Verificación 2: Imprimir en orden COLUMNA-FILA (j, i) ---
    // Esto demuestra que la matriz está cargada correctamente sin importar
    // el orden en que se acceda a la memoria.
    printf("\n--- Impresion (Orden Columna-Fila) ---\n");
    for (int j = 0; j < y; j++) {       // j: Columna externa (0 a 2)
        for (int i = 0; i < x; i++) {   // i: Fila interna (0 a 1)
            int indice = i * y + j;     // Se sigue usando la formula i*y + j
            printf("m[%d][%d] = %d\t", i, j, m[indice]);
        }
        printf("\n");
    }

    // Liberación de memoria reservada
    free(m);
    printf("\nMemoria liberada correctamente.\n");
    
    return 0;
}