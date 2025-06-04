#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // Tamaño del vector

// Función para inicializar el vector con números al azar
void inicializarVector( int vec[] , int size ) {
    for( int i = 0 ; i < size ; i++ ) {
        vec[ i ] = rand() % 100 ; // Números al azar entre 0 y 99
    }
}

// Función para imprimir el vector
void imprimirVector( const int vec[] , int size ) {
    for( int i = 0 ; i < size ; i++ ) {
        printf( "%02.d " , vec[ i ] ) ;
    }
    printf( "\n" ) ;
}

// Función para ordenar el vector(usando el método de burbuja)
void ordenarVector( int vec[] , int size ) {
    for( int i = 0 ; i < (size - 1) ; i++ ) {

        for( int j = 0 ; j < ((size - 1) - i) ; j++ ) {

            if( vec[ j + 1 ] < vec[ j ] ) {
                // Intercambiar elementos
                int temp = vec[ j ] ;

                vec[ j ] = vec[ j + 1 ] ;

                vec[ j + 1 ] = temp ;
            }
        }
    }
}

int main() {
    srand( time( NULL ) ) ; // Semilla para números aleatorios

    int vec [ SIZE ] ;

    // Inicializar el vector con números al azar
    inicializarVector( vec , SIZE ) ;

    // Imprimir el vector inicial
    printf( "Vector inicial:\n" ) ;
    imprimirVector( vec , SIZE ) ;

    // Ordenar el vector
    ordenarVector( vec , SIZE ) ;

    // Imprimir el vector ordenado
    printf( "Vector ordenado:\n" ) ;
    imprimirVector( vec , SIZE ) ;

    return( 0 ) ;
}