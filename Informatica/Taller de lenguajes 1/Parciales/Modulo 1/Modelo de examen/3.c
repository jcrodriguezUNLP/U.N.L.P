// Indique la opción correcta si a partir del siguiente código se desea cambiar el valor de la variable c a 15

#include <stdio.h>

int main() {
    int *a , *b , c , d , *e ;      // --> | int *a ; puntero
                                    //     | int *b ; puntero 
                                    //     | int c  ; entero
                                    //     | int d  ; entero
                                    //     | int *e ; puntero

    c = 10 ;                        // c = 10        ;
    d = c * 2 ;                     // d = ( c * 2 ) ; --> d = 20
    a = e ;                         // a = e         ; los 2 apuntan a basura
    e = &c ;                        // e apunta a la direccion de memoria de c
    b = a = e ;                     // b = a = e     ; --> | b = ( a = e ) -- > | a = &c
                                    //                     |         |          | b = &c
                                    //                     |         v          | e = &c
                                    //                     |       a = e
                                    //                     |       a = &c

    return( 0 ) ;
}

// ____
// |  |  e  = 15 ;
// ----
// _____
// | x | *e = 15 ; ----> | 
// -----                 | 
// ____                  | 
// |  |  *c = 15 ;       | 
// ----                  | 
// ____                  | 
// |  |  a  = 15 ;       | 
// ----                  |  2 OPCIONES CORRECTAS ?????
// ____                  | 
// |  |  &a = 15 ;       | 
// ----                  | 
// ____                  | 
// |  |  b  = 15 ;       | 
// ----                  | 
// _____                 | 
// | x | *b = 15 ; ----> | 
// -----
// ____
// |  | Ninguna de las opciones anteriores cambian el valor de c a 15.
// ----

