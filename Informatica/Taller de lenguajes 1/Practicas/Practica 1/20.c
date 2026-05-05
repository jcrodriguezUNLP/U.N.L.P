// ==============================================================================
// PROBLEMA 20: GENERADOR DE PARES (VARIABLES ESTÁTICAS)
// ==============================================================================
// Desarrolle una función 'damePar()' que:
//     reciba:
//         (sin parámetros).
//     retorne:
//         0 en el 1er llamado, 2 en el 2do, 4 en el 3ro, y así sucesivamente.
//
// Escriba un programa que:
//     lea:
//         un número entero positivo n.
//     imprima:
//         los primeros n números pares haciendo uso de la función damePar().
//     restricción:
//         queda estrictamente prohibido el uso de variables globales.
// ==============================================================================

#include <stdio.h>

// --- 1. FUNCIÓN CORE ---
int damePar() {
    // 'static' cambia el ciclo de vida de la variable local en la memoria RAM:
    // 1. Se inicializa una ÚNICA vez durante toda la ejecución del programa.
    // 2. No se destruye al hacer el 'return' (sobrevive entre llamados).
    // 3. En los llamados siguientes, la inicialización se ignora y la 
    //    variable conserva su último estado modificado.
    static int par = -2 ;

    par += 2 ;
    
    return( par ) ;
}

int main() {
    // --- 2. INICIALIZACIÓN ---
    int n ;

    printf( "--- Generador Secuencial de Numeros Pares ---\n\n" ) ;

    // --- 3. PROCESAMIENTO ---
    printf( "Ingrese la cantidad de numeros pares a generar: " ) ;
    scanf( "%d" , &n ) ;

    printf( "\nGenerando los primeros %d pares:\n" , n ) ;

    // --- 4. SALIDA ---
    // Bucle for utilizando Yoda conditions y operador estricto '<='
    // Para pedir 'n' números, iteramos desde 1 hasta 'n'
    for( int i = 1 ; i <= n ; i++ ) {
        printf( "    Llamado %d -> %d\n" , i , damePar() ) ;
    }

    printf( "\n" ) ;

    return( 0 ) ;
}