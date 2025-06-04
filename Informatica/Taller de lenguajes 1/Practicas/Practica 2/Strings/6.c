#include <stdio.h>
#include <string.h>

#define STRING_SIZE 101 // Tamaño máximo del string mas \0

// leer un string
void leerPalabra( char str[] , int maxLength ){
    printf("\nIngrese una palabra (o 'ZZZ' para terminar): ");
    scanf("%s", str); // Leer un string
}

void contarLetras( const char* str, int letterCount[] ) {
    // Inicializar el array de conteo
    for( int i = 0 ; i < 26 ; i++ ) {
        letterCount[ i ] = 0 ;
    }

    // Contar las letras en la palabra
    for( int i = 0 ; str[ i ] != '\0' ; i++ ) {
        if( ('a' <= str[ i ]) && (str[ i ] <= 'z') ) {
            letterCount[ (str[ i ] - 'a') ]++ ;
        }
    }
}

void imprimirFrecuenciaLetras(const int letterCount[]) {
    // Imprimir el conteo de cada letra
    printf( "\nFrecuencia de letras:\n" ) ;
    
    for( int i = 0 ; i < 26 ; i++ ) {
        if( 0 < letterCount[ i ] ) {
            printf( "%c: %d\n" , ('a' + i) , letterCount[ i ] ) ;
        }
    }
}

int main() {
    char str[ STRING_SIZE ] = "" ;

    int letterCount[26] = {0} ; // Array para contar las letras (a-z)

    leerPalabra( str , STRING_SIZE ) ; // Leer una palabra

    // Llamar a las funciones
    contarLetras( str , letterCount ) ;
    imprimirFrecuenciaLetras( letterCount ) ;

    printf("\n");

    return 0;
}