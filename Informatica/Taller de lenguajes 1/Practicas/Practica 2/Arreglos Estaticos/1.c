#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // inicializar la semilla del generador de numeros aleatorios
    // usando la hora actual como semilla
    srand( time(NULL) ) ;
    
    int numeros[ 50 ] ;
    int paresEnPosImpares = 0 ;
    int imparesEnPosPares = 0 ;

    // inicializar el array con numeros enteros aleatorios
    for (int i = 0 ; i < 50 ; i++ ) {
        numeros[ i ] = rand() ;

        // contar los pares en posiciones impares
        if ( ((i % 2) != 0) && ((numeros[ i ] % 2) == 0) ) {
            paresEnPosImpares++ ;
        }

        // contar los impares en posiciones pares
        if ( ((i % 2) == 0) && ((numeros[ i ] % 2) != 0) ) {
            imparesEnPosPares++ ;
        }
    }

    // imprimir el array
    printf( "Array de numeros aleatorios:\n" ) ;
    for (int i = 0 ; i < 50 ; i++ ) {
        printf( "\nIndice %d: %d", i, numeros[ i ] ) ;
    }
    printf( "\n" ) ;    

    // imprimir los resultados
    printf( "\nCantidad de numeros pares en posiciones impares: %d\n", paresEnPosImpares ) ;
    printf( "Cantidad de numeros impares en posiciones pares: %d\n", imparesEnPosPares ) ;
    printf( "\n" ) ;

    return( 0 ) ;
}