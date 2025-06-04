#include <stdio.h>

#define ARRAY_SIZE 10

// Función para invertir el orden de los elementos en un arreglo
void swap( int numeros[] , int n ) {
    int aux ;
    int j ;

    for (int i = 0 ; i < (n / 2) ; i++)   {
        j = ( (n - 1) - i ) ;
        
        aux = numeros[ i ] ;
        numeros[ i ] = numeros[ j ] ;
        numeros[ j ] = aux ;
    }
}

// imprime el arreglo
void imprimirArreglo( int numeros[] , int n ) {
    for (int i = 0 ; i < n ; i++)   {
        printf( "%d " , numeros[ i ] ) ;
    }
    printf( "\n" ) ;
}

int main() {
    int numeros[ ARRAY_SIZE ] = { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 } ;
    int n = ARRAY_SIZE ;

    printf( "Arreglo original: " ) ;
    imprimirArreglo( numeros , n ) ;

    swap( numeros , n ) ;
    printf( "Arreglo invertido: " ) ;
    imprimirArreglo( numeros , n ) ;

    printf("\n") ;

    return( 0 ) ;
}

