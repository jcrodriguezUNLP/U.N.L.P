#include <stdio.h>
#define MAX 4
#define DEBUG 1
#define VERBOSE 0

void procesar( int ) ;

int main(){
    int ini = 10 ;

    #if 3 < MAX                             // VERDADERO
        procesar( ini ) ;                   // Llama a procesar(10) luego de preprocesar
        #undef VERBOSE                      // Desdefine VERBOSE
    #else
        printf( "FIN\n" ) ;                 // No procesa
    #endif

    return( 0 ) ;
}

void procesar( int base ){
    int i        ;                          // Declaración de i
    int r = base ;                          // r = 10

    #ifndef VERBOSE                         // VERDADERO porque VERBOSE no está definido
        #define FACTOR 2                    // Define FACTOR como 2
    #else
        #define FACTOR 0                    // No se procesa
    #endif

    for( i = 1 ; i < MAX ; i++ ){
        r += ( i * FACTOR ) ;               // 1 < 4 --> r = 10 + (1*2) = 12
                                            // 2 < 4 --> r = 12 + (2*2) = 16
                                            // 3 < 4 --> r = 16 + (3*2) = 22

        #if DEBUG                           // VERDADERO porque DEBUG está definido
            printf( "%d - %d\n", i, r ) ;   // 1 < 4 --> Imprime "1 - 12"
                                            // 2 < 4 --> Imprime "2 - 16"
                                            // 3 < 4 --> Imprime "3 - 22"
        #endif
    }

    #if !defined( FACTOR )                  // FALSO porque FACTOR está definido
        printf( "RESULTADO: %d\n", r ) ;    // No se procesa
    #endif
}

// B) al cambiar la linea 2 por #define MAX 2 se compilarian mas instricciones?
//      solo se imprimiria "FIN"

// C) al cambiar la linea 25 por #if VERBOSE se compilaran menos instrucciones?
//      se compilarian las mismas instrucciones pero cambiarian los resultados

// D) al cambiar la linea 36 por #ifndef DEBUG se compilaran menos instrucciones?
//      si, no se compilarian las instrucciones dentro del #if DEBUG