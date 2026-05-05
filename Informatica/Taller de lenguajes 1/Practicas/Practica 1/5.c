// ==============================================================================
// PROBLEMA 5: MÚLTIPLOS DE 5
// ==============================================================================
// Escriba un programa que:
//     imprima:
//         los números enteros múltiplos de 5 comprendidos entre 1 y 50.
//     condición:
//         realizar dos soluciones:
//         a. utilizando el operador %
//         b. utilizando un for con incremento de 5 en 5.
// ==============================================================================

#include <stdio.h>

int main() {
    // --- 1. SOLUCIÓN A: OPERADOR MÓDULO (%) ---
    // Enfoque: Fuerza bruta. Recorre todos los números y filtra.
    
    printf( "--- Solucion A: Uso del operador %% ---\n" ) ;
    
    int n = 1 ;

    while( n <= 50 ) {
        if( (n % 5) == 0 ) {
            printf( "%d es multiplo de 5\n" , n ) ;
        }

        n++ ;
    }

    printf( "\n" ) ;


    // --- 2. SOLUCIÓN B: BUCLE FOR CON INCREMENTO ---
    // Enfoque: Optimizado. Salta directamente de a 5, evitando cálculos innecesarios.
    
    printf( "--- Solucion B: Bucle for (i += 5) ---\n" ) ;
    
    for( int i = 5 ; i <= 50 ; i += 5 ) {
        printf( "%d es multiplo de 5\n" , i ) ;
    }
    
    printf( "\n" ) ;

    return( 0 ) ;
}