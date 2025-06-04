#include <stdio.h>
#include <string.h>

#define STRING_SIZE 101 // Tamaño máximo del string mas \0

// leer un string
void leerPalabra( char str[] , int maxLength ){
    printf("\nIngrese una palabra (o 'ZZZ' para terminar): ");
    scanf("%s", str); // Leer un string
}

// Implementación propia de la función strlen
int my_strlen( const char *str ) {
    int length = 0;

    while( *str ) {
        length++ ;

        str++ ;
    }

    return( length ) ;
}

int main() {
    char str[ STRING_SIZE ] = "" ;

    leerPalabra( str , STRING_SIZE ) ; // Leer una palabra

    //"uando mi str"
    printf( "\nusando mi funcion:" ) ; // Imprimir la palabra
    printf( "\n  La longitud de la palabra es: %d", my_strlen( str ) ) ; // Imprimir la longitud de la palabra
    
    printf( "\nusando strlen:" ) ; // Imprimir la palabra
    printf( "\n  La longitud de la palabra es: %d", strlen( str ) ) ; // Imprimir la longitud de la palabra

    printf("\n");

    return 0;
}