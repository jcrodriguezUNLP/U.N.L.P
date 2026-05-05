// 2. (1 punto) Indique qué imprime el código siguiente:

#include <stdio.h>
#define MOSTRAR 0                       // definición inicial de MOSTRAR = 0

int main(){
    int i ;                             // declaración de la variable i
    
    for( i = 10 ; 5 < i ; i-- ) {       // bucle que decrementa i desde 10 hasta 6
        #ifdef MOSTRAR                  // si MOSTRAR está definido
            printf( "%d", i ) ;         //      imprime el valor de i
            
            #undef MOSTRAR              //      elimina la definición de MOSTRAR
        #else                           // si MOSTRAR no está definido
            #define MOSTRAR 0           //      define MOSTRAR como 0

        #endif                          // fin de la directiva condicional
    }
    
    return( 0 ) ;
}

// análisis:
// El código utiliza directivas de preprocesador para controlar la impresión de valores.
// Inicialmente, MOSTRAR está definido como 0.
// En la primera iteración del bucle (i=10), MOSTRAR está definido, por lo que se imprime 10 y luego se elimina la definición de MOSTRAR.
// En la segunda iteración (i=9), MOSTRAR ya no está definido, por lo que se redefine como 0.
// En la tercera iteración (i=8), MOSTRAR está definido nuevamente, por lo que se imprime 8 y luego se elimina la definición de MOSTRAR.
// Este patrón continúa, imprimiendo los valores pares de i: 10, 8, 6.
// Por lo tanto, la salida del programa será: 10 8 6