// ==============================================================================
// PROBLEMA 18: NÚMEROS PSEUDO-ALEATORIOS
// ==============================================================================
// Escriba un programa que:
//     imprima:
//         15 números generados pseudo-aleatoriamente.
//     nota:
//         investigue las funciones rand() y srand() de <stdlib.h>.
//
// Responda:
//     1. ¿La secuencia generada es siempre la misma? ¿Por qué?
//     2. ¿Qué se puede hacer para generar secuencias diferentes?
// ==============================================================================

// --- 1. RESPUESTAS TEÓRICAS ---
//
// 1. ¿La secuencia generada es siempre la misma?
//    SÍ. Si solo se usa rand() sin configurar nada más, la secuencia será 
//    idéntica en cada ejecución.
//
// 2. ¿Por qué ocurre esto?
//    rand() es una función matemática determinista. Aplica una fórmula sobre 
//    una "semilla" base. Si no se le proporciona una semilla manualmente, el 
//    compilador de C asume automáticamente que la semilla es 1. Al arrancar 
//    siempre desde el 1, la fórmula escupe siempre los mismos resultados.
//
// 3. ¿Qué se puede hacer para generar secuencias diferentes?
//    Se debe usar la función srand() para inyectar una semilla nueva al inicio 
//    del programa. La convención estándar es pasarle time(NULL), lo que usa 
//    los segundos del reloj de la PC como semilla, garantizando que el punto 
//    de partida sea distinto cada segundo.

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Necesario para leer el reloj de la PC

int main() {
    
    // --- 2. DEMOSTRACIÓN SIN SEMILLA (DETERMINISTA) ---
    printf( "--- Secuencia sin semilla (siempre igual) ---\n" ) ;
    
    // Bucle Yoda con operador estricto '<='
    for( int i = 1 ; i <= 15 ; i++ ) {
        printf( "Numero aleatorio %d: %d\n" , i , rand() ) ;
    }


    // --- 3. DEMOSTRACIÓN CON SEMILLA (DINÁMICA) ---
    printf( "\n--- Secuencia con semilla (diferente en cada ejecucion) ---\n" ) ;
    
    // Genera una semilla usando la hora actual del sistema operativo para 
    // que los números del rand() siempre sean distintos.
    srand( time( NULL ) ) ;

    for( int i = 1 ; i <= 15 ; i++ ) {
        printf( "Numero aleatorio %d: %d\n" , i , rand() ) ;
    }

    return( 0 ) ;
}