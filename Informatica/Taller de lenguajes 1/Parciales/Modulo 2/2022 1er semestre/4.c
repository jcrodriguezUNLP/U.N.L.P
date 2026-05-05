// implemente la biblioteca ipot.h, la cual contiene funciones matematiccas para enteros
// la misma debe contener las siguientes funciones:
//    int potencia( int base , int exponente ) ; eleva 'base' a la 'exponente'
//    int cuadrado( int numero               ) ; eleva 'numero' al cuadrado

// indique claramente:
//      el nombre del archivo donde se encuentran los prototipos de la funcion
//      la declaracion de tipos y donde va la implementacion de las funciones( de debe implementarlas )



/* * Nombre del archivo: ipot.h 
 * Descripción: Contiene los prototipos de las funciones matemáticas.
 */

#ifndef IPOT_H                              // Guarda de inclusión (inicio)
#define IPOT_H                              // IPOT_H

int potencia( int base , int exponente ) ;

int cuadrado( int numero ) ;

#endif                                      // IPOT_H (Fin de la guarda)



/* * Nombre del archivo: ipot.c
 * Descripción: Contiene la implementación (código) de las funciones.
 */

#include "ipot.h" // Importamos nuestros propios prototipos

int potencia( int base , int exponente ) {
    int resultado = 1 ;
    int i ;
    
    // Si el exponente es 0, cualquier número da 1
    if( exponente == 0 ) {
        return( 1 ) ;
    }
    
    // Multiplicamos la base por sí misma 'exponente' veces
    for( i = 0 ; i < exponente ; i++ ) {
        resultado = resultado * base;
    }
    
    return resultado;
}

int cuadrado(int numero) {
    // Reutilizamos la lógica matemática simple
    // También se podría llamar a: potencia(numero, 2);
    return numero * numero;
}



/* Nombre del archivo: main.c */
#include <stdio.h>
#include "ipot.h"  // Usamos comillas "" para bibliotecas locales

int main() {
    int n = 5 ;
    int b = 2 ;
    int e = 3 ;

    printf( "El cuadrado de %d es : %d\n", n ,    cuadrado( n   ) ) ;
    printf( "%d elevado a la %d es: %d\n", b , e, potencia(b , e) ) ;

    return( 0 ) ;
}