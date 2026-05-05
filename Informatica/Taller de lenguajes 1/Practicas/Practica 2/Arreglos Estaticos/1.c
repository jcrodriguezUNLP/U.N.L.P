// ==============================================================================
// PROBLEMA 1: NÚMEROS PSEUDOALEATORIOS Y POSICIONES
// ==============================================================================
// Escriba un programa que:
//     genere:
//         50 números enteros de forma pseudoaleatoria.
//     almacene:
//         los números generados en un arreglo unidimensional.
//     imprima:
//         - la cantidad de números pares que se encuentran en posiciones impares.
//         - la cantidad de números impares que se encuentran en posiciones pares.
// ==============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int esPar( int n ) {
    return( !(n % 2) ) ;
}

int main(){

    srand( time( NULL ) ) ;

    int vectorNumeros[ 50 ] = { 0 } ;

    int cantParesEnPosImpar = 0 ;
    int cantImparesEnPosPar = 0 ;

    for( int i = 0 ; i < 50 ; i++ ) {
        vectorNumeros[ i ] = ( (rand() % 50) + 1 ) ;

        if( esPar( i ) ) {
            if( !esPar( vectorNumeros[i] ) ) {
                cantImparesEnPosPar++ ;
            }
        }
        
        if( esPar( vectorNumeros[i] ) ){
            cantParesEnPosImpar++ ;
        }
    }

    printf( "cant pares en pos impar: %d\n" , cantParesEnPosImpar ) ;
    printf( "cant impares en pos par: %d\n" , cantImparesEnPosPar ) ;

    return( 0 ) ;
}