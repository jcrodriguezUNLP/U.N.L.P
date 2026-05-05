// ==============================================================================
// ANÁLISIS 16: FUNCIÓN SWAP
// ==============================================================================
// Contexto:
//     - Se supone que la función intercambia el valor de sus dos parámetros.
//
// Tarea:
//     1. ¿Funciona correctamente?
//     2. Si no es así, modifique la función swap para que lo haga.
// ==============================================================================

// --- 1. RESPUESTAS TEÓRICAS ---
// 1. ¿Funciona correctamente la versión original?
//    NO. La versión original recibe los parámetros "por valor" (crea una copia 
//    aislada en la pila de memoria de la función). Al modificar 'a' y 'b', 
//    solo se modifican esas copias, dejando intactas las variables 'x' e 'y' 
//    originales del main().
//
// 2. Modificación:
//    Para modificar la memoria real del main(), la función debe recibir las 
//    direcciones de memoria (punteros) de las variables. El operador '*' nos 
//    permite "viajar" a esa dirección y reescribir el dato original.

#include <stdio.h>

// --- 2. PROTOTIPOS ---
// CORRECCIÓN: Se cambia la firma para recibir punteros a enteros
void swap( int *dirA , int *dirB ) ;

int main() {
    // --- 3. INICIALIZACIÓN ---
    int x = 10 ;
    int y = 20 ;

    printf( "--- Estado Inicial ---\n" ) ;
    printf( "x = %d \t y = %d\n" , x , y ) ;

    // --- 4. PROCESAMIENTO ---
    // CORRECCIÓN: Enviamos las direcciones de memoria usando el operador '&'
    swap( &x , &y ) ;

    // --- 5. SALIDA ---
    printf( "\n--- Estado Final (Post-Swap) ---\n" ) ;
    printf( "x = %d \t y = %d\n" , x , y ) ;

    return( 0 ) ;
}

// --- 6. IMPLEMENTACIÓN CORE ---
void swap( int *dirA , int *dirB ) {
    
    // 1. Rescatamos el valor alojado en la dirección A usando el operador '*'
    int tmp = *dirA ;
    
    // 2. Escribimos en la dirección A el valor que vive en la dirección B
    *dirA = *dirB ;
    
    // 3. Escribimos en la dirección B el valor temporal rescatado
    *dirB = tmp ;
}