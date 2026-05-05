// ==============================================================================
// PROBLEMA 12: RAÍZ, CUADRADO Y CUBO
// ==============================================================================
// Escriba un programa que:
//     imprima:
//         la raíz cuadrada, el cuadrado y el cubo de los enteros del 1 al 10.
//     nota:
//         investigue las funciones sqrt() y pow() de <math.h>.
// ==============================================================================

#include <stdio.h>
#include <math.h> // Requiere enlazar la librería matemática al compilar

int main() {
    
    printf( "--- Calculadora de Potencias y Raices ---\n\n" ) ;

    // Bucle del 1 al 10 usando estrictamente el operador <=
    for( int i = 1 ; i <= 10 ; i++ ) {
        
        printf( "Numero %d:\n" , i ) ;
        
        // sqrt() recibe un double y retorna un double
        // pow() recibe (base, exponente) como doubles y retorna un double
        printf( "    Raiz Cuadrada = %.2f\n" , sqrt( i ) ) ;
        printf( "    Cuadrado      = %.2f\n" , pow( i , 2 ) ) ;
        printf( "    Cubo          = %.2f\n" , pow( i , 3 ) ) ;
        
        printf( "--------------------\n" ) ;
    }

    return( 0 ) ;
}