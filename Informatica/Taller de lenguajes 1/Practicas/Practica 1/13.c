// ==============================================================================
// PROBLEMA 13: NÚMEROS PRIMOS
// ==============================================================================
// Desarrolle una función que:
//     reciba:
//         un número entero n.
//     determine:
//         si el mismo es primo o no.
//
// Escriba un programa que:
//     lea:
//         números enteros desde teclado.
//     condición de corte:
//         hasta que la cantidad de primos leídos sea exactamente 5.
// ==============================================================================

#include <stdio.h>

// --- 1. FUNCIÓN CORE (Inciso A) ---
int esPrimo( int n ) {
    // Por definición matemática, los números menores o iguales a 1 no son primos.
    if( n <= 1 ) { 
        return( 0 ) ; 
    } 
    
    // Buscamos divisores desde el 2 hasta (n - 1) usando estrictamente '<'.
    for( int i = 2 ; i < n ; i++ ) {
        
        // Si el módulo es 0, significa que 'i' es divisor exacto de 'n'.
        if( (n % i) == 0 ) { 
            return( 0 ) ; 
        }
    }

    return( 1 ) ;
}

int main() {
    // --- 2. INICIALIZACIÓN (Inciso B) ---
    int n ;
    int cantPrimos = 0 ;

    printf( "--- Buscador de 5 Numeros Primos ---\n\n" ) ;

    // --- 3. PROCESAMIENTO ---
    // Bucle do-while iterando hasta alcanzar el objetivo, usando estrictamente '<'.
    do {
        printf( "Ingrese un numero entero: " ) ;
        scanf( "%d" , &n ) ;

        if( esPrimo( n ) ) {
            cantPrimos++ ;
            printf( " -> ¡El %d es PRIMO! (Llevamos %d/5)\n" , n , cantPrimos ) ;
        } else {
            printf( " -> El %d no es primo.\n" , n ) ;
        }

    } while( cantPrimos < 5 ) ;

    // --- 4. SALIDA ---
    printf( "\n¡Se han encontrado los 5 numeros primos con exito!\n" ) ;

    return( 0 ) ;
}