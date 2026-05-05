// Analice y ejecute el siguiente código: 

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

// #define SQUAREOF( x ) x * x     --> error
#define SQUAREOF( x ) (x) * (x)    // corrección

int main() { 
    int xin = 3 ;

    printf( "\nxin = %i\n\n" , xin ) ; 

    printf( "SQUAREOF( xin       ) = %i\n" , SQUAREOF( xin       ) ) ; 
    printf( "SQUAREOF( xin + 4   ) = %i\n" , SQUAREOF( xin + 4   ) ) ; 
    printf( "SQUAREOF( xin + xin ) = %i\n" , SQUAREOF( xin + xin ) ) ; 
} 

// A)
//     ¿Qué es lo que hace?
//     Calcula el cuadrado de un número usando una macro.
// B)
//     La macro SQUAREOF debería calcular el cuadrado de un número
//     ¿Los resultados son los esperados?
//          No.
//     ¿Cuál es el problema? 
//          La macro no está correctamente parentizada, lo que causa errores de precedencia en las operaciones.
// C)
//     Modifique la macro para que el cálculo sea correcto. 