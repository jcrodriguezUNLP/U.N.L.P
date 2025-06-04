#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

// imprimir el array
void imprimirArray( float numeros[] , int n ) {
    printf( "\nArray de numeros aleatorios:\n" ) ;
    
    for( int i = 0 ; i < n ; i++ ) {
        printf( "\nIndice %02d: %.2f" , i, numeros[ i ] ) ;
    }
}

//llenar el array con números aleatorios
void llenarArray( float numeros[] , int n ) {
    for( int i = 0 ; i < n ; i++ ) {
        numeros[ i ] = rand() % 100 ; // Números aleatorios entre 0 y 99
    }
}

// Función que calcula el promedio , el mínimo y la posición del máximo
void calcularEstadisticas( float numeros[] , int n , float *promedio , float *minimo , int *posMaximo ) {
    float suma = 0.0 ;
    *minimo = numeros[0] ;
    float max = numeros[0] ;
    *posMaximo = 0 ;

    for( int i = 0 ; i < n ; i++ ) {
        suma += numeros[ i ] ;

        if( numeros[ i ] < *minimo ) {
            *minimo = numeros[ i ] ;
         }

        if( numeros[ i ] > max ) {
            max = numeros[ i ] ;
            *posMaximo = i;
        }
    }

    *promedio = suma / n ;
}

int main() {
    // Inicializar la semilla del generador de números aleatorios
    srand( time( NULL) ) ;

    float numeros[ ARRAY_SIZE ] ;

    // Llenar el array con números aleatorios
    llenarArray( numeros , ARRAY_SIZE ) ;

    // Imprimir el array
    imprimirArray( numeros , ARRAY_SIZE ) ;

    // Variables para almacenar los resultados
    float prom ;
    float min ;
    int posMax ;

    // Llamar a la función para calcular las estadísti cas
    calcularEstadisticas( numeros , ARRAY_SIZE , &prom , &min , &posMax ) ;

    // Imprimir los resultados
    printf( "\n\nEl promedio es: %.2f" , prom ) ;
    printf( "\nEl minimo es: %.2f" , min ) ;
    printf( "\nLa posicion del maximo es: %d" , posMax ) ;
    printf( "\nEl maximo es: %.2f" , numeros[ posMax ] ) ;

    printf( "\n" ) ;

    return 0 ;
}