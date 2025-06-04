#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ANCHO 3
#define ALTO 3

// llenar la matriz con numeros aleatorios entre 0 y 10
void llenar_matriz( int matriz[][ANCHO] , int alto ) {
    for (int i = 0 ; i < alto ; i++ ) {
        for (int j = 0 ; j < ANCHO ; j++ ) {
            matriz[ i ][ j ] = ( rand() % 4 ) ; // Números aleatorios entre 0 y 3
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

// sumar dos matrices
void sumarMatrices( int A[][ANCHO] , int B[][ANCHO] , int C[][ANCHO] , int alto ) {
    for (int i = 0 ; i < alto ; i++ ) {
        for (int j = 0 ; j < ANCHO ; j++ ) {
            C[ i ][ j ] = A[ i ][ j ] + B[ i ][ j ] ;
        }
    }
}

int main() {
    // inicializar la semilla del generador de numeros aleatorios
    srand( time(NULL) ) ;

    // Declarar las matrices
    int A[ ALTO ][ ANCHO ] ;
    int B[ ALTO ][ ANCHO ] ;
    int C[ ALTO ][ ANCHO ] ;

    // Llenar las matrices A y B con números aleatorios
    llenar_matriz( A , ALTO ) ;
    llenar_matriz( B , ALTO ) ;

    // Imprimir la matriz A
    printf( "\nMatriz A:\n\n" ) ;
    imprimir_matriz( A , ALTO ) ;

    // Imprimir la matriz B
    printf( "\nMatriz B:\n\n" ) ;
    imprimir_matriz( B , ALTO ) ;

    // Sumar las matrices A y B, y almacenar el resultado en C
    sumarMatrices( A , B , C , ALTO ) ;

    // Imprimir la matriz resultante C
    printf( "\nMatriz C (resultado de A + B):\n\n" ) ;
    imprimir_matriz( C , ALTO ) ;

    printf( "\n" ) ;
    
    return( 0 ) ;
}
