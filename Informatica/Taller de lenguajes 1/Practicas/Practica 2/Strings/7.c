#include <stdio.h>
#include <string.h>

#define STRING_SIZE 101 // Tamaño máximo del string más \0

// leer un string
void leerPalabra( char str[], int maxLength ) {
    printf( "\nIngrese una palabra: " ) ;
    scanf( "%s" , str ) ; // Leer un string
}

// Función usando índices numéricos
int esPalindromoIndices( const char* str ) {
    int len = strlen( str ) ; // Longitud de la palabra
    int resultado = 1 ; // Inicialmente asumimos que es palíndroma

    for( int i = 0 ; i < (len / 2) ; i++ ) {
        if( str[ i ] != str[ ((len -  1) - i) ] ) {
            resultado = 0 ; // No es palíndroma
            i = len ; // Forzar la salida del bucle
        }
    }
    return( resultado ) ; // Retornar el resultado
}

// Función usando punteros
int esPalindromoPunteros( const char* str ) {
    int resultado = 1 ; // Inicialmente asumimos que es palíndroma

    const char* inicio = str ; // Puntero al inicio de la palabra
    const char* fin = str + strlen ( str ) - 1 ; // Puntero al final de la palabra

    while( inicio < fin ) {
        if( *inicio != *fin ) {
            resultado = 0 ; // No es palíndroma
            inicio    = fin ; // Forzar la salida del bucle
        } else {
            inicio++ ; // Avanzar el puntero del inicio
            fin-- ;    // Retroceder el puntero del final
        }
    }

    return( resultado ) ; // Retornar el resultado
}

int main() {
    char str [ STRING_SIZE ] = "" ;

    int letterCount[ 26 ] = { 0 } ; // Array para contar las letras(a-z)

    leerPalabra( str , STRING_SIZE ) ; // Leer una palabra

    // Verificar si es palíndroma usando índices
    if( esPalindromoIndices( str ) ) {
        printf( "La palabra '%s' es palíndroma(usando índices).\n" , str ) ;
    } else {
        printf( "La palabra '%s' no es palíndroma(usando índices).\n" , str ) ;
    }

    // Verificar si es palíndroma usando punteros
    if( esPalindromoPunteros( str ) ) {
        printf( "La palabra '%s' es palíndroma(usando punteros).\n" , str ) ;
    } else {
        printf( "La palabra '%s' no es palíndroma(usando punteros).\n" , str ) ;
    }

    printf( "\n" ) ;

    return( 0 ) ;
}