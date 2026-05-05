// implemente una funcion q reciba una cadena y retorne su version comprimida usando RLE( carcter seguido de su cantidad de repeticiones )
// solo se debe comprimir si el conteo es mayor a 1
// ejemplo "aaabbbbcaa" -> "a3b4ca2"

#include <stdio.h>
#include <string.h>

void comprimir_rle( const char in[] , char out[] ) {

    int largoIn = strlen( in ) ;

    if( largoIn == 0 ) {
        out[ 0 ] = '\0' ;

        return ;
    }

    char carActual      = in[ 0 ] ;
    int cantApariciones = 1       ;

    int posOut = 0 ;

    for( int posIn = 1 ; posIn <= largoIn ; posIn++ ) {
        if( in[posIn] == carActual ){
            cantApariciones++ ;
        } else {
            out[ posOut++ ] = carActual ;
            
            if( 1 < cantApariciones ) {
                out[ posOut++ ] = ( '0' + cantApariciones ) ;
            }

            carActual       = in[ posIn ] ;
            cantApariciones = 1           ;
        }
    }

    out[ posOut ] = '\0' ;
}