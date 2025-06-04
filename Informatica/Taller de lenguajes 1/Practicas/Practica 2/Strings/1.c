#include <stdio.h>
#include <string.h>

#define STRING_SIZE 101 // Tamaño máximo del string mas \0

// leer un string
void leerPalabra( char str[] , int maxLength ){
    printf("\nIngrese una palabra (o 'ZZZ' para terminar): ");
    scanf("%s", str); // Leer un string
}

int cantPalabrasMas5() {
    char str[ STRING_SIZE ] = "" ;
    int contador = 0 ;
    int notFin ;
    
    do {
        leerPalabra( str , STRING_SIZE ) ; // Leer una palabra

        // Comparar la palabra con "ZZZ"
        notFin = strcmp( str , "ZZZ" ) == 0 ? 0 : 1 ;

        if( notFin ) {
            if( 5 <= strlen( str ) ) {
                contador++;
            }
        }
    } while( notFin ) ;

    return( contador ) ; // Retornar la cantidad de palabras con más de 5 caracteres
}

int main() {
    printf( "\ncantidad de palabras con mas de 5 caracteres: %d" , cantPalabrasMas5() ) ;

    printf( "\n" ) ;
    
    return( 0 ) ;
}