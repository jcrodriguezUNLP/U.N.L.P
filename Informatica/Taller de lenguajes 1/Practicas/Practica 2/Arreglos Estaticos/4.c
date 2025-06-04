#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ANCHO 4
#define ALTO 4

// llenar la matriz con numeros aleatorios entre 0 y 10
void llenarMatriz( char matriz[][ANCHO] , int alto ) {
    char caracter = 'a' ;

    for (int i = 0 ; i < alto ; i++ ) {
        for (int j = 0 ; j < ANCHO ; j++ ) {
            matriz[ i ][ j ] = caracter ;

            caracter++;
        }
    }
}

// funcion para imprimir la matriz
void imprimirMatriz( char matriz[][ANCHO] , int alto ) {
    for (int i = 0 ; i < alto ; i++ ) {
        for (int j = 0 ; j < ANCHO ; j++ ) {
            printf( "%c ", matriz[ i ][ j ] ) ;
        }
        printf( "\n" ) ;
    }
}

// multiplicar la matriz por un escalar
void trasponerMatriz( char matriz[][ANCHO] , char traspuesta[][ALTO] , int alto ) {
    for( int i = 0 ; i < alto ; i++ ) {
        for( int j = 0 ; j < ANCHO ; j++ ) {
            traspuesta[ i ][ j ] = matriz[ j ][ i ];
        }
    }
}

int main() {
    // inicializar la semilla del generador de numeros aleatorios
    // usando la hora actual como semilla
    srand( time(NULL) ) ;

    // matriz
    char matriz[ ALTO ][ ANCHO ] ;

    // llenar la matriz con numeros aleatorios
    llenarMatriz( matriz , ALTO ) ;

    // imprimir la matriz
    printf( "\nMatriz original:\n\n" ) ;
    imprimirMatriz( matriz , ALTO ) ;

    // transponer la matriz
    char traspuesta[ANCHO][ALTO];
    trasponerMatriz( matriz , traspuesta , ALTO );

    // imprimir la matriz transpuesta
    printf( "\nMatriz traspuesta:\n\n" );
    imprimirMatriz( traspuesta , ANCHO );

    printf( "\n" ) ;
    return( 0 ) ;
}
