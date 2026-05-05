// A)
//     Investigue las funciones de conversión de texto a número
//     escriba un programa “calculadora.c”
//         reciba como argumentos a la función main:
//             dos números enteros
//             un operador “+”, “-”, “/”, “.”
//         imprima en pantalla:
//             resultado de la operación
//             Si el operador recibido no es uno de los mencionados anteriormente, entonces el programa debe imprimir un mensaje de error.  
// B)
//     Utilice una terminal para compilar el programa a través de la línea de comandos.

#include <stdio.h>
#include <stdlib.h>

int main( int argc , char* argv[] ){

    if( argc != 4 ){
        printf( "Error: Se requieren 3 argumentos: numero1 operador numero2\n" ) ;
        return( 1 ) ;
    }

    int num1 = atoi( argv[1] ) ;
    int num2 = atoi( argv[3] ) ;

    char operador = argv[2][0] ;    // argumento 2 , primer caracter

    int resultado ;

    switch( operador ){
        case '+':
            resultado = ( num1 + num2 ) ;
            break ;
        case '-':
            resultado = ( num1 - num2 ) ;
            break ;
        case '.':
            resultado = ( num1 * num2 ) ;
            break ;
        case '/':
            if( num2 == 0 ){
                printf( "Error: Division por cero no permitida\n" ) ;
                return( 1 ) ;                                               // salir con error
            } else {
                resultado = ( num1 / num2 ) ;
            }
            break ;
        default:
            printf( "Error: Operador no reconocido\n" ) ;
    }

    printf( "%d %c %d = %d\n" , num1 , operador , num2 , resultado ) ;


    return( 0 ) ;
}