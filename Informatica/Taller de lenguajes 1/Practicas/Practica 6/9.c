// Realice un programa que genere un vector de 1000 enteros al azar y utilice una función para localizar un elemento

// A)
//     Implementar la función de búsqueda que, dado un entero, retorne la posición donde se encuentra. 
//     En caso de no existir el número retorne -1. 
// B)
//     Modificar A) para agregar información de depuración que permita imprimir en consola la cantidad de veces que se debió acceder al arreglo para encontrar (o no) el elemento en cada llamado a la función.
//     Utilice las directivas del procesador para:
//         activar/desactivar la depuración
//         imprimir/no imprimir la información en la consola. 
// C)
//     Verifique el tamaño del programa compilando con la depuración y sin la depuración
//     Explique porque difieren.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

#define DEBUG 0

int buscarElemento( int arr[], int size, int elemento ){
    int pos = 0 ;

    int encontre = 0 ; // "BOOLEAN"
    
    while( (pos < size) && (!encontre) ){
        encontre = ( arr[ pos ] == elemento ) ? 1 : 0 ;

        if( !encontre ){
            pos++ ;
        }
    }
    
    #if DEBUG
        printf( "cantidad de iteraciones = %d\n", pos ) ;
    #endif

    if( !encontre ){
        pos = -1 ;
    }

    return( pos ) ;
}

int main(){
    srand( (unsigned)time(NULL) ) ;
    
    int arr[ SIZE ] ; 

    for( int i = 0 ; i < SIZE ; i++ ){
        arr[ i ] = rand() ;
    }

    int pos = buscarElemento( arr , SIZE , 5 ) ;

    if( pos != -1 ) {
        printf( "El numero 5 se encontro en la posicion: %d\n", pos ) ;
    } else {
        printf( "El numero 5 no esta en el arreglo.\n" ) ;
    }

    return( 0 ) ;
}