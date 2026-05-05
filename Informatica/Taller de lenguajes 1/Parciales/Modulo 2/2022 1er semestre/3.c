// A)
//    defina el tipo de dato Piramide que permita representar de manera dinamica y eficiente una piramide de enteros con n elementos en su base, n - 1 en el siguiente nivel, y asi sucesivamente hasta llegar al ultimo nivel con 1 elemento.

typedef struct {
    int  niveles ;    // cantidad de niveles de la piramide
    int* datos   ;    // puntero a los datos de la piramide almacenados en un arreglo dinamico
} Piramide ;

// B)
//    Dados los siguientes prototipos, implementar una funcion que permita reservar y liberar una piramide de n elementos de base.
//    Piramide crearPiramide  ( int n              ) ;
//    void     liberarPiramide( Piramide p , int n ) ;

#include <stdlib.h>

Piramide crearPiramide( int n ) {
    Piramide p ;

    p.niveles = n ;
    
    int totalElementos = ( n * (n + 1) / 2 ) ; // suma de los primeros n numeros naturales
    
    p.datos = (int*) malloc( totalElementos * sizeof(int) ) ;
    
    return( p ) ;
}

void liberarPiramide( Piramide p , int n ) {
    free(p.datos);
}