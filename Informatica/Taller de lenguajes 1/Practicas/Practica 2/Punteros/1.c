// ==============================================================================
// PROBLEMA 1: ESTADÍSTICAS POR REFERENCIA
// ==============================================================================
// Desarrolle una única función que:
//     reciba:
//         un arreglo unidimensional de tipo float. 
//     retorne (vía punteros):
//         el promedio
//         el mínimo
//         posición del máximo de sus valores
//     nota:
//         es la refactorización del Problema 2 usando paso por referencia.
// ==============================================================================

#include <stdio.h>

void procesarArreglo( float array[] , int dimL , float* DM_Prom , float* DM_ValMin , int* DM_PosMax ) {
    if( 0 == dimL ) {
        *DM_Prom   = 0  ;
        *DM_ValMin = 0  ;
        *DM_PosMax = -1 ;

        return ;
    }

    float n = array[ 0 ] ;

    float sumaTotal = n ;

    float valMin = n ;

    float valMax = n ;
    int   posMax = 0 ;

    for( int i = 1 ; i < dimL ; i++ ) {
        n = array[ i ] ;

        sumaTotal += n ;

        if( n < valMin ) {
            valMin = n ;
        }
        
        if( valMax < n ) {
            valMax = n ;
            posMax = i ;
        }
    }

    *DM_Prom   = ( sumaTotal / dimL ) ;
    *DM_ValMin = valMin               ;
    *DM_PosMax = posMax               ;
}

int main() {

    return( 0 ) ;
}