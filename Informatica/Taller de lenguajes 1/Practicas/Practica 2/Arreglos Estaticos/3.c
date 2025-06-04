#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ANCHO 10
#define ALTO 10

// llenar la matriz con numeros aleatorios entre 0 y 10
void llenar_matriz( int matriz[][ANCHO] , int alto ) {
    for (int i = 0 ; i < alto ; i++ ) {
        for (int j = 0 ; j < ANCHO ; j++ ) {
            matriz[ i ][ j ] = ( rand() % 4 ) ;
        }
    }
}

// funcion para imprimir la matriz
void imprimir_matriz( int matriz[][ANCHO] , int alto ) {
    for (int i = 0 ; i < alto ; i++ ) {
        for (int j = 0 ; j < ANCHO ; j++ ) {
            printf( "%d ", matriz[ i ][ j ] ) ;
        }
        printf( "\n" ) ;
    }
}

// multiplicar la matriz por un escalar
void multiplicar_matriz( int matriz[][ANCHO] , int alto , int escalar ) {
    for (int i = 0 ; i < alto ; i++ ) {
        for (int j = 0 ; j < ANCHO ; j++ ) {
            matriz[ i ][ j ] *= escalar ;
        }
    }
}

int main() {
    // inicializar la semilla del generador de numeros aleatorios
    // usando la hora actual como semilla
    srand( time(NULL) ) ;

    // matriz
    int matriz[ ALTO ][ ANCHO ] ;

    // llenar la matriz con numeros aleatorios
    llenar_matriz( matriz , ALTO ) ;

    // imprimir la matriz
    printf( "\nMatriz original:\n\n" ) ;
    imprimir_matriz( matriz , ALTO ) ;

    // multiplicar la matriz por un escalar
    int escalar = 2 ;
    multiplicar_matriz( matriz , ALTO , escalar ) ;

    // imprimir la matriz multiplicada
    printf( "\nMatriz multiplicada por %d:\n\n", escalar ) ;
    imprimir_matriz( matriz , ALTO ) ;

    printf( "\n" ) ;
    return( 0 ) ;
}
