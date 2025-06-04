#include <stdio.h>
#include <stdlib.h> // Para srand() y rand()
#include <time.h>   // Para time()

int main() {
    int dado1 ;
    int dado2 ;

    int jugada ;

    // Inicializar la semilla del generador de números aleatorios con la hora actual
    srand( time(NULL) ) ;

    // Generar dos números aleatorios entre 1 y 6
    dado1 = ( (rand() % 6) + 1 ) ;
    dado2 = ( (rand() % 6) + 1 ) ;

    jugada = ( dado1 + dado2 ) ;
    
    // Imprimir los valores de los dados
    printf( "\n\nDado 1: %d" , dado1  ) ;
    printf( "\nDado 2: %d"   , dado2  ) ;
    printf( "\njugada: %d"   , jugada ) ;
    
    if( (jugada == 7) | (jugada == 11) ){
        printf( "\nGanaste" ) ;
    } else if( (jugada == 2) | (jugada == 12) ){
        printf( "\nPerdiste" ) ;
    } else{
        int jugada1 = jugada ;
        
        do{
            dado1 = ( (rand() % 6) + 1 ) ;
            dado2 = ( (rand() % 6) + 1 ) ;
            
            jugada = ( dado1 + dado2 ) ;
            
            // Imprimir los valores de los dados
            printf( "\n\nDado 1: %d" , dado1  ) ;
            printf( "\nDado 2: %d"   , dado2  ) ;
            printf( "\njugada: %d"   , jugada ) ;
        } while( jugada != jugada1 ) ;
        
        printf( "\nFin del juego" ) ;
    }

    return( 0 ) ;
}