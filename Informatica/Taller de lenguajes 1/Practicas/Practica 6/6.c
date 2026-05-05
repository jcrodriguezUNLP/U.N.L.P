// Realice un programa que defina una macro AREA_CIRCULO(r) que permita calcular el área de un círculo para un radio r.
// El cuerpo del programa debe generar aleatoriamente 10 valores diferentes que representan radios e imprimir el área correspondiente. 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

# define CANT_RADIOS 10

#define AREA_CIRCULO(r) ( 3.14159 * (r) * (r) )

int main(){
    srand( (unsigned)time( NULL ) ) ;

    int radio ;

    int radios[ CANT_RADIOS ] ;


    for( int i = 0 ; i < CANT_RADIOS ; i++ ){
        radio = rand() % 100 ; // Genera un radio aleatorio entre 0 y 99

        radios[ i ] = radio ;
    }

    for( int i = 0 ; i < CANT_RADIOS ; i++ ){
        printf("El area del circulo con radio %d es: %.2f\n", radios[i], AREA_CIRCULO( radios[i] ) ) ;
    }

    return( 0 ) ;
}