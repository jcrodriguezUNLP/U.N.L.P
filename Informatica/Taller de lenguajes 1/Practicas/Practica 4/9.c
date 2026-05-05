// Indique para cada arreglo definido: 
// a. ¿Qué tipo de arreglo se está utilizando (estático/dinámico/de longitud variable)? 
// b. ¿En qué momento se determina cuánta memoria se va a reservar (compilación/ejecución)? 
// c. ¿Cuál es el límite de tamaño de cada tipo de arreglo? 
// d. ¿Se puede cambiar el tamaño en ejecución? 
// e. ¿Se puede liberar la memoria reservada? 
// f. ¿El nombre del arreglo puede apuntar a otra dirección? 
// g. ¿Todos los códigos compilan de acuerdo a ANSI C90?

// Código 1:

#include <stdio.h> 
#include <stdlib.h> 

#define N 50 

int main() { 
    int arreglo1[N]; 
    return 0; 
}


// Código 2:

#include <stdio.h> 
#include <stdlib.h> 
 
int main() { 
    int n; 
    scanf("%d",&n);  
    /* el usuario ingresa 50 */ 
    int arreglo2[n]; 
    return 0; 
} 


// Código 3:  

#include <stdio.h> 
#include <stdlib.h> 

#define N 50 
 
int main() { 
    int* arreglo3 = (int*) malloc( N* sizeof(int) ) ; 
    
    return 0; 
} 


#include <stdio.h> 
#include <stdlib.h> // Necesario para malloc/free
#define N 50        // Constante definida en preprocesador

/*
 * ====================================================================
 * ANALISIS DE ARREGLOS EN C
 * ====================================================================
 */

int main() { 
    // Variable para la demostración del Código 2
    int n = 50; 
    
    // --- CÓDIGO 1: int arreglo1[N]; ---
    printf("\n--- ANALISIS DE ARREGLO 1 (int arreglo1[N]) ---\n");
    
    int arreglo1[N]; 
    
    /*
     * a. Tipo de arreglo: Estático. El tamaño es fijo antes de la compilación (por #define).
     * b. Momento de reserva: Compilación (o al inicio de la ejecucion, en el stack).
     * c. Límite de tamaño: Stack (Pila). Límite relativamente pequeño.
     * d. Cambiar tamaño en ejecución: No.
     * e. Liberar memoria: No (se libera automáticamente al salir de main).
     * f. Nombre apunta a otra dirección: No (arreglo1 es un alias de la dirección base, constante).
     * g. Compila en ANSI C90: Sí.
     */
    printf("1. Arreglo Estatico: Tamano fijo en compilacion (Stack).\n");
    
    // --- CÓDIGO 2: int arreglo2[n]; ---
    printf("\n--- ANALISIS DE ARREGLO 2 (int arreglo2[n]) ---\n");
    
    // Simulación de lectura de n (en este caso n=50)
    // scanf("%d",&n); 
    
    int arreglo2[n]; 
    
    /*
     * a. Tipo de arreglo: De Longitud Variable (VLA - Variable Length Array).
     * b. Momento de reserva: Ejecución (el tamaño 'n' es una variable). Se reserva en el Stack.
     * c. Límite de tamaño: Stack (Pila). Límite relativamente pequeño.
     * d. Cambiar tamaño en ejecución: No (el tamaño se fija cuando se declara).
     * e. Liberar memoria: No (se libera automáticamente al salir de main).
     * f. Nombre apunta a otra dirección: No (arreglo2 es un alias de la dirección base, constante).
     * g. Compila en ANSI C90: No (Requiere el estandar C99 o posterior).
     */
    printf("2. Arreglo VLA: Tamano variable en ejecucion (Stack).\n");
    printf("   NOTA: Solo compila en C99 o posteriores.\n");

    // --- CÓDIGO 3: int *arreglo3 = malloc(...) ---
    printf("\n--- ANALISIS DE ARREGLO 3 (int *arreglo3 = malloc(...)) ---\n");
    
    int * arreglo3 = (int *) malloc (N*sizeof(int)); 
    
    // Verificación de error de malloc (buena practica)
    if (arreglo3 == NULL) {
        printf("3. ERROR: Fallo la reserva dinamica de memoria.\n");
        return 1;
    }

    /*
     * a. Tipo de arreglo: Dinámico. El tamaño y la vida util son controlados por el programador.
     * b. Momento de reserva: Ejecución (con la llamada a malloc). Se reserva en el Heap (Monton).
     * c. Límite de tamaño: Heap (Montón). Límite dado por la memoria virtual del sistema (grande).
     * d. Cambiar tamaño en ejecución: Sí (usando realloc()).
     * e. Liberar memoria: Sí (debe hacerse explicitamente usando free()).
     * f. Nombre apunta a otra dirección: Sí (arreglo3 es una variable puntero y puede reasignarse).
     * g. Compila en ANSI C90: Sí (malloc y punteros son parte de C90).
     */
    printf("3. Arreglo Dinamico: Tamano en ejecucion (Heap). Debe liberarse con free().\n");
    
    // Demostracion del punto 'e' (Liberacion de memoria)
    free(arreglo3);
    printf("   Memoria dinamica liberada con free(arreglo3).\n");
    
    printf("----------------------------------------------------------------\n");
    return 0; 
}

/*
 * NOTA FINAL: El codigo 2 (VLA) solo compila si el compilador soporta C99 o superior. 
 * Para un estricto ANSI C90, solo Codigo 1 y Codigo 3 son validos.
 */