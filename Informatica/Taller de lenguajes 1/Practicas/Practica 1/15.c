// ==============================================================================
// PROBLEMA 15: FACTORIAL
// ==============================================================================
// Desarrolle una función que:
//     reciba:
//         un número entero.
//     retorne:
//         su factorial (n! = 1 x 2 x 3 x ... x n).
//     condiciones:
//         a. Escribir versión iterativa.
//         b. Escribir versión recursiva.
// ==============================================================================

#include <stdio.h>

// --- 1. FUNCIÓN CORE: VERSIÓN ITERATIVA (Inciso A) ---
int factorialIterativo( int n ) {
    int factorial = 1 ;

    // Acumula multiplicaciones usando un bucle estándar
    for( int i = 2 ; i <= n ; i++ ) {
        factorial *= i ; 
    }

    return( factorial ) ;
}

// --- 2. FUNCIÓN CORE: VERSIÓN RECURSIVA (Inciso B) ---
int factorialRecursivo( int n ) {
    // Caso base: define cuándo la función deja de llamarse a sí misma
    if( n <= 1 ) {
        return( 1 ) ;
    }

    // Llamada recursiva: apila ejecuciones en la memoria hasta llegar al caso base
    return( n * factorialRecursivo( n - 1 ) ) ;
}

int main() {
    // --- 3. INICIALIZACIÓN ---
    int n ;

    printf( "--- Calculadora de Factorial ( n! ) ---\n\n" ) ;

    // --- 4. PROCESAMIENTO Y SALIDA ---
    printf( "Ingrese un numero natural: " ) ;
    scanf( "%d" , &n ) ;

    // NOTA TÉCNICA: El factorial crece a un ritmo exponencial extremo. 
    // Un 'int' de 4 bytes solo puede calcular hasta 12! antes de desbordarse 
    // (integer overflow) y empezar a mostrar números erróneos o negativos.
    printf( "\nResultados para %d!:\n" , n ) ;
    printf( "    -> Iterativo : %d\n" , factorialIterativo( n ) ) ;
    printf( "    -> Recursivo : %d\n" , factorialRecursivo( n ) ) ;

    return( 0 ) ;
}