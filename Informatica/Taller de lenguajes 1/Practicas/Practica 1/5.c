// Escriba  un programa que imprima  en pantalla  todos los  números enteros múltiplos de 5 
// comprendidos entre 1 y 50. Realice dos soluciones con las siguientes características: 
// a. Utilizando el operador % para determinar cuándo un número es múltiplo de 5. 
// b. Utilizando un for donde la variable índice se incremente en 5 unidades por cada iteración

#include <stdio.h>

int main() {
    // a
    for( int i = 1 ; i <= 50 ; i++ ){
        // opcion 1
        if( (i % 5) == 0 ) {
            printf( "%d es múltiplo de 5\n" , i ) ;
        }

        // opcion 2 // aprovechando que 0 es falso y cualquier otro valor es verdadero
        if( !(i % 5) ) {
            printf( "%d es múltiplo de 5\n" , i ) ;
        }
    }

    // b
    for( int i = 5 ; i <= 50 ; i += 5 ) {
        printf( "%d es múltiplo de 5\n" , i ) ;
    }

    return( 0 ) ;
}