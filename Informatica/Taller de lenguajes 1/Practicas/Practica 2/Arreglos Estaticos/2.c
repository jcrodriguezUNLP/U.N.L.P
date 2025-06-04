#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

float promedio( float numeros[] , int n ) {
    float suma = 0.0 ;

    for (int i = 0 ; i < n ; i++ ) {
        suma += numeros[ i ] ;
    }

    return( suma / n ) ;
}

float minimo( float numeros[] , int n ) {
    float min = numeros[ 0 ] ;

    for (int i = 1 ; i < n ; i++ ) {
        if ( numeros[ i ] < min ) {
            min = numeros[ i ] ;
        }
    }

    return( min ) ;
}

// posicion del valor maximo
int posMaximo( float numeros[] , int n ) {
    float max = numeros[ 0 ] ;
    int pos = 0 ;

    for( int i = 1 ; i < n ; i++ ) {
        if( max < numeros[ i ] ) {
            max = numeros[ i ] ;
            pos = i ;
        }
    }

    return( pos ) ;
}


int main() {
    // inicializar la semilla del generador de numeros aleatorios
    // usando la hora actual como semilla
    srand( time(NULL) ) ;
    
    float numeros[ ARRAY_SIZE ] ;

    // inicializar el array con numeros enteros aleatorios
    for (int i = 0 ; i < ARRAY_SIZE ; i++ ) {
        numeros[ i ] = rand() ;
    }

    // imprimir el array
    printf( "\nArray de numeros aleatorios:\n" ) ;

    for (int i = 0 ; i < ARRAY_SIZE ; i++ ) {
        printf( "\nIndice %d: %f " , i , numeros[ i ] ) ;
    }

    // calcular el promedio
    float prom = promedio( numeros , ARRAY_SIZE ) ;
    printf( "\n\nEl promedio es: %f" , prom ) ;

    // calcular el minimo
    float min = minimo( numeros , ARRAY_SIZE ) ;
    printf( "\n\nEl minimo es: %f" , min ) ;

    // calcular la posicion del maximo
    int pos = posMaximo( numeros , ARRAY_SIZE ) ;
    printf( "\n\nLa posicion del maximo es: %d" , pos ) ;
    printf( "\nEl maximo es: %f" , numeros[ pos ] ) ;

    printf( "\n" ) ;

    return( 0 ) ;
}