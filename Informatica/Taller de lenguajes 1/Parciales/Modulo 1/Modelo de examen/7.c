// Escriba un programa que:
//     lea:
//         palabras ingresadas por teclado
//             hasta la lectura de la palabra “FIN”
//             (las palabras tienen como máximo 20 caracteres)
    
//     Al finalizar:
//         informe:
//             cual es la palabra de menor longitud

#include <stdio.h>
#include <string.h>

#define largoMax 20

int main() {
    char palabra [ (largoMax + 1) ] ;
    char shortest[ (largoMax + 1) ] ;
    
    int longitudMinima = ( largoMax + 1 ) ; 

    int distintos ;

    do {
        scanf( "%s" , palabra ) ;

        distintos = strcmp( palabra, "FIN" ) ;  // palabra == "FIN" -> | distintos = strcmp( palabra, "FIN" ) ;
                                                //                     |               |
                                                //                     |               v
                                                //                     | distintos =   0 ;

        if( distintos ) {
            int longitudPalabra = strlen( palabra ) ;   // strlen cuenta cuántos caracteres hay hasta encontrar el '\0'
            
            if( longitudPalabra < longitudMinima ) {
                longitudMinima = strlen( palabra ) ;
                
                strcpy( shortest, palabra ) ;   // strcpy( destino , origen ) ;
            }
        }
        
    } while( distintos ) ;

    if( longitudMinima <= largoMax ) {
        printf( "\nLa palabra mas corta es: %s\n" , shortest ) ;
    } else {
        printf( "\nNo se ingresaron palabras validas.\n" ) ;
    }

    return( 0 ) ;
}