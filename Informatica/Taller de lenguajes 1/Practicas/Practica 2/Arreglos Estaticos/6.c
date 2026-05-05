// ==============================================================================
// PROBLEMA 6: FRECUENCIA DE DÍGITOS
// ==============================================================================
// Escriba un programa que:
//     lea:
//         un número entero desde el teclado.
//     imprima:
//         la cantidad de veces que aparece cada dígito numérico en el mismo.
// ==============================================================================
#include <stdio.h>

void imprimirFrecuencias( int frecuencias[ 10 ] ) {
    
    printf( "      |" ) ;
    for( int i = 0 ; i < 10 ; i++ ) {
        printf( " %d |" , i ) ;
    }
    printf( "\n" ) ;

    printf( "------+" ) ;
    for( int i = 0 ; i < 10 ; i++ ) {
        printf( "---+" ) ;
    }
    printf( "\n" ) ;

    printf( " Frec |" ) ;
    for( int i = 0 ; i < 10 ; i++ ) {
        printf( " %d |" , frecuencias[ i ] ) ;
    }
    printf( "\n\n" ) ;
}

void calcularFrecuenciaDigitos( int numero ) {
    int frecuencias[ 10 ] = { 0 } ;

    while( numero != 0 ) {
        int num = ( numero % 10 ) ;

        frecuencias[ num ]++ ;

        numero /= 10 ;
    }

    imprimirFrecuencias( frecuencias ) ;
}

int main() {
    int inputNumero ;

    printf( "--- Analizador de Frecuencia Numerica ---\n\n" ) ;
    
    // Lectura desde teclado
    printf( "Ingrese un numero entero: " ) ;
    scanf( "%d" , &inputNumero ) ;

    printf( "\nAnalizando el numero: %d\n\n" , inputNumero ) ;

    // Invocamos el core
    calcularFrecuenciaDigitos( inputNumero ) ;

    return( 0 ) ;
}